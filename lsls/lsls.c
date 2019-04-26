#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
/**
 * Main
 */
// HINTS:
// 1. stat() arguments require the path/filename UNLESS it is already at the path
// 2. Concatenation of strings is C is not "normal" and a helper function is needed to do it accurately (so, to get the path/file-name string you need to do this).
// 3. If the file is in directory `"."` and you concat the path, you are gunna have a bad time (see 1)
// 4. Not ending a path with "/" may mean you end up having a bad time.
char *concat(const char *s1, const char *s2)
{
  char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  // in real code you would check for errors in malloc here
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

int main(int argc, char **argv)
{
  //Variables I am using:
  struct dirent *de = NULL;
  struct stat buf;
  DIR *dr;
  char *filename;

  // Parsing the Command Line

  printf("There are %d command line argument(s):\n", argc);

  // Open directory
  // DIR *dr = opendir(".");
  if (argv[1] == NULL)
  {

    dr = opendir(".");
  }
  else
  {
    dr = opendir(argv[1]);
  }
  // Print some file length

  // Repeatly read and print entries

  if (dr == NULL)
  {

    printf("Can't open. Maybe there's nothing here in this directory?");
    return 0; // exit out with code 0
  }
  // Close directory
  while ((de = readdir(dr)) != NULL)
  {
    // get around parsing issues
    if (argv[1] != NULL)
    {
      filename = concat(argv[1], de->d_name);
      printf("filename: %s", filename);
    }
    else
    {

      filename = de->d_name;
    }
    if (de->d_type != DT_DIR && !stat(filename, &buf))
    {

      printf("%s -- %10lli bytes\n", de->d_name, buf.st_size);
      // printf("file size is %10lld\n", buf.st_size);
    }
    else if (de->d_type == DT_DIR)
    {
      printf("%s\n", de->d_name);
    }
    else
    {
      printf("%s\n", de->d_name);
      printf("stat() failed.\n");
    }
  }
  closedir(dr);
  return 0;
}
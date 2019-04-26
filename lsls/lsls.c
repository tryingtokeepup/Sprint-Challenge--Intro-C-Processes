#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
/**
 * Main
 */
// HINTS:
// 1. stat() arguments require the path/filename UNLESS it is already at the path
// 2. Concatenation of strings is C is not "normal" and a helper function is needed to do it accurately (so, to get the path/file-name string you need to do this).
// 3. If the file is in directory `"."` and you concat the path, you are gunna have a bad time (see 1)
// 4. Not ending a path with "/" may mean you end up having a bad time.

int main(int argc, char **argv)
{
  //Variables I am using:
  struct dirent *de = NULL;
  struct stat buf;
  DIR *dr;
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
    printf("%s\n", de->d_name);
    if (!stat(de->d_name, &buf))
    {

      printf("file size is %lld\n", buf.st_size);
    }
    else
    {

      printf("stat() failed for this file, try with another file.\n");
    }

    // stat("de", &buf);
    // printf("file size is %lld\n", buf.st_size);
  }
  closedir(dr);
  return 0;
}
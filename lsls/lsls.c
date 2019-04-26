#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  //Variables I am using:
  struct dirent *de = NULL;
  DIR *dr;
  // Parsing the Command Line

  printf("There are %d command line argument(s):\n", argc);

  if (argc < 2)
  {
    printf("Testing: testing program <dirname>\n");
    return 1;
  }
  dr = opendir(argv[1]);
  // Open directory
  // DIR *dr = opendir(".");

  // Repeatly read and print entries
  if (dr == NULL)
  {

    printf("Can't open. Maybe there's nothing here in this directory?");
    return 0; // exit out with code 0
  }
  // Close directory
  while ((de = readdir(dr)) != NULL)
    printf("%s\n", de->d_name);

  closedir(dr);
  return 0;
}
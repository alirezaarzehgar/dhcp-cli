/**
 * @file dhcpcli.c
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-10-16
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "cli/dhcpcli.h"
#include "cli/file.h"
#include "lease/lease.h"

static struct option long_option[] =
{
  {"show", required_argument, NULL, 's'},
  {"add", required_argument, NULL, 'a'},
  {"edir", required_argument, NULL, 'e'},
  {"database", required_argument, NULL, 'f'},
  {"init", required_argument, NULL, 'i'},
};

int
main (int argc, char const *argv[])
{
  int opt;

  int index;

  int programMode = MODE_UNKNOW;

  char database[DHCPCLI_MAX_FILEPATH_LEN];

  strncpy (database, DHCP_DATABASE_PATH, DHCPCLI_MAX_FILEPATH_LEN);

  while ((opt = getopt_long (argc, (char *const *)argv, "s:a:e:f:i", long_option,
                             &index)) != -1)
    {
      switch (opt)
        {
        case 's':
          programMode = MODE_SHOW;
          break;

        case 'a':
          programMode = MODE_ADD;
          break;

        case 'e':
          programMode = MODE_EDIT;
          break;

        case 'f':
          if (databaseExists (optarg))
            strncpy (database, optarg, DHCPCLI_MAX_FILEPATH_LEN);
          break;

        case 'i':
          if (databaseInit (database))
            printf ("database initialized successfully\n");

          exit (EXIT_SUCCESS);
          break;
        }
    }

  printf ("%s\n", database);

  return 0;
}

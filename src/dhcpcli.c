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
#include "cli/dhcpcli_handler.h"

static struct option long_option[] =
{
  {"show", no_argument, NULL, 's'},
  {"add", no_argument, NULL, 'a'},
  {"edir", no_argument, NULL, 'e'},
  {"database", required_argument, NULL, 'f'},
  {"init", optional_argument, NULL, 'i'},
  {"config", optional_argument, NULL, 'c'},
  {"leases", optional_argument, NULL, 'l'},
  {NULL, 0, NULL, 0},
};

int
main (int argc, char const *argv[])
{
  int opt;

  int index;

  int programMode = MODE_UNKNOW;

  char database[DHCPCLI_MAX_FILEPATH_LEN];

  strncpy (database, DHCP_DATABASE_PATH, DHCPCLI_MAX_FILEPATH_LEN);

  while ((opt = getopt_long (argc, (char *const *)argv, "saef:i::c::l::",
                             long_option,
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
          if (databaseInit (optarg == NULL ? database : optarg))
            printf ("database initialized successfully\n");
          else
            fprintf (stderr, "already exists\n");

          exit (EXIT_SUCCESS);
          break;

        case 'c':
          if (!databaseExists (database))
            {
              fprintf (stderr, "database notfound\n");
              exit (EXIT_FAILURE);
            }

          dhcpcliConfigHandler (programMode, database, optarg);
          break;

        case 'l':
          if (!databaseExists (database))
            {
              fprintf (stderr, "database notfound\n");
              exit (EXIT_FAILURE);
            }

          dhcpcliLeaseHandler (programMode, database, optarg);
          break;

        default:
          exit(EXIT_FAILURE);
        }
    }

  return 0;
}

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

static struct option long_option[] =
{
  {"show", required_argument, NULL, 's'},
  {"add", required_argument, NULL, 'a'},
  {"edir", required_argument, NULL, 'e'},
  {"database", required_argument, NULL, 'f'},
};

int
main (int argc, char const *argv[])
{
  int opt;

  int index;

  while ((opt = getopt_long (argc, (char *const *)argv, "s:a:e:f:", long_option,
                             &index)) != -1)
    {
      switch (opt)
        {
        case 's':
          /* TODO */
          break;

        case 'a':
          /* TODO */
          break;

        case 'e':
          /* TODO */
          break;

        case 'f':
          /* TODO */
          break;
        }
    }

  return 0;
}

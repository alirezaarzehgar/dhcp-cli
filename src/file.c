/**
 * @file file.c
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-10-13
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "cli/file.h"
#include "lease/lease.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

bool
databaseExists (char *path)
{
  return access (path, F_OK) == 0;
}


/* TODO shit code */
bool
isDatabaseWritable (char *path)
{
  char tmp[strlen (path)];

  memcpy (tmp, path, strlen (path));

  for (size_t i = strlen (tmp); i > 0; i--)
    {
      if (tmp[i] == '/')
        {
          tmp[i] = '\0';

          break;
        }
      else
        tmp[i] = '\0';
    }

  if (!databaseExists (tmp))
    strcpy (tmp, ".");

  return access (tmp, W_OK) == 0;
}

bool
databaseInit (char *path)
{
  if (! isDatabaseWritable (path))
    {
      fprintf (stderr, "Unable to write on database: %s\n", strerror (errno));
      exit (EXIT_FAILURE);
    }

  if (
    !dhcpLeaseInit (path) ||
    !dhcpLeaseInitConf() ||
    !dhcpLeaseInitPool()
  )
    return false;

  dhcpLeaseClose();

  return true;
}
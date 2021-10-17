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
#include <libgen.h>

bool
databaseExists (char *path)
{
  return access (path, F_OK) == 0;
}

bool
isDatabaseWritable (char *path)
{
  char dir[strlen (path)];

  strcpy (dir, path);

  dirname (dir);

  return  access (dir, W_OK) == 0;
}

bool
databaseInit (char *path)
{
  /* TODO error handling and reporting should be out of function */
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
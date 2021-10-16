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

bool
databaseExists (char *path)
{
  return access (path, F_OK) == 0;
}

bool
databaseInit (char *path)
{
  int retval;

  if (! (retval = databaseExists (path)))
    return retval;

  databaseInit (path);

  /* TODO */

  dhcpLeaseClose();
}
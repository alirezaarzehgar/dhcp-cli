/**
 * @file dhcpcli_handler.c
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-10-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "cli/dhcpcli_handler.h"
#include "cli/file.h"

void
dhcpcliConfigShow (char *db, char *arg)
{
  printf ("%s & %s", db, arg);
  /* TODO dhcpcliConfigShow */
}

void
dhcpcliConfigEdit (char *db, char *arg)
{
  /* TODO dhcpcliConfigEdit */
}

void
dhcpcliConfigAdd (char *db, char *arg)
{
  /* TODO dhcpcliConfigAdd */
}

void
handleToCorrectMode (int mode, char *db, char *arg, dhcpcliHandler_t show,
                     dhcpcliHandler_t add, dhcpcliHandler_t edit)
{
  dhcpLeaseInit (db);

  switch (mode)
    {
    case MODE_SHOW:
      show (db, arg);
      break;

    case MODE_ADD:
      add (db, arg);
      break;

    case MODE_EDIT:
      edit (db, arg);
      break;
    }

  dhcpLeaseClose();
}

void
dhcpcliConfigHandler (int mode, char *db, char *arg)
{
  handleToCorrectMode (mode, db, arg, dhcpcliConfigShow, dhcpcliConfigAdd,
                       dhcpcliConfigEdit);
}

void
dhcpcliLeaseShow (char *db, char *arg)
{
  /* TODO dhcpcliLeaseShow */
}

void
dhcpcliLeaseEdit (char *db, char *arg)
{
  /* TODO dhcpcliLeaseEdit */
}

void
dhcpcliLeaseAdd (char *db, char *arg)
{
  /* TODO dhcpcliLeaseAdd */
}

void
dhcpcliLeaseHandler (int mode, char *db, char *arg)
{
  handleToCorrectMode (mode, db, arg, dhcpcliLeaseShow, dhcpcliLeaseAdd,
                       dhcpcliLeaseEdit);
}
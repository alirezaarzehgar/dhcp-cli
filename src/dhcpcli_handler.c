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
dhcpcliConfigShow (char *arg)
{
    /*TODO*/
  if (arg == NULL)
    {
      dhcpLeaseConfigResult_t conf;

      for (int i = 1; conf.id > 0; conf = dhcpLeaseGetConfigById (i), i++)
        printf ("%dmask : %s\n", conf.mask);
    }

}

void
dhcpcliConfigEdit (char *arg)
{
  /* TODO dhcpcliConfigEdit */
}

void
dhcpcliConfigAdd (char *arg)
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
      show (arg);
      break;

    case MODE_ADD:
      add (arg);
      break;

    case MODE_EDIT:
      edit (arg);
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
dhcpcliLeaseShow (char *arg)
{
  /* TODO dhcpcliLeaseShow */
}

void
dhcpcliLeaseEdit (char *arg)
{
  /* TODO dhcpcliLeaseEdit */
}

void
dhcpcliLeaseAdd (char *arg)
{
  /* TODO dhcpcliLeaseAdd */
}

void
dhcpcliLeaseHandler (int mode, char *db, char *arg)
{
  handleToCorrectMode (mode, db, arg, dhcpcliLeaseShow, dhcpcliLeaseAdd,
                       dhcpcliLeaseEdit);
}
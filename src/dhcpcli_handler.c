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

void
dhcpcliConfigShow (char *db, char *arg)
{
    printf("%s & %s", db, arg);
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
handleToCorrectMode (dhcpcliHandler_t show, dhcpcliHandler_t add,
                     dhcpcliHandler_t edit)
{

}

void
dhcpcliConfigHandler (int mode, char *db, char *arg)
{
    printf("Hi!");
  switch (mode)
    {
    case MODE_SHOW:
      dhcpcliConfigShow (db, arg);
      break;

    case MODE_ADD:
      dhcpcliConfigEdit (db, arg);
      break;

    case MODE_EDIT:
      dhcpcliConfigAdd (db, arg);
      break;
    }
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
  switch (mode)
    {
    case MODE_SHOW:
      dhcpcliLeaseShow (db, arg);
      break;

    case MODE_ADD:
      dhcpcliLeaseEdit (db, arg);
      break;

    case MODE_EDIT:
      dhcpcliLeaseAdd (db, arg);
      break;
    }
}
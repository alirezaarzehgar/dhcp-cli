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
printConf (dhcpLeaseConfigResult_t cfg)
{
  if (cfg.id == 0)
    return;

  printf ("id : %d\n", cfg.id);
  printf ("mask : %s\n", cfg.mask);
  printf ("router : %s\n", cfg.mask);
  printf ("domain : %s\n", cfg.domain);
  printf ("lease time : %d\n", cfg.lease_time);
  printf ("\n");
}

void
printLease (dhcpLeasePoolResult_t lease)
{
  printf ("id : %d\n", lease.id);
  printf ("config id : %d\n", lease.config.id);
  printf ("ip : %s\n", lease.ip);
  printf ("host : %s\n", L (lease.host) != 0 ? lease.host : UNDEFINED_STRING);
  printf ("mac : %s\n", L (lease.mac) != 0 ? lease.mac : UNDEFINED_STRING);
  printf ("\n");
}

#define SHOW_HANDLER_FUNCTIONALITY(getXByIdCallback, printXCallback, XCountCallback)      \
do {      \
  int id = atoi (arg != NULL ? arg : "");     \
        \
  if (id > 0)     \
    {       \
      printXCallback (     \
        getXByIdCallback (id)     \
      );      \
    }       \
  else        \
    {     \
      for (size_t i = 1; i <= XCountCallback(); i++)      \
        {     \
          printXCallback (     \
            getXByIdCallback (i)      \
          );      \
        }       \
    }     \
}while(0)

void
dhcpcliConfigShow (char *arg)
{
  SHOW_HANDLER_FUNCTIONALITY (dhcpLeaseGetConfigById, printConf,
                              dhcpLeaseConfCount);
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
  SHOW_HANDLER_FUNCTIONALITY (dhcpLeasePoolGetById, printLease,
                              dhcpLeasePoolCount);
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
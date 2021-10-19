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
dhcpcliConfigShow (char *arg)
{
  int id = atoi (arg != NULL ? arg : "");

  dhcpLeaseConfigResult_t conf;
  int i = 1;

  if (id > 0)
    {
      printConf (
        dhcpLeaseGetConfigById (id)
      );

      return;
    }


  do
    {
      bzero (&conf, sizeof (dhcpLeaseConfigResult_t));
      conf = dhcpLeaseGetConfigById (i);
      printConf (conf);
    }
  while (conf.id == i++);
}

void
dhcpcliConfigEdit (char *arg)
{
  int id = atoi (arg != NULL ? arg : "");

  dhcpLeaseConfigResult_t conf;
  int i = 1;

  if (id > 0)
    {
      printConf (
         (id)
      );

      return;
    }


  do
    {
      bzero (&conf, sizeof (dhcpLeaseConfigResult_t));
      conf = dhcpLeaseGetConfigById (i);
      printConf (conf);
    }
  while (conf.id == i++);
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
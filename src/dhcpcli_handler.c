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

bool
isConfValid (dhcpLeaseConfigResult_t cfg)
{
  return cfg.id != 0;
}

void
printConf (dhcpLeaseConfigResult_t cfg)
{
  if (!isConfValid (cfg))
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
  printf ("lease flag : %d\n", lease.lease_flag);
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
  int id = atoi (arg != NULL ? arg : "");

  if (id != 0)
    {
      dhcpLeaseConfigResult_t conf = dhcpLeaseGetConfigById (id);

      if (!isConfValid (conf))
        {
          fprintf (stderr, "lease config with id %d not found\n", id);
          return;
        }

      printf ("id : %d\n", conf.id);
      xgetSafeLineWithFormatParser (conf.mask, sizeof (conf.mask),
                                    "Update mask [%s] : ", conf.mask);

      xgetSafeLineWithFormatParser (conf.router, sizeof (conf.router),
                                    "Update router [%s] : ", conf.router);

      xgetSafeLineWithFormatParser (conf.domain, sizeof (conf.domain),
                                    "Update domain [%s] : ", conf.domain);

      xgetSafeIntWithFormatParser (&conf.lease_time, "Update lease time [%d] : ",
                                   conf.lease_time);

      printConf (conf);

      if (xinputConfirm ("is that right [Y/n] ? "))
        {
          /* TODO update config */
        }
    }
}

void
dhcpcliConfigAdd (char *arg)
{
  dhcpLeaseConfigResult_t conf;
  bzero (&conf, sizeof (conf));

  printf ("id : %d\n", conf.id);
  xgetSafeLineWithFormatParser (conf.mask, sizeof (conf.mask),
                                "mask : ", NULL);

  xgetSafeLineWithFormatParser (conf.router, sizeof (conf.router),
                                "router : ", NULL);

  xgetSafeLineWithFormatParser (conf.domain, sizeof (conf.domain),
                                "domain : ", NULL);

  xgetSafeIntWithFormatParser (&conf.lease_time, "lease time [%d] : ",
                               DEFAULT_LEASE_TIME);

  printConf (conf);

  if (xinputConfirm ("is that right [Y/n] ? "))
    {
      /* TODO add config */
    }

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
      break;Confar *db, char *arg)
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
  int id = atoi (arg != NULL ? arg : "");

  if (id != 0)
    {
      dhcpLeasePoolResult_t lease = dhcpLeasePoolGetById (id);

      if (lease.id == 0)
        {
          fprintf (stderr, "lease with id %d not found\n", id);
          return;
        }

      printf ("id : %d\n", lease.id);
      xgetSafeLineWithFormatParser (lease.host, sizeof (lease.host),
                                    "Update hostname [%s] : ", lease.host);

      xgetSafeLineWithFormatParser (lease.ip, sizeof (lease.ip),
                                    "Update ip [%s] : ", lease.ip);

      xgetSafeIntWithFormatParser (&lease.config.id, "Update config id [%d] : ",
                                   lease.config.id);

      xgetSafeIntWithFormatParser ((int *)&lease.lease_flag,
                                   "do you want to set lease flag [%d](0/1) ? ", lease.lease_flag);

      printLease (lease);

      if (xinputConfirm ("is that right [Y/n] ? "))
        {
          /* TODO update lease */
        }
    }
}

void
dhcpcliLeaseAdd (char *unsed)
{
  dhcpLeasePoolResult_t lease;

  bzero (&lease, sizeof (lease));

  printf ("id : %d\n", lease.id);
  xgetSafeLineWithFormatParser (lease.host, sizeof (lease.host),
                                "hostname : ", NULL);

  xgetSafeIntWithFormatParser (&lease.config.id, "config id [%d] : ",
                               dhcpLeaseConfCount());

  xgetSafeLineWithFormatParser (lease.mac, sizeof (lease.mac),
                                "mac : ", NULL);

  xgetSafeLineWithFormatParser (lease.ip, sizeof (lease.ip),
                                "ip : ", NULL);

  xgetSafeIntWithFormatParser ((int *)&lease.lease_flag,
                               "do you want to set lease flag [%d](0/1) ? ", true);

  printLease (lease);

  if (xinputConfirm ("is that right [Y/n] ? "))
    {
      /* TODO Add lease */
    }
}

void
dhcpcliLeaseHandler (int mode, char *db, char *arg)
{
  handleToCorrectMode (mode, db, arg, dhcpcliLeaseShow, dhcpcliLeaseAdd,
                       dhcpcliLeaseEdit);
}
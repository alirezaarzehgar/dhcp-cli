#include "lease/lease.h"
#include "cli/dhcpcli.h"

#if !defined(DHCPCLI_HANDLER_H)
#define DHCPCLI_HANDLER_H

typedef void (*dhcpcliHandler_t) (char *db, char *arg);

void dhcpcliConfigShow (char *db, char *arg);

void dhcpcliConfigEdit (char *db, char *arg);

void dhcpcliConfigAdd (char *db, char *arg);

void dhcpcliConfigHandler (int mode, char *db, char *arg);

void dhcpcliLeaseShow (char *db, char *arg);

void dhcpcliLeaseEdit (char *db, char *arg);

void dhcpcliLeaseAdd (char *db, char *arg);

void dhcpcliLeaseHandler (int mode, char *db, char *arg);

#endif // DHCPCLI_HANDLER_H

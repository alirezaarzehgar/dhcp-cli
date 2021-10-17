#include "lease/lease.h"
#include "cli/dhcpcli.h"

#if !defined(DHCPCLI_HANDLER_H)
#define DHCPCLI_HANDLER_H

typedef void (*dhcpcliHandler_t) (char *arg);

void dhcpcliConfigShow (char *arg);

void dhcpcliConfigEdit (char *arg);

void dhcpcliConfigAdd (char *arg);

void dhcpcliConfigHandler (int mode, char *db, char *arg);

void dhcpcliLeaseShow (char *arg);

void dhcpcliLeaseEdit (char *arg);

void dhcpcliLeaseAdd (char *arg);

void dhcpcliLeaseHandler (int mode, char *db, char *arg);

#endif // DHCPCLI_HANDLER_H

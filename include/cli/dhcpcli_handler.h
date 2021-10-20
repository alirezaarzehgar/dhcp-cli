#include "lease/lease.h"
#include "cli/dhcpcli.h"
#include "cli/safe_input.h"

#if !defined(DHCPCLI_HANDLER_H)
#define DHCPCLI_HANDLER_H

#define L           strlen
#define UNDEFINED_STRING            "not found"
#define DEFAULT_LEASE_TIME          600

typedef void (*dhcpcliHandler_t) (char *arg);

void dhcpcliConfigShow (char *arg);

void dhcpcliConfigEdit (char *arg);

void dhcpcliConfigAdd (char *arg);

void dhcpcliConfigHandler (int mode, char *db, char *arg);

void dhcpcliLeaseShow (char *arg);

void dhcpcliLeaseEdit (char *arg);

void dhcpcliLeaseAdd (char *arg);

void dhcpcliLeaseHandler (int mode, char *db, char *arg);

static inline void
xgetSafeLineWithFormatParser (char *ptr, size_t size, char *message,
                              char *defaultValue)
{
  safeInput input;

#define dest input.sen

  safeInputInit (&input, (size_t)DHCP_LEASE_DOMAIN_STR_MAX_LEN);

  printf (message, defaultValue);

  getSafeLine (&input);

  defaultValue = defaultValue == NULL ? "" : defaultValue;

  strncpy (ptr, L (dest) == 0 ? defaultValue : dest, size);

  safeInputClose (&input);
}

static inline void
xgetSafeIntWithFormatParser (int *intPtr, char *const message,
                             int defaultValue)
{
  safeInput input;

  safeInputInit (&input, 9);

  printf (message, defaultValue);

  getSafeStr (&input);

  if (intPtr != NULL)
    *intPtr = atoi (input.str) == 0 ? defaultValue : atoi (input.str);

  safeInputClose (&input);
}

static inline bool
xinputConfirm (char *msg)
{
  safeInput input;

#define ch    input.ch

  printf (msg);

  getSafeChar (&input);

  return ch == 'Y' || ch == 'y';
}

#endif // DHCPCLI_HANDLER_H

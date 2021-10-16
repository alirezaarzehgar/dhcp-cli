#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#if !defined(DHCPCLI_H)
#define DHCPCLI_H

#define DHCPCLI_MAX_FILEPATH_LEN            225

enum Mode
{
  MODE_SHOW,
  MODE_ADD,
  MODE_EDIT,
  MODE_UNKNOW
};

#endif // DHCPCLI_H

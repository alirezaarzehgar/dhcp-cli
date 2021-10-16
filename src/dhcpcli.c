/**
 * @file dhcpcli.c
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-10-16
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "cli/dhcpcli.h"

int
main (int argc, char const *argv[])
{
  printf ("hello cli\n");
  printf ("path : %s\n", DHCP_DATABASE_PATH);
  return 0;
}

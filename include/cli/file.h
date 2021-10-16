#include <stdbool.h>

#if !defined(DHCPD_FILE_H)
#define DHCPD_FILE_H

bool databaseExists (char *path);

bool databaseInit (char *path);

bool isDatabaseWritable (char *path);

#endif // DHCPD_FILE_H

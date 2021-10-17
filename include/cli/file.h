#include <stdbool.h>
#include <stddef.h>

#if !defined(DHCPD_FILE_H)
#define DHCPD_FILE_H

bool databaseExists (char *path);

bool databaseInit (char *path);

bool isDatabaseWritable (char *path);

size_t dirLen (char const *path);

#endif // DHCPD_FILE_H

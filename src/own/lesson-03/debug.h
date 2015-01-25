#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>

#define MEMORY_ALLOCATION_FAIL "could not allocate memory"

#ifdef DEBUG
#define dbgmsg(MESSAGE, ...) printf("< DEBUG >: " MESSAGE "\n", ##__VA_ARGS__)
#else
#define dbgmsg(MESSAGE, ...)
#endif

#endif /* DEBUG_H */

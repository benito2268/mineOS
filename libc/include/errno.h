#ifndef _ERRNO_H
#define _ERRNO_H

#define ENOERROR 0
#define EOVERFLOW 1
//more to be added here

extern int errno;

char* strerror(int errnum);

#endif
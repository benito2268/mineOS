#include <errno.h>

int errno = ENOERROR;

char* strerror(int errnum) {
    switch(errnum) {
        case ENOERROR:
            return "ENOERROR";
            break;
        case EOVERFLOW:
            return "EOVERFLOW";
            break;
    }
}


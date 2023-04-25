#include <stdlib.h>
#include <stdbool.h>

//as in the standard itoa()
//numbers not in base 10 are considered unsigned
char* itoa(int val, char* str, int base) {
    int i = 0;
    bool is_neg = false;

    if(val == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }   

}
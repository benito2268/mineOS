#include <stdlib.h>
#include <stdbool.h>

//as in the standard itoa()
//numbers not in base 10 are considered unsigned

void reverse(char str[], int len) {
    int start = 0;
    int end = len - 1;
    while(start < end) {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        end--;
        start++;
    }
}

char* itoa(int val, char* str, int base) {
    int i = 0;
    bool is_neg = false;

    //handle the zero case manually
    if(val == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    //check if signed or base 10
    if(val < 0 && base == 10) {
        is_neg = true;
        val = -val;
    }

    while(val != 0) {
        int rem = val % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        val /= base;
    }

    if(is_neg) {
        str[i++] = '-';
    }

    str[i] = '\0';

    reverse(str, i);

    return str;
}
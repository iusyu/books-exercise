#include <stdlib.h>
#include <stdio.h>

int gt(long a, long b) {
    return a > b;
}

long absdiff(long x, long y) {
    long result;
    if( x > y ) 
        result = x - y;
    else
        result = y - x;

    return result;
}


long absdiff_j(long x, long y) {
    long result;
    int ntest = x <= y;
    if( ntest ) goto Else;
    result = x - y;
    goto Done;
Else:
    return y-x;
Done:
    return result;
}

long switch_eg(long x) {
    long result = 0;
    switch (x)
    {
    case 1:
        result = 5;
        break;
    case 2:
        result = 10;
        break;
    case 3:
        result = 15;
    default:
        result = 1;
        break;
    }
    return result;
}

long absdiff_c(long x, long y) {
    return (x>y)?(x-y):(y-x);
}

int main(void) {
    return 1;
}
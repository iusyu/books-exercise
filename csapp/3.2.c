#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>


int test_1() {
		printf("Unsigned size: %d \n", sizeof(unsigned));
}

int test_2() {
		printf("Unsigned size: %d \n", sizeof(long));
}

void shift_left4_right(long x, long n) {
	x <<= 4;
	x >>= n;
}

typedef unsigned __int128 uint128_t;

void store_uprod(uint128_t *dst, uint64_t x, uint64_t y) {
	*dst = x * (uint128_t) y;
}

int main() {
	test_1();
	test_2();
}

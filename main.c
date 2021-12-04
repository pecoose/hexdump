#include "hexdump.h"

#include <stdio.h>

int main(int argc, char const *argv[]) {
	int len = 128 + 4;
	char s[len];
	for (int i = 0; i < len; i++) {
		s[i] = -10 + i;
	}
	if (hexdump((void *)s, sizeof(s)) == -1) {
		fprintf(stderr, "hexdump() failed\n");
	}
	return 0;
}


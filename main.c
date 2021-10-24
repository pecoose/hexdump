#include "hexdump.h"

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int len = 1024;
  char s[len];
  for (int i = 0; i < len; i++) {
    s[i] = 'A' + i;
  }
  if (hexdump((void *)s, sizeof(s)) == -1) {
    fprintf(stderr, "hexdump() failed\n");
  }
  return 0;
}


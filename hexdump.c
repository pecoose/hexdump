#include "hexdump.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int width(int n) {
  if (n == 0) {
    return 1;
  }
  int res = 0;
  while (n > 0) {
    n /= 10;
    res++;
  }
  return res;
}

int hexdump(const void *buf, size_t len) {
  if (buf == NULL && len == 0) {
    return -1;
  }
  unsigned char *p = (unsigned char *)buf;
  int row = 16;
  int lines = len % row == 0 ? len / row : len / row + 1;
  int line = 0;
  int offset = width(lines);
  char hex[3 * row + 1];
  char ascii[row + 1];
  memset(hex, 0, sizeof(hex));
  memset(ascii, 0, sizeof(ascii));
  for (unsigned int i = 0; i < len; i++) {
    int idx = 3 * (i % row);
    snprintf(&hex[idx], 4, "%02X ", p[i]);
    if (p[i] >= ' ' && p[i] <= '~') {
      ascii[i % row] = p[i];
    } else {
      ascii[i % row] = '.';
    }
    if (((i + 1) % row) == 0) {
      printf("%s  %s\n", hex, ascii);
      if (line % row == 0) {
        putchar('\n');
      }
    }
    if ((i % row) == 0) {
      printf("%*.*d | ", offset, width(line), line);
      line++;
    }
  }
  if ((len % row) != 0) {
    printf("%s %s\n", hex, ascii);
  }
  return 0;
}

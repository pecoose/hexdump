#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DumpHex(const void *data, size_t size) {
  char ascii[17];
  size_t i, j;
  ascii[16] = '\0';
  for (i = 0; i < size; ++i) {
    printf("%02X ", ((unsigned char *)data)[i]);
    if (((unsigned char *)data)[i] >= ' ' &&
        ((unsigned char *)data)[i] <= '~') {
      ascii[i % 16] = ((unsigned char *)data)[i];
    } else {
      ascii[i % 16] = '.';
    }
    if ((i + 1) % 8 == 0 || i + 1 == size) {
      printf(" ");
      if ((i + 1) % 16 == 0) {
        printf("|  %s \n", ascii);
      } else if (i + 1 == size) {
        ascii[(i + 1) % 16] = '\0';
        if ((i + 1) % 16 <= 8) {
          printf(" ");
        }
        for (j = (i + 1) % 16; j < 16; ++j) {
          printf("   ");
        }
        printf("|  %s \n", ascii);
      }
    }
  }
}

void PrintBuffer(void *pBuff, unsigned int nLen) {
  if (NULL == pBuff || 0 == nLen) {
    return;
  }

  const int nBytePerLine = 16;
  unsigned char *p = (unsigned char *)pBuff;
  char szHex[3 * nBytePerLine + 1];
  memset(0, szHex, sizeof(szHex));
  printf("-----------------begin-------------------\n");
  for (unsigned int i = 0; i < nLen; ++i) {
    int idx = 3 * (i % nBytePerLine);
    if (0 == idx) {
      memset(szHex, 0, sizeof(szHex));
    }
#ifdef WIN32
    sprintf_s(&szHex[idx], 4, "%02x ", p[i]); // buff长度要多传入1个字节
#else
    snprintf(&szHex[idx], 4, "%02x ", p[i]); // buff长度要多传入1个字节
#endif

    // 以16个字节为一行，进行打印
    if (0 == ((i + 1) % nBytePerLine)) {
      printf("%s\n", szHex);
    }
  }

  // 打印最后一行未满16个字节的内容
  if (0 != (nLen % nBytePerLine)) {
    printf("%s\n", szHex);
  }

  printf("------------------end-------------------\n");
}

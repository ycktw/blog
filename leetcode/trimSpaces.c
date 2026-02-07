#include <stdio.h>
#include <ctype.h>

int trimSpaces(char *str) {
  char *start = str;
  char *end = str;

  // Skip leading spaces
  while (isspace((unsigned char)*start)) {
    start++;
  }

  // If the string is all spaces, set it to an empty string
  if (*start == '\0') {
    *str = '\0';
    return 0;
  }

  // Move end pointer to the end of the string
  while (*end != '\0') {
    end++;
  }
  end--; // Move back to the last character

  // Skip trailing spaces
  while (end > start && isspace((unsigned char)*end)) {
    end--;
  }

  // Null-terminate the trimmed string
  *(end + 1) = '\0';

  // Shift the trimmed string to the beginning of the original string
  // 修改後的搬移邏輯 (取代原本的 if (start != str) 區塊)
  char *dest = str;
  int inSpace = 0; // 用來標記前一個字元是否為空格

  while (*start != '\0') {
    if (!isspace((unsigned char)*start)) {
      *dest++ = *start;
      inSpace = 0; // 目前不是空格
    } else {
      if (!inSpace) { // 如果這是遇到的「第一個」空格
        *dest++ = ' ';
              inSpace = 1; // 標記我們已經補過空格了，後續連續空格將被忽略
      }
    }
    start++;
  }
  *dest = '\0'; // 確保最後結尾正確

  return 0;

}

int main() {
  char testTarget[] = "    test 1234  hellow ";
  printf("Before: '%s'\n", testTarget);
  trimSpaces(testTarget);
  printf("After: '%s'\n", testTarget);
  return 0;
}

// vim set fdm=marker ts=2 ai et sts=2 sw=2 tw=0 noexpandtab
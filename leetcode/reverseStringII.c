#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cleanSpaces(char *s) {
    int i = 0, j = 0;
    int n = strlen(s);
    while (j < n) {
        while (j < n && s[j] == ' ') j++;             // 跳過前面的空格
        if (j < n && i > 0) s[i++] = ' ';             // 如果不是第一個單字，加一個空格
        while (j < n && s[j] != ' ') s[i++] = s[j++]; // 搬運單字
    }
    s[i] = '\0'; // 記得手動補上字串終結符
}

// 這是你之前提到的雙指標 swap 邏輯
void reverse(char *s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

void reverseWords(char *s) {
    int n = strlen(s);
    int start = 0;

    for (int end = 0; end <= n; end++) {
        // 當 end 走到空格，或者走到字串的最末端 (\0) 時
        if (s[end] == ' ' || s[end] == '\0') {
            // 翻轉從 start 到 end-1 的區間 (即該單字)
            reverse(s, start, end - 1);

            // 下一個單字的起點就在空格的下一個位置
            start = end + 1;
        }
    }
}

int main() {
  char testTarget[] = "    test 1234  hellow ";
  char *target = testTarget;
  char *p;

  printf("Before: '%s'\n", target);
  cleanSpaces(target);
  reverse(target, 0, strlen(target) - 1);
  printf("A1: '%s'\n", target);
  reverseWords(target);
  printf("A2: '%s'\n", target);
  return 0;
}

// vim set fdm=marker ts=2 ai et sts=2 sw=2 tw=0 noexpandtab
#include <string.h>
#include <stdio.h>

int lengthOfLastWord(char * s) {
    int length = 0;
    char *p = s + strlen(s) - 1; // 指向最後一個字元

    // 階段一：過濾末尾所有空白
    // p >= s 是為了確保指標不會退到字串記憶體範圍之外
    while (p >= s && *p == ' ') {
        p--;
    }

    // 階段二：開始計算單字長度
    while (p >= s && *p != ' ') {
        length++;
        p--;
    }
	p ++;
	printf("Length of last word(%s): %d\n", p, length); // Output: 5

    return length;
}

int main() {
	int len = lengthOfLastWord("Hello World");
	printf("[output] Length : %d\n", len); // Output: 5
	return 0;
}
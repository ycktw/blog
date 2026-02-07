#include <stdio.h>
#include <string.h>

// 簡單的 MAX 巨集
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char * s) {
    int n = strlen(s);
    if (n == 0) return 0;

    // 建立一個長度 128 的陣列來記錄每個 ASCII 字元上次出現的位置
    // 初始化為 0，代表還沒看過該字元
    int lastSeen[128] = {0};

    int maxLen = 0;
    int left = 0; // 視窗的左邊界

    for (int right = 0; right < n; right++) {
        // 取得當前字元（強制轉為 unsigned 避免特殊字元索引出錯）
        unsigned char c = s[right];

        // 核心邏輯：如果當前字元之前出現過，且它的位置在當前視窗 [left, right] 內
        if (lastSeen[c] > left) {
            // 將左邊界跳轉到該字元上次出現位置的「下一個」
            left = lastSeen[c];
        }

        // 計算目前視窗長度： (右索引 - 左索引 + 1)
        maxLen = MAX(maxLen, right - left + 1);

        // 更新該字元最後一次出現的位置（儲存 index + 1，方便下次 left 直接跳轉）
        lastSeen[c] = right + 1;
    }

    return maxLen;
}

// 測試用 main 函式
int main() {
    char *s1 = "abcabcbb";
    char *s2 = "pwwkew";
	int ret1 = lengthOfLongestSubstring(s1);
	int ret2 = lengthOfLongestSubstring(s2);
    printf("Result 1: %d\n", ret1); // 應該輸出 3
    printf("Result 2: %d\n", ret2); // 應該輸出 3
    return 0;
}
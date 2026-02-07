#include <stdio.h>

/**
 * 核心演算法：動態規劃 (空間優化版)
 * 時間複雜度：O(n)
 * 空間複雜度：O(1)
 */
int climbStairs(int n) {
    // 基礎情況：0 階（通常題目定義為 1 種方法，但 LeetCode n 從 1 開始）
    // 1 階有 1 種走法，2 階有 2 種走法 (1+1, 2)
    if (n <= 2) {
        return n;
    }

    // 我們只需要紀錄「前兩階」的結果
    // prev2: 到達 (i-2) 階的方法數
    // prev1: 到達 (i-1) 階的方法數
    int prev2 = 1;
    int prev1 = 2;
    int current = 0;

    // 從第 3 階開始計算，直到第 n 階
    for (int i = 3; i <= n; i++) {
        // 到達本階的方法 = 前一階的方法 + 前兩階的方法
        current = prev1 + prev2;

        // 滾動更新：為下一階做準備
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int test_cases[] = {2, 3, 4, 5, 10};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("--- LeetCode 70. Climbing Stairs 測試 ---\n");
    for (int i = 0; i < num_tests; i++) {
        int n = test_cases[i];
        printf("樓梯階數: %2d | 不同走法: %d\n", n, climbStairs(n));
    }

    return 0;
}
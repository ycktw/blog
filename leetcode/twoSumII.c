#include <stdio.h>
#include <stdlib.h>

/**
 * 核心演算法：對撞雙指標 (Two Pointers)
 * * numbers: 輸入的排序陣列
 * numbersSize: 陣列長度
 * target: 目標和
 * returnSize: 由我們填寫，告訴呼叫者回傳了多少個元素 (這題固定是 2)
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;

    // 分配記憶體給結果陣列。LeetCode 規範：由 caller 負責 free。
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            // 題目規範是 1-indexed，所以索引要 +1
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else if (sum < target) {
            // 目前和太小，左指標右移以增加數值
            left++;
        } else {
            // 目前和太大，右指標左移以減少數值
            right--;
        }
    }

    // 雖然題目保證有解，但防禦性編程建議回傳 NULL 或處理無解情況
    *returnSize = 0;
    return NULL;
}

// --- 測試主程式 ---
int main() {
    // 測試案例 1
    // numbers = [2, 7, 11, 15], target = 9
    int numbers[] = {2, 7, 11, 15};
    int target = 9;
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    int returnSize;

    printf("輸入陣列: [2, 7, 11, 15], 目標: %d\n", target);

    int* result = twoSum(numbers, numbersSize, target, &returnSize);

    if (result != NULL && returnSize == 2) {
        printf("結果索引(%d): [%d, %d]\n", returnSize, result[0], result[1]);
        // 釋放 twoSum 內部 malloc 的記憶體
        free(result);
    } else {
        printf("未找到解答。\n");
    }

    // 測試案例 2: numbers = [2, 3, 4], target = 6
    int numbers2[] = {2, 3, 4};
    int target2 = 6;
    int numbersSize2 = 3;

    int* result2 = twoSum(numbers2, numbersSize2, target2, &returnSize);
    if (result2) {
        printf("輸入陣列: [2, 3, 4], 目標: 6 -> 結果(%d): [%d, %d]\n", returnSize, result2[0], result2[1]);
        free(result2);
    }

    return 0;
}
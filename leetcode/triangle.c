#include <stdlib.h>
#include <stdio.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;

    // 1. 為「每一行的指標」分配空間
    int** result = (int**)malloc(numRows * sizeof(int*));

    // 2. 為「紀錄每行長度的陣列」分配空間
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        // 第 i 行有 i+1 個數字
        (*returnColumnSizes)[i] = i + 1;
        result[i] = (int*)malloc((i + 1) * sizeof(int));

        // 每一行的頭尾都是 1
        result[i][0] = 1;
        result[i][i] = 1;

        // 計算中間的數字
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }

    return result;
}

// --- 測試主程式：示範如何使用 generate 函式 ---
int main() {
    int numRows = 5;
    int returnSize;          // 用來接收「總共有幾行」
    int* returnColumnSizes;  // 用來接收「每行有多長」的陣列指標

    // 呼叫函式
    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);

    printf("帕斯卡三角形 (numRows = %d):\n", numRows);
    for (int i = 0; i < returnSize; i++) {
        // 根據 returnColumnSizes[i] 知道這一行要印幾個
        for (int j = 0; j < returnColumnSizes[i]; j++) {
			if (j == 0) {
				printf("%*d ", 5 - i, triangle[i][j]);
			} else {
				printf("%d ", triangle[i][j]);
			}
        }
        printf("\n");
    }

    // --- 重要的記憶體釋放步驟 ---
    // 必須先釋放每一行，再釋放指標陣列本身
    for (int i = 0; i < returnSize; i++) {
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes); // 別忘了這個紀錄長度的陣列也要 free

    return 0;
}
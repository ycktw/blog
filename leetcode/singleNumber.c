#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        // 使用 XOR 運算子進行累計
        result ^= nums[i];
		printf("result:%d\n", result);
    }
    return result;
}

int main() {
    int nums[] = {4, 1, 2, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int single = singleNumber(nums, size);

    printf("陣列中落單的數字是: %d\n", single);
    return 0;
}
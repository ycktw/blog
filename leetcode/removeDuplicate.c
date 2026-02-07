#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int slow = 0; // 指向目前最後一個「非重複」的數字

	// 第一個一定是非重複的，從第二個數字開始檢查
    for (int fast = 1; fast < numsSize; fast++) {
        // 如果發現一個跟目前數字不同的新數字
        if (nums[fast] != nums[slow]) {
            slow++;             // 慢指標前進
            nums[slow] = nums[fast]; // 覆蓋掉後面的重複值
        }
    }
	printf("去重後的數字: ");
	for (int i = 0; i <= slow; i++) {
		printf("%d ", nums[i]); // 輸出去重後的數字
	}
	printf("\n");

    // 回傳長度，即索引 + 1
    return slow + 1;
}

int main() {
	int arr[] = {1, 2, 2, 3, 4, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
	removeDuplicates(arr, n);

	printf("原本的空間:");
	for (int i = 0; i <= n; i++) {
		printf("%d ", arr[i]); // 輸出去重後的數字
	}
	printf("\n");
	return 0;
}
#include <stdio.h>

void removeElement(int* nums, int numsSize, int val) {
	int i = 0;
	for (int j = 0; j < numsSize; j++) {
		if (nums[j] != val) {
			nums[i] = nums[j];
			i++;
		}
	}
	printf("After removing %d, the new array is: ", val);
	for (int k = 0; k < i; k++) {
		printf("%d ", nums[k]);
	}
}

int main() {
	int num[] = {3, 2, 2, 3};
	int val = 3;
	removeElement(num, 4, val);
	return 0;
}
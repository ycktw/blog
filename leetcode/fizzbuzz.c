#include <stdio.h>
#include <stdlib.h>

char ** fizzBuzz(int n, int* returnSize) {
    // 1. 分配存放字串指標的空間
    char **result = (char **)malloc(n * sizeof(char *));
    *returnSize = n;

    for (int i = 1; i <= n; i++) {
        // 2. 為每個字串分配空間（FizzBuzz 最長 8 字元 + \0，給 10 足夠）
        result[i-1] = (char *)malloc(10 * sizeof(char));

        if (i % 15 == 0) {
            sprintf(result[i-1], "FizzBuzz");
        } else if (i % 3 == 0) {
            sprintf(result[i-1], "Fizz");
        } else if (i % 5 == 0) {
            sprintf(result[i-1], "Buzz");
        } else {
            sprintf(result[i-1], "%d", i);
        }
    }
    return result;
}

int main() {
	int n = 15;
	int returnSize;
	char **result = fizzBuzz(n, &returnSize);

	for (int i = 0; i < returnSize; i++) {
		printf("%s\n", result[i]);
		free(result[i]); // 釋放每個字串的空間
	}
	free(result); // 釋放存放字串指標的空間

	return 0;
}


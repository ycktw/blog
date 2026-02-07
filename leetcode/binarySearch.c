#include <stdio.h>
#include <stdlib.h>

// Counting the combination of binary tree
long long numTrees(int n) {
    if (n <= 1) return 1;

    // dp[i] means the number of different binary trees that can be formed with i nodes
    long long *dp = (long long *)calloc(n + 1, sizeof(long long));
    dp[0] = 1; // empty tree
    dp[1] = 1; // single node tree

    // when i is given to 2, we start from 2
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // dp[j] means the number of left tree, dp[i-j-1] the number of right tree, and excluding the root node
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    long long result = dp[n];
    free(dp);
    return result;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <number_of_nodes>\n", argv[0]);
		exit(1);
	}
    int n = atoi(argv[1]);
		if (n < 0) {
			printf("Usage: %s <number_of_nodes>\n", argv[0]);
			exit(1);
		}
    printf("the number of node %d: %lld\n", n, numTrees(n));
    return 0;
}
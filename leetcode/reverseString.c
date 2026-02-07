#include <stdio.h>
#include <ctype.h>

int reverseString(char *str) {
	if (str == NULL) {
		return -1;
	}
	char *start = str;
	char *end = str;
	while (*end != '\0') {
		end++;
	}
	end--; // Move back to the last character
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return 0;
}

int main() {
  char testTarget[] = "    test 1234  hellow ";
  printf("Before: '%s'\n", testTarget);
  reverseString(testTarget);
  printf("After: '%s'\n", testTarget);
  return 0;
}

// vim set fdm=marker ts=2 ai et sts=2 sw=2 tw=0 noexpandtab
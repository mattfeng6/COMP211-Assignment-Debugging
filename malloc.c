// output: "111 + 229 = (null)

// function returning the local variable

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sumString(char* intStr1, char* intStr2);

int main() {
	char* res = sumString("111", "229");
	printf("111 + 229 = %s", res);
	// free(res);
}

char* sumString(char* intStr1, char* intStr2) {
	int size = strlen(intStr1);
	char* res[size];
	//char* res = (char*) malloc(size);
	int carry = 0;
	for (int i = size - 1; i >= 0; i --) {
		int curSum = intStr1[i] + intStr2[i] - '0' - '0' + carry;
		if (curSum >= 10) {
			carry = 1;
			curSum -= 10;
		}
		res[i] = '0' + curSum;
	}
	return res;
}
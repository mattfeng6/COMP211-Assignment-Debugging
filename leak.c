// memory leak

// function returning the value 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sumString(char* intStr1, char* intStr2);

int main() {
	int times = 9999;
	while (times != 0) {
		char* res = sumString("111999", "229999");
		// free(res);
		times -= 1;
	}
}

char* sumString(char* intStr1, char* intStr2) {
	int size = strlen(intStr1);
	char* res = (char*) malloc(size*9999999);
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
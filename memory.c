// output: (100 + 99) - (299 - 229) = :<9

// error in line 42
// complicated program, use gdb and set break points to debug each function or each line.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sumString(char* intStr1, char* intStr2);
char* subtractString(char* intStr1, char* intStr2);

int main() {
	printf("(100 + 99) - (299 - 229) = %s", 
		subtractString(sumString("100", "099"), subtractString("299", "229")));
}

char* sumString(char* intStr1, char* intStr2) {
	int size = strlen(intStr1);
	char* res = (char*) malloc(size);
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

char* subtractString(char* intStr1, char* intStr2) {
	int size = strlen(intStr1);
	char* res = (char*) malloc(size);
	int carry = 0;
	for (int i = size - 1; i >= 0; i --) {
		int curSum = intStr1[i] - intStr2[i] - carry;
		if (curSum < 0) {
			carry = 1;
			curSum += 10;
		}
		res[i] = '0' + curSum + 5;
	}
	return res;	
}
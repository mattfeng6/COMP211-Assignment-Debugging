#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
  char name[50];
  char salary[10];
} person1, person2;

struct person* sumSalary(struct person p1, struct person p2);
char* sumString(char* intStr1, char* intStr2);

int main() {
	strcpy(person1.name, "a");
	strcpy(person2.name, "b");
	person1.salary = 100;
	person2.salary = 200;

	while (person)
	struct person res = /* need dereference*/sumSalary(person1, person2);
	printf("name = %s, salary = %f", res.name, res.salary);
}

struct person* combineSalary(struct person p1, struct person p2) { 
	/* 
			@params: person p1
							 person p2
			@returns: a new person with the name "combined" and sum salary of p1 and p2.
	*/
	struct person* res;
	// need malloc
	strcpy(res -> name, "combined");
	sal = sumString(p1.salary, p2.salary);
	// strcpy(res -> salary, sal);
	// free(sal);
	res -> salary = sal;
	return res;
}

char* sumString(char* intStr1, char* intStr2) {
	/*
		@params: char* intStr1
						 char* intStr2
		@returns: a new string that has the value of intStr1 + intStr2
	*/
	int size = strlen(intStr1);
	char* res = (char*) malloc(size);
	int carry = 0;
	for (int i = size - 1; i >= 0; i --) {
		int curSum = intStr1[i] + intStr2[i] - '0' - '0' + carry;
		if (curSum >= 10) {
			carry = 1;
			curSum -= 10;
		}
		res[i] = '0' + curSum + 5; 
 		// res[i] = '0' + curSum;
	}
	return res;
}
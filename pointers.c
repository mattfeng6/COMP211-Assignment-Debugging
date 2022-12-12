/* pointers.c:22:43: error: invalid initializer
  struct person res = sumSalary(person1, person2);
*/

// pointers are memory addresses, dereference to get values

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
  char name[50];
  float salary;
} person1, person2;

struct person* sumSalary(struct person p1, struct person p2);

int main() {
	strcpy(person1.name, "a");
	strcpy(person2.name, "b");
	person1.salary = 100;
	person2.salary = 200;

	struct person res = /* need dereference*/sumSalary(person1, person2);
	printf("name = %s, salary = %f", res.name, res.salary);
	free(res);
}

struct person* sumSalary(struct person p1, struct person p2) {
	struct person* res = malloc(sizeof(struct person));
	strcpy(res -> name, "combined");
	res -> salary = p1.salary + p2.salary;
	return res;
}
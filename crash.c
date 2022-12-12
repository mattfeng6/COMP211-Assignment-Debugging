#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *p;

void concatenate(char* str) {
  // concatenate contents of str to contents of p
  strcat(p, str);
}

int main() {
  char a[6] = "hello ";
  char b[10] = "world...\n";
  concatenate(a);
  concatenate(b);
  printf("%s", p);
  return 0;
}
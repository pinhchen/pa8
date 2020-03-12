#include <stdlib.h>
#include <stdio.h>

void insert(int*, int, int, int);

int main() {
  int size = 8;
  int* elts = calloc(size, sizeof(int));
  int i;
  for(i = 0; i < size; i += 1) {
    elts[i] = i * 10;
  }
  insert(elts, size, 2, 37);
  int j;
  for(j = 0; j < size; j += 1) {
    printf("%d ", elts[j]);
  }
  printf("\n");

  free(elts);

  return 0;
}

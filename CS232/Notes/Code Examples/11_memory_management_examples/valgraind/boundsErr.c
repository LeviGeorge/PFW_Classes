#include <stdlib.h>

int main(){
  int n = 5;
  int *arr = malloc(sizeof(int) * n);

  arr[n] = 6;

  free(arr);

  return 0;
}

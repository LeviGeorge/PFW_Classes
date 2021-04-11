#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if (argc != 4) {
    printf("USAGE: %s nRows nCols rowMajor\n", argv[0]);
    return -1;
  }
  
  const int nRows = atoi(argv[1]);
  const int nCols = atoi(argv[2]);
  const int rowMajor = atoi(argv[3]);

  double *data = malloc(sizeof(double) * nRows * nCols);

  int r, c;

  if(rowMajor){
    for(r=0; r<nRows; r++){
      for(c=0; c<nCols; c++){
	      data[r * nCols + c] = r;
      }
    }
  }
  else{
    for(c=0; c<nCols; c++){
      for(r=0; r<nRows; r++){
	      data[r * nCols + c] = c;
      }
    }
  }

  for (r=0; r<nRows; r++){
    for (c=0; c<nCols; c++){
      printf("%f\t", data[r * nCols + c]);
    }
    printf("\n");
  }

  free(data);

  return 0;
}

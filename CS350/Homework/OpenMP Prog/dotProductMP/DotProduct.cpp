#include <iostream>
#include <omp.h>

// Define length of dot product vectors and number of OpenMP threads
#define VECLEN 100
#define NUMTHREADS 6

int main(int argc, char* argv[])
{
	int i, tid, len = VECLEN, threads = NUMTHREADS;
	double* a, * b;
	double sum, psum;

	printf("Starting omp_dotprod_openmp. Using %d threads\n", threads);

	// Assign storage for dot product vectors 
	a = (double*)malloc(len * threads * sizeof(double));
	b = (double*)malloc(len * threads * sizeof(double));

	// Initialize dot product vectors 
	for (i = 0; i < len * threads; i++) {
		a[i] = 2.0;
		b[i] = 1.0;
	}
	// Initialize global sum 
	sum = 0.0;

	//
	//   Perform the dot product in an OpenMP parallel region for loop with a sum reduction
	//   For illustration purposes:
	//     - Explicitly sets number of threads
	 //   - Each thread keeps track of its partial sum
	//

#pragma omp parallel private(i,tid,psum) num_threads(threads) 
	{
		psum = 0.0;
		tid = omp_get_thread_num();

#pragma omp for
		for (i = 0; i < len * threads; i++)
		{
			psum += (a[i] * b[i]);
		}
		printf("Thread %d partial sum = %f\n", tid, psum);

#pragma omp critical 
		sum += psum;
	}

	printf("Done! the final value for sum  =  %f \n", sum);

	free(a);
	free(b);
}

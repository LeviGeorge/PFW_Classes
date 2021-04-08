#include <iostream>
#include <omp.h>


 // OpenMP first Program
 // A Simple Hello World
 // N computing threads printing "Hello World" Message
 //

int main(int argc, char* argv[])
{
	int nthreads = 4;

	// set number of threads to 4
	omp_set_num_threads(nthreads);

	// start the fork
#pragma omp parallel
	{// parallel region started
		int id; //private to each thread
		//Obtain thread number
		id = omp_get_thread_num();
		printf("Hello World from thread %d\n", id);
	}// parallel region ended.

	//all threads joined the master thread now.

	
}
#include <omp.h>
#include <stdio.h>
#include <time.h>
 
 // threads
int main() {
	//time
	clock_t start = clock();
	clock_t diff;

	int num_steps = 100000;
	double step = 1.0 / num_steps;
	double area;
	
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int nthreads = omp_get_num_threads();
		printf("we have %d threads\n", nthreads);
		double sum = 0.0;

		int i;
		for (i = id; i < num_steps; i += nthreads){
			double x = (i + .5) * step;
			double y = 4/ (1 + (x * x));
			sum += y;
		}
		#pragma omp critical
		{
			area += sum * step;
		}
	}
	printf("%lf\n", area);
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken: %d seconds %d milliseconds", msec/1000, msec%1000);
}

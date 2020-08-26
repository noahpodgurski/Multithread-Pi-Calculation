#include <omp.h>
#include <time.h>
#include <stdio.h>

 // sequential
int main() {
	//time
	clock_t start = clock();
	clock_t diff;

	int num_steps = 100000;
	double step = 1.0 / num_steps;
	double sum = 0.0;
	double area;

	int i;
	for (i = 0; i < num_steps; i++){
		double x = (i + .5) * step;
		double y = 4/ (1 + (x * x));
		sum += y;
	}  
	area = sum * step;
	
	printf("%lf\n", area);
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken: %d seconds %d milliseconds", msec/1000, msec%1000);
}

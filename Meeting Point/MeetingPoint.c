#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ABS(x) (x > 0 ? x : -(x))
#define MAX(x, y) (x > y ? x : y)

int main(void) {
	long int *a, *b ;
	int T;
	long double ave1 = 0, ave2 = 0;
	long double min, X=0,Y=0;
	unsigned int index = 0;
	unsigned long long int total=0, M=0,N = 0;
	
	scanf("%d", &T);
	
	a = malloc(sizeof(long long int) * T);
	b = malloc(sizeof(long long int) * T);
	
	for (int i=0; i<T; i++) {
		scanf("%ld %ld", &(a[i]), &(b[i]));
	}
	
	for (int i=0; i<T; i++) {
		ave1 += (long double) a[i] / T;
		ave2 += (long double) b[i] / T;
	}
	
	X= ((ave1-a[0])*(ave1-a[0]));
	Y=((ave2-b[0])*(ave2-b[0]));
	min = sqrt(X + Y);
	
	for (int i=1; i<T; i++) {
		double X1,Y1;
		X1 = ((ave1-a[i])*(ave1-a[i]));
		Y1 = ((ave2-b[i])*(ave2-b[i]));
		double diff = sqrt(X1 + Y1);
		if (diff < min) {
			min = diff;
			index = i;
		}
	}
	
	for (int i=0; i<T; i++) {
	
		M = (ABS(a[index]-a[i]));
		N = (ABS(b[index]-b[i]));
		total += MAX(M,N);
	}

	printf("%llu\n", total);
	
	return 0;
}
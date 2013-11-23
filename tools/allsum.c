#include <stdio.h>
#include <stdlib.h>
#define MAX_DATA 501

int main() {
	int i;
	double *a;
	double ans = 0;	

	a =(double *) malloc(sizeof(double) * MAX_DATA);
	for(i = 0; i < MAX_DATA; i++) scanf("%lf", &a[i]);

	printf("first time:%6f\n", a[0]);
	printf("second time:%6f\n", a[1]);

	for(i = 1; i < MAX_DATA; i++) ans += a[i];
	printf("total time:%6f\n", ans+a[0]);
	printf("average time:%6f\n", ans/(MAX_DATA-1));

	free(a);
	return 0;
}

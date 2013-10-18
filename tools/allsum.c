#include <stdio.h>
#include <stdlib.h>
#define MAX_DATA 501

int main() {
	int i;
	double *a;
	double ans = 0;	

	a =(double *) malloc(sizeof(double) * MAX_DATA);
	for(i = 0; i < MAX_DATA; i++) scanf("%lf", &a[i]);

	for(i = 0; i < MAX_DATA; i++) ans += a[i];

	printf("%6f\n", ans);

	free(a);
	return 0;
}

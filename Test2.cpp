# include<stdio.h>
#include <math.h>

int main(){
	int a = 111111*111111;
	printf("%d\n", a);
	int b = sqrt(-10);
	printf("%d\n",b);
	double c= 111111.0*111111.0;
	printf("%.1lf\n", c);
	float d = 1.0/0.0;
	printf("%f\n", d);
	int e = 1/0;
	printf("%d\n", e);	
}

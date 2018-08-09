# include <stdin.h>

int main(){
	int a, b, c, m;
	scanf("%d%d%d", &a, &b, &c);
	m = 70*a+21*b+15*c;
	if(m>105)
		m-=105;
	printf("%d\n", m);
	return 0;
}

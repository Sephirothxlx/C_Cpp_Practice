#include <stdio.h>
#define maxn 24;

int main(){
	int n, k, m;
	int a,b;
	scanf("%d%d%d", &n,&k,&m);
	int h[n];
	for(int i=0;i<n;i++){
		h[i]=i+1;
	} 
	int left=n;
	int c1=0,c2=0 ;
	while(left>0){
		for(int i=0;i<n;i%=n){
			if(h[i]!=0){
				c1++;
				if(c1==k){
					a=i;
					c1=0;
					break;	
				}
			}
			i++;
		}
		for(int i=n-1;i>-1;i--){
			if(h[i]!=0){
				c2++;
				if(c2==m){
					b=i;
					c2=0;
					break;
				}
			}
			if(i==0)
				i=n;
		}
		if(a==b)
			left--;
		else
			left-=2;
		printf("%d %d\n",a,b);
		//printf("%d %d\n",h[a],h[b]);
		h[a]=h[b]=0;
	}
	return 0;
}

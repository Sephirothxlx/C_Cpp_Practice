#include <stdio.h>
#define maxn 100005;
int ans[amxn];

int main(){
	memset(ans,0,sizeof(ans));
	for(int i=0;i<100000){
		int temp,t=i;
		temp=t;
		while(t){
			temp+=t%10;
			t/=i;
		}
		ans[temp]=i;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#define maxn 100

int left, chance;
char s[maxn],s2[maxn];
int win, lose;
void guess(char ch);

void guess(char ch){
	int tag=1;
	for(int i=0; i<strlen(s);i++){
		if(ch == s[i]){
			left--;
			s[i]=' ';
			tag=0;
		}
	}
	if(tag==1){
		chance--;
	}
	if(left==0)
		win=1;
	if(chance==0)
		lose=1;
} 

int main(){
	int round;
	while(scanf("%d%s%s",&round, s, s2)==3&&round!=-1){
		printf("Round %d\n", round);
		win=lose=0;
		left=strlen(s);
		chance=7;
		for(int i=0;i<strlen(s2); i++){
			guess(s2[i]);
			if(win||lose)
				break;
		}
		if(win==1)
			printf("win%%s");
		else
			printf("lose");
	}
}

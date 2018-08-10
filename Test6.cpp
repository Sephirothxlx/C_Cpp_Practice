# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main(){
	char a[12];
	sprintf(a, "%d%d", 4,3);
	char* s=strchr(a, a[strlen(a)-1]);
	printf("%c\n", s);
	
	char *b="dsdsd";
	char c[20]= "ssdg";
	strcat(c,b);
	printf("%s\n",c); 
	char h[200];
	strcpy(h,c);
	printf("%s\n",h);
	
	int q=1;
	int p=!q;
	printf("%d\n",p);
	
	char f= toupper('w');
	printf("%c",f);
} 

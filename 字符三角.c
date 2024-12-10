#include<stdio.h>
#include<string.h>
int main(void){
	char s[51];
	fgets(s,50,stdin);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		for(char *sp=s+i;sp<s+n;sp++){
			printf("%c",*sp);
		}
	}
}

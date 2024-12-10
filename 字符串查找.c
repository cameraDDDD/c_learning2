#include<string.h>
#include<stdio.h>
int main(void){
	char s[1000],t[200],* sp=s;
	int count=0;
	fgets(s,1000,stdin);
	fgets(t,200,stdin);
	int a=strlen(s);
	int b=strlen(t);
	t[b-1]='\0';
	b--;
	
	for(int i=0;i<=a-b+1;i++,sp++){
		if(strncmp(sp,t,b)==0){
			printf("%d",i);
		}
	}


}
	


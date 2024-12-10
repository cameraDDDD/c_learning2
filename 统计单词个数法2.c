/*好像有问题*/
#include<stdio.h>
#include<string.h>
int countwords(char s[100]){
	int count=0;
	char gar[50];
	while(sscanf(s,"%s",gar)==1){
		count++;
	}
	return count;
}
int main(void){
	char n[101];
	int count;
	fgets(n,100,stdin);
	count=countwords(n);
	printf("%d",count);
}

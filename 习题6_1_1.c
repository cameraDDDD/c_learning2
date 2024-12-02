#include<stdio.h>
int main(void){
	int i=1;
	while(i<=15)
		if(++i%3!=2) continue;
		else printf("%d     ",i);
	printf("\n");
	return 0;
}

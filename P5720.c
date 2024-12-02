#include<stdio.h>
int main(void){
	int a,day=1;
	scanf("%d",&a);
	while(a!=1)
	{
		a/=2;
		day++;
	}
	printf("%d",day);
	return 0;
}

#include<stdio.h>
int fuck(int n[]);
int main(void){
	int a[3]={0};
	fuck(a);
	printf("%d",a[0]);
}
int fuck(int n[]){
	n[0]=1;
}

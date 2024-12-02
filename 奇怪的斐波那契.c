//´íµÄ,ËÀÑ­»·ÁË 
#include<stdio.h>
long long Fibonacci(long long n){
	if(n==1||n==2){
		return 1;
	}
	else if(n==20){
		return 6765;
	}
	else return Fibonacci(n+1)-Fibonacci(n-1);
}
int main(void){
	printf("%lld",Fibonacci(10));
}

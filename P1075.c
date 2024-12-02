#include<stdio.h>



int main(void){
	int n;
	scanf("%d",&n);
	for(int i=2;;i++){
		if(n%i==0){
			
				printf("%d",i);
				return 0;
			}
			
		}
	
}

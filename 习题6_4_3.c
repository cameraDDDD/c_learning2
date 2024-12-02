//Ï°Ìâ6.4.2 
#include<stdio.h>
int main(void){
	int x=0,xl=0,xxl=0;
	int n=100,money=100;
	for(x=99;x!=0;x-=3){
		for(xl=n-x;xl>=0;xl--){
			xxl=n-x-xl;
				if(xxl*3+xl*2+x/3==100)
					printf("¹«¼¦:%d\tÄ¸¼¦:%d\tÐ¡¼¦:%d\n",xxl,xl,x); 
			
		}
	}
}

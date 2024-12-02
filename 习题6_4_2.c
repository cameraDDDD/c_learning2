#include<stdio.h>
int main(void){
	int a, b, c, n, l=0;
	scanf("%d",&n);
	for(a=1;a<10;a++){
		for(b=0;b<10;b++){
			for(c=1;c<10;c++){
				if(a*101+b*20+c*101==n){l=1;
					printf("a=%d,b=%d,c=%d\n",a,b,c);
				}
				
			}
		}
	}
	if(l==0)
		printf("无对应的a,b,c");
}

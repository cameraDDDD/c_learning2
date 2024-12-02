#include<stdio.h>
void fuk(int k,int* list){
	for(;k>0;k/=10){
		list[k%10]++;
	}

}

//6.4.4
int main(void){
	int a, b, c,k,n[10]={0};int x;int i;

	for(a=100;a<1000;a++){
		for(b=100;b<1000;b++){
		
			for(c=100;c<1000;c++){	
				for(x=0;x<10;x++){
					n[x]=0;
				}
				fuk(a,n);
				fuk(b,n);
				fuk(c,n);
				k=1;
				
				for(i=1;i<10;i++){
					if(n[i]!=1)
						k=0;
						
				}
				if(k==1&&2*a==b&&3*a==c)
					printf("\t%d\t%d\t%d",a,b,c);
			
			}
		}
	}
	
}

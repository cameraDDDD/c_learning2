#include<stdio.h>
int main(void){
	int n,N;
	scanf("%d",&n);
	N=n;
	int python[N][N],length=1,if_change=1;
	int *p=&python[0][0];
	enum State{
		R,D,L,U
	};
	enum State now=R;
	for(int i=1;i<=N*N;i++){
		*p=i;
		if(length==n){
			now=(now+1)%4;
			if(if_change==1){
				if_change=0;
				n-=1;
			}else{
				if_change=1;
			}
			length=0;
			
		}
		
		if(now==R){
			p+=1;
			length++;
			continue;
		}
		if(now==D){
			p+=N;
			length++;
			continue;
		}
		if(now==L){
			p-=1;
			length++;
			continue;
		}
		if(now==U){
			p-=N;
			length++;
			continue;
		}
		
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%03d",python[i][j]);
			if(j<N-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
}

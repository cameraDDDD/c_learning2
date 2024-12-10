#include<stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	int python[n][n];
	int *p=&python[0][0];
	for(int i=1;i<=n*n;i++){
		*p=i;
		if(i%n==0&&i!=0){
			p+=n;
		}
		else if((i/n)%2){
			
			p--;
		}
		else{
			
			p++;
		}
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%03d",python[i][j]);
			if(j<n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
}


#include<stdio.h>
int main(void){
	int n,sum=0;
	scanf("%d",&n);
	int l[n];
	for(int i=0;i<n;i++){
		scanf("%d",&l[i]);
	}
	for(int i=0;i<n;i++){sum++;
		for(int k=i+1;k<n;k++){
			if(l[i]<=l[k])
				{
				sum--;
				break;}
			
		}
	
	
	}

printf("%d",sum);
return 0;

}

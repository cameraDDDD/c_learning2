#include<stdio.h>
#include<math.h>
void sort(int group[],int n){
	for(int i=1;i<n;i++){
		int base=group[i],j=i-1;
		for(;group[j]>base&&j>=0;j--){
			group[j+1]=group[j];
		}
		group[j+1]=base;
		
	}	
}
int main(void){
	int a,b,n;
	int j=0;
	scanf("%d",&n);
	int group[n-1];
	scanf("%d",&b);
	while(scanf("%d",&a)==1){
		
		group[j]=abs(a-b);
		j++;
		b=a;
	}
	sort(group,n-1);
	for(int i=0;i<n-1;i++)
		if(group[i]!=i+1){
			printf("Not jolly");
			return 0;
		}
	printf("Jolly");
	return 0;
		
	
}

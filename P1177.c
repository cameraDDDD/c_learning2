#include<stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	int nums[n];
	for(int i=0;i<n;i++){
		scanf("%d",nums+i);
	}
	for(int i=1;i<n;i++){
		int base=nums[i],j=i-1;
		while(j>=0&&nums[j]>base){
			nums[j+1]=nums[j];
			j--;
		}
		nums[j+1]=base;
	}
	for(int i=0;i<n;i++){
		printf("%d ",nums[i]);
	}
	
}

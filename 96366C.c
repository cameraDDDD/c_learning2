#include<stdio.h>
int main(void){
	int n,max,now,sum=0;
	scanf("%d",&n);
	int nums[n];
	for(int i=0;i<n;i++){
		scanf("%d",nums+i);
	}
	max=(nums[0]>nums[1])?nums[0]:nums[1];
	sum+=max;
	for(int i=1;i<n;i++){
		if(nums[i]>max){
			max=nums[i];
		}
		sum+=max;
	}
	printf("%d",sum);
	
}

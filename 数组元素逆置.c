//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
void swag(int *nums,int n){
	for(int i=0;i<n/2;i++){
		int v;
		v=nums[i];
		nums[i]=nums[n-i-1];
		nums[n-i-1]=v;
	}
	
}
int main(void){
	int nums[10];
	for(int i=0;i<10;i++){
		scanf("%d",nums+i);
		
	}
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",*nums,*(nums+1),*(nums+2),*(nums+3),*(nums+4),*(nums+5),*(nums+6),*(nums+7),*(nums+8),*(nums+9));
	swag(nums,10);
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",*nums,*(nums+1),*(nums+2),*(nums+3),*(nums+4),*(nums+5),*(nums+6),*(nums+7),*(nums+8),*(nums+9));
	
}






































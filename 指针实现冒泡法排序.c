//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
void swap(int *x,int *y){
	*x^=*y^=*x^=*y;
}
void sort(int *nums,int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(nums[j]>nums[j+1])
				swap(&nums[j],&nums[j+1]);
		}
	}
}
int main(void){
	int n,nums[n];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",nums+i);
	}
	sort(nums,n);
	for(int i=0;i<n;i++){
		printf("%d ",nums[i]);
	}
	
}



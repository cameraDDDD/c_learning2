//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
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
	int n,x;
	scanf("%d",&n);
	int a[n];
	int *nums=a;
	for(int i=0;i<n;i++){
		scanf("%d",nums++);
	}
	sort(a,n);
	scanf("%d",&x);
	for(int i=0;i<n;i++){
		if(x<a[i]){
			if(i==0){
				x=a[i];
				break;
			}else{
				x=((a[i]-x)>=(x-a[i-1]))?a[i-1]:a[i];
				break;
			}
			
		}
		if(i==n-1){
			x=a[i];
		}
		
	}
	printf("%d",x);
	
	
}







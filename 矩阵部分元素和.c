//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
int main(void)
{
	int n,up=0,down=0;
	scanf("%d",&n);
	int sq[n][n];
	int * p=sq[0];
	for(int i=0;i<n*n;i++)
		scanf("%d",p+i);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			up+=sq[i][j];
			
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i;j>=0;j--){
			down+=sq[i][j];
		}
	}
	printf("%d %d",up,down);
}



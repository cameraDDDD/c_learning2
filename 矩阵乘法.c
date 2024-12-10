//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
int main(void){
	int m,n,p;
	scanf("%d%d%d",&m,&n,&p);
	int a[m][n],b[n][p],c[m][p];
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			c[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<p;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			for(int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			printf("%d",c[i][j]);
			if(j<p-1)
				printf(" ");
		}
		putchar('\n');
	}
	
	
	
}

#include<stdio.h>
int main(void){
	int m,n;
	scanf("%d%d",&m,&n);
	int nums[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&nums[i][j]);
		}
	}
	//转置
	int b[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[i][j]=nums[j][i];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",b[i][j]);
		}
		printf('\b');
		putchar('\n');
	}
}

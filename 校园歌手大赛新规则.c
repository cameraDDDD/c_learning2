//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
int main(void){
	int points[20],no[20],n=0,sum=0;
	double mean;
	
	for(int i=0;i<20;i++){
		scanf("%d",points+i);
	}
	for(int i=0;i<20;i++){
		sum+=points[i];
		}
	mean=(double)sum/20;
	printf("所有评委平均分:%.3lf\n",mean);
	for(int i=0;i<20;i++){
		double d=points[i]-mean;
		if((d+10)*(10-d)<0){
			sum-=points[i];
			no[n]=points[i];
			n++;
		}
	}
		
		
		
		printf("不合格得分:");
		for(int i=0;i<n;i++){
			printf("%d ",no[i]);
		}
		printf(".\n");
		
		printf("最后得分:%.3lf分.",(double)sum/(20-n));
		return 0;
	}
	


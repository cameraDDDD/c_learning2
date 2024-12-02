#include<stdio.h>
#define N 20
int fun2(float x);
int main(void){
	int sum=0,a;
	for(int i=0;i<N;i++){
		scanf("%d",&a);
		if(fun2(a))
		sum+=a;
		else{i--;continue;}
	}
printf("平均成绩为%.2llf",(double)sum/N);
}
int fun2(float x){
	int t;
	if (x>=0&&x<=100)t=1;
	else t=0;
	return t;
}

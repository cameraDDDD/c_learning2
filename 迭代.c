#include<stdio.h>
#include<math.h>

//定义main函数
int main()
{
	//请在此添加您的代码
	/*****************Begin******************/
    double x0,x1=0.0;
    step2:
    x0=x1;
    x1=cos(x0);
    if(fabs(x0-x1))
        printf("root=%.6lf",x0);
    else
        goto step2;
    








    
	/***************** End ******************/
	return 0;
}

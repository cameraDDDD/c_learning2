#include <stdio.h>
#include <math.h>
#define PI acos(-1)//就是3.1415926差不多
#define eps 1e-7//代表0.0000001
#define EE exp(1.0)
double f(double);
int main()
{
	double y;
	scanf("%lf", &y);
	double l = 0.33, r = 10, mid;
	while (l < r) //判断区间是否可以继续二分
	{
		mid = (l + r) / 2; //取区间的中点
		if (fabs(f(mid) - y) < eps) //若已经满足精度要求，则mid即为方程的解
			break;
		if (f(mid) < y + eps)
			r = mid;
		else
			l = mid;
	}
	printf("%.5f\n", mid);
	return 0;
}
double f(double x)
{
	/**********Begin**********/
    double y = (sin(sqrt(x))+pow(EE,-(pow(x,1/3))))/log(PI*x);
    return y;
    
	
    
   
   /**********End**********/
}

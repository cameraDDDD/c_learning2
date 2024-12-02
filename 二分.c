#include <stdio.h>
#include <math.h>
#define PI acos(-1)//����3.1415926���
#define eps 1e-7//����0.0000001
#define EE exp(1.0)
double f(double);
int main()
{
	double y;
	scanf("%lf", &y);
	double l = 0.33, r = 10, mid;
	while (l < r) //�ж������Ƿ���Լ�������
	{
		mid = (l + r) / 2; //ȡ������е�
		if (fabs(f(mid) - y) < eps) //���Ѿ����㾫��Ҫ����mid��Ϊ���̵Ľ�
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

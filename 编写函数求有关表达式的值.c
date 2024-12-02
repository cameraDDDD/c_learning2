#include<stdio.h>
//编写题目要求的函数
/*********Begin*********/
double f2(int n){
    double sum=1;
    for(int i=1;i<=n;i++){
        sum*=2*i+1;
    }
    return sum;
}
double f1(int n){
    double sum=1;
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    return sum;
}
double fuk(int n){
    double result=1,up,down;
    for(int i=1;i<=n;i++){
        result+=f1(i)/f2(i);
    }
    return result;
}
/*********End**********/ 
int main(void)
{  
    /*********Begin*********/
    int n;
    scanf("%d",&n);
    printf("%.10lf",fuk(n));
    /*********End**********/ 
    return 0;
}

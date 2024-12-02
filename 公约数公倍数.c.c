#include<stdio.h>
//编写最大公约数GCD函数
/*********Begin*********/
long long int GCD(long long int a, long long int b) {  
    while (b != 0) {  
        long long int temp = b;  
        b = a % b;  
        a = temp;  
    }  
    return a;    
}  
/*********End**********/ 
 

//编写最小公倍数LCM函数
/*********Begin*********/
long long int LCM(long long int a, long long int b) {  
    return (a / GCD(a, b)) * b;  
} 
/*********End**********/ 
int main(void)
{  
    /*********Begin*********/
    long long int x, y;
    scanf("%lld %lld",&x,&y);
    if(x<0||y<0) {printf("Input Error");return 0;}
    printf("%lld %lld",GCD(x,y),LCM(x,y));
    /*********End**********/ 
    return 0;
}

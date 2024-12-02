//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
int main(void){
    int n;
    char c;
    while(scanf("%d %c",&n,&c)==2){
        for(int i=1;i<=n;i++){
            for(int k=i*2;k-1>0;k--){
                putchar(c);
            }
            putchar('\n');
        }
        for(int i=n-1;i>0;i--){
            for(int k=i*2;k-1>0;k--){
                putchar(c);
            }
            putchar('\n');
        }
    
    
    }
return 0;}

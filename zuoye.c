//���ڴ�������Ĵ��룬���ӳ��������Dev C++�����е��Ժ����ύ
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

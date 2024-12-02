#include<stdio.h>
int main(void){
    char a;
    char g[100];
    int i;
    gets(g);
    for(i=0;g[i]!='\0';i++) ;
	i--;//统计string长度
    while(g[i]==0) i--;//剔除0
    for(;i>=0;i--){
        printf("%c",g[i]);
    }

    
}

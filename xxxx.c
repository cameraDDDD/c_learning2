#include<stdio.h>
int main(void){
    char a;
    char g[100];
    int i;
    gets(g);
    for(i=0;g[i]!='\0';i++) ;
	i--;//ͳ��string����
    while(g[i]==0) i--;//�޳�0
    for(;i>=0;i--){
        printf("%c",g[i]);
    }

    
}

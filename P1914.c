#include<stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	char ch;
	getchar();//读取换行符
	while((ch=getchar())!=EOF){
		ch=ch-'a';
		ch+=n;
		ch=ch%26+'a';
	
		putchar(ch);
	}
}

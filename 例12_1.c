#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(void){
	FILE * fp;
	char ch;
	system("chcp 65001 & cls");//设置控制台中文编码为UTF-8
//	char s[100];
	setlocale(LC_ALL,"en_US.UTF-8");
	if((fp=fopen("README.txt","a+"))==NULL){
		printf("无法创建文件!");
		exit(3);
	}
	while((ch=fgetc(fp))!=EOF){
		putchar(ch);
	}
	
	fclose(fp);
	getchar();
	return 0;
}

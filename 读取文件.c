#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(void){
	FILE * fp;
	char ch;
	system("chcp 65001 & cls");//设置控制台中文编码为UTF-8
	if((fp=fopen(".c","r"))==NULL){
		printf("读取文件错误!");
		exit(3);
	}
	while((ch=fgetc(fp))!=EOF){
		putchar(ch);
	}
	fclose(fp);
	return 0;
}

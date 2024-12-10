//#include<stdio.h>
//int main(void){
//	char ch;
//	int count=0;
//	int flag=1;
//	while((ch=getchar())!=EOF){
//
//		if(ch!=' '&&flag==1){
//			count++;
//			flag=0;
//			continue;
//		}
//		if(ch==' '&&flag==0){
//			flag=1;
//			continue;
//		}
//	}
//	printf("%d",count);
//}
//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
#include<string.h>
int countwords(char s[100]){
	int count=0;
	int flag=1;
	int n=strlen(s);
	char ch;
	for(int i=0;i<n&&ch!='\n';i++){
		ch=s[i];
	
			
			if(ch!=' '&&flag==1){
				count++;
				flag=0;
				continue;
			}
			if(ch==' '&&flag==0){
				flag=1;
				continue;
			
		}
	}
	return count;
}
int main(void){
	char n[101];
	int count;
	fgets(n,100,stdin);
	count=countwords(n);
	printf("%d",count);
}



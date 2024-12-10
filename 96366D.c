#include<stdio.h>
#include<string.h>
#define L "ljl"
void shiftString(char *str, int shift) {
	int len = strlen(str);
	for (int i = len ; i >= 0; i--) {
		str[i + shift] = str[i];
	}

}
int main(void){
	int line;
	scanf("%d",&line);
	getchar();
	for(;line>0;line--){
		char s[1000]={0};
		gets(s);
		char * sp=s;
		for(int i=0;i<997&&s[i]!='\0';i++){
			if(strncmp(sp+i,L,3)==0){
				shiftString(sp+i,2);
				sp[i]='n';
				sp[i+1]='c';
				sp[i+4]='r';
				i+=5;
				
			}
			
		}
		puts(s);
		
	}
	
}

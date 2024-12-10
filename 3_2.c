#include<stdio.h>
#include<string.h>
void escape(char * s,char * t){
	int tl=strlen(t);
	for(int i=0;i<tl;i++){
		switch(t[i]){
		case '\a':strcat(s,"\\a");break;
		case '\b':strcat(s,"\\b");break;	
		case '\f':strcat(s,"\\f");break;	
		case '\n':strcat(s,"\\n");break;
			
			
			
		case '\r':strcat(s,"\\r");break;
		case '\t':strcat(s,"\\t");break;
		case '\v':strcat(s,"\\v");break;
		default: strncat(s,&t[i],1);//妙啊啊啊
		}
			
	}		
	
}
int main(void){
	char s[100]={'\0'};
	char b[30]={"Hea\vaaa\ral\tlo\nwor\bld"};
	puts(b);//真是让人摸不着头脑
	
	
	escape(s,b);
	fputs(s,stdout);
	
}

#include<stdio.h>
int main(void){
	char s1[]="computing",s2[]="computer";
	int i=0;
	while(s1[1]!='\0'&&s2[i]!='\0'&&s1[i]==s2[i])
		i++;
	printf("s1-s2=%d\n",s1[i]-s2[i]);
	return 0;
} 

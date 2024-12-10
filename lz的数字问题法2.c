#include<stdio.h>
#include<stdlib.h>
char a[20000],b[20000];
int main(void){
	int flag = 1;
	scanf("%s %s",a,b);
	for(int i=0;i<20000;i++){
		if(a[i]=='.'&&b[i]=='.'){
			for(int j=i+1;j<i+7;j++){
				if(a[j]!=b[j])
				flag = 0;
				}
			break;
		}
		else if(a[i]=='.'){
			
			if(b[i]!='\0'){
				flag = 0;
				break;
			}
				
			for(int j=i+1;j<i+7;j++){
				if(a[j]!='0'){
					flag=0;
					break;
				}
			}
			break;
		}
		else if(b[i]=='.'){
			
			if(a[i]!='\0'){
				flag = 0;
				break;
			}
			for(int j=i+1;j<i+7;j++){
				if(b[j]!='0'){
					flag=0;
					break;
				}
			}
			break;
			
		}
		if(a[i]!=b[i])
			flag = 0;
	}
	
		
	    if(flag==1)
			printf("YES");
		else
			printf("NO");
}

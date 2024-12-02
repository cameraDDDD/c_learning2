#include<stdio.h>
int fun(float x,float a,float b,float c){
	return a*x*x+b*x+c;
}
void prn_pict(int m,int n){
	char ch='A';
	for(int i=0;i<m;i++){
		for(int k=0;k<n;k++){
			printf("%c",ch);
		}
		ch++;
		putchar('\n');
	}
}
int main(void){
	prn_pict(5,3);
}

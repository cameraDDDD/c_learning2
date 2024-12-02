#include<stdio.h>
int max(int x,int y){
	for(int i=x;i>=1;i--){
		if(y%i==0&&x%i==0)
			return i;
	}
}
int min(int x,int y){
	for(int i=x;;i++){
		if(i%x==0&&i%y==0){
			return i;
		}
	}
}
/*int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",max(a,b));
	printf("%d",min(a,b));
}*/

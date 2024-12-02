#include<stdio.h>
#include<math.h>
void f(int l,int L,int n[l][l],int,int);
int main(void){
	int n;
	scanf("%d",&n);
	int l=pow(2,n);
	int L=l;
	int group[l][l];
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			group[i][j]=1;
		}
	}
	f(l,l,group,0,0);
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			printf("%d ",group[i][j]);
		}
		putchar('\n');
	}
}
void f(int l,int L,int n[L][L],int a,int b){
	
	if(l>=2){
		for(int i=a;i<l/2+a;i++){
			for(int j=b;j<l/2+b;j++){
				n[i][j]^=1;
			}
		}
	}
	
	
	l/=2;
	if(l>=2)
	{
		f(l,L,n,a+l,b);	
		f(l,L,n,a,b+l);
		f(l,L,n,a+l,b+l);	
	}

		
	
}
	


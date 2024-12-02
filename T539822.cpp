#include<stdio.h>
int main(void){
	int n,A,D,K,i,p,hpower=0,num=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d/%d/%d",&K,&D,&A);
		if(K-D>=10)
			p=K*(K-D)+A;
		else if(K>=D)
			p=(K-D+1)*3+A;
		else
			p=A*2;
		if(p>hpower)
		{	
			hpower=p;
			num=i;
		}
			
		
		
			
	}
	printf("%d",num);
	return 0;
}

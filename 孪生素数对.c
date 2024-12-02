//14นุ
#include<stdio.h>
#include<math.h>
int if_prime(int n){
	if(n<=1)
		return 0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return 0;
	}
    return 1;
    }
int main(void){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=m,count=0;count<n;i++){
        if(if_prime(i)&&if_prime(i+2)){
            printf("%d,%d\n",i,i+2);
            count++;
            
        }
    }
	return 0;
}

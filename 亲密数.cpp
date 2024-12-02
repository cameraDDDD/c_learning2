#include<stdio.h>
int love(int n){int sum=0;
    for(int i=n-1;i>0;i--){
        if(n%i==0)
            sum+=i;

    }
    return sum;
	}

int main(void)
{   for(int i=2;i<=3000;i++){
    int k=love(i);
    if(love(k)==i){
        printf("(%d,%d)",i,k);
    }
	
}
    
   
    return 0;
}

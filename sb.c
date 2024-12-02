#include<stdio.h>
	int exp(int x,int y){
        for(;y>0;y--){
            x*=10;
        }
        return x;
    }
    int main(void)
	{  
	  /*********Begin*********/
	  int a, n,nn, sum;
      scanf("%d%d",a,n);
      for(;n>0;n--){
          
          for(int i=n;i>0;i--){
              sum+=exp(a,nn-n);
          }

      }
	  /*********End**********/ 
       return 0;
	}

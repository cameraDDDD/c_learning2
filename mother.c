#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
	  double one=1,mother=2;
      while(mother<=100)
      {
          one-=1/mother;
          mother++;
      }
	  printf("%.3lf",one);
	  /*********End**********/ 
       return 0;
	}

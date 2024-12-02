#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	/**********Begin**********/
srand(time(NULL));
int a=rand()%6+1;
printf("Dice is: %d",a);
if(a%2==1)
    puts("lose");
else    
    puts("win");





	/**********End**********/
	return 0;
} 

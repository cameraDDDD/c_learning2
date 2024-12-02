#include<stdio.h>
int main(void){
	int ref[] = {8,4,0,2};
	int *ptr;
	int index;//意为索引 
	for (index = 0,ptr = ref;index < 4;index++,ptr++)
		printf("%d %d\n",ref[index],*ptr);
	return 0;
	/*输出为 8 8
			 4 4
			 0 0 
			 2 2
			 
			 */
	 
}

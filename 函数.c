#include<stdio.h>
/*void chline(char ch,int i,int j)
{   int k=i;
	for(;j>0;j--){
		for(i=0;i<k;i++)
			printf("%c",ch);
		printf("\n");
	}	
	return ;
}
int main(void){
	chline('6',6,6);
}*/
//����ʹ��ָ��
void* chline(char* ch,int* i,int* j){
	int *k=*i;
	for(;*j>0;*j--){
		for(*i=0;*i<*k;*i++)
			printf("%c",*ch);
		printf("\n");
	}	
	return ;
}
int main(void){
	*chline('6',6,6);
	return 0;
}
 

#include <stdio.h>
#include<math.h>

int main()
{
	int sum=0,n=0,j,yes,high;
	//--------------��������ʼ------------------	
	scanf("%d",&high);
	j=high;
    while((high>=2)&&(n<=9))
	{	
		yes=1;
		for(;j>=0;)
			j--;
			if(high%j==0)
			{	
				yes=0; 
				break;
			}
		if(!yes)
		{	
			sum+=j;
			n++;
		}
		//high++;
	}
	printf("sum=%d\n",sum);	
	//-----------�����������---------------------
	return 0;
}


//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
int main(void){ 
	int True;
	char ch;
    char group[200];
    int i=0;
    while(1){True=1;
	for(;(ch=getchar())!='\n';i++){
        group[i]=ch;
        
    }
    i--;
   for(int k=0;k<=i/2;k++){
        if(group[k]!=group[i-k])
        {
            printf("NO\n");
            True=0;
			i=0;
			break;
        }
        
   }
		if(True)
		{
			i=0;
			printf("Yes\n");
		}

	}
return 0;
}

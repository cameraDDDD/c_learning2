#include<stdio.h>
#include<math.h>
int find(int n){
    int s=sqrt(n);
    if(n/s==s)
        return 1;
    return 0;
}
int main(void){
    int a,b,n,s;
    while(scanf("%d%d",&a,&b)==2){
        for(int i=0;i<=10000;i++)
        {   
            s=i+a;
            
            if(find(s))
            {
                s=i+b;
                
                if(find(s)){
                    printf("%d\n",i);
                    break;
                }
            }
            printf("Not found!\n");
        }
        
        


    }

return 0;}

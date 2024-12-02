#include<stdio.h>
#include<string.h>
int main(void){
	char ch[10];
	int l,r,k,cut;
	int n, m;
	scanf("%d%d",&n,&m);
	n+=1;
	int f[1000]={0};
	for(int i=1;i<=m;i++){
		scanf("%s",ch);
		if(strcmp(ch, "water") == 0){
			
			scanf("%d%d",&l,&r);
			for(;l<=r;l++){
				f[l]++;
			}
		}
		if(strcmp(ch, "rise") == 0){
			cut=0;
			scanf("%d%d%d",&l,&r,&k);
				for(;l<=r;l++){
					if(f[l]>=k){
						f[l]=0;
						cut++;
						
					}
				}
			printf("%d\n",cut);
		}
		
		
		
		
		
		}
	}


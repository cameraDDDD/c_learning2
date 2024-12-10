#include<stdio.h>
void sort(int group[],int n){
	for(int i=1;i<n;i++){
		int base=group[i],j=i-1;
		for(;group[j]>base&&j>=0;j--){
			group[j+1]=group[j];
		}
		group[j+1]=base;
		
	}  
}

int main(void){
	int n,s=0,max=0;
	scanf("%d",&n);
	int nums[n];
	for(int i=0;i<n;i++){
		scanf("%d",nums+i);
	}
	sort(nums,n);
	for(int i=n-1,add=1;i>=0;i--,add++){
		
			s=add+nums[(i+n-1)/2];
		
			if(max<s)
				max=s;
		
		
	}
	printf("%d",max);
	
	
}


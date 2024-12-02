#include<stdio.h>
//≤Â»Î≈≈–Ú
void swap(int *a,int *b){
	int *t=a;
	*a=*b;
	*b=*t;
}
void insertion_sort(int nums[],int size){
	for(int i=1;i<size;i++){
		for(k=i;k>0;k--){
			if(nums[k]<nums[k-1])
				swap(&nums[k],&num[k-1]);
			
		}
	}
	
} 

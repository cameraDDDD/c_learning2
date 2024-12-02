#include<stdio.h>
int combination(int n, int k) {  
	int C[k + 1];  
	for (int i = 0; i <= k; i++) {  
		C[i] = 0;  
	}  
	C[0] = 1;
	for (int i = 1; i <= n; i++) {  
		for (int j = (i < k ? i : k); j > 0; j--) {  
			C[j] += C[j - 1];  
		}  
	}  
	
	return C[k];  
}  
int main(void){
	int n,sum=0;
	scanf("%d",&n);
	for(int i=0;i<=n-i;i+=1){
		sum+=combination(n-i,i);
		
	}
	printf("%d",sum);
	return 0;
	
	
	
}

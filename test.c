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


		
	
	printf("%d");
	return 0;
	
	
	
}


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
int kevin(int n){
	int sum=0;

	for(int i=0;i<=n-i;i+=1){
		sum+=combination(n-i,i);
		
	}
	printf("%d\n",sum);
	return 0;
	}
int main(void){
	int n;
	scanf("%d",&n);
	for(;n>0;n--){
		int x;
		scanf("%d",&x);
		kevin(x);
	}
		
}


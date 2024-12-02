#include<stdio.h>
/*int combination(int n, int k) {  
	// 基本情况  
	if (k == 0 || k == n) {  
		return 1;  
	}  
	
	return combination(n - 1, k - 1) + combination(n - 1, k);  
} */
int combination(int n, int k) {  
	int C[k + 1];  
	// 初始化 C 数组  
	for (int i = 0; i <= k; i++) {  
		C[i] = 0;  
	}  
	C[0] = 1; // C(n, 0) 始终为 1  
	
	// 计算组合数  
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

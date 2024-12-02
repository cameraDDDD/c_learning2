#include<stdio.h>

int if_prime(int n){
	if(n<=1)
		return 0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main(void){
	int a,b,d1,d2,d3,d4,d5;
	scanf("%d%d",&a,&b);
	
	int arr[1000] = {[0]=5,[1]=7,[2]=11};
	int palindrome,i=3;
	for (d1 = 1; d1 <= 9; d1+=2) {    
    	for (d2 = 0; d2 <= 9; d2++) {
        	palindrome = 100*d1 + 10*d2 + d1;
        		if(if_prime(palindrome)){
					arr[i]=palindrome;
					i++;
				}
			 }
     	}
    for (d1 = 1; d1 <= 9; d1+=2) {    
    	for (d2 = 0; d2 <= 9; d2++) {
        	palindrome = 1000*d1 + 100*d2 + 10*d2+d1;
        		if(if_prime(palindrome)){
					arr[i]=palindrome;
					i++;
				}
			 }
     	}
 	
	for (d1 = 1; d1 <= 9; d1+=2) {    
    	for (d2 = 0; d2 <= 9; d2++) {
        	for (d3 = 0; d3 <= 9; d3++) {
           		palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
        		if(if_prime(palindrome)){
					arr[i]=palindrome;
					i++;
				}
			 }
     	}
 	 }
 	 for (d1 = 1; d1 <= 9; d1+=2) {    
    	for (d2 = 0; d2 <= 9; d2++) {
        	for (d3 = 0; d3 <= 9; d3++) {
           		palindrome = 100000*d1 + 10000*d2 +1000*d3 +100*d3+ 10*d2 + d1;
        		if(if_prime(palindrome)){
					arr[i]=palindrome;
					i++;
				}
			 }
     	}
 	 }
	 for (d1 = 1; d1 <= 9; d1+=2) {    
    	for (d2 = 0; d2 <= 9; d2++) {
        	for (d3 = 0; d3 <= 9; d3++) {
           		for (d4 = 0;d4 <= 9; d4++)
        		{
palindrome=1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 +100*d3+10*d2+d1;
        		if(if_prime(palindrome)){
				arr[i]=palindrome;
				i++; 
				}
				}
		 	
			 }
     	}
 	} 
 	for (d1 = 1; d1 <= 9; d1+=2) {    
    	for (d2 = 0; d2 <= 9; d2++) {
        	for (d3 = 0; d3 <= 9; d3++) {
           		for (d4 = 0;d4 <= 9; d4++)
        		{
palindrome=10000000*d1 + 1000000*d2 + 100000*d3 + 11000*d4 +100*d3+10*d2+d1;
        		if(if_prime(palindrome)){
				arr[i]=palindrome;
				i++; 
				}
				}
		 	
			 }
     	}
 	} 
 	for(int j=0;j<=i;j++){
 		if(arr[j]>=a&&arr[j]<=b){
 			printf("%d\n",arr[j]);
		 }
	 }
	return 0;
}

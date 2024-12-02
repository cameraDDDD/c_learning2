#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isPalindrome(int x) {
    char n[100];
    fgets(n,100,stdin);
    int len=strlen(n);
    for(int i=0;i<=len/2;i++){
        if(n[i]!=n[len-1-i]){
            return false;
        }
    }
    return true;
}
int main(void){
	printf("%d",isPalindrome(-121));
}

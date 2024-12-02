#include <stdio.h>  
#include <stdlib.h>  

int factorial(int n) {  
    if (n == 0) {  
        return 1;  
    } else {  
        return n * factorial(n - 1);  
    }  
}  

int evaluate(int left, char op, int right) {  
    int result;  
    switch (op) {  
        case '+': result = left + right; break;  
        case '-': result = left - right; break;  
        case '*': result = left * right; break;  
        case '/':  
            if (right != 0) {  
                result = left / right; break;  
            } else {  
                printf("error\n");  
                return 0;   
            }  
        case '%':  
            if (right != 0) {  
                result = left % right; break;  
            } else {  
                printf("error\n");  
                return 0; 
            }  
        default:  
            printf("invalid operator\n");  
            return 0;  
    }  
    return result;  
}  

int main() {  
    int left, right, result;  
    char op;  
    do{  
    
        scanf("%d", &left);  
        
        
        scanf(" %c", &op);   
        
        if (op == '!') {  
            result = factorial(left);  
            printf("%d\n", result);  
        } else {  
            
            scanf("%d", &right);  
            result = evaluate(left, op, right);  
            if(!(right==0&&(op=='/'||op=='%')))
            printf("%d\n", result);  
        }  
    }  while(getchar()!=EOF);
    return 0;  
} 

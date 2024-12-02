#include <stdio.h>  

int main() {  
    int n;  
    scanf("%d", &n);  // Read the number of input values  
    int L[6];  // Assuming at most 6 values based on the original code's logic  
    for (int i = 0; i < 6; i++) {  
        scanf("%d", &L[i]);  // Read the input values into the array L  
    }  

    // Fill the remaining values with the last element if there are less than 6 inputs  
    for (int i = n; i < 6; i++) {  
        L[i] = L[n - 1];  // Repeat the last value  
    }  

    int day = 1;  
    int sum_value = 0;  

    for (int i = 0; i < n; i++) {  
        int k;  
        scanf("%d", &k);  // Read the k value  
        if (k) {  
            if (day < 3) {  
                sum_value += L[0];  
            } else if (day < 7) {  
                sum_value += L[1];  
            } else if (day < 30) {  
                sum_value += L[2];  
            } else if (day < 120) {  
                sum_value += L[3];  
            } else if (day < 365) {  
                sum_value += L[4];  
            } else {  
                sum_value += L[5];  
            }  
            day++;  
        } else {  
            day = 1;  // Reset day if input is 0  
        }  
    }  

    printf("%d\n", sum_value);  // Output the final sum  
    return 0;  
}

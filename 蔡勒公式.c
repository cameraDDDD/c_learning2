#include <stdio.h> 
#include <stdio.h>  

// ���չ�ʽ�������ڼ�  
int zellerCongruence(int year, int month, int day){  
    if (month == 1 || month == 2){  
        month += 12;  
        year -= 1;  
    }  
    int q = day;  
    int m = month;  
    int k = year % 100;  
    int j = year / 100;  
    int h = (q + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;  
    return h;  
}  

int main() {  
    int year, month, day, dayOfWeek;  
     
    scanf("%4d", &year);  
    scanf("%2d", &month);  
    scanf("%2d", &day);  
    dayOfWeek = zellerCongruence(year, month, day);  

 
    const char* weekDays[] = {"������","������","����һ", "���ڶ�", "������", "������", "������"};  
    printf("���ǣ�%s\n", weekDays[dayOfWeek]);  

    return 0;  
}

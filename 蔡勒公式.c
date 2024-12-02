#include <stdio.h> 
#include <stdio.h>  

// 蔡勒公式计算星期几  
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

 
    const char* weekDays[] = {"星期六","星期日","星期一", "星期二", "星期三", "星期四", "星期五"};  
    printf("这是：%s\n", weekDays[dayOfWeek]);  

    return 0;  
}

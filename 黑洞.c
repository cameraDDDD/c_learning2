//请在此输入你的代码，复杂程序可先在Dev C++中运行调试后再提交
#include<stdio.h>
#include<stdlib.h>
#define HOLE 6174
void insertionSort(int nums[], int size) {//插入排序
    for (int i = 1; i < size; i++) {
        int base = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}
int main(void){
    char n[6];
    scanf("%s",n);
    //insertionSort(n,5);
    printf("%d",atoi(n));

    
    

}

//���ڴ�������Ĵ��룬���ӳ��������Dev C++�����е��Ժ����ύ
#include<stdio.h>
#include<stdlib.h>
#define HOLE 6174
void insertionSort(int nums[], int size) {//��������
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

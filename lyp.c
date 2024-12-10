#include<stdio.h>
int main()
{
	int size = 0;
	scanf("%d",&size);
	int arr[size];
	int m = 0;
	for (int i = 0, t = 0; i < size; i++)
	{
		scanf("%d",&t);
		arr[i] = t;
		int k = i;
		// 插入
		while (k - 1 >= 0 && arr[k - 1] > arr[k])
		{
			int temp = arr[k];
			arr[k] = arr[k-1];
			arr[k-1] = temp;
			k--;
		}
		int n = arr[i / 2] + i + 1;
		if (m < n)
		{
			m = n;
		}
	}
	printf("%d",m);
	
	return 0;
}

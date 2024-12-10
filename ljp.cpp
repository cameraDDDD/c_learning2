#include<iostream>
using namespace std;
int main()
{
	int size = 0;
	cin >> size;
	int* arr = new int[size];
	int m = 0;
	for (int i = 0, t = 0; i < size; i++)
	{
		cin >> t;
		arr[i] = t;
		int k = i;
		// 插入
		while (k - 1 >= 0 && arr[k - 1] > arr[k])
		{
			swap(arr[k - 1], arr[k]);
			k--;
		}
		int n = arr[i / 2] + i + 1;
		if (m < n)
		{
			m = n;
		}
	}
	cout << m;
	
	return 0;
}

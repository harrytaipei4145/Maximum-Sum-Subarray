#include<iostream>

using namespace std;


int cross(int num[], int low,int mid,int high)
{
	int left_sum = 0;
	int right_sum = 0;
	int sum = 0;
	int max_right=0, max_left = 0;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + num[i];
			if (sum > left_sum)
			{
				left_sum = sum;
			}
	}
	
		sum = 0;
	for (int j = mid+1;  j<=high; j++)
	{
		sum = sum + num[j];
			if (sum > right_sum)
			{
				right_sum = sum;
			}
	}
	return left_sum + right_sum;
}

int find(int num[], int low, int high)
{
	int left, right, cross_sum,mid;
	if (low == high)
	{
		if (num[low] > 0)
			return num[low];
		else
			return 0;
	}
		
	else
	{
		mid = (low + high) / 2;
		left = find(num, low, mid);
		right = find(num, mid + 1, high);
		cross_sum = cross(num, low, mid, high);
		if (left >= right && left >= cross_sum)
			return left;
		else if (right >= left && right >= cross_sum)
			return right;
		else
			return cross_sum;
	}
}

int main()
{
	int count = 0;
	int number[10000];
	int max_sum = 0;
	while (!cin.fail())
	{
		cin >> number[count];
		count++;
	}
	count = count - 2;
	
	max_sum = find(number, 0, count);
	cout << max_sum;
	system("pause");
}


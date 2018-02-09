#include<iostream>

using namespace std;


int sub(int start, int end, int num[])
{
	int max_sum = 0;
	int sum=0;
	for (int i = start; i <= end; i++)
	{
		sum += num[i];
		if (sum >= max_sum)
			max_sum = sum;
	}
	return max_sum;
}


int main()
{
	int count = 0;
	int number[10000];
	int temp_sum=0;
	int max_sum = 0;
	while (!cin.fail())
	{
		cin >> number[count];
		count++;
	}
	count = count - 2;
	
	for (int i = 0; i <= count; i++)
	{
		temp_sum = sub(i, count, number);
		if (temp_sum > max_sum)
			max_sum = temp_sum;
	}
	cout << max_sum;
	
}

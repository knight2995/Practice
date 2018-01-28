#include <iostream>

using namespace std;

int main()
{
	int n;
	int arr[23] = { 0, };

	cin >> n;

	while (n--)
	{
		int temp;
		cin >> temp;
		arr[temp - 1]++;
	}

	for (int i = 0; i < 23; i++)
		cout << arr[i] << " ";
}
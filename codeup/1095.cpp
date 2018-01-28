#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int value = INT_MIN;
	while (n--)
	{
		int temp;
		cin >> temp;
		if (temp < value)
			value = temp;
	}


	cout << value;
}
#include <iostream>

using namespace std;

int main()
{
	int n, m, k, l;
	cin >> n >> m >> k >> l;

	int value = n;

	l -= 1;

	while (l--)
		value = value * m + k;

	cout << value;
}
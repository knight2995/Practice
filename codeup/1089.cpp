#include <iostream>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	int value = n;

	k -= 1;

	while (k--)
		value += m;

	cout << value;
}
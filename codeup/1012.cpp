#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float f;
	cin >> f;
	cout << fixed;
	cout.precision(6);
	cout << f;
}
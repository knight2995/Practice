#include <iostream>

using namespace std;

void print(int **,int);
void fill(int **, int);
int main()
{

	int n;
	cin >> n;
	

	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}

	}

	fill(arr, n);
	print(arr, n);


}
void print(int **arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void fill(int **arr, int n)
{
	int m = n;
	int xVector = 1;
	int yVector = 1;

	int x = 0;
	int y = 0;
	int v = 1;


	while (m > 0)
	{
		//가로 m번
		for (int i = 0; i < m; i++)
		{
			arr[y][x] = v;
			v++;
			x += xVector;
		}
		xVector = -xVector;
		x +=  xVector;

		m--;

		y += yVector;

		print(arr, n);
		cout << endl;

		//세로 m번
		for (int i = 0; i < m; i++)
		{
			arr[y][x] = v;
			v++;
			y += yVector;
		}
		yVector = -yVector;
		y += yVector;

		print(arr, n);
		cout << endl;

		x += xVector;
		

	}
}
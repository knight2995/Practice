#include <stdio.h>

int main()
{

	int x;

	scanf("%d", &x);

	int sum = 0;

	//first
	while (x > 0)
	{
		sum += x;
		x--;

	}

	printf("%d", sum);
}
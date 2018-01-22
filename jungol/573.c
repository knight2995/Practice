#include <stdio.h>

void put(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <n; j++)
			printf("%d ", i *n + j + 1);
		printf("\n");
	}

}

int main()
{
	int n;
	scanf("%d", &n);

	put(n);



}
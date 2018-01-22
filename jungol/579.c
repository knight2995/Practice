#include <stdio.h>
//selection sort
void func(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] > arr[i])
			{
				int temp = arr[i];    // exchange list[i] & list[j]
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main()
{
	int arr[10];
	int n;
	int i;
	scanf("%d", &n);
	printf("%d", n);
	for (i = 0; i < n; i++)
		scanf("%d ", arr[i]);

	func(arr, n);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
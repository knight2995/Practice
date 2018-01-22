#include <stdio.h>

void foo(int n)
{
	int sum = 0;	//합을 저장
	int value = 0;	//역의 값 저장
	for (int i = 0; n > 0; i++)
	{
		int k = n % 10;
		sum += k;
		value = value * 10 + k;
		n /= 10;

	}
	printf("%d %d\n", value, sum);
}
int main()
{
	int a;
	while (1)
	{
		scanf("%d", &a);
		if (a == 0)
			break;
		foo(a);
	}
}
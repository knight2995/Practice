
#include <stdio.h>
#include <math.h>
const int Kaprekar = 6174;
int findMax(int input)
{
	int num[4];
	int max = 0;
	for (int i = 0; i<4; i++) {
		num[i] = input % 10;
		input = input / 10;
	}

	// ∫ÚO -> Ω««‡Ω√∞£ ∫ÚO(N^2) 
	// ∫ÚO(nlogn)

	for (int k = 0; k<3; k++)
	{
		for (int l = k + 1; l<4; l++)
		{
			if (num[l] > num[k])
			{
				int temp = num[k];
				num[k] = num[l];
				num[l] = temp;
			}
		}
	}
	for (int m = 0; m<4; m++) {
		max = max + num[m] * pow(10, 3 - m);
	}
	return max;
}
int findMin(int input)
{
	int num[4];
	int max = 0;
	for (int i = 0; i<4; i++) {
		num[i] = input % 10;
		input = input / 10;
	}

	// ∫ÚO -> Ω««‡Ω√∞£ ∫ÚO(N^2) 
	// ∫ÚO(nlogn)

	for (int k = 0; k<3; k++)
	{
		for (int l = k + 1; l<4; l++)
		{
			if (num[l] < num[k])
			{
				int temp = num[k];
				num[k] = num[l];
				num[l] = temp;
			}
		}
	}
	for (int m = 0; m<4; m++) {
		max = max + num[m] * pow(10, 3 - m);
	}
	return max;
}
int getKaprekar(int n)
{
	int count = 0;
	int newNumber = n;
	while (newNumber != 6174)
	{
		newNumber = findMax(newNumber) - findMin(newNumber);
		count++;
	}
	return count;

}




int main()
{


	int n;

	scanf("%d", &n);

	printf("%d", getKaprekar(n));
}
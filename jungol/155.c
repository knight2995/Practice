#include <stdio.h>


int main()
{
	char string[6] = { 'J','U','N','G','O','L' };

	char find;
	scanf("%c", &find);

	int i;
	int index = -1;
	for (i = 0; i < 6; i++)
	{
		if (string[i] == find)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		printf("none");
	else
		printf("%d", index);



}
#include <stdio.h>

void convert_to_binary(unsigned int num);
void convert_to_hexa(unsigned int num);
void convert_to_octa(unsigned int num);

int main() {

	unsigned int decimalnum;
	unsigned int system;
	
	scanf("%d %d",&decimalnum, &system);

	if (system == 2)
		convert_to_binary(decimalnum);
	else if (system == 8)
		convert_to_octa(decimalnum);
	else if (system == 16)
		convert_to_hexa(decimalnum);

}
void convert_to_binary(unsigned int num) 
{
	char result[32];
	int i = 0;
	
	while (num > 0)
	{
		result[i++] = (num % 2) + '0';
		num /= 2;

	}
	while (i--)
		printf("%c", result[i]);
	
}
void convert_to_octa(unsigned int num)
{
	char result[32];
	int i = 0;

	while (num > 0)
	{
		result[i++] = (num % 8) + '0';
		num /= 8;

	}
	while (i--)
		printf("%c", result[i]);
}
void convert_to_hexa(unsigned int num) 
{
	char result[32];
	int i = 0;

	while (num > 0)
	{
		int temp = (num % 16);
		if (temp >= 10)
			result[i++] = 'A' + (temp - 10);
		else
			result[i++] = temp + '0';
		
		num /= 16;

	}
	while (i--)
		printf("%c", result[i]);
	
}

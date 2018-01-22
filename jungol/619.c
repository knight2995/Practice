#include <stdio.h>

int main()
{
	int a;
	int* ip;

	ip = &a;

	scanf("%d", &a);
	printf("%#p %d", *ip, *ip);


}
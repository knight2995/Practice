#include <stdio.h>
#include <string.h>
#include "MyString.h"
int main()
{

	char str1[20] = "Hello";
	char str2[6] = "World";
	char str3[5] = "2018";

	if (strlen(str1) == _strlen(str1) && strlen(str2) == _strlen(str2))
		printf("_strlen 통과\n");

	_strcpy(str1, str2);
	if (strcmp(str1, str2) == 0)
		printf("_strcpy 통과\n");

	strcpy(str1, "Hello ");

	_strcat(str1, str2);

	if (strcmp(str1, "Hello World") == 0)
		printf("_strcat 통과\n");

	if (_atoi(str3) == 2018)
		printf("_atoi 통과\n");

}
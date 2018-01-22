#pragma once



size_t _strlen(const char *s)
{
	size_t i = 0;

	while (s[i] != '\0')
		i++;

	return i;
}

char* _strcpy(char *dest, const char *src)
{
	size_t i = 0;

	while (src[i] != '\0')
		dest[i++] = src[i];

	return dest;
}

char* _strcat(char *dest, const char *src)
{
	size_t i = 0;
	size_t j = 0;
	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
		dest[i + j] = src[j++];

	return dest;
}

int _atoi(const char* s)
{
	size_t i = 0;
	int value = 0;
	while (s[i] != '\0')
	{
		value = value * 10 + (s[i] - '0');
		i++;
	}

	return value;
}
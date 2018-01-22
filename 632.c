int main()
{

	int x, y, z, min;

	scanf("%d %d %d", &x, &y, &z);

	//first
	min = x;
	if (min > y)
		min = y;
	if (min > z)
		min = z;

	printf("%d", min);

}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 50, P = 1, d = 2, nr = 0, i, k = 0, j = 0, s[50] = { 0 }, s2[200] = { 0 }, s3[51] = { 0 }, rest;
	printf("Sirul de numere de la 1->50 este:");
	for (i = 0; i < n; i++)
	{
		s[i] = i + 1;
		printf(" %d", s[i]);
	}
	printf("\n\n");
	for (i = 1; i < n; i++)
	{
		for (d = 2; d < s[i]; d++)
		{
			if (s[i] % d == 0)
			{
				s2[j] = s[i];
				j++;
				break;
			}
			if (s[i] % d != 0)
			{
				s3[k++] = s[i];
				break;
			}
		}
	}
	for (i = 0; i < 23; i++)
	{
		s[i] = s2[i];
	}
	for (i = 0; i < 23; i++)
	{
		s2[i] = s3[i];
	}
	for (i = 0, j = 0, k = 0; i < 23; i++)
	{
		P = s3[i];
		while (P != 0)
		{
			rest = P % 2;
			P /= 2;
			s2[j++] = rest;
		}
		s2[j] = ' ';
		j++;
	}
	for (i = 0; i < 23; i++)
	{
		s3[i] = 0;
	}
	printf("Iar numerele prime in forma binara sunt:\n");
	for (k = 0; k <= 133;)
	{
		if (s2[k] == 32)
		{
			k++;
			printf("\n");
		}
		printf("%d ", s2[k++]);
	}
}
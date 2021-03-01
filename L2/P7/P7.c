#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define citire(n) scanf("%d",&n);
int main() 
{
	int a[30], b[30], n,k, i, sum =0;
	printf("Introduceti numarul: ");
	citire(n);
	for (i = 0; i <= n; i++)
		a[i] = i;
    for (k = 0; k <= i; k++)
		{
			n = k; 
		 B:
			b[k] = n % 2;
			n /= 2;
			if (n != 0)
			{

				goto B;
			}
		}
	for (k = 0; k <= i; k++)
	{
		sum += b[k];
	}
	printf("\nSuma bitilor fiecarui numar de la 1 la N este = ");
	{
		printf("%d\n", sum);
	}
}
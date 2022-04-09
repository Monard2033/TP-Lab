//Afisarea submultimilor dintr o multime
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[4], n, i;
	printf("Dati nr. de valori: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("v[%d]= ", i);
		scanf("%d", &a[i]);
	}
	for (i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1)
				printf("%d ", a[j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
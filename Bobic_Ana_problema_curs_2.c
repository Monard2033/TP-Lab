/*Se dă o mulțime de numere naturale cu valori de la 0 la 1000. Se citesc
de la intrare diferite valori în intervalul [0,1000], să se utilizeze un
vector de octeți de dimensiune cât mai mică pentru memorarea
elementelor mulțimii.*/
#include<stdio.h>
#include<stdlib.h>

int v[32];
int main()
{
	int n, x;
	printf("Introduceti numarul de elemente: ");
	scanf("%d", &n);
	printf("Introduceti elementele: \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		int a = x / 32;
		int b = x % 32;
		v[a] |= (1 << b);
	}
	for (int i = 0; i < 1001; i++)
	{
		int a = i / 32;
		int b = i % 32;
		if ((v[a] >> b) & 1)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

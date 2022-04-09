//Implementare Binary Search
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[100], n, i, x, li, lf, aux=0;
	printf("Dati nr. de elemente ale vectorului: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("v[%d]=", i+1);
		scanf("%d", &A[i]);
	}
	printf("Dati elementul pe care doriti sa il cautati: ");
	scanf("%d", &x);
	li = 1; lf = n;
	while (li <= lf) 
	{
		i = (li + lf) / 2;

		if (A[i] == x)
		{
			aux = i;
			printf("Indexul cautat este : %d", aux);
			printf("\n");
			break;
		}

		if (x < A[i])
		{

			lf = i - 1;
		}
		else
		{
			li = i + 1;
		}
	}
	if (aux == 0)
	{
		printf("Valoarea %d nu se regaseste in vector\n", x);
	}
	system("pause");
	return 0;
}
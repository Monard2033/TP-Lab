//Implementare Linear Search
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[100], n, i, x;
	printf("Dati nr. de elemente ale vectorului: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("Dati elementul pe care doriti sa il cautati: ");
	scanf("%d", &x);
	for (i = 0; i < n; i++)
	{
		if (x == A[i])
		{
			printf("Indexul cautat este : %d ", i);
			printf("\n");
			break;
		}
	}
		if (i == n)
		{
			printf("Elementul %d nu se regaseste in vector\n", x);
		}
	system("pause");
	return 0;
}
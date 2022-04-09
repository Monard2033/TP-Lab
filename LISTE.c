
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int value;
	struct Node *nxt;
}nod;


nod *insertBeginning(nod *first, int val)
{
	nod *p = (nod *)malloc(sizeof(nod));
	if (p == NULL)
		exit(0);
	p->nxt = NULL;
	p->value = val;
	if (first == NULL)
		return p;
	else
	{
		p->nxt = first;
		return p;
	}
}
void write(nod *first)
{
	nod *q;
	q = first;
	while (q != NULL)
	{
		printf("%d ", q->value);
		q = q->nxt;
	}
	printf("\n");
}

void insertN(nod *first)
{
	int n, i=1;
	nod *q = first;
	int val;
	nod *p = (nod*)malloc(sizeof(nod));
	if (p == NULL)
		exit(0);
	p->nxt = NULL;
	printf("Dati valoarea pozitiei pe care se va adauga un nod: ");
	scanf("%d", &n);

	printf("Dati valoarea nodului: ");
	scanf("%d", &val);
    p->value = val;

	while (q != NULL && (i+1)<n)
	{
		q = q->nxt;
		i++;
	}
	if ((i+1) == n)
	{
		//printf("S-a ajuns. %d \n", i);
		p->nxt = q->nxt;
		q->nxt= p;
	}
}

int main()
{
	printf("%s\n", __FILE__);
	nod *first=NULL;
	int val;
	int opt;
	do {
		printf("\n1. Adaugarea in fata a unui nod in lista.");
		printf("\n2. Afisare lista.");
		printf("\n3. Adaugarea unui nod pe o pozitie data.");
		printf("\nOptiunea dumneavoastra este: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0: exit(0);
		case 1:
			printf("Dati valoarea nodului: ");
			scanf("%d", &val);
			first=insertBeginning(first, val);
	        break;
		case 2: write(first);
			break;
		case 3: insertN(first);
			write(first);
			break;
		default:
			printf("Optiune gresita!!!\n");
			break;
		}
	} while (1);

	system("pause");
	return 0;
}
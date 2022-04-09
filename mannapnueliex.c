#include <stdio.h>

void push(int *st, int *k, int el)
{
	(*k)++;
	st[*k] = el;
}

void pop(int *st, int *k, int el)
{
	(*k)--;
}

int elem_vf(int *st, int k)
{
	return st[k];
}

int f(int x)
{
	if (x >= 12)
		x = x - 1;
}

int stiva_goala(int k)
{
	if (k == 0)
		return 0;
}

int main()
{
	int st[100], k = -1, x;
	printf("Introduceti un numar:");
	scanf("%d", &x);
	if (x > 12)
		x = x - 1;
	else
	{
		while (x < 12)
		{
			push(st, &k, x + 2);
			x = x + 2;
		}
		while (x >= 12)
		{
			pop(st, &k, elem_vf(st, k));
			push(st, &k, x - 1);
			x--;
		}
	}
	printf("\n f=%d \n\n\n", x);
	system("pause");
	return 0;
}
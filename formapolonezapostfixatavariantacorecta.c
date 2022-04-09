#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prioritate(char c)
{
	if (c == '(' || c == ')')
		return 0;
	else if (c == '/' || c == '*')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else
		return 3;
}

void adaugare_stiva(char st[100], int *k, char el)
{
	(*k)++;
	st[*k] = el;
}

void stergere_din_stiva(char st[100], int *k, char el)
{
	(*k)--;
}

char element_varf(char st[100], int k)
{
	return st[k];
}

int main()
{
	int i = 0, pr, k = -1, j = 0, n;
	char st[100], fp[100], aux, mat[100], mat2[100];

	printf("Introduceti o expresie matematica scrieti expresia ---intre paranteze ()---\n altfel nu se va parcurge cum trenuie expresia matematica:\n");
	gets(mat);

	while (mat[i] != '\0')
	{
		if (mat[i] >= 'a' && mat[i] <= 'z')
		{
			fp[j] = mat[i];
			j++;
		}
		else
		{
			adaugare_stiva(st, &k, mat[i]);
			pr = prioritate(mat[i]);
			if (pr == 2)
			{
				aux = mat[i];
				stergere_din_stiva(st, &k, mat[i]);
				while ((prioritate(element_varf(st, k)) == 1) || (prioritate(element_varf(st, k)) == 2))
				{

					fp[j] = element_varf(st, k);
					j++;
					stergere_din_stiva(st, &k, element_varf(st, k));
				}
				adaugare_stiva(st, &k, aux);
			}
			if (pr == 1)
			{
				aux = mat[i];
				stergere_din_stiva(st, &k, mat[i]);
				while (prioritate(element_varf(st, k)) == 1)
				{

					fp[j] = element_varf(st, k);
					j++;
					stergere_din_stiva(st, &k, element_varf(st, k));
				}
				adaugare_stiva(st, &k, aux);
			}
			if (mat[i] == ')')
			{
				stergere_din_stiva(st, &k, element_varf(st, k));
				do
				{

					fp[j] = element_varf(st, k);
					j++;
					stergere_din_stiva(st, &k, element_varf(st, k));
				} while (element_varf(st, k) != '(');
				stergere_din_stiva(st, &k, element_varf(st, k));
			}
		}
		i++;
	}
	n = j;
	for (j = 0; j < n; j++)
		printf("%c", fp[j]);
	printf("\n");
	system("pause");
	return 0;
}
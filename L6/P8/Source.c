#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int Valid(int r,int p,char a[10][10])
{
	int i, j, k=0;
	char s[50];
	if (r != 0)
	{
		i = p;
		j = r;
	}
	else
	{
		i = p;
		j = 10;
	}
			if(a[i][j] == 'X')
			{
				printf(" Ati nimerit intr-o bomba!\n");
				return 0;
			}
			else
			{
				printf("\nLocatia care s-a ales, are cifra %c\n",a[i][j]);
					s[k] = a[i][j];
					k++;
				return 1;
			}
			system("pause");
			system("cls");
			return 1;
}
void BT() 
{}
int main()
{  
	char a[10][10],s[50]; int i, j, r, p,n=0;
	FILE* f;
	time_t t;
	srand((unsigned)time(&t));
	f = fopen("Minesweeper.txt", "rt");
	for (i = 0; i <= 9; i++)
	for (j = 0; j <= 10; j++)
	{
		fscanf(f, "%c", &a[i][j]);
		printf(" %c", a[i][j]);
	}
	fclose(f);
	printf("\n|Se alege un numar aleatoriu de la 1 la 100|\n ");
	n = rand() % 100;
	printf("\n Numarul generat este - %d \n", n);
	p = n / 10;
	r = n % 10;
	Valid(r, p, a);
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int setflag(int n, int k)
{  // seteaza bitul de pe pozitia k la valoarea 1
	int mask = 1 << k;
	return n | mask;
}

int unsetflag(int n, int k)
{  //seteaza bitul de pe pozitia k la valoarea 0
	int mask = ~(1 << k);
	return n & mask;
}

int getflag(int n, int k)
{  //returneaza valoarea bitului de pe pozitia k
	int mask = 1 << k;
	return ((n&mask) == mask);
}

int changeflag(int n, int k)
{  // schimba valoarea bitului de pe pozitia k
	int mask = (1 << k);
	return n ^ mask;
}

int main()
{
	FILE *fi;
	FILE *fo;
	int i, j;
	int k;
	int x,n;
	char a[126] = { 0 };
	fi = fopen("citire.txt", "r");
	fo = fopen("afisare.txt", "w");
	while (1)
	{
		if (feof(fi))
			break;
		fscanf(fi, "%d", &x);
		//printf("%d\n", x);
		n = x / 8;
		k = x % 8;
		a[n] = a[n] | (1 << k);
	}
	for (i = 0; i <= 125; i++)
		for (j = 0; j <= 7; j++)
			if (getflag(a[i], j) == 1)
				fprintf(fo, "%d\n", i * 8 + j);
	fclose(fi);
	fclose(fo);
	system("pause");
	return 0;
}
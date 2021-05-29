#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
	int min, sum, k, t1 = 1, t2 = 1;
	printf("Introduceti numarul 'k' dorit: ");
	scanf("%d", &k);
	while (t1 + t2 <= k)
	{
		sum = t1 + t2;
		t1 = t2;
		t2 = sum;
	}
	min = 0;
	while (k > 0)
	{
		if (k - t2 >= 0)
		{
			k = k - t2;
			min++;
		}
		sum = t2 - t1;
		t2 = t1;
		t1 = sum;
	}
	printf("k=%d", min);
}
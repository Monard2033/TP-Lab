//Exercitiul 1 tema curs 2
#include<stdlib.h>
#include<stdio.h>

int main() {
	int i, v[32], a, b, n, x;
	for (i = 0; i < 32; i++) {
		v[i] = 0;
	}
	printf("Dati numarul de elemente: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		a = x / 32;
		b = x % 32;
		v[a] |= (1 << b);
	}
	for (i = 0; i < 1001; i++) {
		a = i / 32;
		b = i % 32;
		if ((v[a] >> b) & 1) {
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}
/*Se dau N dame şi o tablă de şah de dimensiune NxN.
Să se găsească toate modalităţile de a aranja toate damele astfel încât oricare două dame să nu
se atace. Două dame se atacă dacă se află pe aceeaşi linie, coloană sau diagonală.
Se cere să se afişeze solutiile.*/
#include <stdio.h>
#include <math.h>

int N = 4;
int stiva[5];

int isValid(int position) {
	for (int i = 1; i < position; i++) {
		if (stiva[i] == stiva[position]) 
			return 0;
		if ((i-stiva[i]) == ( position-stiva[position] ) ||((stiva[i] + i) == (stiva[position] + position )))
		      return 0;
	}
	return 1;
}

void printPermutation() {
	for (int i = 1; i <= N; ++i) 
		if (stiva[i] == i) 
			return 0;
	for (int i = 1; i <= N; ++i) 
		printf("%d %d\n", i, stiva[i]);
		
	
	printf("\n");
}

void generatePermutations(int position) {
	for (int i = 1; i <= N; ++i) {
		stiva[position] = i;
		if (isValid(position)) 
			if (position == N) {
				printPermutation();
			}
			else 
				generatePermutations(position + 1);
			
	}
}

int main() {
	generatePermutations(1);
	return 0;
}

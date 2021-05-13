#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int i, j, x, y,z, m[10][10], wall = 0;
int floodfill(int m[10][10], int x, int y)
{
   //Sincer nustiu cum sa implementez in cazul respectiv
}
int main()
{
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			m[i][j] = (i == 0 || i == 10 - 1 || j == 0 || j == 10 - 1) ? 0 : 1;
		}
	for (i = 1; i < 9; i++)
		for (j = 1; j < 9; j++)
			m[i][j] = (rand() % (3 - 0+1));
	x = (rand() % (8 - 3 + 1)) + 1;
	z = (rand() % (8 - 3 + 1)) + 1;
	y = (rand() % (8 - 5 + 1)) + 1;
	    m[0][x] = 1;
		m[y][9] = 1;
		m[9][z] = 1;
		floodfill(m, x,y);
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
				printf("%d ", m[i][j]);
			printf("\n");
		}
}
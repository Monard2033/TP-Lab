#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct operator{
	char semn;
	int prioritate;
}stiva;

stiva operatori[40];
char E[80];
int i=0,v, n = -1, operanzi[40], modifiactor_prioritate=0, nr=-1;
int priority(char ch)
{
	if (ch == '+' || ch == '-') 
    return 0;
	if(ch=='*' || ch=='/') 
    return 1;
}
void creare_stive(char ch)
{
	if (ch >= 'a'&& ch <= 'z') 
        {
		printf("%c= ", ch);
		scanf("%d", &v);
		n++;
		operanzi[n] = v;
		return;
		
	}else
	if (ch == '(')
	{
		modifiactor_prioritate += 10;
		
	}else
	if (ch == ')')
	{
		modifiactor_prioritate -= 10;
	}
	else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
	{
		nr++;
		operatori[nr].prioritate=modifiactor_prioritate + priority(ch);
		//printf("%d \n", operatori[nr].prioritate);
		if(nr==0)
			operatori[nr].semn = ch;
		else
		if (operatori[nr].prioritate > operatori[nr - 1].prioritate)
		{
			operatori[nr].semn = ch;// printf("Semnul: %c .\n", operatori[nr].semn);
		}
		else
			if(nr>=1)
			{
				i++;
				printf("%c= ",E[i]);
				scanf("%d", &v);
				n++;
				operanzi[n] = v;
				
				if (ch == '-') {
					operanzi[(n - 1)] = operanzi[n - 1] - operanzi[n];
					//printf("%d= %d-%d \n",operanzi[(n - 1)],operanzi[n - 1],operanzi[n]);
				}
			if (ch == '+')
			{
				operanzi[(n - 1)] = operanzi[n - 1] + operanzi[n];
				//printf("S-a efectuat operatia.\n");
			}
			if (ch == '*')
				operanzi[(n - 1)] = operanzi[n - 1] * operanzi[n];
			if (ch == '/')
				operanzi[(n - 1)] = operanzi[n - 1] / operanzi[n];
			n--;
			nr--;
		}
	}
}
int main()
{
	//printf("%s\n", __FILE__);
	printf("Expresia este: ");
	scanf("%s", E);
	for (i = 0; i <= strlen(E); i++)
		creare_stive(E[i]);
	while (nr >= 0)
	{
		//printf("Semnul este: %c \n", operatori[nr].semn);
		switch (operatori[nr].semn) {
		case '+':
			operanzi[(n - 1)] = operanzi[n - 1] + operanzi[n];
			//printf("S-a efectuat operatia.\n");
			break;
		case '-':
			operanzi[(n - 1)] = operanzi[n - 1] - operanzi[n];
			break;
		case '*':
			operanzi[(n - 1)] = operanzi[n - 1] * operanzi[n];
			break;
		case '/':
			operanzi[(n - 1)] = operanzi[n - 1] / operanzi[n];
			break;
		default: printf("Eroare!\n");
		}
			n--;
			nr--;
		
	}
	
	printf("Rezultatul e: %d ", operanzi[n]);
	return 0;
}
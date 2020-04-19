#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char linha[1000];

void ReadAqr()
{
	int i=0;
	FILE *f = fopen("numeros.csv", "rt");
	char Line[100000];
	while (fgets(Line, sizeof(Line), f))
	{
	
		printf("%i - Item = %s \n",i, strtok(Line, ","));
		i++;
	}
}

void BubbleSort(int vet[], int count)
{
	int aux = 0;

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (vet[j] > vet[j + 1])
			{
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}
	}
}

int main()
{

	ReadAqr();

	int vet[10] = {4, 5, 7, 3, 5, 78, 43, 34, 23, 20};

	return (0);
}
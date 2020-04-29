#include <stdio.h>
#include <stdlib.h>
/* Matheus Valdir e Patrick*/
typedef unsigned char bool;

bool false = 0, true = 1;
int count = 0;

void *readFile()
{
    char num;
    char buffer[10];
    int buffercount = 0;
    static int numbers[10000000];

    FILE *file = fopen("numeros.csv", "r");

    if (!file)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(-1);
    }
    while (true)
    {
        if ((num = fgetc(file)) == EOF)
        {
            buffer[buffercount] = '\0';
            numbers[count] = atoi(buffer);
            count++;
            break;
        }
        if (num == ',')
        {
            buffer[buffercount] = '\0';
            numbers[count] = atoi(buffer);
            count++;
            buffercount = 0;
        }
        else if (buffercount < 10)
        {
            buffer[buffercount] = num;
            buffercount++;
        }
    }
    fclose(file);
    return numbers;
}

int main()
{
    int *vet;
    int op = 0;

    printf("----------------------ORDENADOR DE NUMEROS------------------------");
    printf("\nDigite 1 para ler o arquivo com os numeros:\nDigite 0 para sair: ");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        printf("\nCarregando arquivo...");
        vet = readFile();
        printf("\n %i numeros foram carregados para a memoria com sucesso! ", count);
    case 0:
        exit(0);

    default:
        break;
    }
}

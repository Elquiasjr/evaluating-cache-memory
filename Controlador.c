#include <stdio.h>
#include <stdlib.h>


void criaNum(char *nomeArquivo){
    FILE *arq;
    arq = fopen(nomeArquivo, "wb");
    int i;
    for(i=1000; i<=23000; i+=100){
            fwrite(&i, sizeof(int), 1, arq);
    }
    fclose(arq);
} 


int leNum(char *nomeArquivo){
    FILE *arq;
    int *elemento = NULL, quantidade = 0;
    arq = fopen(nomeArquivo, "rb");
    elemento = (int *)malloc(quantidade * sizeof(int));
    
    if (arq == NULL) {
    //Sai do programa caso o arquivo não tenha sido aberto
    printf("Erro ao tentar abrir o arquivo.\n");
    exit(1);
    }
    //Efetua a contagem de elementos lendo o arquivo
     while (fread(elemento, 4, 1, arq) == 1){
        //printf("%d\n", *elemento);
        if (elemento != NULL) {
        quantidade++;
      }
    }

    //Fecha o arquivo
    fclose(arq);
    free(elemento);
    //Exibe a quantidade de linhas
    printf("Quantidade de elementos: %d\n",quantidade);
    return quantidade;
}


int main(){
    criaNum("Verynums.bin");
    int tamanho = leNum("Verynums.bin"), elemento = 0;

    system("rm tempo.txt");

    FILE *arquivo = fopen("tempo.txt", "a+b");
    fprintf(arquivo, "%d\n",tamanho);
    fclose(arquivo);

    FILE *arq = fopen("Verynums.bin", "rb");
    char var[100];

        while(fread(&elemento, 4, 1, arq) == 1){
            //printf("%d\n", elemento);
            sprintf(var, "gcc main.c && ./a.out %d", elemento); 
            system(var); //system recebe valor de var
        }
    
    system("octave");
    fclose(arq);
    return 0;
}
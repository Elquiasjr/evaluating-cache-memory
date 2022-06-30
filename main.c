#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

struct pix {
    unsigned int r, g, b;
};

typedef struct pix pix;

pix *color;

int main(int argc, char *argv[]){
    
    int TAM = atoi(argv[1]);
    //int TAM = 1000;

    color = (pix *) malloc(TAM * TAM *sizeof(pix));

    double ti,tf,tempo1; //ti = tempo1 inicial // tf = tempo1 final
    ti = tf = tempo1 = 0;
    struct timeval tempo_inicio, tempo_fim;
    gettimeofday(&tempo_inicio,NULL);

    int i,j;
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            color[i* TAM + j].r = (
            color[i* TAM + j].r +
            color[i* TAM + j].g +
            color[i* TAM + j].b 
            )/3;
    }
    }

    gettimeofday(&tempo_fim,NULL);
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
    tempo1 = (tf - ti)/1000;
    printf("Tempo1 gasto em milissegundos %.3f\n",tempo1);

    //função 2

    double tempo2; //ti = tempo inicial // tf = tempo final
    ti = tf = tempo2 = 0;
    struct timeval tempo_inicio2, tempo_fim2;
    gettimeofday(&tempo_inicio2,NULL);

    i=j=0;
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            color[j* TAM + i].r = (
            color[j* TAM + i].r +
            color[j* TAM + i].g +
            color[j* TAM + i].b 
            )/3;
    }
    }

    gettimeofday(&tempo_fim2,NULL);
    tf = (double)tempo_fim2.tv_usec + ((double)tempo_fim2.tv_sec * (1000000.0));
    ti = (double)tempo_inicio2.tv_usec + ((double)tempo_inicio2.tv_sec * (1000000.0));
    tempo2 = (tf - ti)/1000;
    printf("Tempo2 gasto em milissegundos %.3f\n",tempo2);

    //termino da função 2

    //tempo em um arquivo
    FILE *arq;
    arq = fopen("tempo.txt", "a+b");
    fprintf(arq, "%d %.3f %.3f\n", TAM, tempo1, tempo2);
    fclose(arq);

    
    return 0;
}
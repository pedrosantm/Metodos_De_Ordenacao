#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "op.h"


typedef struct aluno{
    char nome[10];
    int matricula;
    char curso[10];
    double cf;
    int periodo;
}aluno;

typedef struct {
    int comparacoes;
    int movimentacoes;
} Contadores;

int main(){
    
    aluno vet_1000_aleatorio[1000];
    aluno vet_1000_crescente[1000];
    aluno vet_1000_decrescente[1000];
    
    aluno vet_10000_aleatorio[10000];
    aluno vet_10000_crescente[10000];
    aluno vet_10000_decrescente[10000];
    
    aluno vet_100000_aleatorio[100000];
    aluno vet_100000_crescente[100000];
    aluno vet_100000_decrescente[100000];
    
    aluno vet_200000_aleatorio[200000];
    aluno vet_200000_crescente[200000];
    aluno vet_200000_decrescente[200000];



    //preenchendo os vetores

    //aleatorios
    preenche_aleatorio(vet_1000_aleatorio, 1000);
    preenche_aleatorio(vet_10000_aleatorio, 10000);
    preenche_aleatorio(vet_10000_aleatorio, 10000);
    preenche_aleatorio(vet_200000_aleatorio, 2000);


    //crescente
    preenche_crescente(vet_1000_crescente, 1000);
    preenche_crescente(vet_10000_crescente, 10000);
    preenche_crescente(vet_10000_crescente, 10000);
    preenche_crescente(vet_200000_crescente, 2000);


    //decrescente
    preenche_decrescente(vet_1000_decrescente, 1000);
    preenche_decrescente(vet_10000_decrescente, 10000);
    preenche_decrescente(vet_10000_decrescente, 10000);
    preenche_decrescente(vet_200000_decrescente, 2000);




    clock_t inicio, fim;
    double tempo_gasto;

    Contadores contSelect = {0, 0};
    Contadores contInsert = {0, 0};
    Contadores contMerge = {0, 0};
    int comparacoes = 0;
    int movimentacoes = 0;

    ////// vetor 1000///////////////

    ///////Vetor 1000 Aleatório 
    for(int i=0; i<10; i++){
        inicio = clock();
        selectSortAluno(vet_1000_aleatorio, 1000, &contSelect);
        fim = clock();
        tempo_gasto += (double)(fim - inicio)/10 / CLOCKS_PER_SEC;
        comparacoes +=contSelect.comparacoes/10;
        movimentacoes +=contSelect.movimentacoes/10;
    }
    printf("Vetor 1000 Aleatorio, SelectSort\nComparacoes - %d\nMovimentacoes - %d\nTempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);
    comparacoes = 0;
    movimentacoes = 0;



    inicio = clock();
    insertSortAluno(vet_1000_aleatorio, 1000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Aleatorio - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_1000_aleatorio, 0, 999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Aleatorio - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    /////Vetor 1000 Crescente 
    inicio = clock();
    selectSortAluno(vet_1000_crescente, 1000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Crescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    inicio = clock();
    insertSortAluno(vet_1000_crescente, 1000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Crescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);


    inicio = clock();
    mergeSortAluno(vet_1000_crescente, 0, 999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Crescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    //////Vetor 1000 Decrescente
    inicio = clock();
    selectSortAluno(vet_1000_decrescente, 1000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Decrescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

   
    inicio = clock();
    insertSortAluno(vet_1000_decrescente, 1000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Decrescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_1000_decrescente, 0, 999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Decrescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);







    /////// vetor 10000///////////////////

    ////// Vetor 10000 aleatorio
    for(int i = 0; i<10; i++){
        inicio = clock();
        selectSortAluno(vet_10000_aleatorio, 10000, &contSelect);
        fim = clock();
        tempo_gasto += (double)(fim - inicio)/10 / CLOCKS_PER_SEC;
        comparacoes +=contSelect.comparacoes/10;
        movimentacoes +=contSelect.movimentacoes/10;
    }
     printf("Vetor 10000 Aleatorio - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);
     comparacoes = 0;
     movimentacoes = 0;
    
    inicio = clock();
    insertSortAluno(vet_10000_aleatorio, 10000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 10000 Aleatorio - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_10000_aleatorio, 0, 9999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 10000 Aleatorio - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    ///// Vetor 10000 Crescente 
    inicio = clock();
    selectSortAluno(vet_10000_crescente, 10000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 10000 Crescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    // Vetor 10000 Crescente - InsertSort
    inicio = clock();
    insertSortAluno(vet_10000_crescente, 10000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 10000 Crescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_10000_crescente, 0, 9999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 10000 Crescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    /////Vetor 10000 Decrescente 
    inicio = clock();
    selectSortAluno(vet_10000_decrescente, 10000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 10000 Decrescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

  
    inicio = clock();
    insertSortAluno(vet_10000_decrescente, 10000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 10000 Decrescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    inicio = clock();
    mergeSortAluno(vet_10000_decrescente, 0, 9999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 10000 Decrescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);




    
    
    /////// vetor 100000///////////////////


    // Vetor 100000 Aleatório 
    for(int i = 0; i<10; i++){
        inicio = clock();
        selectSortAluno(vet_100000_aleatorio, 100000, &contSelect);
        fim = clock();
        tempo_gasto += (double)(fim - inicio)/10 / CLOCKS_PER_SEC;
        comparacoes +=contSelect.comparacoes/10;
        movimentacoes +=contSelect.movimentacoes/10;
    }
    printf("Vetor 100000 Aleatorio - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);
    comparacoes = 0;
    movimentacoes = 0;

    
    inicio = clock();
    insertSortAluno(vet_100000_aleatorio, 100000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 100000 Aleatorio - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_100000_aleatorio, 0, 99999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 100000 Aleatorio - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    // Vetor 100000 Crescente 
    inicio = clock();
    selectSortAluno(vet_100000_crescente, 100000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 100000 Crescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    
    inicio = clock();
    insertSortAluno(vet_100000_crescente, 100000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 100000 Crescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

   
    inicio = clock();
    mergeSortAluno(vet_100000_crescente, 0, 99999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 100000 Crescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    // Vetor 100000 Decrescente 
    inicio = clock();
    selectSortAluno(vet_100000_decrescente, 100000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 100000 Decrescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    
    inicio = clock();
    insertSortAluno(vet_100000_decrescente, 100000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 100000 Decrescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

   
    inicio = clock();
    mergeSortAluno(vet_100000_decrescente, 0, 99999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 100000 Decrescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);




    ///////vetor 200000//////


    // Vetor 200000 Aleatório 
    for(int i=0; i<10; i++){
    inicio = clock();
    selectSortAluno(vet_200000_aleatorio, 200000, &contSelect);
    fim = clock();
    tempo_gasto += (double)(fim - inicio) / CLOCKS_PER_SEC;
    comparacoes +=contSelect.comparacoes/10;
    movimentacoes +=contSelect.movimentacoes/10;
    }
    printf("Vetor 200000 Aleatorio - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);
    comparacoes = 0;
    movimentacoes = 0;

   
    inicio = clock();
    insertSortAluno(vet_200000_aleatorio, 200000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 200000 Aleatorio - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);


    inicio = clock();
    mergeSortAluno(vet_200000_aleatorio, 0, 199999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 200000 Aleatorio - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    // Vetor 200000 Crescente 
    inicio = clock();
    selectSortAluno(vet_200000_crescente, 200000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 200000 Crescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

   
    inicio = clock();
    insertSortAluno(vet_200000_crescente, 200000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 200000 Crescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_200000_crescente, 0, 199999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 200000 Crescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    // Vetor 200000 Decrescente 
    inicio = clock();
    selectSortAluno(vet_200000_decrescente, 200000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 200000 Decrescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    
    inicio = clock();
    insertSortAluno(vet_200000_decrescente, 200000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 200000 Decrescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_200000_decrescente, 0, 199999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 200000 Decrescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);





    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

void preenche_aleatorio(aluno *vetor, int tamanho);
void preenche_crescente(aluno *vetor, int tamanho);
void preenche_decrescente(aluno *vetor, int tamanho);
int compararAlunos(const void *a, const void *b);
void selectSortAluno(aluno *vetor, int tamanho, Contadores *cont);
void insertSortAluno(aluno *vetor, int tamanho, Contadores *cont);
void mergeSortAluno(aluno *vetor, int inicio, int fim, Contadores *cont);
void merge(aluno *vetor, int inicio, int meio, int fim, Contadores *cont);





int main(){

    FILE * file;
    file = fopen("C:\\Users\\pedro\\Desktop\\ordenacao.txt", "w");
    
    
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
    int op;
    Contadores contSelect = {0, 0};
    Contadores contInsert = {0, 0};
    Contadores contMerge = {0, 0};
    Contadores contquick = {0, 0};
    int comparacoes = 0;
    int movimentacoes = 0;

    ////// vetor 1000///////////////

    ///////Vetor 1000 Aleatório 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_1000_aleatorio, 1000);
    }
    for(int i=0; i<10; i++){
        inicio = clock();
        selectSortAluno(vet_1000_aleatorio, 1000, &contSelect);
        fim = clock();
        tempo_gasto += (double)(fim - inicio)/10 / CLOCKS_PER_SEC;
        comparacoes +=contSelect.comparacoes/10;
        movimentacoes +=contSelect.movimentacoes/10;
    }
    fprintf(file,"Vetor 1000 Aleatorio, SelectSort\nComparacoes - %d\nMovimentacoes - %d\nTempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);
   



    inicio = clock();
    insertSortAluno(vet_1000_aleatorio, 1000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 1000 Aleatorio - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_1000_aleatorio, 0, 999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 1000 Aleatorio - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos ordenação\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_1000_aleatorio, 1000);
    }

    /////Vetor 1000 Crescente 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_1000_crescente, 1000);
    }
    inicio = clock();
    selectSortAluno(vet_1000_crescente, 1000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 1000 Crescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    inicio = clock();
    insertSortAluno(vet_1000_crescente, 1000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 1000 Crescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);


    inicio = clock();
    mergeSortAluno(vet_1000_crescente, 0, 999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 1000 Crescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_1000_crescente, 1000);
    }

    //////Vetor 1000 Decrescente
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_1000_decrescente, 1000);
    }
    inicio = clock();
    selectSortAluno(vet_1000_decrescente, 1000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 1000 Decrescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

   
    inicio = clock();
    insertSortAluno(vet_1000_decrescente, 1000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Vetor 1000 Decrescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_1000_decrescente, 0, 999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 1000 Decrescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_1000_decrescente, 1000);
    }







    /////// vetor 10000///////////////////

    ////// Vetor 10000 aleatorio
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_10000_aleatorio, 10000);
    }
    comparacoes = 0;
    movimentacoes = 0;
    for(int i = 0; i<10; i++){
        inicio = clock();
        selectSortAluno(vet_10000_aleatorio, 10000, &contSelect);
        fim = clock();
        tempo_gasto += (double)(fim - inicio)/10 / CLOCKS_PER_SEC;
        comparacoes +=contSelect.comparacoes/10;
        movimentacoes +=contSelect.movimentacoes/10;
    }
     fprintf(file, "Vetor 10000 Aleatorio - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);
     
    
    inicio = clock();
    insertSortAluno(vet_10000_aleatorio, 10000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 10000 Aleatorio - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_10000_aleatorio, 0, 9999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 10000 Aleatorio - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_10000_aleatorio, 1000);
    }

    ///// Vetor 10000 Crescente 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_10000_crescente, 10000);
    }
    inicio = clock();
    selectSortAluno(vet_10000_crescente, 10000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 10000 Crescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    
    inicio = clock();
    insertSortAluno(vet_10000_crescente, 10000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 10000 Crescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_10000_crescente, 0, 9999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 10000 Crescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_10000_crescente, 10000);
    }


    /////Vetor 10000 Decrescente 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_10000_decrescente, 10000);
    }
    inicio = clock();
    selectSortAluno(vet_10000_decrescente, 10000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 10000 Decrescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

  
    inicio = clock();
    insertSortAluno(vet_10000_decrescente, 10000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 10000 Decrescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    inicio = clock();
    mergeSortAluno(vet_10000_decrescente, 0, 9999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 10000 Decrescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_10000_decrescente, 10000);
    }





    
    
    /////// vetor 100000///////////////////


    // Vetor 100000 Aleatório 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_100000_aleatorio, 100000);
    }
    comparacoes = 0;
    movimentacoes = 0;
    for(int i = 0; i<10; i++){
        inicio = clock();
        selectSortAluno(vet_100000_aleatorio, 100000, &contSelect);
        fim = clock();
        tempo_gasto += (double)(fim - inicio)/10 / CLOCKS_PER_SEC;
        comparacoes +=contSelect.comparacoes/10;
        movimentacoes +=contSelect.movimentacoes/10;
    }
    fprintf(file, "Vetor 100000 Aleatorio - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);
    

    
    inicio = clock();
    insertSortAluno(vet_100000_aleatorio, 100000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 100000 Aleatorio - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_100000_aleatorio, 0, 99999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 100000 Aleatorio - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_100000_aleatorio, 100000);
    }

    // Vetor 100000 Crescente 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_100000_crescente, 100000);
    }
    inicio = clock();
    selectSortAluno(vet_100000_crescente, 100000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprint(file, "Vetor 100000 Crescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    
    inicio = clock();
    insertSortAluno(vet_100000_crescente, 100000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 100000 Crescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

   
    inicio = clock();
    mergeSortAluno(vet_100000_crescente, 0, 99999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 100000 Crescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_100000_crescente, 100000);
    }


    // Vetor 100000 Decrescente 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_100000_decrescente, 100000);
    }
    inicio = clock();
    selectSortAluno(vet_100000_decrescente, 100000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 100000 Decrescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    
    inicio = clock();
    insertSortAluno(vet_100000_decrescente, 100000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 100000 Decrescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

   
    inicio = clock();
    mergeSortAluno(vet_100000_decrescente, 0, 99999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 100000 Decrescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_100000_decrescente, 100000);
    }




    ///////vetor 200000//////


    // Vetor 200000 Aleatório 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_200000_aleatorio, 200000);
    }
    comparacoes = 0;
    movimentacoes = 0;
    for(int i=0; i<10; i++){
    inicio = clock();
    selectSortAluno(vet_200000_aleatorio, 200000, &contSelect);
    fim = clock();
    tempo_gasto += (double)(fim - inicio) / CLOCKS_PER_SEC;
    comparacoes +=contSelect.comparacoes/10;
    movimentacoes +=contSelect.movimentacoes/10;
    }
    fprintf(file, "Vetor 200000 Aleatorio - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);
    
   
    inicio = clock();
    insertSortAluno(vet_200000_aleatorio, 200000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Aleatorio - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);


    inicio = clock();
    mergeSortAluno(vet_200000_aleatorio, 0, 199999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Aleatorio - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);

    inicio = clock();
    quickSortAluno(vet_200000_aleatorio, 0, 199999, &contquick);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Aleatorio - QuickSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contquick.comparacoes, contquick.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_200000_aleatorio, 200000);
    }

    // Vetor 200000 Crescente 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_200000_crescente, 200000);
    }
    inicio = clock();
    selectSortAluno(vet_200000_crescente, 200000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Crescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

   
    inicio = clock();
    insertSortAluno(vet_200000_crescente, 200000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Crescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_200000_crescente, 0, 199999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Crescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_200000_crescente, 200000);
    }

    // Vetor 200000 Decrescente 
    printf("1-Ver o vetor antes da ordenacao\n2-Ordenar");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_200000_decrescente, 200000);
    }
    inicio = clock();
    selectSortAluno(vet_200000_decrescente, 200000, &contSelect);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Decrescente - SelectSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contSelect.comparacoes, contSelect.movimentacoes, tempo_gasto);

    
    inicio = clock();
    insertSortAluno(vet_200000_decrescente, 200000, &contInsert);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Decrescente - InsertSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contInsert.comparacoes, contInsert.movimentacoes, tempo_gasto);

    
    inicio = clock();
    mergeSortAluno(vet_200000_decrescente, 0, 199999, &contMerge);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    fprintf(file, "Vetor 200000 Decrescente - MergeSort: Comparacoes - %d, Movimentacoes - %d, Tempo - %f segundos\n", contMerge.comparacoes, contMerge.movimentacoes, tempo_gasto);
    printf("1-Ver o vetor apos  ordenacao\n2-Prosseguir");
    scanf("%d", &op);
    if(op==1){
        print_vetor(vet_200000_decrescente, 200000);
    }

    fclose(file);



    return 0;
}


void preenche_aleatorio(aluno *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++){ 
         for (int j = 0; j < 10; j++) {
            //preenche o nome com letras aleatorias
        vetor->nome[j] = rand() % 26 + 'A';
    }
         vetor->nome[9] = '\0'; 
        
        // Preenchendo a matrícula com valores aleatórios
        vetor[i].matricula = rand() % 10000 + 1; 
        
        // Preenchendo o curso aleatoriamente (apenas como exemplo, você pode mudar isso)
        for (int i = 0; i < tamanho; i++) {
         for (int j = 0; j < 10; j++) {
        vetor->curso[j] = rand() % 26 + 'A';
    }
         vetor->curso[9] = '\0'; 
        
        // Preenchendo o coeficiente de forma aleatória
        vetor[i].cf = ((double)rand() / RAND_MAX) * 10.0;
        
        // Preenchendo o período com valores aleatórios
        vetor[i].periodo = rand() % 10 + 1; 
    }
  }

}



void preenche_crescente(aluno *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
         for (int j = 0; j < 10; j++) {
            //preenche o nome com letras aleatorias
        vetor->nome[j] = rand() % 26 + 'A';
    }
         vetor->nome[9] = '\0'; 

        // Preenchendo a matrícula 
        vetor[i].matricula = i + 1;

        // Preenchendo o curso sequencialmente 
         for (int j = 0; j < 10; j++) {
            //preenche o nome com letras aleatorias
        vetor->curso[j] = rand() % 26 + 'A';
    }
         vetor->curso[9] = '\0'; 

        // Preenchendo o coeficiente de forma ordenada
        vetor[i].cf = (double)i / 10.0; 

        // Preenchendo o período sequencialmente
        vetor[i].periodo = (i % 10) + 1;
    }
}



void preenche_decrescente(aluno *vetor, int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            //preenche o nome com letras aleatorias
        vetor->nome[j] = rand() % 26 + 'A';
    }
         vetor->nome[9] = '\0'; 

        // Preenchendo a matrícula com valores decrescentes
        vetor[i].matricula = tamanho - i;

        // Preenchendo o curso de forma decrescente 
        for (int j = 0; j < 10; j++) {
            //preenche o nome com letras aleatorias
        vetor->curso[j] = rand() % 26 + 'A';
    }
         vetor->curso[9] = '\0'; 

        // Preenchendo o coeficiente de forma decrescente
        vetor[i].cf = (double)(tamanho - i) / 10.0; 

        // Preenchendo o período de forma decrescente
        vetor[i].periodo = ((tamanho - i) % 10) + 1; 
    }
}




/// algoritimos de ordenação////



int compararAlunos(const void *a, const void *b) {
    const aluno *alunoA = (const aluno *)a;
    const aluno *alunoB = (const aluno *)b;

    //nome
    int cmp = strcmp(alunoA->nome, alunoB->nome);
    if (cmp != 0) return cmp;

    //matrícula
    if (alunoA->matricula < alunoB->matricula) 
        return -1;
    if (alunoA->matricula > alunoB->matricula) 
        return 1;

    //curso
    cmp = strcmp(alunoA->curso, alunoB->curso);
    if (cmp != 0) return cmp;

    //cf
    if (alunoA->cf < alunoB->cf)
         return -1;
    if (alunoA->cf > alunoB->cf)
         return 1;

    //período
    if (alunoA->periodo < alunoB->periodo) 
        return -1;
    if (alunoA->periodo > alunoB->periodo)
         return 1;

    return 0; 
}



//SelectSort
void selectSortAluno(aluno *vetor, int tamanho, Contadores *cont) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < tamanho; j++) {
            cont->comparacoes++; // Contabiliza uma comparação
            if (compararAlunos(&vetor[j], &vetor[min_index]) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            aluno temp;
            memcpy(&temp, &vetor[i], sizeof(aluno));
            memcpy(&vetor[i], &vetor[min_index], sizeof(aluno));
            memcpy(&vetor[min_index], &temp, sizeof(aluno));
            cont->movimentacoes += 3; // Contabiliza 3 movimentações (troca de elementos)
        }
    }
}


//insertsort
void insertSortAluno(aluno *vetor, int tamanho, Contadores *cont) {
    for (int i = 1; i < tamanho; i++) {
        aluno chave;
        memcpy(&chave, &vetor[i], sizeof(aluno));
        int j = i - 1;
        while (j >= 0 && compararAlunos(&vetor[j], &chave) > 0) {
            cont->comparacoes++; // Contabiliza uma comparação
            memcpy(&vetor[j + 1], &vetor[j], sizeof(aluno));
            j = j - 1;
            cont->movimentacoes++; // Contabiliza uma movimentação
        }
        memcpy(&vetor[j + 1], &chave, sizeof(aluno));
        cont->movimentacoes++; // Contabiliza uma movimentação
    }
}



//mergesort
void mergeSortAluno(aluno *vetor, int inicio, int fim, Contadores *cont) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSortAluno(vetor, inicio, meio, cont);
        mergeSortAluno(vetor, meio + 1, fim, cont);
        merge(vetor, inicio, meio, fim, cont);
    }
}

void merge(aluno *vetor, int inicio, int meio, int fim, Contadores *cont) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    aluno L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        memcpy(&L[i], &vetor[inicio + i], sizeof(aluno));
    for (int j = 0; j < n2; j++)
        memcpy(&R[j], &vetor[meio + 1 + j], sizeof(aluno));

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        cont->comparacoes++; // Contabiliza uma comparação
        if (compararAlunos(&L[i], &R[j]) <= 0) {
            memcpy(&vetor[k], &L[i], sizeof(aluno));
            i++;
        } else {
            memcpy(&vetor[k], &R[j], sizeof(aluno));
            j++;
        }
        k++;
        cont->movimentacoes++; // Contabiliza uma movimentação
    }

    while (i < n1) {
        memcpy(&vetor[k], &L[i], sizeof(aluno));
        i++;
        k++;
        cont->movimentacoes++; // Contabiliza uma movimentação
    }

    while (j < n2) {
        memcpy(&vetor[k], &R[j], sizeof(aluno));
        j++;
        k++;
        cont->movimentacoes++; // Contabiliza uma movimentação
    }
}


void print_vetor(aluno *vetor, int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("Elemento %d: Matricula-%d, nome-%c, curso-%c, Cf-%c, periodo-%d\n", i, vetor[i].matricula, vetor[i].nome, vetor[i].curso, vetor[i].curso, vetor[i].cf, vetor[i].periodo);
    }
    return;
}

void quickSortAluno(aluno vetor[], int esquerda, int direita, Contadores *cont) {
    if (direita - esquerda > 0) {
        int pivoIndex = encontrarPivo(vetor, esquerda, direita);
        int i = esquerda;
        int j = direita - 1;

        while (1) {
            while (compararAlunos(&vetor[++i], &vetor[pivoIndex]) < 0) {
                cont->comparacoes++; // Contabiliza uma comparação
            }
            while (compararAlunos(&vetor[--j], &vetor[pivoIndex]) > 0) {
                cont->comparacoes++; // Contabiliza uma comparação
            }

            if (i < j) {
                trocar(&vetor[i], &vetor[j]);
                cont->movimentacoes++; // Contabiliza uma movimentação
            } else {
                break;
            }
        }

        trocar(&vetor[i], &vetor[direita - 1]);
        cont->movimentacoes++; // Contabiliza uma movimentação

        quickSortAluno(vetor, esquerda, i - 1, cont);
        quickSortAluno(vetor, i + 1, direita, cont);
    }
}

////

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[10];
    int matricula;
    char curso[10];
    double cf;
    int periodo;
}aluno;



int main(){
    
    aluno vet_1000_aleatorio[1000];
    aluno vet_1000_crescente[1000];
    aluno vet_1000_decrescente[1000];
    
    aluno vet_10000_aleatorio[10000];
    aluno vet_10000_crescente[10000];
    aluno vet_10000_decrescente[10000];
    
    aluno vet_100000_aleatorio[100000];
    aluno vet_100000crescente[100000];
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



void preenche_Ordenado(aluno *vetor, int tamanho) {
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



void preencher_decrescente(aluno *vetor, int tamanho) {
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



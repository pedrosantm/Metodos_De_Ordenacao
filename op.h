#include <stdio.h>
#include <stdlib.h>
#include <time.h>





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

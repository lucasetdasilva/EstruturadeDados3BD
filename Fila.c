#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *prox;
}No;

typedef struct No celula;

void enfileirar(celula **in, celula **fi, int conteudo){
    
    celula *novo = malloc(sizeof(celula));
    
    novo -> valor = conteudo;
    novo -> prox = NULL;
    
    if((*in) == NULL){
        (*in) = (*fi) = novo;
        printf("Paciente adicionado\n\n");
        
        
    }else{
        (*fi) -> prox = novo;
        *fi = novo;
        printf("Paciente adicionado\n\n");
    }
}

int desenfileirar(celula **in, celula **fi){
    
    celula *remover = *in;
    
    if(remover == NULL){
        return NULL;
        
        
    }else{
        int conteudo = remover -> valor;
        (*in) = remover -> prox;
        free(remover);
        return conteudo;
        printf("\n\n");
    
    }
    
}

void mostrarFila(celula **f){
    
    celula *aux = (*f);
    
    if(aux == NULL)
        printf("TODOS OS PACIENTES FORAM ATENDIDOS\n\n");
    
    printf("\n");
    while(aux != NULL){
        printf("%d\n", aux -> valor);
        aux = aux -> prox;
        
    }
    
}

void main()
{
    celula *inicio, *fim;
    inicio = fim = NULL;
    
    int opcao, valor;
    
    do{
        printf("BEM-VINDO(A) AO HOSPITAL MUNICIPAL\n");
        printf("O que deseja fazer ?");
        printf("\n\t0 - Sair\n\t1 - Adicionar RA de paciente para atendimento\n\t2 - Remover paciente que já foi atendido\n\t3 - Mostrar Pacientes em espera\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            
            case 1:
                printf("Digite o RA do paciente: ");
                scanf("%d",&valor);
                enfileirar(&inicio,&fim,valor);
                break;
            
            case 2:
               int valor = desenfileirar(&inicio,&fim);
               printf("Paciente de RA %d foi atendido", valor);
               break;
            
            case 3:
                mostrarFila(&inicio);
                break;
            
            
            default:
                if(opcao != 0)
                    printf("Opção Inválida");
        }
        
    } while(opcao != 0);
    

}


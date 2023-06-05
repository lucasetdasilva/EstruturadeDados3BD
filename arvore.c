#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel *esquerda;
    struct cel *direita;
};

typedef struct cel no;
typedef no *arvore;

arvore inserir(arvore raiz, no *novo){
    no *atual, *pai;
    
    if (raiz == NULL) return novo;

    atual = raiz;
    
    while(atual != NULL){
        pai = atual;
        if(atual -> conteudo > novo -> conteudo) atual = atual -> esquerda;
        else atual = atual -> direita;
        
    }
    if(pai -> conteudo > novo -> conteudo) pai -> esquerda = novo;
    else pai -> direita = novo;
    
    return raiz;
    
}

void Erd(arvore r) {
    if (r != NULL) {
        Erd (r->esquerda);
        printf ("%d\n", r->conteudo);
        Erd (r->direita);
    }
}

arvore removerRaiz(arvore raiz){
    
    no *p, *q;
    
    if(raiz != NULL){
        
        if(raiz -> esquerda == NULL) q = raiz -> direita;
    
        else if(raiz -> esquerda == NULL && raiz -> direita == NULL) q = NULL;

        else{
            p = raiz; q = raiz -> esquerda;
        
            while(q -> direita != NULL){
                p = q; q = q -> direita;
            }
        
            if(p != raiz){
                p -> direita = q -> esquerda;
                q -> esquerda = raiz -> esquerda;
            }
        
            q -> direita = raiz -> direita;
    }
    free(raiz);
    return q;    
        
    } else{
        printf("Árvore vazia\n");
        return NULL;
        
    }
    
    
    
}


void main(){
    
 arvore arvorebinaria = NULL;
 
 int valor,opcao;    
 do{
        printf("O que deseja fazer ?");
        printf("\n\t0 - Sair\n\t1 - Inserir nó a árvore\n\t2 - Remover nó da árvore\n\t3 - Percorrer árvore\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            
            case 1:
                printf("Digite o valor do nó: ");
                scanf("%d",&valor);
                no *novo = malloc(sizeof(no));
                novo -> conteudo = valor;
                novo -> esquerda = NULL;
                novo -> direita = NULL;
 
                arvorebinaria = inserir(arvorebinaria,novo);
                break;
            
            case 2:
               arvorebinaria = removerRaiz(arvorebinaria);
               break;
            
            case 3:
                Erd(arvorebinaria); 
                break;
            
            
            default:
                if(opcao != 0)
                    printf("Opção Inválida");
        }
        
    } while(opcao != 0);   
}

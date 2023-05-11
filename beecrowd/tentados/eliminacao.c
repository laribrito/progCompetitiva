#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int indice;
    struct no *prox;
    struct no *ant;
} Lista;

void insereInicioListaDuploEncad(Lista** L, int I, Lista** fim){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->indice = I;
    novo->prox = *L;
    if(novo->prox!=NULL) novo->prox->ant = novo;
    else {
        novo->ant = NULL;
        *fim = novo; 
    }
    *L=novo;
}

// código clássico de eliminação com lista encadeada

int main(void){
    int qtdTotalAmigos, passo, qtd;
    scanf("%d", &qtd);
    for(int y=1; y<=qtd;y++){
        scanf("%d %d", &qtdTotalAmigos, &passo);
        Lista *lista = NULL;
        Lista *cauda = NULL;
        //inicializa a roda de amigos
        for(int x=qtdTotalAmigos; x>=1; x--) insereInicioListaDuploEncad(&lista, x, &cauda);
        lista->ant = cauda;
        cauda->prox = lista;
        
        // executa as eliminações
        int qtdAtual = qtdTotalAmigos, auxPasso = 1;
        Lista* nav;
        for(nav= lista; nav!=nav->prox; ){
            if(auxPasso == passo){
                Lista* excluido=nav;
                nav->ant->prox = nav->prox;     
                nav->prox->ant = nav->ant;               
                auxPasso=1;
                qtdAtual--;
                nav = nav->prox;
                free(excluido);
            } else {
                auxPasso++;                
                nav = nav->prox;
            }
        }
        printf("Case %d: %d\n", y, nav->indice);
    }
    return 0;
}
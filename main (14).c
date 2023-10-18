#include <stdio.h>
#include <stdlib.h> 

typedef int TipoItem;

typedef struct No {
    TipoItem info;
    struct No *prox;
} Lista;

int vazia(Lista *l) {
    return (l == NULL);
}

void LimparLista(Lista *l) {
    if (l != NULL) {
        Lista *aux = l->prox;
        free(l);
        LimparLista(aux);
    }
}

void VerificarVazia(Lista *l) {
    if (vazia(l))
        printf("(%d) - LISTA VAZIA\n", vazia(l));
    else
        printf("(%d) - LISTA NÃO VAZIA", vazia(l));
}

Lista *Inserir(Lista *l, TipoItem info) {
    Lista *aux = (Lista *)malloc(sizeof(Lista));
    aux->info = info;
    aux->prox = l;
    return aux;
}

Lista *Remover(Lista *l, TipoItem info) {
    Lista *ant = l;
    Lista *p = l;

    while (p != NULL && p->info != info) {
        ant = p;
        p = p->prox;
    }

    if (p != NULL) {
        if (p == l)
            l = l->prox;
        else
            ant->prox = p->prox;
        free(p);
    } else
        printf("Elemento não encontrado!\n");

    return l;
}

void Imprimir(Lista *l) {
    printf("\nLista: ");
    while (l != NULL) {
        printf("%d ", l->info);
        l = l->prox;
    }
    printf("\n");
}

Lista *Inverter(Lista *l) {
    Lista *aux = NULL;

    while (l != NULL) {
        aux = Inserir(aux, l->info);
        l = l->prox;
    }

    return aux;
}

Lista *Concatenar(Lista *l1, Lista *l2) {
    Lista *aux = NULL, *resultado = NULL;

    while (l1 != NULL) {
        aux = Inserir(aux, l1->info);
        l1 = l1->prox;
    }

    while (l2 != NULL) {
        aux = Inserir(aux, l2->info);
        l2 = l2->prox;
    }

    resultado = Inverter(aux);
    LimparLista(aux);
    aux = NULL;
    return resultado;
}

Lista *Intercalar(Lista *l1, Lista *l2) {
    Lista *aux = NULL, *resultado = NULL;

    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            aux = Inserir(aux, l1->info);
            l1 = l1->prox;
        }

        if (l2 != NULL) {
            aux = Inserir(aux, l2->info);
            l2 = l2->prox;
        }
    }
    resultado = Inverter(aux);
    LimparLista(aux);
    aux = NULL;
    return resultado;
}

int main() {
    Lista *l1 = NULL;
    Lista *l2 = NULL;
    Lista *l3 = NULL;
    Lista *l4 = NULL;
    Lista *l5 = NULL;

    VerificarVazia(l1);

    printf("=> Inserção de elementos na lista:");
    l1 = Inserir(l1, 1);
    l1 = Inserir(l1, 2);
    l1 = Inserir(l1, 3);
    l1 = Inserir(l1, 4);
    l1 = Inserir(l1, 5);

    Imprimir(l1);

    printf("\n=> Remoção de elementos na lista:");
    l1 = Remover(l1, 2);
    l1 = Remover(l1, 3);
    Imprimir(l1);

    printf("\n=> Inversão de elementos de uma lista:");
    l2 = Inverter(l1);
    Imprimir(l2);

    l3 = Inserir(l3, 1);
    l3 = Inserir(l3, 1);
    l3 = Inserir(l3, 3);
    l3 = Inserir(l3, 4);
    l3 = Inserir(l3, 5);
    Imprimir(l3);

    printf("\n=> Listas concatenadas:");
    l4 = Concatenar(l1, l3);
    Imprimir(l4);

    printf("\n=> Listas intercaladas:");
    l5 = Intercalar(l1, l3);
    Imprimir(l5);

    LimparLista(l1);
    LimparLista(l2);
    LimparLista(l3);
    LimparLista(l4);
    LimparLista(l5);
    l1 = NULL;
    l2 = NULL;
    l3 = NULL;
    l4 = NULL;
    l5 = NULL;
    VerificarVazia(l1);
    VerificarVazia(l2);
    VerificarVazia(l3);
    VerificarVazia(l4);
    VerificarVazia(l5);

    return 0;
}

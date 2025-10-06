#include <stdio.h>
#include <stdlib.h>

typedef struct PCB {
    unsigned int pid;
    unsigned int fila;

    int tr;
    int espera;

    struct PCB* prox; 
    struct PCB* ant; 
} PCB;

typedef struct Fila {
    PCB* inicio;
    PCB* fim;
} Fila;

#define NUM_FILAS 32
Fila escalonador[NUM_FILAS];


void new_escalonador(){
    for(int i=0; i< NUM_FILAS; i++){
        escalonador[i].inicio = null;
        escalonador[i].fim = null;
    }
}

PCB* criar_novo(unsignedint pid, unsigned int fila) {
    PCB* novo = (PCB*) malloc(sizeof(PCB));
    novo->pid = pid;
    novo->fila = fila;
    novo->tr = (rand() % 20) + 1;
    novo-> espera = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void add_fila(Fila* f, PCB* p) {
    p->prox = NULL;
    if(f->fim == NULL){
        f->inicio = f->fim = p;
    } else {
        f->fim->prox = p;
        p->ant = f->fim;
        f->fim = p;
    }
}

PCB* remover_inicio(Fila* f) {

    if (f->inicio == NULL) return NULL;
    PCB* p = f->inicio;
    f->inicio = p->prox;
    if (f->inicio != NULL)
        f->inicio->ant = NULL;
    else
        f->fim = NULL;
    return p;
}

int main () {
    new_escalonador();
    unsigned int pprid = 0;
    for (int i=0; i < 1000000; i++){
        pprid++;
        unsigned int fx = (rand() * 1000) & 0x1f;

        PCB* novo = criar_novo(pprid, fila_aleatoria);
        add_fila(&escalonador[fila_aleatoria], novo);
    }
    
    int ciclo = 0;

    while (1){
        if (ciclo>0 && ciclo %10 == 0) {
            for (int i = NUM_FILAS -1; i > 0; i--){
                PCB* p = remover_inicio(&escalonador[i]);
                if(p != NULL) {
                    p-> fila = i-1;
                    add_fila(&escalonador[i-1], p);
                }
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct PCB {
    unsigned int pid;
    unsigned int fila;
    int i; //contador de tempo restante

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
    for(int i=0; I< NUM_FILAS; i++){
        escalonador[i].inicio = null;
        escalonador[i].fim = null;
    }
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
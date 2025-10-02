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

#define Num_fila 32
Fila escalonador[Num_fila];

void new_escalonador(){
    for(int i=0; I< Num_fila; i++){
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

        PCB* novo = criar_novo(pprid, fila)
    }
    
}
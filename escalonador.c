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
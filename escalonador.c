#include <stdio.h>
#include <stdlib.h>

typedef struct PCB {
    unsigned int pid;
    unsigned int fila;
    int i; //contador de tempo restante
    struct PCB *p; //ponteiro ao proximo
}
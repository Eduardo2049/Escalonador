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

    while(ciclo < 1000) {
        pprid++;
        unsigned int fila_rand = rand() & 0x1f;

        PCB* novo = criar_novo(pprid, fila_aleatoria);
        add_fila(&escalonador[fila_aleatoria], novo);
        i++;
    }
    
    int ciclo = 0;

    while (ciclo < 1000) {
            ciclo++;
            
            int f = 0;
            PCB* exec = NULL;
            while (f < NUM_FILAS) {
                if (escalonador[f].inicio != NULL) {
                    exec = remover_inicio(&escalonador[f]);
                    break;
                }
                f++;
            }
            if (exec != NULL) {
                exec->tempo_restante--;
                printf("Ciclo %d -> Executando PID %d (prioridade %d, restante=%d)\n",
                    ciclo, exec->pid, exec->fila, exec->tempo_restante);
                if (exec->tempo_restante > 0) {
                    add_fila(&escalonador[exec->fila], exec);
                } else {
                    free(exec);
                }
            }
            if (ciclo > 0 && ciclo % 10 == 0) {
                int j = 1;
                while (j < NUM_FILAS) {
                    PCB* p = remover_inicio(&escalonador[j]);
                    if (p != NULL) {
                        p->fila = j - 1; 
                        add_fila(&escalonador[j - 1], p);
                    }
                    j++;
                }
            }
        }
    return 0;
}
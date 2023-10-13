#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} TipoNodo;

typedef TipoNodo* PunteroNodo;
typedef TipoNodo* Cola;

void encolar(Cola* cola, int valor);
int desencolar(Cola* cola);
void mostrar(Cola* cola);

int main() {
    Cola cola = NULL;

    encolar(&cola, 10); // 1ro de la cola (Recordar FIFO)
    encolar(&cola, 20);
    encolar(&cola, 30);
    encolar(&cola, 40);

    printf("Contenido de la cola: \n");
    mostrar(&cola);

    desencolar(&cola); // Eliminar el elemento en la parte frontal de la cola
    desencolar(&cola);

    printf("\nContenido de la cola después de desencolar: \n");
    mostrar(&cola);
    
    return 0;
}

void encolar(Cola* cola, int valor) {
    PunteroNodo nuevoNodo = (PunteroNodo)malloc(sizeof(TipoNodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    if (*cola == NULL) {
        *cola = nuevoNodo;
    } else {
        PunteroNodo actual = *cola;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

int desencolar(Cola* cola) {
    if (*cola == NULL) {
        return 0; // La cola está vacía
    }

    PunteroNodo nodoFrente = *cola;
    *cola = nodoFrente->siguiente;
    int valor = nodoFrente->valor;
    free(nodoFrente);

    return valor;
}

void mostrar(Cola* cola) {
    PunteroNodo actual = *cola;

    if (*cola == NULL) {
        printf("La cola está vacía.\n");
    } else {
        while (actual != NULL) {
            printf("%d, ", actual->valor);
            actual = actual->siguiente;
        }
    }
}
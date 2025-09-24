#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

// Insertar al inicio
struct Nodo* insertarInicio(struct Nodo *cabeza, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return cabeza;

    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = cabeza;

    if (cabeza != NULL) {
        cabeza->anterior = nuevo; // el viejo primero apunta hacia atrás
    }

    return nuevo; // nueva cabeza
}

// Recorrer hacia adelante
void recorrerAdelante(struct Nodo *cabeza) {
    printf("Recorrido hacia adelante:\n");
    while (cabeza != NULL) {
        printf("%d ", cabeza->dato);
        if (cabeza->siguiente == NULL) break; // llegamos al final
        cabeza = cabeza->siguiente;
    }
    printf("\n");

    // Llamar recorrido hacia atrás desde el último
    printf("Recorrido hacia atrás:\n");
    while (cabeza != NULL) {
        printf("%d ", cabeza->dato);
        cabeza = cabeza->anterior;
    }
    printf("\n");
}

int main() {
    struct Nodo *cabeza = NULL;

    cabeza = insertarInicio(cabeza, 30);
    cabeza = insertarInicio(cabeza, 20);
    cabeza = insertarInicio(cabeza, 10);

    recorrerAdelante(cabeza);

    return 0;
}
lista_doble.c
Mostrando lista.c
Estructuras de Datos y Algoritmos I
Próximas
¡Excelente! No tienes ninguna tarea para entregar pronto.

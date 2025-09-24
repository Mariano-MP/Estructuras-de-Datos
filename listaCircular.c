#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Insertar al final en lista circular
struct Nodo* insertarFinal(struct Nodo *cabeza, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return cabeza;

    nuevo->dato = valor;

    if (cabeza == NULL) {
        // Primer nodo, apunta a sí mismo
        nuevo->siguiente = nuevo;
        return nuevo;
    }

    // Encontrar el último nodo (que apunta a cabeza)
    struct Nodo *temp = cabeza;
    while (temp->siguiente != cabeza) {
        temp = temp->siguiente;
    }

    temp->siguiente = nuevo;
    nuevo->siguiente = cabeza;
    return cabeza;
}

// Recorrer la lista circular
void recorrer(struct Nodo *cabeza, int vueltas) {
    if (cabeza == NULL) return;

    struct Nodo *temp = cabeza;
    printf("Recorriendo lista circular (%d vueltas):\n", vueltas);
    for (int i = 0; i < vueltas; i++) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

int main() {
    struct Nodo *cabeza = NULL;

    cabeza = insertarFinal(cabeza, 10);
    cabeza = insertarFinal(cabeza, 20);
    cabeza = insertarFinal(cabeza, 30);

    recorrer(cabeza, 6); // 6 pasos: da 2 vueltas

    return 0;
}
#include <stdio.h>
#define MAX 5   // Capacidad fija de la pila

// Definición de la estructura Pila.
// 'datos' guarda los elementos y 'tope' marca el índice del último elemento insertado.
typedef struct {
    int datos[MAX];
    int tope;          // Cuando la pila está vacía, tope = -1
} Pila;

// Inicializa la pila dejándola vacía.
void inicializar(Pila *p) {
    p->tope = -1;      // Convención: -1 significa "sin elementos"
}

// Inserta un elemento en la cima (PUSH).
void push(Pila *p, int valor) {
    // Caso extremo: ¿está llena? (no hay espacio para insertar)
    if (p->tope == MAX - 1) {
        printf("La pila está llena\n");
    } else {
        // Pre-incremento: primero subimos el tope, luego escribimos en esa posición.
        p->datos[++(p->tope)] = valor;
        printf("Insertado %d en la pila (tope=%d)\n", valor, p->tope);
    }
}

// Elimina y devuelve el elemento en la cima (POP).
int pop(Pila *p) {
    // Caso extremo: ¿está vacía? (no hay qué extraer)
    if (p->tope == -1) {
        printf("La pila está vacía\n");
        return -1;     // Valor para indicar "no había dato"
    } else {
        // Devolvemos el elemento actual y luego reducimos el tope.
        return p->datos[(p->tope)--];
    }
}

int main(void) {
    Pila p;
    inicializar(&p);                // tope = -1 (pila vacía)

    // Insertamos 3 elementos en orden: 10, 20, 30.
    // Por LIFO, 30 quedará arriba y será el primero en salir.
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    // Extraemos dos veces: saldrán 30 y luego 20 (últimos en entrar).
    printf("Elemento extraído: %d\n", pop(&p));
    printf("Elemento extraído: %d\n", pop(&p));
    printf("Elemento extraído: %d\n", pop(&p));
    return 0;

}
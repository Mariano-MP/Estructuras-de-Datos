#include <stdio.h>
#define MAX 5   // Capacidad fija de la cola (índices válidos: 0..MAX-1)

// Definición de la estructura Cola.
// 'frente' apunta al índice del siguiente elemento a salir.
// 'final' apunta al índice del último elemento insertado.
// Convención de vacío: frente > final
typedef struct {
    int datos[MAX];
    int frente;   // índice del primer elemento válido
    int final;    // índice del último elemento válido
} Cola;

// Inicializa la cola vacía.
// Para que "vacío" sea cierto, dejamos frente=0 y final=-1 (frente > final).
void inicializar(Cola *c) {
    c->frente = 0;
    c->final  = -1;
}

// ENCOLAR (enqueue): inserta al FINAL de la cola.
void enqueue(Cola *c, int valor) {
    // Caso extremo: ¿está "llena" porque ya alcanzamos el final del arreglo?
    if (c->final == MAX - 1) {
        printf("La cola está llena (no recicla espacio en esta versión)\n");
    } else {
        // Avanzamos 'final' y colocamos el nuevo valor en esa posición.
        c->datos[++(c->final)] = valor;
        printf("Insertado %d en la cola (frente=%d, final=%d)\n", valor, c->frente, c->final);
    }
}

// DESENCOLAR (dequeue): saca del FRENTE de la cola.
int dequeue(Cola *c) {
    // Vacío si frente > final.
    if (c->frente > c->final) {
        printf("La cola está vacía\n");
        return -1;   // Valor centinela: no había dato
    } else {
        // Devolvemos el elemento actual en 'frente' y movemos 'frente' a la derecha.
        return c->datos[(c->frente)++];
    }
}

int main(void) {
    Cola c;
    inicializar(&c);                // frente=0, final=-1 (cola vacía)

    // Encolamos 3 elementos: 5, 15, 25.
    // Por FIFO, el primero en entrar (5) será el primero en salir.
    enqueue(&c, 5);                 // final=0
    enqueue(&c, 15);                // final=1
    enqueue(&c, 25);                // final=2

    // Sacamos dos elementos: saldrán 5 y luego 15 (primeros en entrar).
    printf("Elemento extraído: %d\n", dequeue(&c)); // sale 5, frente pasa 1
    printf("Elemento extraído: %d\n", dequeue(&c)); // sale 15, frente pasa 2

    // Si intentas desencolar más veces que elementos insertados, verás "La cola está vacía".
    return 0;
}
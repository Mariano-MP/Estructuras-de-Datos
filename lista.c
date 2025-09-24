#include <stdio.h>
#include <stdlib.h>

// 1) Definimos la estructura del nodo
struct Nodo {
    int dato;                // almacena el valor
    struct Nodo *siguiente;  // apunta al siguiente nodo (o NULL)
};

// 2) Crea un nodo en el heap y devuelve su puntero
//    Retorna NULL si no hay memoria
struct Nodo* crearNodo(int valor) {
    // Reservamos memoria del tamaño de un Nodo
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        // Siempre validar malloc
        printf("[crearNodo] Error: no se pudo reservar memoria.\n");
        return NULL;
    }

    // Inicializamos campos
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    printf("[crearNodo] Creado nodo en %p con dato=%d (siguiente=NULL)\n",
           (void*)nuevo, nuevo->dato);

    return nuevo;
}

// 3) Inserta al INICIO de la lista y devuelve la nueva cabeza
struct Nodo* insertarInicio(struct Nodo *cabeza, int valor) {
    printf("[insertarInicio] Insertando %d al inicio...\n", valor);

    // Creamos el nodo
    struct Nodo *nuevo = crearNodo(valor);
    if (nuevo == NULL) {
        // Si falló la memoria, devolvemos la misma cabeza
        return cabeza;
    }

    // enlazamos: el nuevo apunta a la cabeza actual
    nuevo->siguiente = cabeza;

    // La nueva cabeza ahora es "nuevo"
    cabeza = nuevo;

    printf("[insertarInicio] Nueva cabeza en %p (dato=%d)\n",
           (void*)cabeza, cabeza->dato);

    return cabeza;
}

// 4) Recorre la lista e imprime valores y direcciones
void recorrer(struct Nodo *cabeza) {
    printf("\n[recorrer] Mostrando lista enlazada:\n");
    if (cabeza == NULL) {
        printf("(lista vacía)\n");
        return;
    }

    while (cabeza != NULL) {
        printf("  Nodo en %p: dato=%d, siguiente=%p\n",
               (void*)cabeza, cabeza->dato, (void*)cabeza->siguiente);
        cabeza = cabeza->siguiente;  // avanzamos al siguiente nodo
    }
    printf("  NULL\n");
}

// 5) Libera toda la memoria de la lista
void liberar(struct Nodo *cabeza) {
    printf("\n[liberar] Liberando memoria de la lista...\n");

    while (cabeza != NULL) {
        struct Nodo *tmp = cabeza;         // guardo el nodo actual
        cabeza = cabeza->siguiente;         // avanzo antes de liberar
        printf("  free(%p)\n", (void*)tmp); // mostramos qué liberamos
        free(tmp);                          // libero el nodo
    }

    printf("[liberar] Memoria liberada correctamente.\n");
}

int main(void) {
    struct Nodo *cabeza = NULL;  // lista inicialmente vacía
    int n;

    // 6) Preguntamos cuántos números ingresará el usuario
    printf("¿Cuántos números deseas guardar en la lista? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Entrada inválida.\n");
        return 1;
    }

    // 7) Leemos los valores e insertamos siempre al INICIO
    for (int i = 0; i < n; i++) {
        int x;
        printf("Valor %d/%d: ", i + 1, n);
        if (scanf("%d", &x) != 1) {
            printf("Entrada inválida.\n");
            // Si falla, salimos liberando lo que ya tengamos
            liberar(cabeza);
            return 1;
        }
        cabeza = insertarInicio(cabeza, x);
    }

    // 8) Mostramos la lista (con direcciones)
    recorrer(cabeza);

    // 9) Importante: liberar toda la memoria al final
    liberar(cabeza);

    return 0;
}
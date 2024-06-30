#include <stdio.h>
#include <stdlib.h>

// Estructura del NODO
typedef struct tiponodo
{
  int entero;
  struct tiponodo *siguiente;
  struct tiponodo *anterior;
} NODO;

// Estructura de la Cola
typedef struct
{
  NODO *primero;
  NODO *ultimo;
} COLA;

// Inicializar la cola
COLA *inicializarCola()
{
  COLA *cola = (COLA *)malloc(sizeof(COLA));
  if (cola == NULL)
  {
    printf("No hay memoria disponible :(\n");
    exit(1);
  }

  cola->primero = cola->ultimo = NULL;
  return cola;
}

// Agregar un elemento a la cola
void encolar(COLA *cola, int nuevoEntero)
{
  NODO *nuevoNodo = (NODO *)malloc(sizeof(NODO));

  if (nuevoNodo == NULL)
  {
    printf("No hay memoria disponible :(\n");
    exit(1);
  }

  nuevoNodo->entero = nuevoEntero;
  nuevoNodo->anterior = cola->primero;
  nuevoNodo->siguiente = NULL;

  if (cola->ultimo == NULL)
  {
    cola->primero = cola->ultimo = nuevoNodo;
  }
  else
  {
    cola->primero->siguiente = nuevoNodo;
    cola->primero = nuevoNodo;
  }

  printf("Agregar numero: %d\n", nuevoEntero);
}

// Eliminar un elemento de la cola y retornar el numero entero eliminado
int desencolar(COLA *cola)
{
  if (cola->primero == NULL)
  {
    printf("La cola esta vacia\n");
    exit(1);
  }

  // NODO *nodoAEliminar = cola->primero;
  NODO *nodoAEliminar = cola->ultimo;

  cola->ultimo = nodoAEliminar->siguiente;

  if (cola->ultimo != NULL)
  {

    cola->ultimo->anterior = NULL;
  }

  int enteroDelNodo = nodoAEliminar->entero;

  if (cola->ultimo == NULL)
  {
    cola->primero = NULL;
  }

  free(nodoAEliminar);

  return enteroDelNodo;
}

void imprimirCola(COLA *cola)
{
  NODO *nodoActual = cola->primero;

  printf("Cola: [");

  while (nodoActual != NULL)
  {
    if (nodoActual->anterior != NULL)
    {
      printf("%d ", nodoActual->entero);
    }
    else
    {
      printf("%d", nodoActual->entero);
    }
    nodoActual = nodoActual->anterior;
  }

  printf("]\n");
}

int main()
{
  COLA *cola = inicializarCola();
  int enteros[] = {22, 2, 47, 72, 88, 35};

  printf("\n=======AGREGAR ELEMENTOS A LA COLA========\n\n");

  // Ingresar los enteros a la cola
  for (int i = 0; i < 6; i++)
  {
    encolar(cola, enteros[i]);

    // Imprimir la cola con el nuevo elemento agregado
    imprimirCola(cola);
  }

  printf("\n=======ELIMINAR ELEMENTOS DE LA COLA========\n\n");

  // Imprimir los elementos de la cola antes de ser removidos
  imprimirCola(cola);

  // Remover los elementos de la cola e imprimir el elemento eliminado
  while (cola->ultimo != NULL)
  {
    printf("Eliminar: %d\n", desencolar(cola));

    // Imprimir la cola sin el elemento eliminado
    imprimirCola(cola);
  }

  return 0;
}
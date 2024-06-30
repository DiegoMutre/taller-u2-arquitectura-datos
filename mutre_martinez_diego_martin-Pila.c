#include <stdio.h>
#include <stdlib.h>

// Estructura del Nodo
typedef struct tiponodo
{
  int entero;
  struct tiponodo *siguiente;
} NODO;

// Metodo para imprimir los elementos de la pila
void imprimir(NODO *primerNodo)
{
  NODO *nodoActual = primerNodo;

  printf("Pila: [");
  while (nodoActual != NULL)
  {
    if (nodoActual->siguiente != NULL)
    {
      printf("%d ", nodoActual->entero);
    }
    else
    {
      printf("%d", nodoActual->entero);
    }
    nodoActual = nodoActual->siguiente;
  }
  printf("]\n");
}

// Metodo para añadir un elemento a la pila
void agregar(NODO **primerNodo, int numero)
{
  NODO *nuevoNodo = (NODO *)malloc(sizeof(NODO));

  if (nuevoNodo == NULL)
  {
    printf("No hay memoria disponible :(\n");
    exit(1);
  }

  nuevoNodo->entero = numero;
  nuevoNodo->siguiente = *primerNodo;
  *primerNodo = nuevoNodo;

  // Imprimir el nuevo numero (entero) agregado
  printf("Agregar numero: %d\n", numero);
}

// Metoodo para eliminar un elemento de la pila
int eliminar(NODO **primerNodo)
{
  if (*primerNodo == NULL)
  {
    printf("La pila esta vacia, asi que no se puede eliminar nada");
    exit(1);
  }

  NODO *nodoAEliminar = *primerNodo;
  int numero = nodoAEliminar->entero;
  *primerNodo = (*primerNodo)->siguiente;
  free(nodoAEliminar);
  return numero;
}

int main()
{
  NODO *pila = NULL;

  int numerosEnteros[] = {22, 2, 47, 72, 88, 35}; // Estos datos vienen del taller

  printf("\n=======AGREGAR ELEMENTOS A LA PILA========\n\n");

  // Ingresar los numeros enteros en la pila
  for (int i = 0; i < 6; i++)
  {
    agregar(&pila, numerosEnteros[i]);

    // Imprimir la pila con el nuevo nodo
    imprimir(pila);
  }

  printf("\n=======ELIMINAR ELEMENTOS DE LA PILA========\n\n");

  // Imprimir los elementos de la pila antes de ser eliminados
  imprimir(pila);

  // Extraer e imprimir cada elemento hasta vaciar la pila
  while (pila != NULL)
  {
    printf("Eliminar numero: %d\n", eliminar(&pila));

    // Imprimir la pila sin el numero eliminado
    imprimir(pila);
  }

  return 0;
}
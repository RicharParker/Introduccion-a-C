#include <stdio.h>
#include <stdlib.h>

int main()
{
char i,j;
char longitud;
char cadena[50];
char temporal;

printf("Introduce una palabra: "); //imprimimos lo que queramos que aparezca en la consola//
gets(cadena);
longitud=strrev(cadena);  //Devuelve la longitud de la cadena C//
for (i=0,j=longitud-1; i<longitud/2; i++,j--) // declaramos una terminacion nula,
{
	temporal=cadena[i];
	cadena[i]=cadena[j];
	cadena[j]=temporal;
}


/* Rellenar de unos los elementos del 10 al 20 */

int* ptr;			/* el puntero */
int vector [50];	/* el vector */
int P;			/* variable contadora */

ptr = &vector[0];	/* ptr apunta al origen del vector */
ptr+=10;			/* ptr apunta a vector[10] */

for ( P=0; P<=10; P++ )
{
  *ptr = 1;	/*	asigna 1 a la posición de memoria apuntada 				por "ptr" */
  ptr++;		/* 	ptr pasa al siguiente elemento */
    printf("Resultado: %s\n", cadena);
}return 0;
}

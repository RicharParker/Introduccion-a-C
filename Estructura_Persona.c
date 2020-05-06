#include <stdio.h>
#include <stdlib.h>
typedef struct persona
{
    unsigned long int id_persona;
	char nombre[100];
	char sexo;
	char direccion[100], religion[50], escolaridad[20];
	unsigned short int edad;
} Persona;
int main()
{
     Persona estructura_pers[10];
     Persona una_persona;
     FILE *aarchive;
    int cont=0;

    do {

    printf("Persona numero [%d]\n",cont);

    printf("Introduzca el nombre completo:\n");
    fflush(stdin);
    scanf(estructura_pers[cont].nombre, 99,stdin);

    printf("Introduzca el sexo:\n");
    fflush(stdin);
    estructura_pers[cont].sexo = getc(stdin);

    printf("Introduzca la direccion:\n");
    fflush(stdin);
    scanf(estructura_pers[cont].direccion, 99,stdin);

    printf("Introduzca la edad :\n");
    fflush(stdin);
    scanf("%hu", &estructura_pers[cont].edad);

    printf("Introduzca la escolaridad:\n");
    fflush(stdin);
    scanf(estructura_pers[cont].escolaridad, 99,stdin);

    printf("Introduzca la religion \n");
    fflush(stdin);
    scanf(estructura_pers[cont].religion, 99,stdin);



    cont++;

  } while(cont<2);

  aarchive = fopen("miarchivo.bin", "w");


  fwrite(estructura_pers, sizeof(Persona), 10, aarchive);

  fclose(aarchive);
  return 0;
}

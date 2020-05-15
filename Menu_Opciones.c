#include <stdio.h>
#include <stdlib.h>

typedef struct persona
{
	unsigned long int id_persona;
	char nombre[100];
	char sexo;
	char direccion[100], religion[50], escolaridad[20];
	unsigned short int edad;

}Persona;
Persona array_de_personas[3];
char CD(Persona array_de_personas[3])
{
	int charge;
	char opc='n';
	FILE *archivo;
	archivo = fopen("miarchivo.bin", "rb");

	if(archivo == NULL)
	{
		printf("Error al cargar el archivo\n");
		printf("carga de los datos [S]\n");
		scanf("%c",&opc);


	return 0;
}
char MP(Persona array_de_personas[3])// MODIFICAR DATOS DE LA PERSONA
{
	int seleccion=0,m;
	char resultado;
	do
	{
         printf("\nSeleccione la persona a modificar [1-10]: ");
         scanf("%d",&seleccion);
	 printf("\nPersona #%d\n",seleccion);
	 while ((m = getc(stdin)) != '\n' && m != EOF);
	 printf("Introduzca el nombre completo:\n");
	 fgets(array_de_personas[seleccion-1].nombre, 99,stdin);
	 printf("Introduzca el sexo [M/F]:\n");
	 array_de_personas[seleccion-1].sexo = getc(stdin);
	 while ((m = getc(stdin)) != '\n' && m != EOF);
	 printf("Introduzca la direccion:\n");
	 fgets(array_de_personas[seleccion-1].direccion, 99,stdin);
	 printf("Introduzca la religion:\n");
	 fgets(array_de_personas[seleccion-1].religion, 49,stdin);
	 printf("Introduzca la escolaridad:\n");
	 fgets(array_de_personas[seleccion-1].escolaridad, 19,stdin);
	 printf("Introduzca la edad:\n");
	 scanf("%hu", &array_de_personas[seleccion-1].edad);
	 while ((m = getc(stdin)) != '\n' && m != EOF);
	 printf("La persona #%d ha sido modificada\n",seleccion);
	 printf("Desea seguir modificando? [S/N]\n");
	 scanf("%c",&resultado);
	}
	while(resultado=='S'||resultado=='S');
	return 0;
        }
       char SP(Persona array_de_personas[10]) //MOSTRAR DATOS DE LA PERSONA
        {
	for (size_t i = 0; i < 2; i++)
	return 0;
       }
       char GD(Persona array_de_personas[10]) //Guardar datos
       {
	FILE *archivo;
	printf("\nGuardando datos en archivo.bin\n");
	archivo = fopen("archivo.bin", "wb");
	if(archivo == NULL)
	{
	printf("Error al abrir \n");
	return 1;
	}
	fwrite(array_de_personas, sizeof(Persona), 3, archivo);
	printf("Guardado en file: archivo.bin\n");
	return 0;
}


int main(void)
{

    int opc = 0 , archivo= 0;
    FILE *archive;

    do{
       printf("\n\t\t\t\tBIENVENIDO AL MENU DE OPCIONES\n" );
       printf("\n\t\t[1]. Cargar datos de un archivo.\n");
       printf("\t\t[2]. Modificar datos de una persona.\n");
       printf("\t\t[3]. Mostrar la lista de personas.\n");
       printf("\t\t[4]. Guardar datos en archivo.\n");
       printf("\t\t[5]. Salir. \n");
       printf("\n\t\tIngrese su opcion: [ ]\b\b");
       scanf("%d",&opc);
      switch(opc){
        case 1:
        system("cls");
        archivo = fopen("miarchivo.txt","w");
        fprintf(archivo,"\n Orlando ");
        printf("tu archivo ha sido creado\n");
        fclose(archivo);
        break;

        case 2:
         system("cls");
         FILE *archivo;
         char cadena;
         archivo = fopen("datos.txt","rb");
         while (feof(archivo)== 0){
         fscanf(archivo, "%c",&cadena);
         cadena= fgetc(archivo);
         printf("%c", cadena);}
         fclose(archivo);
         break;
         printf("\n\n Se ha leido el archivo correctamente");//
         break;
        case 3:
         SP(array_de_personas);
	 printf("\n\t\t\t\t¿Que desea hacer? \n");
	 printf("\t\t[1].Cargar datos de archivo\n");
         printf("\t\t[2].Modificar datos de una persona\n");
	 printf("\t\t[3].Guardar datos en archivo\n");
       	 printf("\n\t\tIngrese su opcion: [ ]\b\b");
 	 scanf("%d",&opc);
         break;
        case 4:
	opc=0;
	GD(array_de_personas);//GUARDA LOSS DATOS DE LA ARRAY
        break;
        case 5:
        break;
        default:
        system("cls");
        printf("La opcion que ingreso es incorrecta");
        getch();
        break;
        }

        }while(opc != 5 );

       return 0;
}

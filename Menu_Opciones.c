#include <stdio.h>
#include <string.h>

typedef struct persona // Definir tipos de datos estructura
{
	unsigned long int id_persona;
	char nombre[100];
	char sexo;
	char direccion[100], religion[50], escolaridad[20];
	unsigned short int edad;

} Persona;


Persona array_de_personas[4]; //Esta es la variable global llamada array de personas

char cargar_datos(Persona array_de_personas[4]) //Acá se cargan los datos de las personas
{
	int charge;
	char opcion1='n'; //
	FILE *aarchivo;//Esta función sirve para abrir y crear ficheros
	aarchivo = fopen("archivo.bin", "rb"); //Aquí abre un archivo binario para lectura

	if(aarchivo == NULL) //Si no hay ningun archivo, aparecerá el mensaje de error
	{
		printf("Error al cargar el archivo\n");
		printf("¿Desea cargar los datos manualmente? [S/N]\n"); //Aqui se da la opcion para cargar los datos manualmente
		scanf("%c",&opcion1);
		if (opcion1=='n'||opcion1=='N')
		{
			return 0;

		} else{

			for (size_t i = 0; i < 4; i++) //Aqui inicializamos i con cero, despues, le colocamos un limite, e irá contando de uno en uno
			{
				printf("\n");
				array_de_personas[i].id_persona = i+1;
				while ((charge = getc(stdin)) != '\n' && charge != EOF); //Aqui podemos leer una linea de caracteres
				printf("Introduzca el nombre completo:\n");
				fgets(array_de_personas[i].nombre, 99,stdin); //Con fgets almacenamos el array y con stdin funcionara como la lectura de los caracteres
				printf("Introduzca el sexo [M/F]:\n");
				array_de_personas[i].sexo = getc(stdin);
				while ((charge = getc(stdin)) != '\n' && charge != EOF); // Borra la memoria para cargar nuevos datos
				printf("Introduzca la direccion:\n");
				fgets(array_de_personas[i].direccion, 99,stdin); //Con fgets almacenamos los caracteres de direccion
				printf("Introduzca la religion:\n");
				fgets(array_de_personas[i].religion, 49,stdin); //Con fgets almacenamos los caracteres de religion
				printf("Introduzca la escolaridad:\n");
				fgets(array_de_personas[i].escolaridad, 19,stdin); //Con fgets almacenamos los caracteres de escolaridad
				printf("Introduzca la edad:\n");
				scanf("%hu", &array_de_personas[i].edad);
			}
		}
	}
	fclose(aarchivo);

	return 0;
}


char modificar_persona(Persona array_de_personas[4])
{
	int seleccion=0,m;
	char resultado;
	do
	{
		printf("\nSeleccione la persona a modificar [1-10]: "); //Aqui se puede modifiacar los datos de la persona seleccionada
		scanf("%d",&seleccion);
		printf("\nPersona #%d\n",seleccion);
		while ((m = getc(stdin)) != '\n' && m != EOF); // hace flush en la entrada, limpia la memoria
		printf("Introduzca el nombre completo:\n");
		fgets(array_de_personas[seleccion-1].nombre, 99,stdin);
		printf("Introduzca el sexo [M/F]:\n");
		array_de_personas[seleccion-1].sexo = getc(stdin);
		while ((m = getc(stdin)) != '\n' && m != EOF);// hace flush en la entrada, limpia la memoria
		printf("Introduzca la direccion:\n");
		fgets(array_de_personas[seleccion-1].direccion, 99,stdin);
		printf("Introduzca la religion:\n");
		fgets(array_de_personas[seleccion-1].religion, 49,stdin);
		printf("Introduzca la escolaridad:\n");
		fgets(array_de_personas[seleccion-1].escolaridad, 19,stdin);
		printf("Introduzca la edad:\n");
		scanf("%hu", &array_de_personas[seleccion-1].edad);
		while ((m = getc(stdin)) != '\n' && m != EOF);// hace flush en la entrada, limpia la memoria
		printf("La persona #%d ha sido modificada\n",seleccion);
		printf("Desea seguir modificando? [S/N]\n");
		scanf("%c",&resultado);
	}
	while(resultado=='S'||resultado=='S');// mientras el resultado es S va a segiuir modificando personas y si el resultado es N va a regresar al menú

	return 0;
}


char mostrar_personas(Persona array_de_personas[10])// La funcion muestra la lista de personas que hay hasta el momento
{
	for (size_t i = 0; i < 4; i++)//Aqui inicializamos i con cero, despues, le colocamos un limite, e irá contando de uno en uno
	{
		printf("\nPersona #%lu\nNombre:%s\nSexo:%c\nDireccion: %s\nReligion: %s\nEscolaridad: %s\nEdad: %hu\n", array_de_personas[i].id_persona, array_de_personas[i].nombre, array_de_personas[i].sexo, array_de_personas[i].direccion, array_de_personas[i].religion, array_de_personas[i].escolaridad, array_de_personas[i].edad);
	}
	return 0;

}

char guardar_datos(Persona array_de_personas[10])// La funcion guarda los datos de la persona y sus modificaciones que se le han hecho en el archivo.bin
{
	FILE *aarchivo;//Esta función sirve para abrir y crear ficheros
	printf("\nGuardando datos en archivo.bin\n");
	aarchivo = fopen("archivo.bin", "wb");//Aquí abre un archivo binario en modo escritura
	if(aarchivo == NULL)
	{
		printf("Error al abrir \n");
		return 1;
	}
	fwrite(array_de_personas, sizeof(Persona), 3, aarchivo);//Es capaz de escribir hacia un fichero o varios registros de la misma longitud almacenados a partir de una dirección de memoria determinada.
	printf("Guardado en file: archivo.bin\n");
	return 0;
}

int main()

{
    int opcion,c;
    FILE *aarchivo;
	char respuesta;

	do
	{
	printf("\n\t\tBIENVENIDO AL MENU DE OPCIONES\n" );
    printf("\n\t\t[1]. Cargar datos de un archivo.\n");
    printf("\t\t[2]. Modificar datos de una persona.\n");
    printf("\t\t[3]. Mostrar la lista de personas.\n");
    printf("\t\t[4]. Guardar datos en archivo.\n");
    printf("\t\t[5]. Salir. \n");
    printf("\n\t\tIngrese su opcion: [ ]\b\b");
    scanf("%d",&opcion);

    switch(opcion)
    {
      case 1: //Carga de datos

				opcion=0;
				cargar_datos(array_de_personas);// pide la función cargar
				printf("\n\t\t\t\t¿Que desea hacer? \n");
				printf("\n\t\t[1].Modificar datos de una persona. \n");
				printf("\t\t[2].Mostrar la lista de personas.\n");
				printf("\t\t[3].Guardar datos en archivo.\n");
				printf("\n\t\tIngrese su opcion: [ ]\b\b");
				scanf("%d",&opcion);

        switch(opcion)
    		{
                    case 1://Carga de datos
						modificar_persona(array_de_personas);break;//funcion que modifics la persona
					case 2://cargar de datos
						mostrar_personas(array_de_personas);break;//funcion que muestra a la persona
					case 3://Carga de datos
						guardar_datos(array_de_personas);break;//funcion que guarda los datos
        }
      	break;
      case 2: //Modificar los datos de la persona
				opcion=0;
				modificar_persona(array_de_personas);
				printf("\n\t\t\t\t¿Que desea hacer? \n");
				printf("\t\t[1].Mostrar la lista de personas.\n");
				printf("\t\t[2].Guardar datos en archivo.\n");
				printf("\n\t\tIngrese su opcion: [ ]\b\b");
				scanf("%d",&opcion);

        switch(opcion)
    		{
                    case 1://modifica a la persona
						mostrar_personas(array_de_personas);break;//esta funcion muestra la lista
					case 2:
						guardar_datos(array_de_personas);break;//esta funcion guarda los datos
        }
      	break;
      case 3: //Muestra la lista de las personas
				opcion=0;
				mostrar_personas(array_de_personas);
				printf("\n\t\t\t\t¿Que desea hacer? \n");
				printf("\t\t[1].Cargar datos de archivo\n");
			    printf("\t\t[2].Modificar datos de una persona\n");
				printf("\t\t[3].Guardar datos en archivo\n");
				printf("\n\t\tIngrese su opcion: [ ]\b\b");
				scanf("%d",&opcion);
				switch(opcion)
				{
					case 1:// muestra lista
						cargar_datos(array_de_personas);break;//esta funcion muestra lista
					case 2://
						modificar_persona(array_de_personas);break;//esta funcion pmodifica datos persona
					case 3:
						guardar_datos(array_de_personas);break;//esta funcion guarda datos
				}
	      break;
      case 4: //Guarda los datos
				opcion=0;
				guardar_datos(array_de_personas);break;

    default: printf("\n\t\t*ERROR* Ingresa una opcion del menu\n");//en caso que el usuario no ponga alguna de las opciones de menu
    }
	while ((c = getc(stdin)) != '\n' && c != EOF);
	printf("\n\t\t¿Desea salir del menu? [S/N]\n");
	printf("\n\t\tIngrese su opcion: [ ]\b\b");
	scanf("%c",&respuesta );
	}
	while(respuesta=='n'||respuesta=='N');

	return 0;
}

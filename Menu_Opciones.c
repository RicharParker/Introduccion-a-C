#include <stdio.h>
#include <stdlib.h>

int main(void)
{


    int opc = 0 , archivo= 0;
    FILE *archive;

    do{
        system("cls");
        printf("1. Cargar datos de archivo \n");
        printf("2. Modificar datos de una persona \n");
        printf("3. Mostrar la lista de personas\n");
        printf("4. Guardar datos en archvio\n");
        printf("5. Salir \n\n");
        printf("opcion a escoger: \n");
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

        if (archivo == NULL){
            perror("Error en la apertura de archivo");
            return 1;
        }

           FILE *archivo;
           char cadena;
	       archivo = fopen("datos.txt","rb");
           while (feof(archivo)== 0){
           fscanf(archivo, "%c",&cadena);
           cadena= fgetc(archivo);
           printf("%c", cadena);}
           fclose(archivo);
           getch();
           break;
           printf("\n\n Se ha leido el archivo correctamente");//


        }

      }while(opc != 1 );

      return 0;



}



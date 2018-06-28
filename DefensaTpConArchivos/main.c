#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Destinatarios.h"
#include "ArrayList.h"
int main()
{
int opcion;
int index=-1;
char nombre[20];
char email[40];

FILE* black_list;
char* blackListPath="black_list.csv";
eDestinatario* destinatarioListaNegra;

FILE* archivo_destinatarios;
char* destinatariosPath="destinatarios.csv";
eDestinatario* destinatarioTotal;

FILE* destinatariosDepurados;

ArrayList* TotalDestinatarios;
TotalDestinatarios= al_newArrayList();

ArrayList* ListaNegraDestinatarios;
ListaNegraDestinatarios= al_newArrayList();

ArrayList* DestinatariosDepurados;
DestinatariosDepurados= al_newArrayList();

char linea[60];
int contar=0;

do
{
    printf(" 1.CARGAR DESTINATARIOS\n");
    printf(" 2.CARGAR LISTA NEGRA\n");
    printf(" 3.DEPURAR\n");
    printf(" 4.LISTAR\n");
    printf(" 5.SALIR\n");
    printf("\n opcion: ");

    scanf("%d", &opcion);

     switch(opcion)
        {
        case 1:
            index=leer_Archivo(TotalDestinatarios,destinatarioTotal,archivo_destinatarios, destinatariosPath);
            break;
        case 2:
            index=leer_Archivo(ListaNegraDestinatarios,destinatarioListaNegra,black_list, blackListPath);
            break;
        case 3:
            index=depurar_Destinatarios(TotalDestinatarios,destinatarioTotal,ListaNegraDestinatarios,destinatarioListaNegra,DestinatariosDepurados ,destinatariosDepurados);
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("\n No se ha accedido a ninguna opcion del Sistema. Por favor, intente de nuevo.\n\n");
            break;
        }

    }while(opcion!=5);

return 0;
}

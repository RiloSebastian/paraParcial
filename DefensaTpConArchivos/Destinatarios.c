#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Destinatarios.h"

eDestinatario* new_Destinatario()
{
    eDestinatario* destinatarioAux;

    destinatarioAux = (eDestinatario*) malloc(sizeof(eDestinatario));

return destinatarioAux;
}



int set_estado(eDestinatario* this , int estado)
{
int index=-1;

    if(this != NULL && estado >= 0)
    {
     this->Estado = estado;
     index=0;
    }
return index;
}


int get_estado(eDestinatario* this)
{
int index=-1;

    if(this != NULL)
    {
        index= this->Estado;
    }
return index;
}



int set_email(eDestinatario* this, char* email )
{
int index=-1;

    if(this != NULL && email != NULL)
    {
        strcpy(this->email,email);
        index=0;
    }
return index;
}


char* get_email (eDestinatario* this)
{
char* email=NULL;

    if(this != NULL)
    {
        email = this->email;
    }
return email;
}


int set_nombre(eDestinatario* this, char* nombre )
{
int index=-1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        index=0;
    }
return index;
}


char* get_nombre (eDestinatario* this)
{
char* nombre=NULL;

    if(this != NULL)
    {
        nombre = this->nombre;
    }
return nombre;
}


int mostrar_Destinatarios(eDestinatario* this)
{
int index=-1;

    if(this != NULL)
    {
        printf(" NOMBRE: %s ---- EMAIL: %s ---- ESTADO:%d \n", get_nombre(this), get_email(this), get_estado(this));
        index=0;
    }
return index;
}


int comparar_Destinatarios(void* destinatarioA, void* destinatarioB)
{
eDestinatario* destinatario1;
eDestinatario* destinatario2;

destinatario1= (eDestinatario*) destinatarioA;
destinatario2= (eDestinatario*) destinatarioB;
/*
printf("destinatario j: nom: %s -- mail: %s\n",destinatario1->nombre, destinatario1->email);
printf("destinatario i: nom: %s -- mail: %s\n",destinatario2->nombre, destinatario2->email);
system("pause");*/
return strcmp(destinatario1->email, destinatario2->email);
}


int mostrar_lista_Destinatarios(ArrayList* listado)
{
int index=-1;
int i;
int len;
eDestinatario* destinatarioActual;

    if(listado != NULL)
    {
        len = listado->len(listado);
        for(i=0; i<len;i++)
        {
            destinatarioActual= (eDestinatario*) listado->get(listado, i);
            printf("%d.",i+1);
            mostrar_Destinatarios(destinatarioActual);
        }
    index=0;
    }
return index;
}

int leer_Archivo(ArrayList* listado,eDestinatario* destinatarioActual ,FILE* archivo, char* direcc)
{
int index=-1;
char linea[60];
char nombre[20];
char email[40];
int estado;
int contar=0;

memset(linea, '\0',60);

    if(listado != NULL && email != NULL)
    {
        archivo=fopen(direcc,"r");
        if(archivo != NULL)
            {
                fgets(linea, 60, archivo);

                while(!feof(archivo))
                {
                    strcpy(nombre,strtok(linea,","));
                    strcpy(email,strtok(NULL,"\n"));
                    estado=0;

                    cargar_Destinatario(listado,destinatarioActual,email,nombre,estado);
                    contar++;
                    memset(linea, '\0', 60);
                    fgets(linea, 60, archivo);
                }
            fclose(archivo);


            printf("\n PERSONAS EN LA LISTA: %d \n", contar);
            }
        index=0;
    }

return index;
}


int cargar_Destinatario(ArrayList* listado, eDestinatario* destinatarioActual ,char* email,char* nombre, int estado)
{
int index=-1;


    if(listado != NULL && email != NULL)
     {
        destinatarioActual = new_Destinatario();
        set_nombre(destinatarioActual, nombre);
        set_email(destinatarioActual, email);
        set_estado(destinatarioActual,estado);

        listado->add(listado,destinatarioActual);
        index=0;
     }

return index;
}


int lista_Destinatarios_atendidos(ArrayList* ListaPendientes, ArrayList* listaAtendidos)
{
int index=-1;
eDestinatario* destinatarioActual;

    if(ListaPendientes != NULL && listaAtendidos != NULL)
    {
        destinatarioActual= (eDestinatario*) ListaPendientes->pop(ListaPendientes,0);
        listaAtendidos->add(listaAtendidos, destinatarioActual);

        index=0;
    }
return index;
}


int depurar_Destinatarios(ArrayList* TotalDestinatarios,eDestinatario* destinatarioTotal ,ArrayList* ListaNegraDestinatarios,eDestinatario* destinatarioListaNegra ,ArrayList* DestinatariosDepurados, FILE* destinatariosDepurados)
{
FILE* archivo_destinatarios;
ArrayList* aux;
aux=al_newArrayList();
char* destinatariosPath="destinatarios.csv";
eDestinatario* depurados;
int index=-1;
char nombre[20];
char email[40];
int estado;
int i=0;
int j;
int k;

aux=ListaNegraDestinatarios;

    if(TotalDestinatarios != NULL && ListaNegraDestinatarios != NULL && DestinatariosDepurados != NULL)
    {
        for(k=(ListaNegraDestinatarios->len(ListaNegraDestinatarios)); k<TotalDestinatarios->len(TotalDestinatarios);k++)
        {
            estado=-1;
            strcpy(nombre,"--");
            strcpy(email,"--");
            cargar_Destinatario(ListaNegraDestinatarios,destinatarioListaNegra,email,nombre,estado);
        }
        fflush(stdin);
        leer_Archivo(DestinatariosDepurados,depurados,archivo_destinatarios,destinatariosPath);


        for(j=0; j<DestinatariosDepurados->len(DestinatariosDepurados);j++)
        {

            for(i=0; i<ListaNegraDestinatarios->len(ListaNegraDestinatarios);i++)
            {

                fflush(stdin);
                index=comparar_Destinatarios(*(DestinatariosDepurados->pElements+j),*(ListaNegraDestinatarios->pElements+i));
                if(!index==0)
                {

                    DestinatariosDepurados->remove(DestinatariosDepurados,j);
                    ListaNegraDestinatarios->remove(ListaNegraDestinatarios,i);
                    break;

                }
                else if(i==(ListaNegraDestinatarios->len(ListaNegraDestinatarios)) && index!=0 )
                 {

                     DestinatariosDepurados->remove(DestinatariosDepurados,j);
                 }
            }

        }
        mostrar_lista_Destinatarios(DestinatariosDepurados);
        printf("\n PERSONAS EN LA LISTA: %d \n", DestinatariosDepurados->len(DestinatariosDepurados));

        /*destinatariosDepurados=fopen("destinatarios_depurados.txt","w");
            for(i=0;i<DestinatariosDepurados->len(DestinatariosDepurados);i++)
            {

            }
            fclose(destinatariosDepurados);
*/
index=0;
    }

return index;
}



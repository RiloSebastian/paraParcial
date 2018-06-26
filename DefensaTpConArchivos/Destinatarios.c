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

    if(this != NULL && estado > 0)
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
        printf(" ESTADO: %d ---- EMAIL: %s \n", get_estado(this), get_email(this));
        index=0;
    }
return index;
}


int comparar_Destinatarios(void* destinatarioA,void* destinatarioB)
{
eDestinatario* destinatario1;
eDestinatario* destinatario2;

destinatario1= (eDestinatario*) destinatarioA;
destinatario2= (eDestinatario*) destinatarioB;

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
            mostrar_Destinatarios(destinatarioActual);
        }
    index=0;
    }
return index;
}


int cargar_Destinatario(ArrayList* listado, FILE* archivo, char* direcc)
{
eDestinatario* destinatarioActual;
int index=-1;
char linea[60];
char nombre[20];
char email[40];
int estado;
int contar=0;

memset(linea, '\0',60);

    if(listado != NULL && email != NULL)
    {
        destinatarioActual = new_Destinatario();

        archivo=fopen(direcc,"r");
        if(archivo != NULL)
            {
                fgets(linea, 60, archivo);
                while(!feof(archivo))
                {

                    strcpy(destinatarioActual->nombre,strtok(linea,","));
                    strcpy(nombre,destinatarioActual->nombre);
                    set_nombre(destinatarioActual, nombre);

                    strcpy(destinatarioActual->email,strtok(NULL,"\n"));
                    strcpy(email,destinatarioActual->email);
                    set_email(destinatarioActual, email);

                    estado=0;
                    set_estado(destinatarioActual,estado);

                    listado->add(listado, destinatarioActual);

                    printf(" NOMBRE: %s \n EMAIL: %s\n",destinatarioActual->nombre,destinatarioActual->email);
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

int depurar_Destinatarios(ArrayList* TotalDestinatarios, ArrayList* ListaNegraDestinatarios, ArrayList* DestinatariosDepurados, FILE* destinatariosDepurados)
{
eDestinatario* depurados;
int index=-1;
char nombre[20];
char email[40];
int estado;
int i;
int j;
    if(TotalDestinatarios != NULL && ListaNegraDestinatarios != NULL && DestinatariosDepurados != NULL)
    {
        depurados= new_Destinatario();
        for(i=0; i<ListaNegraDestinatarios->len(ListaNegraDestinatarios);i++)
        {
            for(j=0;i<TotalDestinatarios->len(TotalDestinatarios);j++ )
            {
                if((index=comparar_Destinatarios(ListaNegraDestinatarios->pElements,TotalDestinatarios->pElements))==0)
                {
                    depurados= (eDestinatario*) *(TotalDestinatarios->pElements+j);
                    depurados->Estado=1;
                    break;

                }
            }
            set_estado(depurados,estado);
            DestinatariosDepurados->add(DestinatariosDepurados,*(depurados+i));
        }
        destinatariosDepurados=fopen("destinatarios_depurados.txt","w");
            for(i=0;i<DestinatariosDepurados->len(DestinatariosDepurados);i++)
            {
                if(depurados->Estado==0)
                {
                    fprintf(destinatariosDepurados,"%s,%s\n",*(depurados->nombre+i),*(depurados->email));
                    printf("%s,%s",*(depurados->nombre+i),*(depurados->email));
                }
            }
            fclose(destinatariosDepurados);
            index=0;

    }

return index;
}



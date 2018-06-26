#ifndef DESTINATARIOS_H_INCLUDED
#define DESTINATARIOS_H_INCLUDED
#include "ArrayList.h"
typedef struct
{
char nombre[20];
char email[30];
int Estado;
}eDestinatario;

eDestinatario* new_Destinatario();

int set_estado(eDestinatario* , int  );

int get_estado (eDestinatario* );

int set_email(eDestinatario* , char* );

char* get_email (eDestinatario* );

int set_nombre(eDestinatario* , char* );

char* get_nombre(eDestinatario* );

int mostrar_Destinatarios (eDestinatario* );

int comparar_Destinatarios(void* , void* );

int mostrar_lista_Destinatarios(ArrayList* );

int cargar_Destinatarios(ArrayList*, FILE*, char*);

int lista_Destinatarios_atendidos (ArrayList* , ArrayList* );

int depurar_Destinatarios(ArrayList*, ArrayList*, ArrayList*, FILE*);

#endif // DESTINATARIOS_H_INCLUDED

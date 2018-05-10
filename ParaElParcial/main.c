#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 30


/**---------------------------VALIDACIONES-------------------------------------------------*/
char validarnombre(char input[]){
   int siEs;
   char aux[50];
do{

    fflush(stdin);
    gets(aux);

     if(soloNombre(aux))
    {
        strcpy(input,aux);
    }
    else{
         printf("Error: debe ingresar datos enteros\n vuelva a ingresar:\n ");

    }
}while(!soloNombre(aux));
    return input[50];
}

int soloNombre(char str[])
{
    int i=0;
    int retorno=2;


    while(str[i] != '\0')
    {
    if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
            retorno= 0;
        i++;
    }
    else {
        retorno=1;
    }
    return retorno;

}
}
int validarNumero(int numero1)
{
int a;
int b;
char numAux[30];
do{
 fflush(stdin);
 gets(numAux);
 b=atoi(numAux);

    if(b==0){
     printf("Error: debe ingresar datos enteros\n vuelva a ingresar: ");
    }
    else{
     a=atoi(numAux);
     numero1=a;
    }
 }while(b==0);

 return numero1;
}
/**----------------------------------------------------------------------------------------*/

/**-------------------------------FUNCIONES---------------------------------------*/
int inicializar;
    int index;
    int opcion;
    char respuesta;
    eUsuario usuario[TAM];
    eProducto Producto[TAM];

    inicializar=usuarioinit(usuario,TAM);

int usuarioinit(eUsuario usuario[],int cant){
    int retorno = -1;
    int i;
    if(cant > 0 && usuario != NULL){
        retorno = 0;
        for(i=0; i<cant; i++){
            usuario[i].estado= LIBRE;
            usuario[i].idUsuario = LIBRE;
        }
    }
    return retorno;
}

int usuariobuscarLugarLibre(eUsuario usuario[],int cant){
    int retorno = -1;
    int i;
    if(cant > 0 && usuario != NULL){
        retorno = -2;
        for(i=0;i<cant;i++){
            if(usuario[i].estado == LIBRE){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int usuariosiguienteId(eUsuario usuario[],int cant){
    int retorno = 0;
    int i;
    if(cant > 0 && usuario != NULL){
        for(i=0; i<cant; i++){
            if(usuario[i].estado == OCUPADO){
                    if(usuario[i].idUsuario>retorno){
                         retorno=usuario[i].idUsuario;
                    }

            }
        }
    }

    return retorno+1;
}

int usuariobuscarPorId(eUsuario usuario[] ,int cant){
    int retorno = -1;
    int i;
    int auxid;
    printf("ingrese id de usuario");
    scanf("%d", auxid);
    if(cant > 0 && usuario != NULL){
        retorno = -2;
        for(i=0;i<cant;i++){
            if(usuario[i].estado == OCUPADO && usuario[i].idUsuario ==auxid){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int usuarioAlta(eUsuario  usuario[],int cant){
    int retorno = -1;
    int indice;
    char auxnombre[50];

    if(cant > 0 && usuario != NULL){
        retorno = -2;
        indice = usuariobuscarLugarLibre(usuario,cant);
        if(indice >= 0){
            retorno = -3;
            usuario[indice].idUsuario = usuariosiguienteId(usuario,cant);

             printf("\n Ingrese un nombreUsuario:\n");
             validarnombreUsuario(auxnombre);
             strcpy(usuario[indice].nombreUsuario, auxnombre);
             printf(" Ingrese contraseña:\n");
             gets(usuario[indice].contrasenia[30]);
             usuario[indice].estado= OCUPADO;
        }
    }
    return retorno;
}

int modificarUsuario(eUsuario usuario[], int cant){
int index;
int aux;
int i;

printf("ingrese idUsuario de usuario\n");
scanf("%d", &aux);
 if(cant > 0 && usuario != NULL){
for(i=0;i<cant; i++){
    if(usuario[i].estado == OCUPADO &&aux==usuario[i].idUsuario){
         printf("\n Ingrese un nombreUsuario:\n");
             usuario[i].nombreUsuario[50]= validarnombreUsuario(usuario[i].nombreUsuario[50]);
             printf(" Ingrese contraseña:\n");
             gets(usuario[i].contrasenia[30]);

   }
  }
 }
 return index;
}

int usuarioBaja(eUsuario usuario[], int cant){

int index=-1;
int auxid;
int i;

printf("Ingrese Id de la usuario que desea dar de baja:\n");
auxid=validUsuarioarNumero(auxid);

for(i=0;i<cant;i++){
    if(usuario[i].estado==OCUPADO && usuario[i].idUsuario==auxid){
        usuario[i].estado=LIBRE;
        index=0;
        break;
    }
}
return index;
}

int usuariomostrarUno(eUsuario usuario){
    int index;
    printf("\n %s - %d - %d",usuario.nombreUsuario ,usuario.idUsuario ,usuario.estado);
    return index;
}

int usuarioMostrarListado(eUsuario usuario[],int cant){
    int retorno = -1;
    int i;
    if(cant > 0 && usuario != NULL){
        retorno = 0;
        for(i=0; i<cant; i++){
            if(usuario[i].estado==OCUPADO){

                usuariomostrarUno(usuario[i]);
            }
        }
    }
    return retorno;
}

#define TAM 20
#define OCUPADO 1
#define LIBRE 0

typedef struct{

char nombre[50];
int edad;
int dni;
int estado;

}ePersona;

typedef struct
{
    int idUsuario;
    char nombreUsuario[TAM][50];
    char contrasenia[TAM][50];
    int estado;

}eUsuario;

typedef struct
{

    int idProducto[TAM];
    char nombre[TAM][30];
    float precio[TAM];
    int stock[TAM];
    int cantVendida[TAM];
}eProducto;

/** \brief inicializa todos los estados en 0
 * \param recibe una persona
 * \param recibe la cantidad de personas que se pueden ingresar
 */
void inicializar(ePersona persona[],int cant);

/** \brief busca un espacio libre para ingresar una nueva persona
 * \param recibe una persona
 * \param recibe la cantidad de personas que se pueden ingresar
 * \return devuelve la primera posicion libre que encuentre en orden ascendente
 */
int buscarLibre(ePersona persona[], int cant);

/** \brief ingresa una nueva persona
 * \param recibe una persona
 * \param recibe la cantidad de personas que se pueden ingresar
 * \return un valor tipo flag que indique si se pudo ingresar o no
 */
int altaPersona(ePersona persona[], int cant);

/** \brief libera uno de los espacios ocupados por una persona
 * \param recibe una persona
 * \param recibe la cantidad de personas que se pueden ingresar
 * \return
 */
int bajaPersona(ePersona persona[], int cant);

/** \brief muestra las personas ingresadas en orden alfabetico
 * \param recibe una persona
 * \param recibe la cantidad de personas que se pueden ingresar
 */
void mostrarListaPorNombre(ePersona persona[], int cant);

/** \brief muestra un grafico de las edades de las personas ingresadas
 * \param recibe una persona
 * \param recibe la cantidad de personas que se pueden ingresar
 */
void mostrarGrafico(ePersona persona[], int cant);




void inicializar( ePersona persona[],int cant){
    int i;
    if(cant > 0 && persona != NULL)
    {
        for(i=0; i<cant; i++)
        {
            persona[i].estado= LIBRE;
            persona[i].dni= 0;
        }
    }
}




int buscarLibre(ePersona persona[], int cant){
int indice=-1;
int i;

for(i=0;i<20;i++){
    if(persona[i].estado==0){
        indice=i;
        break;
    }
}
return indice;
}

int altaPersona(ePersona persona[], int cant){

int index=-1;
int indice;
indice=buscarLibre(persona,20);
if(indice!=-1){

    printf("\n Ingrese un nombre:\n");
   persona[indice].nombre[50]=validarnombre(persona[indice].nombre);
    printf(" Ingrese edad:\n");
    persona[indice].edad=validarNumero(persona[indice].edad);
    printf(" Ingrese un Dni:\n");
    persona[indice].dni=validarNumero(persona[indice].dni);

    persona[indice].estado= OCUPADO;

    index=0;
}
return index;
}

int bajaPersona(ePersona persona[], int cant){

int index=-1;
int auxDni;
int i;

printf("Ingrese DNI de la persona que desea dar de baja:\n");
auxDni=validarNumero(auxDni);

for(i=0;i<20;i++){
    if(persona[i].dni==auxDni){
        persona[i].estado=LIBRE;
        index=0;
        break;
    }
}
return index;
}

void mostrarListaPorNombre(ePersona persona[], int cant){
int i;
int j;
int k;
char auxnombre[50];
int auxDni;
int auxEdad;

for(i=0;i<20-1;i++){
if(persona[i].estado==OCUPADO){
    for(j=i+1;j<20;j++){
        if(strcmp(persona[j].nombre,persona[i].nombre)<0 && persona[j].estado==OCUPADO){
            strcpy(auxnombre , persona[j].nombre);
            strcpy(persona[j].nombre, persona[i].nombre);
            strcpy(persona[i].nombre, auxnombre );

              auxDni=persona[j].dni;
              persona[j].dni=persona[i].dni;
              persona[i].dni=auxDni;

              auxEdad=persona[j].edad;
              persona[j].edad=persona[i].edad;
              persona[i].edad=auxEdad;
   }
  }
 }
}

for(k=0;k<20;k++){
    if(persona[k].estado==OCUPADO){
     printf("\n NOMBRE:%s\n EDAD:%d\n DNI:%d\n \n ", persona[k].nombre, persona[k].edad, persona[k].dni);
  }
 }
}

void mostrarGrafico(ePersona persona[], int cant){
    int i;
    int j;
    int menos18=0, entre18y35=0, mas35=0, contOcupado=0;

    for(i=0;i<cant;i++){
            if(persona[i].estado==OCUPADO){
                if(persona[i].edad<18){
                menos18++;
                }
                else if(persona[i].edad>35){
                    mas35++;
                }
                else{
                    entre18y35++;
                }
               contOcupado++;
            }
      }
      for(j=contOcupado; j>=0;j--){
            if(menos18<=j){
                printf("     ");
            }
            else{
                printf("  *  ");
            }
            if(entre18y35<=j){
                printf("     ");
            }
            else{
                printf("   *  ");
            }
            if(mas35<=j){
                printf("     \n");
            }
            else{
                printf("  *  \n");
            }
      }
      printf("x<18 18>x<35 x>35\n\n");

}




/**-------------------------------------------------ESQUELETO DE MENU-----------------------------------------------*/

ePersona persona[20];
int opcion;
int index;
char respuesta[2];

inicializar(persona, 20);
/* inicializa todos los estados en 0 */

do{
printf("\n 1. Agregar una persona\n 2. Borrar una persona\n 3. Imprimir lista ordenada por nombre\n 4. Imprimir grafico de edades\n");
printf("\n opcion: ");
fflush(stdin);
opcion=validarNumero(opcion);

switch(opcion){

case 1:
    index=altaPersona(persona,20);
    if(index==0){
        printf("Persona Agregada\n");
    }
    else{
        printf("Error\n");
    }
    break;
case 2:
    index=bajaPersona(persona,20);
    if(index==0){
        printf("Persona dada de baja\n");
    }
    else{
        printf("la persona no ha sido dada de baja\n");
    }
    break;
case 3:
    mostrarListaPorNombre(persona,20);
    break;
case 4:
    mostrarGrafico(persona,20);
    break;
default :
    printf("\n Error: ingrese alguna de las opciones dadas con anterioridad.\n");
    break;
}
/* menu de opciones */

printf("volver a ingresar?: ");
scanf("%s", respuesta);

}while(strcmp(respuesta,"s")==0);
/*condicion para que se repita la iteracion
*/
return 0;
}
/**---------------------------------------------ESTRUCTURAS GENERICAS---------------------------------------------*/
/**---------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1

int eGen_init( eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idGenerica= 0;
        }
    }
    return retorno;
}

int eGen_buscarLugarLibre(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int eGen_siguienteId(eGenerica listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idGenerica>retorno)
                    {
                         retorno=listado[i].idGenerica;
                    }
            }
        }
    }
    return retorno+1;
}

int eGen_buscarPorId(eGenerica listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_mostrarUno(eGenerica parametro)
{
     printf("\n %s - %d - %d",parametro.nombre,parametro.idGenerica,parametro.estado);
}
int eGen_mostrarListado(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                eGen_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}

int eGen_mostrarListadoConBorrados(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eGen_mostrarUno(listado[i]);
        }
    }
    return retorno;
}

int eGen_alta(eGenerica  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eGen_siguienteId(listado,limite);
            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                retorno = 0;
                strcpy(listado[indice].nombre,"juan ");
                listado[indice].idGenerica = id;
                listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}

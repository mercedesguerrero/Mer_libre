#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define TAM 10
#define OCUPADO 0
#define LIBRE 1
#define CANTIDAD 10

void mostrarMenu()
{
    system("cls");

    printf("\nMER LIBRE>>> Seleccione una opcion: \n\n");

    printf("1- Crear cuenta de usuario \n");
    printf("2- Modificar datos de usuario\n");
    printf("3- Dar de baja usuario\n");
    printf("4- VENDER PRODUCTO - Nueva publicacion\n");
    printf("5- Modificar producto publicado\n");
    printf("6- Cancelar publicacion\n");
    printf("7- COMPRAR PRODUCTO\n");
    printf("8- listadoUsuario de publicaciones por Usuario\n");
    printf("9- Lista de productos publicados\n");
    printf("10- Lista de usuarios registrados\n");
    printf("11- Salir\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}


int eUsuario_init (eUsuario listadoUsuario[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoUsuario != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listadoUsuario[i].estado= LIBRE;
            listadoUsuario[i].idUsuario= 0;
        }
    }
    return retorno;
}

int eUsuario_buscarLugarLibre(eUsuario listadoUsuario[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoUsuario != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listadoUsuario[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**< BUSCA EL MAYOR Y DEVUELVE EL SIGUIENTE */
int eUsuario_siguienteId(eUsuario listadoUsuario[],int limite)
{
    int retorno = 0;
    int i;
    int flag=0;

    if(limite > 0 && listadoUsuario != NULL)
    {
        flag =1;
        for(i=0; i<limite; i++)
        {
            if(listadoUsuario[i].estado == OCUPADO)
            {
                    if(listadoUsuario[i].idUsuario>retorno)
                    {
                         retorno=listadoUsuario[i].idUsuario;
                    }

            }
        }
    }

    if(flag==1)
    {
        retorno= retorno+1; //LE SUMO 1 PARA QUE DE EL SIGUIENTE ID
    }
    if(flag==0)
    {
        retorno=-1;
    }

    return retorno;
}


int eUsuario_buscarPorId(eUsuario listadoUsuario[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoUsuario != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listadoUsuario[i].estado == OCUPADO && listadoUsuario[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



void eUsuario_mostrarUno(eUsuario listadoUsuario[])
{
     printf("\n %s - %d - %d", listadoUsuario.nombre[], listadoUsuario.idUsuario, listadoUsuario.estado);
}

int eUsuario_mostrarlistadoUsuario(eUsuario listadoUsuario[],int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && listadoUsuario != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listadoUsuario[i].estado==OCUPADO)
            {

                eUsuario_mostrarUno(listadoUsuario[i]);
            }
        }
    }
    return retorno;
}


int eUsuario_mostrarlistadoUsuarioConBorrados(eUsuario listadoUsuario[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoUsuario != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listadoUsuario[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUsuario_mostrarUno(listadoUsuario[i]);
        }
    }
    return retorno;
}




int eUsuario_alta(eUsuario listadoUsuario[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listadoUsuario != NULL)
    {
        retorno = -2;
        indice = eUsuario_buscarLugarLibre(listadoUsuario, limite);

        if(indice > 0)//HAY LUGAR LIBRE EN EL VECTOR
        {
            retorno = -3;
            id = eUsuario_siguienteId(listadoUsuario, limite);

            if(id>= 0)//por si hay inconsistencia
            {
                getValidString("Ingrese su nombre: \n","Ha superado el m�ximo", nombre,50);
                retorno = 0;
                strcpy(listadoUsuario[indice].nombre, nombre);
                listadoUsuario[indice].idUsuario = id;
                listadoUsuario[indice].estado = OCUPADO;
            }
        }
    }
    return retorno;
}

void eUsuario_baja(eUsuario listadoUsuario[], int limite, int id)
{
    int i;

    eUsuario_mostrarlistadoUsuario(listadoUsuario, CANTIDAD);

    printf( "\n \t Seleccione ID a dar de baja");
    getchar();

    for (i=0; i<limite; i++)
    {
        if(listadoUsuario[i].estado == OCUPADO && listadoUsuario[i].idUsuario == id)
            {
                listadoUsuario[i].idUsuario= 0;
                listadoUsuario[i].estado== LIBRE;
            }

    }
}

/**< PIDE UN STRING DE CARACTERES */
void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf("%s", input);
}

/** \brief VALIDA QUE UN STRING DE CARACTERES NO SE EXCEDA DEL L�MITE
 *
 * \param mensaje a ser mostrado
 * \param mensaje de error
 * \param input Array donde se cargar� el texto ingresado
 * \param limite de caracteres
 */

void getValidString(char mensaje[], char error[], char input[], int limite)
{
    int j;
    char auxString[limite+200]; //por si se pasa

    getString(mensaje, input);

    j= strlen(input);

    while (j>= limite)
    {
        printf("Ha ingresado %d caracteres\n %s", j, error);
        getString(mensaje, input);

        j= strlen(input);

    }

    strcpy(auxString, input);
}


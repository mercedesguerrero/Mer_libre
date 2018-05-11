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

/**< INICIALIZA ESTADO EN LIBRE Y ID DE USUARIO EN 0 */
int eUsuario_init (eUsuario usuario[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuario != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            usuario[i].estado= LIBRE;
            usuario[i].idUsuario= 0;
        }
    }
    return retorno;
}

/**< BUSCA UN LUGAR LIBRE EN EL ARRAY Y SI LO ENCUENTRA DEVUELVE EL ÍNDICE */
int eUsuario_buscarLugarLibre(eUsuario usuario[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuario != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(usuario[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**< BUSCA EL MAYOR Y DEVUELVE EL SIGUIENTE */
int eUsuario_siguienteId(eUsuario usuario[],int limite)
{
    int retorno = 0;
    int i;
    int flag=0;

    if(limite > 0 && usuario != NULL)
    {
        flag =1;
        for(i=0; i<limite; i++)
        {
            if(usuario[i].estado == OCUPADO)
            {
                    if(usuario[i].idUsuario>retorno)
                    {
                         retorno=usuario[i].idUsuario;
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

/**< BUSCA POR ID Y SI LO ENCUENTRA DEVUELVE EL ÍNDICE */
int eUsuario_buscarPorId(eUsuario usuario[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuario != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(usuario[i].estado == OCUPADO && usuario[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/**< MUESTRA UN USUARIO */
void eUsuario_mostrarUno(eUsuario usuario[])
{
     printf("\n %s - %d - %d", usuario[].nombre, usuario[].idUsuario, usuario[].estado);
}

/**< MUESTRA LISTA DE USUARIOS */
int eUsuario_mostrarlistadoUsuario(eUsuario usuario[],int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && usuario != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(usuario[i].estado==OCUPADO)
            {

                eUsuario_mostrarUno(usuario[i]);
            }
        }
    }
    return retorno;
}


int eUsuario_mostrarlistadoUsuarioConBorrados(eUsuario usuario[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuario != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(usuario[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUsuario_mostrarUno(usuario[i]);
        }
    }
    return retorno;
}

/**< DA DE ALTA USUARIOS */
int eUsuario_alta(eUsuario usuario[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && usuario != NULL)
    {
        retorno = -2;
        indice = eUsuario_buscarLugarLibre(usuario, limite);

        if(indice > 0)//HAY LUGAR LIBRE EN EL VECTOR
        {
            retorno = -3;
            id = eUsuario_siguienteId(usuario, limite);

            if(id>= 0)//por si hay inconsistencia
            {
                getValidString("Ingrese su nombre: \n", "Ha superado el máximo", nombre, 50);
                usuario[indice].idUsuario = id;
                strcpy(usuario[indice].nombre, nombre);
                usuario[indice].estado = OCUPADO;
                retorno = 0;
            }
        }
    }
    return retorno;
}

/**< DA DE BAJA USUARIOS */
void eUsuario_baja(eUsuario usuario[], int limite, int id)
{
    int i;

    eUsuario_mostrarlistadoUsuario(usuario, CANTIDAD);

    printf( "\n \t Seleccione ID a dar de baja");
    scanf("%d", i);//VER ESTO getchar();

    for (i=0; i<limite; i++)
    {
        if(usuario[i].estado == OCUPADO && usuario[i].idUsuario == id)
            {
                usuario[i].idUsuario= 0;
                usuario[i].estado== LIBRE;
            }
    }
}

/**< PIDE UN STRING DE CARACTERES */
void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf("%s", input);
}

/** \brief VALIDA QUE UN STRING DE CARACTERES NO SE EXCEDA DEL LÍMITE
 *
 * \param mensaje a ser mostrado
 * \param mensaje de error
 * \param input Array donde se cargará el texto ingresado
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


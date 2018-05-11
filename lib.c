#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


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
int eUsuario_init (eUsuario usuarios[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            usuarios[i].estado= LIBRE;
            usuarios[i].idUsuario= 0;
        }
    }
    return retorno;
}

/**< BUSCA UN LUGAR LIBRE EN EL ARRAY */
int eUsuario_buscarLugarLibre(eUsuario usuarios[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(usuarios[i].estado == LIBRE)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**< BUSCA EL MAYOR Y DEVUELVE EL SIGUIENTE */
int eUsuario_siguienteId(eUsuario usuarios[],int limite)
{
    int retorno = 0;
    int i;
    int flag=0;

    if(limite > 0 && usuarios != NULL)
    {
        flag =1;
        for(i=0; i<limite; i++)
        {
            if(usuarios[i].estado == OCUPADO)
            {
                    if(usuarios[i].idUsuario> retorno)
                    {
                         retorno= usuarios[i].idUsuario;
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

/**< DA DE ALTA USUARIOS */
int eUsuario_alta(eUsuario usuarios[], int limite)
{
    int retorno = -1;
    char nombre[50];
    int idUsuario;
    int indice;

    if(limite > 0 && usuarios != NULL)
    {
        retorno = -2;
        indice = eUsuario_buscarLugarLibre(usuarios, limite);

        if(indice== 0)//HAY LUGAR LIBRE EN EL VECTOR
        {
            retorno = -3;
            idUsuario = eUsuario_siguienteId(usuarios, limite);

            if(idUsuario>= 0)//por si hay inconsistencia
            {
                getValidString("Ingrese su nombre: \n", "Ha superado el maximo. ", nombre, 50);
                strcpy(usuarios[indice].nombre, nombre);
                usuarios[indice].idUsuario = idUsuario;
                usuarios[indice].estado = OCUPADO;
                retorno = 0;
            }
        }
    }
    return retorno;
}

/**< BUSCA POR ID Y SI LO ENCUENTRA DEVUELVE EL ÍNDICE */
int eUsuario_buscarPorId(eUsuario usuarios[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(usuarios[i].estado == OCUPADO && usuarios[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**< MUESTRA LISTA DE USUARIOS */
int eUsuario_mostrarlistadoUsuario(eUsuario usuarios[], int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && usuarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(usuarios[i].estado==OCUPADO)
            {

                eUsuario_mostrarUno(usuarios[i]);
            }
        }
    }
    return retorno;
}

/**< MUESTRA UN USUARIO */
void eUsuario_mostrarUno(eUsuario usuario)
{
     printf("\n %s - %d - %d", usuario.nombre, usuario.idUsuario, usuario.estado);
}

int eUsuario_mostrarlistadoUsuarioConBorrados(eUsuario usuarios[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(usuarios[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUsuario_mostrarUno(usuarios[i]);
        }
    }
    return retorno;
}


/**< DA DE BAJA USUARIOS */
void eUsuario_baja(eUsuario usuarios[], int limite, int id)
{
    int i;

    eUsuario_mostrarlistadoUsuario(usuarios, CANTIDAD);

    printf( "\n \t Seleccione ID a dar de baja");
    scanf("%d", i);//VER ESTO getchar();

    for (i=0; i<limite; i++)
    {
        if(usuarios[i].estado == OCUPADO && usuarios[i].idUsuario == id)
            {
                usuarios[i].idUsuario= 0;
                usuarios[i].estado== LIBRE;
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


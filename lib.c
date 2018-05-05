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

int eUsuario_siguienteId(eUsuario listadoUsuario[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listadoUsuario != NULL)
    {
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

    return retorno+1;
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



int eUsuario_mostrarUno(eUsuario usuario[])
{
     printf("\n %s - %d - %d", usuario.nombre[], usuario.idUsuario, usuario.estado);

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
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsuario_siguienteId(listadoUsuario, limite);

            printf("\nIngrese nombre: ");
            gets(usuario.nombre);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                retorno = 0;
                strcpy(usuario[indice].nombre);
                usuario[indice].idUsuario = id;
                usuario[indice].estado = OCUPADO;
            //}
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
                listadoUsuarioUsuarioerico[i].idUsuario== 0;
                listadoUsuarioUsuarioerico[i].estado== LIBRE;
            }

    }
}

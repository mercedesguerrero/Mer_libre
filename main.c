#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define TAMPRODUCTO 1000
#define TAMUSUARIO 100


int main()
{

    char seguir='s';
    int opcion=0;
    int id;


    eUsuario listadoUsuario[TAMUSUARIO];

    eUsuario_init(listadoUsuario, TAMUSUARIO);

    /*
    printf( "\n \t muestro el array... esta vacio");
    eUsuario_mostrarListado(usuario,TAMUSUARIO);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios");
    eUsuario_mostrarListadoConBorrados(usuario, TAMUSUARIO);
    getchar();

    eUsuario_alta(usuario, TAMUSUARIO);
    eUsuario_alta(usuario, TAMUSUARIO);
    printf( "\n \t cargo dos elementos y muestro el array");
    eUsuario_mostrarListado(usuario, TAMUSUARIO);


    eUsuario_baja(usuario, TAMUSUARIO, id);

    printf( "\n \t muestro el array con los borrados y vacios");
    eUsuario_mostrarListadoConBorrados(usuario, TAMUSUARIO);

    */


    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\nALTA DE USUARIO \n");
                presionarContinuar();
                break;
            case 2:
                eUsuario_mostrarUno(listadoUsuario[]);

                printf("\nMODIFICAR DATOS DEL USUARIO \n");
                presionarContinuar();
                break;
            case 3:
                printf("\nBAJA DEL USUARIO \n");
                presionarContinuar();
                break;
            case 4:
                printf("\nPUBLICAR PRODUCTO \n");
                presionarContinuar();
                break;
            case 5:
                printf("\nMODIFICAR PUBLICACIÓN \n");
                presionarContinuar();
                break;
            case 6:
                printf("\nCANCELAR PUBLICACIÓN \n");
                presionarContinuar();
                break;
            case 7:
                printf("\nCOMPRAR PRODUCTO\n");
                presionarContinuar();
                break;
            case 8:
                printf("\nLISTAR PUBLICACIONES DE USUARIO\n");
                presionarContinuar();
                break;
            case 9:
                printf("\nLISTAR PUBLICACIONES\n");
                presionarContinuar();
                break;
            case 10:
                printf("\nLISTAR USUARIOS\n");
                presionarContinuar();
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');



    return 0;
}


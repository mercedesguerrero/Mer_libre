#ifndef ESTRUCTURAUSUARIO_H_INCLUDED
#define ESTRUCTURAUSUARIO_H_INCLUDED

typedef struct
{
    int idProducto;
    char nombre[50];
    char descripcion[50];
    float precio;
    int stock;
    int estado;
}eProducto;

typedef struct
{
    int idUsuario;
    char nombre[50];
    int estado;
}eUsuario;

typedef struct
{
    int idUsuario;
    int idProducto;
    int estado;
}eProducto_Usuario;

#endif // ESTRUCTURAUSUARIO_H_INCLUDED

int eUsuario_init(eUsuario[],int limite);
int eUsuario_buscarPorId(eUsuario[] ,int limite, int id);
int eUsuario_siguienteId(eUsuario[] ,int limite);
int eUsuario_buscarLugarLibre(eUsuario listadoUsuario[],int limite);

void eUsuario_mostrarUno(eUsuario listadoUsuario[]);
int eUsuario_mostrarListado(eUsuario[] ,int limite);
int eUsuario_mostrarListadoConBorrados(eUsuario[] ,int limite);

int eUsuario_alta(eUsuario[] ,int limite);
void eUsuario_baja(eUsuario listadoUsuario[], int limite, int id);
int eUsuario_modificacion(eUsuario[] ,int limite, int id);

int eUsuario_ordenar(eUsuario[] ,int limite, int orden);

void mostrarMenu();
void presionarContinuar();


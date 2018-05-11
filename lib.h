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
}eVentas;

#endif // ESTRUCTURAUSUARIO_H_INCLUDED

int eUsuario_init(eUsuario[],int limite);
int eUsuario_buscarPorId(eUsuario[] ,int limite, int id);
int eUsuario_siguienteId(eUsuario[] ,int limite);
int eUsuario_buscarLugarLibre(eUsuario[],int limite);

void getString(char mensaje[], char input[]);
void getValidString(char mensaje[], char error[], char input[], int limite);

void eUsuario_mostrarUno(eUsuario[]);
int eUsuario_mostrarlistadoUsuario(eUsuario[] ,int limite);
int eUsuario_mostrarlistadoUsuarioConBorrados(eUsuario[] ,int limite);

int eUsuario_alta(eUsuario[] ,int limite);
void eUsuario_baja(eUsuario[], int limite, int id);
int eUsuario_modificacion(eUsuario[] ,int limite, int id);

int eUsuario_ordenar(eUsuario[] ,int limite, int orden);

void mostrarMenu();
void presionarContinuar();


#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
//Definicion de los metodos
long tamArchivo(char* directorio);
int cantidadElementos(char *directorio);
char *concatenar(char *directorio, char* nombre);
void reservarEspacio(char **arreglo, int length);
char ** listaArchivos(char *directorio, int length);

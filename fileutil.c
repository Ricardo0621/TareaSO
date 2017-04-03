#include "fileutil.h"

//tamArchivo: recibe un directorio y retorna su tamano en bytes
long tamArchivo(char* directorio) {
    FILE *fichero; //Apuntador de tiṕo File
    long contador = 0; //Variable iteradora
    fichero = fopen(directorio, "rb"); //Abrimos un archivo de solo lectura
    while (fgetc(fichero) != EOF) { //Mientras que no alcancemos el final del archivo
        contador++;//Contamos 
    }
    fclose(fichero); //Cerramos el directorio
    return contador; //retornamos el tamano del archivo
}

//cantidadElementos: recibe un directorio y retorna la cantidad de archivos que se encuentran en ese directorio
int cantidadElementos(char *directorio) {
    DIR *d; //Apuntador de tipo dir
    d = opendir(directorio); //Abrimos el directorio especificado
    struct dirent *dir; //Utilizamos una estructura de tipo dirent
    int length; //Variable iteradora
    if (d) { //Si la cadena de caracteres corresponde a un directorio
        while ((dir = readdir(d)) != NULL) { //Mientras que haya algo para leer
            if (dir->d_type != DT_DIR) //Filtramos entre los archivos del directorio
                length++; //Contamos cada archivo
        }
        closedir(d); //Cerramos el directorio
    } else //Si la cadena recibida no corresponde a un directorio imprimimos un mensaje
        printf("La ruta especificada no corresponde a un directorio");
    return length;
}

//concatenar: Recibe un directorio y el nombre un archivo y los concatena  
char *concatenar(char *directorio, char* nombre)
{
	char* aux; //Variable utilizada para concatenar
	aux = malloc(strlen(directorio) + 1 + strlen(nombre)); //Reservamos memoria suficinete para el directorio,el nombre del archivo y el caracter "/" 
    strcpy(aux, directorio); //Copiamos el directorio a la variable auxiliar
    strcat(aux, "/"); //concatenamos el caracter "/" a la varibale auxiliar
    strcat(aux, nombre); //concatenamos el nombre del archivo a la varibale auxiliar
	return aux; //Retornamos toda la ruta del archivo
}

//reservarEspacio: Recibe un arreglo de cadena de caracteres y reserva en cada posicion el espacio correspondiente a la cantidad de elementos en un directorio
void reservarEspacio(char **arreglo, int length)
{
    for (int j = 0; j < length; j++)
        arreglo[j] = malloc(length); 
}

//listaArchivos: Recibe un directorio y la cantidad de sus elementos y retorna un arreglo lleno con la ruta de los archivos presentes en el directorio
char ** listaArchivos(char *directorio, int length) { 
    DIR *d;
    d = opendir(directorio);
    int it = 0;
    struct dirent *dir;
    char ** arrayAux;
    arrayAux = malloc(length * sizeof (char*)); 
    reservarEspacio(arrayAux, length); 
    if (d) {
        while ((dir = readdir(d)) != NULL) { 
            if (dir->d_type != DT_DIR) { 
                char *temp = concatenar(directorio, dir->d_name);
                strcpy(arrayAux[it], temp);
                it++;
            }
        }
        closedir(d); 
    } else
        printf("La ruta especificada no corresponde a un directorio");
    return arrayAux;
}

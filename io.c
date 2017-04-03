#include "fileutil.h"

int main(int argc, char** argv) {
    if(argc != 2)
		printf("Error");
    char* codigo = "1524778";
    char **arrayFinal;
    char *fichero = argv[1]; //fichero pasado por consola
    long size = 0;
    int length = cantidadElementos(fichero); //calcula el tamaño del archivo
    arrayFinal = malloc(length * sizeof (char*));
    arrayFinal = listaArchivos(fichero, length); //retorna el arreglo con la ruta de cada archivo presente        
    for (int j = 0; j < length; j++){
		size = size + tamArchivo(arrayFinal[j]); // calcula el tamano de todos los archivos presentes en el directorio
	}    
	printf("Estudiante_1: %s\nTotal Archivos: %d\nTotal Bytes: %ld\n", codigo, length, size);
    return 0;
}

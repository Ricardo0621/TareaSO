#include "fileutil.h"

int main(int argc, char** argv) {
    if(argc != 2)
		printf("Error");
    char* codigo = "1524778";
    char **arrayFinal;
    char *fichero = argv[1];
    int length = cantidadElementos(fichero);
    arrayFinal = malloc(length * sizeof (char*));
    arrayFinal = listaArchivos(fichero, length);         
    int fd[2];
    long tamPadre = 0;
	//Se apoya en fork para dividir la tarea de contar el tamano de cada elemento en el arreglo con contiene las rutas de los archivos en el directorio    
	pipe(fd);
    int pid;
    if ((pid = fork())) {
        long tamHijo;
        close(fd[1]);
        for (int i = 0; i < (length/2); i++) {
            tamPadre = tamPadre + tamArchivo(arrayFinal[i]);
        }
        read(fd[0], &tamHijo, sizeof (tamHijo));
        printf("Estudiante_1: %s\nTotal Archivos: %d\nTotal Bytes: %ld\n", codigo, length, tamHijo + tamPadre);
    } else {
        close(fd[0]);
        for (int j = (length / 2); j < length ; j++) {
            tamPadre = tamPadre + tamArchivo(arrayFinal[j]);
        }
        write(fd[1], &tamPadre, sizeof (tamPadre));
    }
    return 0;
}

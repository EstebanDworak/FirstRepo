#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct ALUMNO {
   int expediente;
   char *nombre;
   int carrera;
   int edad;
} ALUMNO;



int firstAvailable(int *array, int size);
void registrar(ALUMNO *pointer, int *array, int expediente,char *nombre,int carrera,int edad);
void print(ALUMNO *pointer);
void menu(int *option);
void printAll(int *array,ALUMNO *pointer, int size);


void deleteElement(int *array, int n ){
	array[n-1]=1;
}



int main(void) {

	setbuf(stdin,NULL);
	fflush(stdout);

	ALUMNO alumnos[SIZE];

	int option = 0;

	int available[SIZE];
	for(int i=0;i<SIZE;i++) available[i]=1;


	registrar(alumnos,available,713782,"Esteban",12,18);
	registrar(alumnos,available,713782,"DONG",12,18);
	registrar(alumnos,available,713782,"RICHARD",12,18);
	registrar(alumnos,available,713782,"CESAR",12,18);


	printAll(available,alumnos, 20);

	deleteElement(available,2);

	registrar(alumnos,available,713782,"PONCHO",12,18);
	printAll(available,alumnos, 20);

}



void registrar(ALUMNO *pointer, int *array, int expediente,char *nombre,int carrera,int edad){
	int av = firstAvailable(array,SIZE);
	(pointer+av)->expediente=expediente;
	(pointer+av)->nombre = nombre;
	(pointer+av)->edad = edad;
	(pointer+av)->carrera = carrera;
	array[av]=0;
}

void print(ALUMNO *pointer){
	printf("%d",pointer->expediente);
	printf("%s",pointer->nombre);
	printf("%d",pointer->edad);
	printf("%d\n\n",pointer->carrera);
}

int firstAvailable(int *array, int size){
	for(int i=0;i<SIZE;i++){
		if(*(array+i)==1){
			return i;
		}
	}
	return -1;
}

void printAll(int *array,ALUMNO *pointer, int size){
	for(int i=0;i<size;i++){
		printf("%d - ",i+1);
		if(*(array+i)==0){
			printf("%d ",(pointer+i)->expediente);
			printf("%s ",(pointer+i)->nombre);
			printf("%d ",(pointer+i)->edad);
			printf("%d\n",(pointer+i)->carrera);
		}else{
			printf("LIBRE\n");
		}
	}
}

void menu(int *option){
	printf("\n\t\t Menu");
	printf("\n\t1 - Registrar nuevo alumno");
	printf("\n\t2 - Imprimir datos");
	printf("\n\t3 - Eliminar alumno");
	printf("\n\t1 - Buscar alumno");
	fflush(stdout);

	scanf("%d",option);
}

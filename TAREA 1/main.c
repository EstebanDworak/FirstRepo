#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[15];
    float calificacion;
} Profesor;


void readArray(Profesor *profesorArray, int size);
void printArray(Profesor *profesorArray, int size);
void mergeArrays(Profesor *profesorArray1, int size1, Profesor *profesorArray2, int size2, Profesor *profesorArray3, int size3);
void sortArray(Profesor *profesorArray, int size);

int compararInt(const void *a, const void *b);
int compararString(const void *a, const void *b);
int sim(Profesor *profes,int n);


int main(){
    setbuf(stdout,NULL);
    fflush(stdin);

    Profesor arr1[20];
	Profesor arr2[20];
	Profesor arrF[40];

	int n1, n2;

	printf("\n\nIngrese la cantidad de elementos de la primra lista: ");
    fflush(stdin);
    scanf("%d",&n1);
    readArray(arr1,n1);

	printf("\n\nIngrese la cantidad de elementos de la segunda lista: ");
    fflush(stdin);
    scanf("%d",&n2);
    readArray(arr2,n2);


    mergeArrays(arr1,n1,arr2,n2,arrF, n1+n2);


    int newSize = sim(arrF,n1+n2);
    sortArray(arrF,newSize);
	printf("\n\n");
	printArray(arrF,newSize);


}


void readArray(Profesor *profesorArray, int size){

    for(int i=0; i<size; i++){
        printf("\n\n\t\t%d: Nombre: ",i+1);
        fflush(stdin);
        scanf("%[^\n]",(profesorArray+i)->nombre);
        printf("\t\t   Calificacion: " );
        fflush(stdin);
        scanf("%f",&(profesorArray+i)->calificacion);
    }
}

void printArray(Profesor *profesorArray, int size){
    printf("Profesores: \n\n");
    for(int i=0; i<size; i++) printf("\t%d: Nombre: %s\n\t   Calificacion: %f\n\n",i+1 , (profesorArray+i)->nombre, (profesorArray+i)->calificacion);
}



void mergeArrays(Profesor *profesorArray1, int size1, Profesor *profesorArray2, int size2, Profesor *profesorArray3, int size3){
    for(int i=0; i<size1; i++){
        (profesorArray3)->calificacion=(profesorArray1+i)->calificacion;
        strcpy((profesorArray3)->nombre, (profesorArray1+i)->nombre);
        profesorArray3++;
    }

    for(int i=0; i<size2; i++){
        (profesorArray3+i)->calificacion=(profesorArray2+i)->calificacion;
        strcpy( (profesorArray3+i)->nombre, (profesorArray2+i)->nombre );
    }
}

void sortArray(Profesor *arrF, int size){qsort(arrF, size, sizeof(Profesor), compararInt);}


int sim(Profesor *profesores,int n){

    qsort(profesores, n, sizeof(Profesor), compararString);

	int c=1,c2=0;
	float promedio = profesores[0].calificacion;

	for(int i = 1; i<n;i++){
		if(strcmp(profesores[i].nombre, profesores[i-1].nombre) == 0){
			promedio+=profesores[i].calificacion;
			c++;
		}else{
            profesores[c2].calificacion=promedio/c;
			strcpy(&profesores[c2+1].nombre, &profesores[i].nombre);
			c2++,c=1,promedio+=(-promedio+profesores[i].calificacion);
		}

	}

	profesores[c2].calificacion=promedio/c;
	return c2+1;
}

int compararString(const void *a, const void *b){
    Profesor *ia = (Profesor *)a; Profesor *ib = (Profesor *)b;
    return strcmp(ia->nombre, ib->nombre);
}

int compararInt(const void *a, const void *b){
    Profesor *ia = (Profesor *)a; Profesor *ib = (Profesor *)b;
    return ia->calificacion < ib->calificacion;
}





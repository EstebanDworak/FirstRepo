#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_THREADS 16

typedef struct{
	long long inicio;
	long long fin;
	double sumaParcial;
	HANDLE thread;
}Thread;


DWORD WINAPI suma(void *param);

int main(void) {

	setbuf(stdout,NULL);
	fflush(stdin);
	printf("Running...\n");
	clock_t start = clock();

	long long precision = 1000000000;
	double sumaFinal = 0;
	Thread threads[MAX_THREADS];


	for(int i=0;i<MAX_THREADS;i++){
		threads[i].inicio= precision/MAX_THREADS*i+1;
		threads[i].fin= precision/MAX_THREADS*(i+1);
		threads[i].sumaParcial=0;

		threads[i].thread = CreateThread(NULL, 0, suma, (void *)&threads[i], 0, NULL);
	}

	for(int i=0;i<MAX_THREADS;i++) WaitForSingleObject(threads[i].thread, INFINITE);


	for(int i=0;i<MAX_THREADS;i++) sumaFinal+=threads[i].sumaParcial;
	printf("\n%.15f",sumaFinal*4);


	clock_t stop = clock();
	printf("\n\n%d ms", 1000 * (stop -start)/CLOCKS_PER_SEC);

}

DWORD WINAPI suma(void *param){

	Thread *r=(Thread*)param;

	for(long long i=r->inicio;i<=r->fin;i+=2){
		r->sumaParcial+=(1.0)/(2*i-1);
		r->sumaParcial-=(1.0)/(2*(i+1)-1);
	}
	return 0;

}

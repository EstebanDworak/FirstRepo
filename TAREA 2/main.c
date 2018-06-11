#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	clock_t start = clock();

	int n;
	printf("Hilos:\t");
	scanf("%d", &n);

	long long precision = 50000000000;
	double sumaFinal = 0;
	Thread threads[n];

	for(int i=0;i<n;i++){
		threads[i].inicio= precision/n*i+1;
		threads[i].fin= precision/n*(i+1);
		threads[i].sumaParcial=0;
		threads[i].thread = CreateThread(NULL, 0, suma, (void *)&threads[i], 0, NULL);
	}

	for(int i=0;i<n;i++) WaitForSingleObject(threads[i].thread, INFINITE);
	for(int i=0;i<n;i++) sumaFinal+=threads[i].sumaParcial;
	printf("Pi:\t%.15f",sumaFinal*4);

	clock_t stop = clock();
	printf("\nTiempo:\t%d ms", 1000 * (stop -start)/CLOCKS_PER_SEC);

}

DWORD WINAPI suma(void *param){

	Thread *r=(Thread*)param;
	for(long long i=r->inicio;i<=r->fin;i+=1) r->sumaParcial+=(i%2==0 ? (-1.0):1.0 )/(2*i-1) ;

}

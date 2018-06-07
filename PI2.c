/*
 ============================================================================
 Name        : hilos_suma.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_THREADS 3

typedef struct{
	int inicio;
	int fin;
	unsigned long sumaParcial;
	HANDLE thread;
}Thread;



DWORD WINAPI suma(void *param);



int main(void) {
	Thread threads[MAX_THREADS]={
			{0,10000,0,NULL},
			{10001,20000,0,NULL},
			{20000,30000,0,NULL},
	};



	for(int i=0;i<MAX_THREADS;i++)threads[i].thread = CreateThread(NULL, 0, suma, (void *)&threads[i], 0, NULL);

	for(int i=0;i<MAX_THREADS;i++) WaitForSingleObject(threads[i].thread, INFINITE);

	for(int i=0;i<MAX_THREADS;i++) 	printf("Sumatoria del rango %d: %lu \n",i, threads[i].sumaParcial);


	return 0;
}

DWORD WINAPI suma(void *param){

	Thread *r=(Thread*)param;

	int i;
	for(i=r->inicio;i<=r->fin;i++)
		r->sumaParcial+=i;
	return 0;


/*
	for(long i =1; i<10000000;i+=2){
			sum+=(1.0)/(2*i-1);
			sum-=(1.0)/(2*(i+1)-1);
		}*/

}

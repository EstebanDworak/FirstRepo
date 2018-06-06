/*
 ============================================================================
 Name        : PI.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#define MAX_THREADS 1
long long mainCounter = 1;

DWORD WINAPI calcular(double *suma);


int main(void) {

	setbuf(stdout,NULL);
	fflush(stdin);

	printf("running...\n\n");
	double sum=0;


	clock_t start = clock();



/*
	HANDLE hThreadArray[MAX_THREADS];

	for(int i=0;i<MAX_THREADS;i++){
		 hThreadArray[i] = CreateThread(NULL, 0, (void *)calcular, &sum, 0, NULL);
	}

    WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);
    */




	for(long i =1; i<3000000000;i+=2){
		sum+=(1.0)/(2*i-1);
		sum-=(1.0)/(2*(i+1)-1);
	}



	sum*=4;
	printf("\n%.20f",sum);
	printf("\n3.1415926535897932");


	clock_t stop = clock();
	int ms = 1000 * (stop -start)/CLOCKS_PER_SEC;
	printf("\n%d ms", ms);

}


DWORD WINAPI calcular(double *suma){
	while(mainCounter<300000000){
		*suma+=(1.0)/(2*mainCounter-1);
		*suma-=(1.0)/(2*(mainCounter+1)-1);
		mainCounter+=2;
	}
	printf("\nDONE\n");

}



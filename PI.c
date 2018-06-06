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


#define THREADS 16
long long mainCounter = 1;
long long precision = 100000;
double sum=0;
double c =1;

DWORD WINAPI calcular(double *suma);


void main() {

	setbuf(stdout,NULL);
	fflush(stdin);

	printf("running...\n\n");
	clock_t start = clock();
	HANDLE hThreadArray[THREADS];

	for(int i=0;i<THREADS;i++){
		 hThreadArray[i] = CreateThread(NULL, 0, calcular, &sum, 0, NULL);
		 if (hThreadArray[i] == NULL)printf("error");

	}
	//WaitForSingleObject(hThreadArray[0], INFINITE);
    WaitForMultipleObjects(THREADS, hThreadArray, TRUE, INFINITE);


    for(int i=0; i<THREADS; i++) CloseHandle(hThreadArray[i]);





	sum*=4;
	printf("\n%.20f",sum);
	printf("\n3.1415926535897932");


	clock_t stop = clock();
	printf("\n\n%d ms", 1000 * (stop -start)/CLOCKS_PER_SEC);

}


DWORD WINAPI calcular(double *suma){

	while(mainCounter<precision){
		sum+=c/(2*mainCounter-1);
		c*=-1;
		//sum-=(1.0)/(2*(mainCounter+1)-1);
		mainCounter++;
	}

}














/*
 *
 *

	for(long i =1; i<10000000;i+=2){
		sum+=(1.0)/(2*i-1);
		sum-=(1.0)/(2*(i+1)-1);
	}

 *
 * */

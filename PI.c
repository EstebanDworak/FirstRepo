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


#define THREADS 8
long long mainCounter = 1;
int i=0;
long long precision = 5000000000;
DWORD WINAPI calcular(double *suma);


void main() {

	setbuf(stdout,NULL);
	fflush(stdin);

	printf("running...\n\n");
	double sum=0;


	clock_t start = clock();


	HANDLE hThreadArray[THREADS];

	for(i=0;i<THREADS;i++){
		 hThreadArray[i] = CreateThread(NULL, 0, (void *)calcular, &sum, 0, NULL);
	}
	//WaitForSingleObject(hThreadArray[0], INFINITE);
    WaitForMultipleObjects(THREADS, hThreadArray, TRUE, INFINITE);





	sum*=4;
	printf("\n%.20f",sum);
	printf("\n3.1415926535897932");


	clock_t stop = clock();
	int ms = 1000 * (stop -start)/CLOCKS_PER_SEC;
	printf("\n%d ms", ms);

}


DWORD WINAPI calcular(double *suma){
	long long n1= precision/THREADS*(long long)(i-1);
	long long n2= precision/THREADS*(long long)i;

	printf("\n%lli A %lli",n1,n2);

	for(long long i =n1+1 ; i<n2;i+=2){
		*suma+=(1.0)/(2*i-1);
		*suma-=(1.0)/(2*(i+1)-1);
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

/*
 ============================================================================
 Name        : TAREA 3.c
 Author      : Esteban Cervantes
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "lib.h"

#define clear() system("cls")



int main(void) {

	setbuf(stdout,NULL);
	fflush(stdin);

	int focused=0;
	char n2;
	int flag = 0;
	int temp;


	while(focused!=4){

		printMenu();

		if(flag==0) scanf("%d",&focused);
		else flag=0;

		switch(focused) {

		case 1:
			printMenuClient();
			scanf("%s",&n2);
			clear();
			printf("\n<< System MyDB >>\n");
			switch(n2) {
				case 'a':
					getClients();
					getch();
				break;
				case 'b':
					printf("\n\tInsert id: ");
					scanf("%d",&temp);
					printf("\n\tSearch Result: \n");
					findClient(temp);
					getch();
				break;
				case 'c':
					printf("\n\tInsert id: ");
					scanf("%d",&temp);
					deleteClient(temp);
				break;
				case 'd':
					printf("\n\tAll clients: \n");
					getClients();
					getch();
				break;
				default:
					focused=(int)n2-48;
					printf("focused:%d",focused);
					flag=1;
				break;
			}
		break;

		case 2:
			printMenuAccount();
			scanf("%s",&n2);
			switch(n2) {
				case 'a':
					printf("AAA");
				break;
				default:
					focused=(int)n2-48;
					printf("focused:%d",focused);
					flag=1;
				break;
			}
		break;


		case 3:
			printMenuTransactions();
			scanf("%s",&n2);
			switch(n2) {
				case 'a':
					printf("AAA");
				break;
				default:
					focused=(int)n2-48;
					printf("focused:%d",focused);
					flag=1;
				break;
			}
		break;


		}
	}

	CLIENT usurarios[5];

	if(!fileExist("clientes.dat")){
        printf("Archivo clientes.dat no existe, creando uno nuevo:");
        createFile("clientes.dat");
    }

	if(!fileExist("cuentas.dat")){
        printf("Archivo cuentas.dat no existe, creando uno nuevo:");
        createFile("cuentas.dat");
    }

	if(!fileExist("transacciones.dat")){
        printf("Archivo transacciones.dat no existe, creando uno nuevo:");
        createFile("transacciones.dat");
    }


    for(int i=0;i<5;i++){

        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        usurarios[i].id=i+1;
        strcpy(usurarios[i].name, "Esteban");
        strcpy(usurarios[i].lastName1, "Cervantes");
        strcpy(usurarios[i].lastName2, "Dworak");
        usurarios[i].date.DD=timeinfo->tm_mday;
        usurarios[i].date.MM=timeinfo->tm_mon;
        usurarios[i].date.YYYY=timeinfo->tm_year + 1900;
        usurarios[i].date.hh=timeinfo->tm_hour;
        usurarios[i].date.mm=timeinfo->tm_min;
        usurarios[i].date.ss=timeinfo->tm_sec;

        //addClient(usurarios[i]);
    }



    getClients();


	return EXIT_SUCCESS;
}

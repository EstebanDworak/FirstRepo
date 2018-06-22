/*
 ============================================================================
 Name        : MyDataBase
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

	if(!fileExist("tested.dat")){
        printf("Archivo transacciones.dat no existe, creando uno nuevo:");
        createFile("tested.dat");
    }


	setbuf(stdout,NULL);
	fflush(stdin);

	int focused=0;
	char n2;
	int flag = 0;
	int temp;
    time_t rawtime;
    struct tm * timeinfo;
	//CLIENT clientTemplate={40,"Esteban","Cervantes","Dworak",{10,5,2018}};
	CLIENT clientTemplate;
	//ACCOUNT accountTemplate = {100,5,1000,{10,5,2018}};
	ACCOUNT accountTemplate ;
	TRANSACCION transactionTemplate = {1,1,1,1,{10,5,2018},300};

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

                        time ( &rawtime );
                        timeinfo = localtime ( &rawtime );

                        fflush(stdin);
                        printf("\n\tName:");
                        scanf("%20[^\n]", clientTemplate.name);
                        fflush(stdin);
                        printf("\tLast Name 1:");
                        scanf("%20[^\n]", clientTemplate.lastName1);
                        fflush(stdin);
                        printf("\tLast Name 2:");
                        scanf("%20[^\n]", clientTemplate.lastName2);

                        clientTemplate.date.DD=timeinfo->tm_mday;
                        clientTemplate.date.MM=timeinfo->tm_mon;
                        clientTemplate.date.YYYY=timeinfo->tm_year + 1900;
                        clientTemplate.date.hh=timeinfo->tm_hour;
                        clientTemplate.date.mm=timeinfo->tm_min;
                        clientTemplate.date.ss=timeinfo->tm_sec;

                        addStructToFile(0,&clientTemplate);
                    break;
                    case 'b':
                        printf("\n\tInsert id: ");
                        scanf("%d",&temp);
                        findStructsFromFile(0,temp);
                    break;
                    case 'c':
                        printf("\n\tInsert id: ");
                        scanf("%d",&temp);
                        deleteStructFromFile(0,temp);
                    break;
                    case 'd': printStructsFromFile(0); break;
                    default:
                        focused=(int)n2-48;
                        flag=1;
                    break;
                }
            break;

            case 2:
                printMenuAccount();
                scanf("%s",&n2);
                clear();
                printf("\n<< System MyDB >>\n");
                switch(n2) {
                    case 'a':

                        time ( &rawtime );
                        timeinfo = localtime ( &rawtime );

                        fflush(stdin);
                        printf("\n\tId of user:");
                        fflush(stdin);
                        scanf("%d", &accountTemplate.idUser);

                        printf("yep");

                        //accountTemplate.idUser=1000;
                        accountTemplate.balance=1000;
                        accountTemplate.date.DD=timeinfo->tm_mday;
                        accountTemplate.date.MM=timeinfo->tm_mon;
                        accountTemplate.date.YYYY=timeinfo->tm_year + 1900;
                        accountTemplate.date.hh=timeinfo->tm_hour;
                        accountTemplate.date.mm=timeinfo->tm_min;
                        accountTemplate.date.ss=timeinfo->tm_sec;

                        printf("yep");
                        addStructToFile(1,&accountTemplate);
                    break;
                    case 'b':
                        printf("\n\tInsert id: ");
                        scanf("%d",&temp);
                        findStructsFromFile(1,temp);
                    break;
                    case 'c':
                        printf("\n\tInsert id: ");
                        scanf("%d",&temp);
                        deleteStructFromFile(1,temp);
                    break;
                    case 'd': printStructsFromFile(1); break;
                    default:
                        focused=(int)n2-48;
                        flag=1;
                    break;
                }
            break;


            case 3:
                printMenuTransactions();
                scanf("%s",&n2);
                clear();
                printf("\n<< System MyDB >>\n");
                switch(n2) {
                    case 'a':
                        addStructToFile(2,&transactionTemplate);
                    break;
                    case 'b':
                        printf("\n\tInsert id: ");
                        scanf("%d",&temp);
                        findStructsFromFile(1,temp);
                    break;
                    case 'c':
                        printf("\n\tInsert id: ");
                        scanf("%d",&temp);
                        deleteStructFromFile(1,temp);
                    break;
                    case 'd': printStructsFromFile(2); break;
                    default:
                        focused=(int)n2-48;
                        flag=1;
                    break;
                }
            break;

            case 4:
                exit(1);
            break;
		}
        if(flag==0){
            printf("\n\n\n\tPress key to continue...");
            getch();
        }

	}






	//clientTemplate={40,"Esteban","Cervantes","Dworak",{10,5,2018}};


    //addStructToFile("clientes.dat",&clientTemplate,(long)sizeof(CLIENT));
    //addStructToFile("cuentas.dat",&accountTemplate,(long)sizeof(ACCOUNT));


	return EXIT_SUCCESS;
}





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



void checkFile(FILE *f){
    if (!f){
        printf("No se pudo crear archivo!");
        return 1;
    }
}

int fileExist(const char * filename){
    FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}

void createFile(char *name){
    int index = 0;
    FILE *f_temp = fopen(name,"wb");
    checkFile(f_temp);
    fwrite(&index, sizeof(int), 1, f_temp);
    fclose(f_temp);
}



void printMenu(){
	clear();
	printf("\n<< System MyDB >>\n");
	printf("\n\t1.  Clients");
	printf("\n\t2.  Accounts");
	printf("\n\t3.  Transactions");
	printf("\n\t4.  Exit\n\n");
}
void printMenuClient(){
	clear();
	printf("\n<< System MyDB >>\n");
	printf("\n\t1.  Clients");
		printf("\n\t\ta.  Insert Client");
		printf("\n\t\tb.  Find Client");
		printf("\n\t\tc.  Delete Client");
		printf("\n\t\td.  Print Clients");
	printf("\n\t2.  Accounts");
	printf("\n\t3.  Transactions");
	printf("\n\t4.  Exit\n\n");

}

void printMenuAccount(){
	clear();
	printf("\n<< System MyDB >>\n");
	printf("\n\t1.  Clients");
	printf("\n\t2.  Accounts");
		printf("\n\t\ta.  Create Account");
		printf("\n\t\tb.  Find Account");
		printf("\n\t\tc.  Delete Account");
		printf("\n\t\td.  Print Accounts");
	printf("\n\t3.  Transactions");
	printf("\n\t4.  Exit\n\n");

}
void printMenuTransactions(){
	clear();
	printf("\n<< System MyDB >>\n");
	printf("\n\t1.  Clients");
	printf("\n\t2.  Accounts");
	printf("\n\t3.  Transactions");
		printf("\n\t\ta.  Deposit");
		printf("\n\t\tb.  Redraw");
		printf("\n\t\tc.  Transfer");
		printf("\n\t\td.  Print Transactions");
	printf("\n\t4.  Exit\n\n");

}

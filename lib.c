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

void deleteClient(int n){
    CLIENT client;
    int tmp;

    FILE *f = fopen("clientes.dat","rb");
    FILE *f_tmp=fopen("tmp.bin", "wb");
    checkFile(f_tmp);
    checkFile(f);

    fread(&tmp,sizeof(int),1,f);
    fwrite(&tmp, sizeof(int), 1, f_tmp);

	while (fread(&client,sizeof(CLIENT),1,f) != NULL) {
        if (client.id!=n) fwrite(&client, sizeof(CLIENT), 1, f_tmp);
    }

    fclose(f);
	fclose(f_tmp);
	remove("clientes.dat");
	rename("tmp.bin", "clientes.dat");

}

void getClients(){
    CLIENT client;

    FILE *f = fopen("clientes.dat","rb");
    checkFile(f);

    fseek(f, sizeof(int), SEEK_SET);
	while (fread(&client,sizeof(CLIENT),1,f) != NULL) printClient(client);
    fclose(f);
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

void addClient(CLIENT client){
    int index;

    FILE *f = fopen("clientes.dat","r+b");
    checkFile(f);

    fread(&index,sizeof(int),1,f);
    rewind(f);
    index++;
    fwrite(&index, sizeof(int), 1, f);
	fseek(f, 0L, SEEK_END);
    fwrite(&client, sizeof(client), 1, f);

    fclose(f);
}

void printClient(CLIENT user){
	printf("\n\t%d",user.id);
	printf("\t%s",user.lastName1);
	printf("\t%s",user.lastName2);
	printf("\t%s",user.name);
	printf("\t%d/%d/%d %d:%d:%d",user.date.DD,user.date.MM,user.date.YYYY,user.date.hh,user.date.mm,user.date.ss);
}

void findClient(int id){
    CLIENT client;

    FILE *f = fopen("clientes.dat","rb");
    checkFile(f);

    fseek(f, sizeof(int), SEEK_SET);
	while (fread(&client,sizeof(CLIENT),1,f) != NULL) {
        if(client.id==id) printClient(client);
    }
    fclose(f);
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
	printf("\n\t4.  Exit\n\n");

}

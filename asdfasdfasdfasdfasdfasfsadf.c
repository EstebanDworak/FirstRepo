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

#define clear() system("cls")
typedef struct {
	int DD, MM, YYYY, hh, mm, ss ;
} DATE;


typedef struct {
	int id;
	char name[50];
	char lastName1[50];
	char lastName2[50];
	DATE date;
} CLIENT;


typedef struct {
	int id;
	int idUser;
	int balance;
	DATE apertureDate;
} ACCOUNT;


typedef struct {
	int id;
	int type;
	int originId;
	int destinationId;
	DATE date;
	int amount;
} TRANSACCION;


void addClient(CLIENT client);
void findClient(int id);
void deleteClient(int n);
void printClient(CLIENT user);
void getClients();


void printMenu();
void printMenuClient();
void printMenuAccount();
void printMenuTransactions();


void checkFile(FILE *f);
void createFile(char *name);
int fileExist(const char * filename);


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

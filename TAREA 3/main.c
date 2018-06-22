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

#define clear() system("cls")

char *ROUTE[200];
char *clientesRoute[200];
char *cuentasRoute[200];
char *transaccionesRoute[200];

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
	DATE date;
} ACCOUNT;

typedef struct {
	int id;
	int type;
	int originId;
	int destinationId;
	DATE date;
	int amount;
} TRANSACCION;



void checkFile(FILE *f);
int fileExist(const char * filename);
void createFile(char *name);

void printMenu();
void printMenuClient();
void printMenuAccount();
void printMenuTransactions();

void printClient(CLIENT user);
void printAccount(ACCOUNT account);
void printTransaction(TRANSACCION account);
void printStructsFromFile(int type);
void findStructsFromFile(int type, int id);

void deleteStructFromFile(int type, int id);
void addStructToFile(int type,void *struc);
void addValue(int id,int amount);


int main(void) {

    if(!fileExist("mydb.sys")){
        printf("\n\n\tInsert route for files:\n\t");
        scanf("%200[^\n]", ROUTE);

        FILE *f = fopen("mydb.sys","w");
        checkFile(f);
        fprintf(f,ROUTE);
        fclose(f);
    }

    FILE *f = fopen("mydb.sys", "r");
    fgets(ROUTE, 200, f);
    fclose(f);

    strcat(clientesRoute, ROUTE);
    strcat(clientesRoute, "clientes.dat");
    strcat(cuentasRoute, ROUTE);
    strcat(cuentasRoute, "cuentas.dat");
    strcat(transaccionesRoute, ROUTE);
    strcat(transaccionesRoute, "transacciones.dat");

    if(!fileExist(clientesRoute)) createFile(clientesRoute);
	if(!fileExist(cuentasRoute)) createFile(cuentasRoute);
	if(!fileExist(transaccionesRoute)) createFile(transaccionesRoute);

	setbuf(stdout,NULL);
	fflush(stdin);

	int focused=0;
	char n2;
	int flag = 0;
	int temp;
    time_t rawtime;
    struct tm * timeinfo;

	CLIENT clientTemplate;
	ACCOUNT accountTemplate ;
	TRANSACCION transactionTemplate;

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
                        scanf("%d", &accountTemplate.idUser);

                        accountTemplate.balance=1000;
                        accountTemplate.date.DD=timeinfo->tm_mday;
                        accountTemplate.date.MM=timeinfo->tm_mon;
                        accountTemplate.date.YYYY=timeinfo->tm_year + 1900;
                        accountTemplate.date.hh=timeinfo->tm_hour;
                        accountTemplate.date.mm=timeinfo->tm_min;
                        accountTemplate.date.ss=timeinfo->tm_sec;

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
                    case 'd':
                        printStructsFromFile(1);
                    break;
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

                time ( &rawtime );
                timeinfo = localtime ( &rawtime );


                transactionTemplate.date.DD=timeinfo->tm_mday;
                transactionTemplate.date.MM=timeinfo->tm_mon;
                transactionTemplate.date.YYYY=timeinfo->tm_year + 1900;
                transactionTemplate.date.hh=timeinfo->tm_hour;
                transactionTemplate.date.mm=timeinfo->tm_min;
                transactionTemplate.date.ss=timeinfo->tm_sec;

                switch(n2) {
                    case 'a':
                        fflush(stdin);
                        printf("\n\tId of account:");
                        scanf("%d", &transactionTemplate.destinationId);
                        fflush(stdin);
                        printf("\n\tAmount:");
                        scanf("%d", &transactionTemplate.amount);

                        transactionTemplate.originId=NULL;
                        transactionTemplate.type=0;
                        addStructToFile(2,&transactionTemplate);
                        addValue(transactionTemplate.destinationId,transactionTemplate.amount);
                    break;
                    case 'b':
                        fflush(stdin);
                        printf("\n\tId of account:");
                        scanf("%d", &transactionTemplate.destinationId);
                        fflush(stdin);
                        printf("\n\tAmount:");
                        scanf("%d", &transactionTemplate.amount);

                        transactionTemplate.originId=NULL;
                        transactionTemplate.type=1;
                        addStructToFile(2,&transactionTemplate);
                        addValue(transactionTemplate.destinationId,-transactionTemplate.amount);
                    break;
                    case 'c':
                        fflush(stdin);
                        printf("\n\tId of origin:");
                        scanf("%d", &transactionTemplate.originId);
                        fflush(stdin);
                        printf("\n\tId of destination:");
                        scanf("%d", &transactionTemplate.destinationId);
                        fflush(stdin);
                        printf("\n\tAmount:");
                        scanf("%d", &transactionTemplate.amount);

                        transactionTemplate.type=2;
                        addStructToFile(2,&transactionTemplate);
                        addValue(transactionTemplate.originId,-transactionTemplate.amount);
                        addValue(transactionTemplate.destinationId,transactionTemplate.amount);
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


	return EXIT_SUCCESS;
}




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


void printClient(CLIENT user){
	printf("\n\t%-4d %-15s %-15s %-15s %d/%d/%d %d:%d:%d",user.id,user.name,user.lastName1,user.lastName2,user.date.DD,user.date.MM,user.date.YYYY,user.date.hh,user.date.mm,user.date.ss);
}


void printAccount(ACCOUNT account){
	printf("\n\t%-4d %-8d %-10d %d/%d/%d %d:%d:%d",account.id,account.idUser,account.balance,account.date.DD,account.date.MM,account.date.YYYY,account.date.hh,account.date.mm,account.date.ss);
}

void printTransaction(TRANSACCION account){
	printf("\n\t%-4d %-8d %-10d %-14d %-8d %d/%d/%d %d:%d:%d",account.id,account.type,account.originId,account.destinationId,account.amount,account.date.DD,account.date.MM,account.date.YYYY,account.date.hh,account.date.mm,account.date.ss);
}

void printStructsFromFile(int type){

    printf("\n\tAll results: \n\n");
    if(type==0){

        CLIENT p_array;
        FILE *f = fopen(clientesRoute,"rb");
        checkFile(f);
        fseek(f, sizeof(int), SEEK_SET);

        printf("\t%-4s %-15s %-15s %-15s %-15s", "ID", "Name", "Last Name","Last Name","Date");
        while (fread(&p_array,sizeof(CLIENT),1,f) != NULL) {
            printClient(p_array);
        }
        fclose(f);
    }

    if(type==1){
        ACCOUNT p_array;
        FILE *f = fopen(cuentasRoute,"rb");
        checkFile(f);
        fseek(f, sizeof(int), SEEK_SET);

        printf("\t%-4s %-8s %-10s %-15s", "ID", "UserId", "Balance","Date");

        while (fread(&p_array,sizeof(ACCOUNT),1,f) != NULL) {
            printAccount(p_array);
        }
        fclose(f);
    }


    if(type==2){
        TRANSACCION p_array;
        FILE *f = fopen(transaccionesRoute,"rb");
        checkFile(f);
        fseek(f, sizeof(int), SEEK_SET);

        printf("\t%-4s %-8s %-10s %-14s %-8s %-15s", "ID", "Type","OriginID", "DestinatioID", "Amount", "Date");
        while (fread(&p_array,sizeof(TRANSACCION),1,f) != NULL) {
            printTransaction(p_array);
        }
        fclose(f);
    }
}


void findStructsFromFile(int type, int id){

    printf("\n\tSearch Result: \n");
    if(type==0){
        CLIENT p_array;
        FILE *f = fopen(clientesRoute,"rb");
        checkFile(f);
        fseek(f, sizeof(int), SEEK_SET);

        while (fread(&p_array,sizeof(CLIENT),1,f) != NULL) {
            if((int)p_array.id==id) printClient(p_array);
        }
        fclose(f);
    }

    if(type==1){
        ACCOUNT p_array;
        FILE *f = fopen(cuentasRoute,"rb");
        checkFile(f);
        fseek(f, sizeof(int), SEEK_SET);

        while (fread(&p_array,sizeof(ACCOUNT),1,f) != NULL) {
            if(p_array.id==id) printAccount(p_array);
        }
        fclose(f);
    }
}


void deleteStructFromFile(int type, int id){

    int tmp;
    if(type==0){
        CLIENT p_array;

        FILE *f = fopen(clientesRoute,"rb");
        FILE *f_tmp=fopen("tmp.bin", "wb");
        checkFile(f_tmp);
        checkFile(f);

        fread(&tmp,sizeof(int),1,f);
        fwrite(&tmp, sizeof(int), 1, f_tmp);

        while (fread(&p_array,sizeof(CLIENT),1,f) != NULL)
            if((int)p_array.id!=id) fwrite(&p_array, sizeof(CLIENT), 1, f_tmp);

        fclose(f_tmp);
        fclose(f);
        remove(clientesRoute);
        rename("tmp.bin", clientesRoute);
    }

    if(type==0){
        ACCOUNT p_array;

        FILE *f = fopen(cuentasRoute,"rb");
        FILE *f_tmp=fopen("tmp.bin", "wb");
        checkFile(f_tmp);
        checkFile(f);

        fread(&tmp,sizeof(int),1,f);
        fwrite(&tmp, sizeof(int), 1, f_tmp);

        while (fread(&p_array,sizeof(ACCOUNT),1,f) != NULL)
            if((int)p_array.idUser!=id) fwrite(&p_array, sizeof(ACCOUNT), 1, f_tmp);

        fclose(f_tmp);
        fclose(f);
        remove(cuentasRoute);
        rename("tmp.bin", cuentasRoute);
    }

    if(type==1){
        ACCOUNT p_array;

        FILE *f = fopen(cuentasRoute,"rb");
        FILE *f_tmp=fopen("tmp.bin", "wb");
        checkFile(f_tmp);
        checkFile(f);

        fread(&tmp,sizeof(int),1,f);
        fwrite(&tmp, sizeof(int), 1, f_tmp);

        while (fread(&p_array,sizeof(ACCOUNT),1,f) != NULL)
            if((int)p_array.id!=id) fwrite(&p_array, sizeof(ACCOUNT), 1, f_tmp);

        fclose(f_tmp);
        fclose(f);
        remove(cuentasRoute);
        rename("tmp.bin", cuentasRoute);
    }



}

void addStructToFile(int type,void *struc){
    if(type==0){
        int index;
        FILE *f = fopen(clientesRoute,"r+b");
        checkFile(f);

        fread(&index,sizeof(int),1,f);
        rewind(f);
        index++;

        ((CLIENT*)struc)->id=index;
        fwrite(&index, sizeof(int), 1, f);
        fseek(f, 0L, SEEK_END);
        fwrite(struc, sizeof(CLIENT), 1, f);

        fclose(f);
    }

    if(type==1){
        int index;
        FILE *f = fopen(cuentasRoute,"r+b");
        checkFile(f);

        fread(&index,sizeof(int),1,f);
        rewind(f);
        index++;

        ((ACCOUNT*)struc)->id=index;
        fwrite(&index, sizeof(int), 1, f);
        fseek(f, 0L, SEEK_END);
        fwrite(struc, sizeof(ACCOUNT), 1, f);

        fclose(f);
    }

    if(type==2){
        int index;
        FILE *f = fopen(transaccionesRoute,"r+b");
        checkFile(f);

        fread(&index,sizeof(int),1,f);
        rewind(f);
        index++;

        ((TRANSACCION*)struc)->id=index;
        fwrite(&index, sizeof(int), 1, f);
        fseek(f, 0L, SEEK_END);
        fwrite(struc, sizeof(TRANSACCION), 1, f);

        fclose(f);
    }

}



void addValue(int id,int amount){

        int tmp;

        ACCOUNT p_array;

        FILE *f = fopen(cuentasRoute,"rb");
        FILE *f_tmp=fopen("tmp.bin", "wb");
        checkFile(f_tmp);
        checkFile(f);

        fread(&tmp,sizeof(int),1,f);
        fwrite(&tmp, sizeof(int), 1, f_tmp);

        while (fread(&p_array,sizeof(ACCOUNT),1,f) != NULL){
            if((int)p_array.id!=id){
                fwrite(&p_array, sizeof(ACCOUNT), 1, f_tmp);
            } else{
                p_array.balance+=amount;
                fwrite(&p_array, sizeof(ACCOUNT), 1, f_tmp);
            }
        }
        fclose(f_tmp);
        fclose(f);
        remove(cuentasRoute);
        rename("tmp.bin", cuentasRoute);

}






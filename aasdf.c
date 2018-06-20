/*
 ============================================================================
 Name        : TAREA 3.c
 Author      : Esteban Cervantes
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int d, m, y;
} DATE;


typedef struct {
	int id;
	char name[50];
	char lastName1[50];
	char lastName2[50];
	DATE date;
} USER;


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


void readUser(USER *user);
void printUser(USER user);


void openFile(char *name, char *format, FILE *f){
	f = fopen(name,"a+b");
	if (!f){
		perror("Error deleting record!");
		exit(1);
	}
}


unsigned long getFileSize(char *name){
	FILE *f = fopen(name,"rb");
	if (!f){
		perror("Error deleting record!");
		exit(1);
	}
	fseek(f, 0L, SEEK_END);
	return ftell(f);
}

int main(void) {

	setbuf(stdout,NULL);
	fflush(stdin);

	USER usurario={2,"Esteban","Cervantes","Dworak",{10,5,2018}};
	//printUser(usurario);


	FILE *f;
	FILE *f1;

	openFile("test.dat", "a+b" ,f);
	openFile("test.dat", "a+b" ,f1);

	printf("%li",getFileSize("test.dat"));



	/*
	f = fopen("clientes.dat","a+b");

	if (!f){
		printf("No se pudo crear archivo!");
		return 1;
	}

	int temp=1;
	int index;
	fseek(f, 0L, SEEK_END);
	if(ftell(f) == 0){
		printf("Archivo creado!");
		fwrite(&temp, sizeof(int), 1, f);
	}else printf("Archivo inicialiado anteriormente");
	fclose(f);



	f = fopen("clientes.dat","r+b");
	if (!f){
		printf("No se pudo crear archivo!");
		return 1;
	}
	fread(&index,sizeof(int),1,f);
	printf("\n%d",index);
	rewind(f);
	index++;
	fwrite(&index, sizeof(int), 1, f);
	fclose(f);



	f = fopen("clientes.dat","a+b");
	if (!f){
		printf("No se pudo crear archivo!");
		return 1;
	}
	fwrite(&usurario, sizeof(USER), 1, f);

*/
	/*
	rewind(f);

	fseek(f,sizeof(int),SEEK_SET );

	fread(&usurario,sizeof(USER),1,f);
	printUser(usurario);
	fread(&usurario,sizeof(USER),1,f);
	printUser(usurario);
*/


	//fclose(f);

	return EXIT_SUCCESS;
}



void printUser(USER user){
	printf("\n%d",user.id);
	printf("\n%s",user.lastName1);
	printf("\n%s",user.lastName2);
	printf("\n%s",user.name);
	printf("\n%d/%d/%d",user.date.d,user.date.m,user.date.y);
}


void readUser(USER *user){
	printf("Ingrese nombre:");

}

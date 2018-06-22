/*
 ============================================================================
 Name        : MyDataBase
 Author      : Esteban Cervantes
 Version     : 1.0
 ============================================================================
 */


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

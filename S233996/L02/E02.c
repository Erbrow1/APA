#include <stdio.h>
#include <string.h>
#include <math.h>

#define MaxN 20
#define N 30
#define MaxL 1000
enum comando_e scelta();
enum comando_e {
	r_invalid = 0, r_partenza = 1, r_capolinea = 2, r_data = 3, r_ritardo = 4, r_fine = 5
};
void printLine(struct Linee Linea);
void funzione(enum comando_e comm, struct Linee Linea[MaxL], int num);
long int convert(char str[N]);
struct Linee {
	char cod[N];
	char partenza[N];
	char destinazione[N];
	char data[N];
	char ora_partenza[N];
	char ora_arrivo[N];
	int ritardo;
};

int main() {
	char comando[N];
	enum comando_e comm;
	int l = 1, i, num;
	long int data[MaxL];
	char t1 = 2018 / 10 / 10;
	char t2 = 2017 / 10 / 23;
	struct Linee Linea[MaxL];
	FILE* fp;
	fp = fopen("log.txt", "r");
	fscanf(fp, "%d", &num);
	printf("FILE LETTO\n");
	for (i = 0; i < num; i++) {
		fscanf(fp, "%s %s %s %s %s %s %d", Linea[i].cod, Linea[i].partenza, Linea[i].destinazione, Linea[i].data, Linea[i].ora_partenza, Linea[i].ora_arrivo, &Linea[i].ritardo);
	}

	while (l == 1) {
		comm = scelta();
		if (comm == r_fine) {
			return 0;
		}
		else if (comm != r_invalid) {
			funzione(comm, Linea, num);
		}
	}
}
enum comando_e scelta() {
	char scelta[N];
	int c = 0;
	printf("|================================================================================================================\n");
	printf("| LISTA COMANDI :\n");
	printf("| DATE : elencare tutte le corse partite in un certo intervallo di date\n");
	printf("| PARTENZA : elencare tutti le corse partite da una certa fermata\n");
	printf("| CAPOLINEA : elencare tutti le corse che fanno capolinea in una certa fermata\n");
	printf("| RITARDO : elencare tutte le corse che hanno raggiunto la destinazione in ritardo in un certo intervallo di date\n");
	printf("| RITARDO_TOT : elencare il ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta\n");
	printf("| FINE : termina esecuzione\n");
	printf("|================================================================================================================\n");
	printf("| Inserisci comando : ");
	scanf("%s", scelta);
	while (scelta[c] != '\0') {
		scelta[c] = toupper(scelta[c]);
		c++;
	}
	if (strcmp(scelta, "DATE") == 0) {
		printf("Intervallo di date");
		printf("Prima data: ");
		return r_data;
	}

	else if (strcmp(scelta, "RITARDO") == 0) {
		return r_ritardo;
	}
	else if (strcmp(scelta, "PARTENZA") == 0) {
		return r_partenza;
	}
	else if (strcmp(scelta, "CAPOLINEA") == 0) {
		return r_capolinea;
	}
	else if (strcmp(scelta, "FINE") == 0) {
		return r_fine;
	}
	else {
		printf("Scelta non valida\n");
		return r_invalid;
	}

}

void funzione(enum comando_e comm, struct Linee Linea[MaxL], int num) {
	long int data1, data2;
	char partenza[N], capolinea[N], cod[N];
	int i, pollo = 2, c = 0;
	switch (comm) {
	case r_data:
		printf("Inserisci 2 date (AAAAMMGG)\n");
		printf("Prima data: ");
		scanf("%li", &data1);
		printf("\nSeconda data: ");
		scanf("%li", &data2);
		printf("\n");
		for (i = 0; i < num; i++) {
			if (convert(Linea[i].data) < data1 || convert(Linea[i].data) > data2) {
			}
			else {
				printLine(Linea[i]);
			}
		}
		break;
	case r_partenza:
		printf("Inserire nome fermata di partenza: ");
		scanf("%s", partenza);
		for (i = 0; i < num; i++) {
			if (strcmp(partenza, Linea[i].partenza) == 0) {
				printLine(Linea[i]);
			}
		}
		break;
	case r_capolinea:
		for (i = 0; i < num; i++) {
			if (strcmp(capolinea, Linea[i].destinazione) == 0) {
				printLine(Linea[i]);
			}
		}
		break;
	case r_ritardo:
		while (pollo != 0 && pollo != 1) {
			printf("Ritardo complessivo per una tratta(1) o ritardo tra date(0)?\n");
			scanf("%d", &pollo);

			if (pollo == 0) {
				printf("Scrivi le date tra cui vuoi sapere i ritardi(AAAAMMGG):\n");
				printf("Prima data: ");
				scanf("%li", &data1);
				printf("\nSeconda data: ");
				scanf("%li", &data2);
				printf("\n");
				for (i = 0; i < num; i++) {
					if (convert(Linea[i].data) < data1 || convert(Linea[i].data) > data2) {
					}
					else if (Linea[i].ritardo == 0) {

					}
					else {
						printLine(Linea[i]);
					}
				}
			}
			else if (pollo == 1) {
				printf("Codice tratta per il ritardo:\n");
				scanf("%s", cod);
				c = 0;
				for (i = 0; i < num; i++) {
					if (strcmp(cod, Linea[i].cod) == 0) {
						c += Linea[i].ritardo;
					}
				}
				printf("Ritardo complessivo per la tratta %s di %d minuti\n", cod, c);

			}
		}
		break;
	}
}

long int convert(char str[N]) {
	long int data = 0;
	int c, z = 0;
	for (c = 0; c < 10; c++) {
		if (str[c] == '\\' || str[c] == '/') {
			continue;
		}
		else {
			data += (str[c] - 48) *pow(10, 7 - z);
			z++;
		}
	}
	return data;
}
void printLine(struct Linee Linea) {
	printf("%s %s %s %s %s %s %d\n", Linea.cod, Linea.partenza, Linea.destinazione, Linea.data, Linea.ora_partenza, Linea.ora_arrivo, Linea.ritardo);

}


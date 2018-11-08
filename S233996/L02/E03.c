#include <stdio.h>
#include <string.h>
#include <math.h>

#define M 25
#define N 5
#define MaxL 200

int main() {
	int num, i, z, c = 0, k = -1, flag = 1, t = 0, j, s = 0, v = 0, lol = 0;
	char parole[20][5], par[25], riga[MaxL];
	FILE* fs;
	fs = fopen("sequenze.txt", "r");
	fscanf(fs, "%d", &num);
	for (i = 0; i < num; i++) {
		fscanf(fs, "%s", parole[i]);
		z = 0;
		while (parole[i][z] != '\0') {
			parole[i][z] = toupper(parole[i][z]);
			z++;
		}
		printf("%s\n", parole[i]);
	}
	fclose(fs);
	fs = fopen("testo.txt", "r");
	while (1) {

		fgets(riga, MaxL, fs);
		if (feof(fs) == 1) break;
		i = 0;
		while (riga[i] != '\0') {
			printf("Ciclo %d\n", i);
			printf("\t\t[%c] ", riga[i]);
			riga[i] = toupper(riga[i]);
			printf("[%c]\n", riga[i]);
			i++;
		}
		printf("RIGA:\n%s", riga);


		for (t = 0; t < MaxL; t++) {
			if (riga[t + 5] == '\0') break;
			if (riga[t] == '\0') break;

			if (isalnum(riga[t]) != 0) {
				if (flag == 1) {
					flag = 0;
					c++;
					j = t;
					k = -1;
				}
				k++;
				for (z = 0; z < num; z++) {
					if (riga[t] == parole[z][0]) {
						s = t;
						i = 0;

						while (riga[s] == parole[z][i]) {
							i++;
							s++;
							if (parole[z][i] == '\0') {
								printf("Sequenza trovata: %s\n", parole[z]);
								break;
							}
						}
					}
				}



			}
			else if (isspace(riga[t]) != 0) {
				if (flag == 0) {
					s = 0;
					printf("[");
					for (i = 0; i <= k; i++) {
						if (riga[i + j] == '\0') break;
						par[s] = riga[i + j];
						printf("%c", par[s]);
						s++;
					}
					par[s] = '\0';
					printf("]\n");
					printf("In parola numero %d : %s\n", c, par);
					flag = 1;
				}
			}
			else if (ispunct(riga[t]) != 0) {
				if (flag == 0) {
					for (i = j; i < j + k; i++) {
						if (riga[i] == '\0') break;
						par[v] = riga[i];
						v++;
					}
					printf("Parola numero %d :\n %s\n", c, par);
					flag = 1;
				}
			}
			else continue;
		}
		lol++;
		printf("Ciclo numero %d", lol);
	}

}

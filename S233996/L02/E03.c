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
	}
	fclose(fs);
	fs = fopen("testo.txt", "r");
	while (1) {

		fgets(riga, MaxL, fs);
		if (feof(fs) == 1) break;
		i = 0;
		while (riga[i] != '\0') {
			riga[i] = toupper(riga[i]);
			i++;
		}
		

		for (t = 0; t < MaxL; t++) {

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
								printf("Sequenza %s\n ", parole[z]);
								break;
							}
						}
					}
				}



			}
			else if (isspace(riga[t]) != 0 || ispunct(riga[t]) != 0) {
				if (flag == 0) {
					s = 0;
					for (i = 0; i <= k; i++) {
						if (riga[i + j] == '\0') break;
						par[s] = riga[i + j];
						s++;
					}
					par[s] = '\0';
					printf(" In parola numero %d : %s\n", c, par);
					flag = 1;
				}
			}
			else continue;
		}
	}

}
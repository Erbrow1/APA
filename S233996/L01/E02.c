#include <stdio.h>
#include <string.h>
#define N 200
#define S 30
int Controlla(char sorg[N], char diz[S][2][N], int n, FILE*fr);
; int main() {
	int len = 0, i, n = 0, k;
	char diz[S][2][N];
	char str[N], parola[N];

	FILE* fd;
	FILE* fs;
	FILE* fr;
	fd = fopen("Dizionario.txt", "r");
	fscanf(fd, "%d", &len);
	for (i = 0; i < len; i++) {
		fscanf(fd, "%s %s", diz[i][0], diz[i][1]);
	}
	fclose(fd);
	fs = fopen("Sorgente.txt", "r");
	fr = fopen("Ricodificato.txt", "w");
	while (feof(fs) != 1) {
		fscanf(fs, "%s", str);
		if (feof(fs) == 1) break;
		Controlla(str, diz, len, fr);
	}




}
int Controlla(char sorg[N], char diz[S][2][N], int n, FILE* fr) {
	int i, k = 0, j = 0, t, c = 0, x, p = 0, s = 0, lun = 0;
	for (i = 0; i < strlen(sorg); i++) {
		for (t = 0; t < n; t++) {
			x = strlen(diz[t][1]);
			k = 0;
			if (x > strlen(sorg)) break;
			if (sorg[i] == diz[t][1][k]) {
				j = i;
				c = 0;
				while (sorg[j] == diz[t][1][k]) {
					if (sorg[j] == '\0') {
						break;

					}

					j++;
					k++;
					c++;
				}
				if (c == x) {
					k = 0;
					s = strlen(diz[t][0]);
					if (s > x) {
						printf("%d>%d", s, x);
						lun = strlen(sorg);
						while (lun >= j) {
							sorg[lun + s - x] = sorg[lun];
							lun--;
						}

					}
					for (p = i; p < i + x || p < i + s; p++) {


						sorg[p] = diz[t][0][k];
						k++;
					}
					printf("%s ==", sorg);
					for (k = 0; k < x; k++) {
						printf("%c", diz[t][1][k]);

					}
					printf("\n");
					i = j;
					break;
				}
			}
		}

	}

	fprintf(fr, "%s ", sorg);
}


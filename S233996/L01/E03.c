#include <stdio.h>


#define N 30

void Ruota(int mat[N][N], int nc, int nr);
int main() {
	int i, k, nr,nc;
	int mat[N][N];
	char nomefile[20];
	FILE* fp;
	printf("Scrivi nome file:\n");
	scanf("%s", nomefile);
	fp = fopen(nomefile, "r");
	fscanf(fp, "%d %d", &nr,&nc);
	for (i = 0; i < nr; i++) {
		printf("[");
		for (k = 0; k < nc; k++) {
			fscanf(fp, "%d", &mat[i][k]);
			printf("%d", mat[i][k]);
		}
		printf("]");
	}
	Ruota(mat, nc, nr);
	printf("Grazie e Arrivederci!");
}
void Ruota(int mat[N][N], int nc, int nr) {
	int ind, pos, i, temp[N], k, t, flag = 0, j = 0, rr, rc;
	char sel[20], dir[20];
	while (strcmp(sel, "fine") != 0) {
		printf("Benvenuto nella funzione ruota!\nDigita per favore <selettore> <indice> <direzione> <posizioni>\n Selettore= (riga colonna o fine)\nIndice(Numero della riga o colonna)\nDirezione(Destra o sinistra e Su o giu)\nPosizioni(Di quante posizioni vuoi ruotare?)\n");
		scanf("%s %d %s %d", sel, &ind, dir, &pos);
		printf("%s %d %s %d\n", sel, ind, dir, pos);
		rr = pos % nr;
		rc = pos % nc;
		if (strcmp(dir, "Destra") == 0 || strcmp(dir, "destra") == 0) {
			printf("DESTRA!\n");
			if (pos%nc == 0) {
				printf("Fatto\n");
			}
			else {
				for (k = 0; k < nc - rc; k++) {

					if (flag == 0) {
						for (i = 0; i < rc; i++) {
							temp[i] = mat[ind - 1][nc - rc + i];
							flag = 1;
							j = i;
						}
						i = 0;
					}
					i = i + j + 1;
					j = 0;
					temp[i] = mat[ind - 1][k];


				}
				for (t = 0; t < nc; t++) {
					mat[ind - 1][t] = temp[t];
				}
				printf("Matrice finale:\n");
				for (i = 0; i < nr; i++) {
					printf("[");
					for (j = 0; j < nc; j++) {
						printf("%d ", mat[i][j]);
					}
					printf("]\n");
				}

			}

		}
		else if (strcmp(dir, "Sinistra") == 0 || strcmp(dir, "sinistra") == 0) {
			printf("Sinistra!\n");
			if (pos%nc == 0) {
				printf("Fatto\n");
			}
			else {
				for (k = 0; k < rc; k++) {


					if (flag == 0) {
						for (i = 0; i < nc - rc; i++) {
							temp[i] = mat[ind - 1][i + rc];
							j = i;
						}
						i = 0;
						flag = 1;
					}
					i = i + j + 1;
					j = 0;
					temp[i] = mat[ind - 1][k];


				}
				for (t = 0; t < nc; t++) {
					mat[ind - 1][t] = temp[t];
				}
				printf("Matrice finale:\n");
				for (i = 0; i < nr; i++) {
					printf("[");
					for (j = 0; j < nc; j++) {
						printf("%d ", mat[i][j]);
					}
					printf("]\n");
				}
			}
		}
		else if (strcmp(dir, "Su") == 0 || strcmp(dir, "su") == 0) {
			printf("SU");
			if (pos%nr == 0) {
				printf("Fatto\n");
			}
			else {
				for (k = 0; k < rr; k++) {


					if (flag == 0) {
						for (i = 0; i < nr - rr; i++) {
							temp[i] = mat[i + rr][ind - 1];
							j = i;
						}
						i = 0;
						flag = 1;
					}
					i = i + j + 1;
					j = 0;
					temp[i] = mat[k][ind - 1];

				}
				for (t = 0; t < nr; t++) {
					mat[t][ind - 1] = temp[t];
				}
				printf("Matrice finale:\n");
				for (i = 0; i < nr; i++) {
					printf("[");
					for (j = 0; j < nc; j++) {
						printf("%d ", mat[i][j]);
					}
					printf("]\n");
				}
			}

		}

		else if (strcmp(dir, "Giu") == 0 || strcmp(dir, "giu") == 0) {
			printf("GIU");
			if (pos%nr == 0) {
				printf("Fatto\n");
			}
			else {
				for (k = 0; k < nr - rr; k++) {

					if (flag == 0) {
						for (i = 0; i < rr; i++) {
							temp[i] = mat[nr - rr + i][ind - 1];
							flag = 1;
							j = i;
						}
						i = 0;
					}
					i = i + j + 1;
					j = 0;
					temp[i] = mat[k][ind - 1];
				}
				for (t = 0; t < nc; t++) {

					mat[t][ind - 1] = temp[t];
				}
				printf("Matrice finale:\n");
				for (i = 0; i < nr; i++) {
					printf("[");
					for (j = 0; j < nc; j++) {
						printf("%d ", mat[i][j]);
					}
					printf("]\n");
				}

			}
		}
		flag = 0;


	}
}
	


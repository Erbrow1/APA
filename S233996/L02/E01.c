#include <stdio.h>
#include <ctype.h>

#define MaxN 20
#define MaxSeqL 5
#define MaxL 50
int main() {
	int nc, nr, i, k, hmax = 0, lmax = 0, A = 0, h = 0, l = 0, a = 0, flag = 3, j, bossh[2], bossl[2], bossA[2];
	int map[MaxL][MaxL];
	FILE* fp;
	fp = fopen("mappa.txt", "r");
	fscanf(fp, "%d %d", &nc, &nr);
	for (i = 0; i < nr; i++) {
		printf("[");
		for (k = 0; k < nc; k++) {
			fscanf(fp, "%d ", &map[i][k]);
			printf("%d ", map[i][k]);
		}
		printf("]\n");
	}

	for (i = 0; i < nr; i++) {
		for (k = 0; k < nc; k++) {
			if (map[i][k] == 1) {
				j = i;
				h = 0;
				l = 0;
				a = 0;
				while (map[j][k] == 1) {
					h++;
					j++;
				}
				if (h > hmax) {
					printf("%d>%d", h, hmax);
					hmax = h;
					bossh[0] = i;
					bossh[1] = k;

				}
				j = k;
				while (map[i][j] == 1) {
					l++;
					j++;
				}
				if (l > lmax) {
					lmax = l;
					bossl[0] = i;
					bossl[1] = k;

				}
				a = l * h;
				if (a > A) {
					A = a;
					bossA[0] = i;
					bossA[1] = k;
				}
			}

		}
	}
	printf("Il rettangolo con altezza piu grande ha l'estremo sinistro in (%d,%d) ed e' alta %d\n", bossh[0], bossh[1], hmax);
	printf("Il rettangolo con larghezza piu grande ha l'estremo sinistro in (%d,%d) ed e' larga %d\n", bossl[0], bossl[1], lmax);
	printf("Il rettangolo con area piu grande ha l'estremo sinistro in (%d,%d) e l'area e' di %d\n", bossA[0], bossA[1], A);



}
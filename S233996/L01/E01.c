int main() {
	int i = 0, k = 0, j = 0, ns = NMAX, ng = NMAX, max = 0;
	int mat[NMAX][NMAX], sum[NMAX] = { NULL };
	FILE* fp;
	fp = fopen("mat.txt", "r");
	for (k = 0; k < ns; k++) {
		for (i = 0; i < ng; i++) {
			fscanf(fp, "%d ", &mat[i][k]);
		}

	}
	for (k = 0; k < ns; k++) {
		printf("Giornata %d:\n", k + 1);
		for (i = 0; i < ng; i++) {
			sum[i] = sum[i] + mat[i][k];
			if (sum[i] > max) {
				max = sum[i];
				j = i + 1;
			}
		}
		printf("Capolista: Squadra %d con %d punti\n", j, max);

	}


}
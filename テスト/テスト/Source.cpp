#pragma warning(disable:4996)
#include <stdio.h>
int main(void) {

	int hairetu[10][10], data;
	int i, j;


	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			hairetu[i][j] = 0;
		}
	}

	hairetu[0][5] = 1;

	while (1) {
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				printf("%d", hairetu[i][j]);
			}
			printf("\n");
		}

		printf("みぎ1　ひだり2　うえ3　した4　おわり　5\n");

		scanf("%d", &data);
		if (data == 1) {
			for (i = 0; i < 10; i++) {
				for (j = 0; j < 10; j++) {
					if (hairetu[i][j] == 1) {

						hairetu[i][j + 1] = 1;
						hairetu[i][j] = 0;

					}
				}
			}
		}
		if (data == 2) {
			for (i = 0; i < 10; i++) {
				for (j = 0; j < 10; j++) {
					if (hairetu[i][j] == 1) {

						hairetu[i][j - 1] = 1;
						hairetu[i][j] = 0;

					}
				}
			}
		}
		if (data == 3) {
			for (i = 0; i < 10; i++) {
				for (j = 0; j < 10; j++) {
					if (hairetu[i][j] == 1) {

						hairetu[i + 1][j] = 1;
						hairetu[i][j] = 0;

					}
				}
			}
		}
		if (data == 4) {
			for (i = 0; i < 10; i++) {
				for (j = 0; j < 10; j++) {
					if (hairetu[i][j] == 1) {

						hairetu[i - 1][j] = 1;
						hairetu[i][j] = 0;

					}
				}
			}
		}
		if (data == 5) {
			break;
		}

	}
}
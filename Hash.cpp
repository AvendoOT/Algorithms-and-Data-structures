#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 128

struct cvor {
	unsigned int kljuc;
	cvor *sljed;
} typedef cvor;

unsigned int adresa(unsigned int sifra) {
	unsigned long int A = 2654435769; //knuth
	unsigned int pomak = 32-7;
	return ((A*sifra) >> pomak)%M;
}

void init_hash(cvor *hash[], int n) {
	int i;
	for (i = 0; i < n; ++i) {
		hash[i] = NULL;
	}
}

int upis(cvor *hash[], unsigned int element) {
	cvor *temp;
	if (temp = (cvor*)malloc(sizeof(cvor))) {
		temp->kljuc = element;
		temp->sljed = NULL;
		unsigned int adressa = adresa(element);
		if (hash[adressa] == NULL) {
			hash[adressa] = temp;
			return 1;
		}
		temp->sljed = hash[adressa];
		hash[adressa] = temp;
		return 1;
	}
	return 0;
}
void hash_print(cvor *hash[], int n) {
	int i;
	cvor *temp;
	for (i = 0; i < n; ++i) {
		if (hash[i] != NULL) {
			temp = hash[i];
			printf("\n[%d]: ", i);
			do {
				printf("%d ", temp->kljuc);
				temp = temp->sljed;
			} while (temp);
		}
	}
}
int main(void) {
	unsigned int i, kljuc;
	cvor *hash[M];
	init_hash(hash, M);
	srand((unsigned)time(NULL));
	for (i = 0; i < 130; i++) {
		kljuc = rand();
		if (!upis(hash, kljuc)) {
			printf("Nema memorije");
			return 0;
		}
	}
	hash_print(hash, M);
	return 0;
}
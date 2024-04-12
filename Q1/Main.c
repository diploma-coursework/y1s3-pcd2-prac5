#include <stdio.h>
#include <stdlib.h>

struct Product {
	char productCode[6];
	int expiryYear;
	char country[26];
} prod;

int main() {
	FILE *filePtr;
	char userChoice;
	filePtr = fopen("product.dat", "ab");

	while (1) {
		printf("Enter product code: ");
		scanf(" %5s", prod.productCode);

		printf("Enter expiry year: ");
		scanf(" %d", &prod.expiryYear);

		printf("Enter country: ");
		scanf(" %25[^\n]", prod.country);

		fwrite(&prod, sizeof(prod), 1, filePtr);

		printf("\nContinue to enter products? (y/n) ");
		scanf(" %c", &userChoice);
		if (userChoice != 'y') break;
	}

	fclose(filePtr);
}
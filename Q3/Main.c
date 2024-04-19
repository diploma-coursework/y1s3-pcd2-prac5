#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
	char productCode[6];
	int expiryYear;
	char country[26];
} p[20];

void modifyProduct() {
	FILE* filePtr = fopen("product.dat", "rb");
	if (filePtr == NULL) {
		printf("Error opening product.dat\n");
		exit(-1);

	}
	int pCount = fread(p, sizeof(struct Product), 20, filePtr);
	fclose(filePtr);

	char inputContinue, inputCountry[26];
	int inputExpiryYear, inputDecision, numOfProductsModified = 0;
	do {
		// get product code to modify
		char inputProductCode[6];
		printf("Enter product code to be modified: ");
		scanf(" %6s", inputProductCode);

		// find the product and modify
		int searchRecordExist = 0;
		for (int i = 0; i < pCount; i++) {
			if (strcmp(inputProductCode, p[i].productCode) != 0) continue;
			searchRecordExist = 1;

			printf("Change expiry year? [%d] (y/n): ", p[i].expiryYear);
			scanf(" %c", &inputDecision);
			if (tolower(inputDecision) == 'y') {
				printf("Enter new expiry year: ");
				scanf(" %d", p[i].expiryYear);
			}

			printf("Change country? [%s] (y/n): ", p[i].country);
			scanf(" %c", &inputDecision);
			if (tolower(inputDecision) == 'y') {
				printf("Enter new country: ");
				scanf(" %26s", p[i].country);
			}
			++numOfProductsModified;
			break;
		}
		if (!searchRecordExist) printf("Could not find products with given code.\n");

		printf("\nContinue to modify products? (y/n): ", &inputContinue);
		inputContinue = tolower(inputContinue);
	} while (inputContinue == 'y');

	// write changes back to the file
	filePtr = fopen("product.dat", "wb");
	if (filePtr == NULL) {
		printf("Error opening product.dat\n");
		exit(-1);
	}
	fwrite(p, sizeof(struct Product), pCount, filePtr);
	fclose(filePtr);
}

int main() {
	modifyProduct();
}
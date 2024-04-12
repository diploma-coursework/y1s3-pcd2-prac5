#include <stdio.h>
#include <windows.h>

struct Product {
	char productCode[6];
	int expiryYear;
	char country[26];
} prod;

void displayProducts() {
	SYSTEMTIME t;
	GetLocalTime(&t);
	FILE *filePtr = fopen("product.dat", "rb");
	
	printf("Product Details - as at %d-%d-%d %d:%d\n\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
	printf("Product Code  Expiry Year  Country\n");
	printf("============  ===========  =======\n");

	while (fread(&prod, sizeof(prod), 1, filePtr)) {
		printf("%-12s  %-11d  %s\n", prod.productCode, prod.expiryYear, prod.country);
	}

	fclose(filePtr);
}

int main() {
	displayProducts();
}
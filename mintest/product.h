#include <stdio.h>
#include <string.h>

typedef struct{
	char name[60];
	int weight;
	int price;
} Product;

int createProduct(Product *p);
void readProduct(Product *p); 
int updateProduct(Product *p);   
int deleteProduct(Product *p);       
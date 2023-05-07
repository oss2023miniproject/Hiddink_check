#include "product.h"

int createProduct(Product *p){
    printf("\n");
    printf("제품명은? ");
    scanf("%[^\n]s",p->name);

    printf("중량은? ");
    scanf("%d",&p->weight);

    printf("가격은? ");
    scanf("%d",&p->price);
    
    printf("==> 추가됨\n"); 
    return 1;
}

void readProduct(Product *p){
    printf("%-15s %3dg %4d원\n",p->name,p->weight,p->price);
}

int updateProduct(Product *p){

    printf("\n");
    printf("제품명은? ");
    scanf("%[^\n]s",p->name);

    printf("중량은? ");
    scanf("%d",&p->weight);

    printf("가격은? ");
    scanf("%d",&p->price);
    printf("==> 수정됨!\n");
    return 1;
};

int deleteProduct(Product *p){
    p->weight=-1;
    p->price=-1;
    printf("==> 삭제됨!\n");
    return 0;
}
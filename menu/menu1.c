#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    int price;
    char type[10];
    
} MENU;


int addMENU(MENU *s){
    printf("메뉴명은? ");
    getchar();
    scanf("%[^\n]s", s->name);
    // printf("%s\n ", s->name);
    printf("메뉴종류(P/S/R)? ");
    getchar();
    scanf("%s",s->type);
    printf("가격은? ");
    scanf("%d",&s->price);
  return 1;
};

void readMENU(MENU s){
    printf("*****************\n");
    printf("1	 %d %s %s\n",s.price,s.type, s.name);
};


int updateMENU(MENU *s){
    printf("메뉴명은? ");
    getchar();
    scanf("%[^\n]s", s->name);
    getchar();
    printf("메뉴종류(P/S/R)? ");
    scanf("%s",s->type);
    printf("가격은? ");
    scanf("%d",&s->price);
    printf("=>수정성공 \n");
    return 0;
};



int deleteMENU(MENU *s){
    s->price=-1;
    printf("=> 삭제됨! \n");
    return 0;
};


int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 조회 2. 추가 3. 수정 4. 삭제 0. 종료 >> ");
    scanf("%d", &menu);
    return menu;
};


int main(void){
    MENU s;
    int count = 0, menu;
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            readMENU(s);
        }
        else if (menu == 2){
            addMENU(&s);
        }
        else if (menu == 3){
            updateMENU(&s);
        }
        else if (menu == 4){
            deleteMENU(&s);
        }
    }
    printf("종료됨!\n");
    return 0;
}

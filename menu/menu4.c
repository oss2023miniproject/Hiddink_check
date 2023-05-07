#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 

typedef struct{
    char name[50];
    int price;
    char type[10];
} MENU;

void saveData(MENU **s, int count){
    FILE *fp;
    fp = fopen("menu.txt", "wt");
    for(int i=0; i<count; i++){
        if(s[i]->price==-1) continue;
        fprintf(fp, "%d %s %s\n",s[i]->price,s[i]->type, s[i]->name);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}

int loadData(MENU **s){
    int count =0;
    FILE *fp;
    fp=fopen("menu.txt", "rt");
    if(fp==NULL){
        printf("=> 파일 없음");
    }
    else{
        while(!feof(fp)){
            s[count]=(MENU *)malloc(sizeof(MENU));
            fscanf(fp, "%d", &s[count]->price);
            if(feof(fp)) break;
            fscanf(fp, "%s", s[count]->type);
            fscanf(fp, "%[^\n]s", s[count]->name);
        count++;
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    }
    
    return count;
}

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

void readMENU(MENU *s){
    printf("	 %d %s %s\n",s->price,s->type, s->name);
};

void listMENU(MENU *s[], int count){
    printf("*****************\n");
    for(int i=0; i<count;i++){
        if(s[i]->price ==-1) continue;
        printf("%2d",i+1);
        readMENU(s[i]);
    }
    printf("\n");
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
    printf("=>수정성공 ");
    return 0;
};

int selectdatano (MENU *s[], int count){
    int no;
    listMENU(s, count);
    printf("번호는? (취소 :0)?");
    scanf("%d", &no);
    return no;
}

int deleteMENU(MENU *s){
    s->price=-1;
    printf("=> 삭제됨! \n");
    return 0;
};


int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 조회 2. 추가 3. 수정 4. 삭제 5. 파일저장 6. 이름 검색 0. 종료 >> ");
    scanf("%d", &menu);
    return menu;
};

void searchName(MENU **s, int count){
    int scnt =0;
    char search[20];
    printf("검색할 이름은? ");
    getchar();
    scanf("%[^\n]s",search);
    printf("*****************\n");
    for(int i=0;i<count;i++){
        if(s[i]->price==-1) continue;
        if(strstr(s[i]->name,search)){
            printf("%2d ", i+1);
            readMENU(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된데이터없음!");
    printf("\n");
};

int main(void){
    MENU *s[20];
    int count = 0, menu;
    int index =0;
    count = loadData(s);
    index =count;


    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            listMENU(s,index);
        }
        else if (menu == 2){
            s[index]=(MENU *)malloc(sizeof(MENU));
            count += addMENU(s[index++]);
        }
        else if (menu == 3){
            int no = selectdatano(s,index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateMENU(s[no-1]);
        }
        else if (menu == 4){
            int no = selectdatano(s,index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deletok;
            printf("정말로 삭제하시겠습까?(삭제 :1)");
            scanf("%d",&deletok);
            if(deletok ==1){
                if(deleteMENU(s[no-1])) count--;
            }
        }
        else if (menu == 5){
            saveData(s,index);
        }
        else if (menu == 6){
            searchName(s,index);
        }

    }
    printf("종료됨!\n");
    return 0;
}

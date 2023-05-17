#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#include "main.h"

int main(void){
    Person *s[20];
    Team *a[24];
    char y[100];//팀의 리더의 이름을 받는 변수,삭제시킬 때 필요.
    int a_index=0;
    int a_count=0;
    int selectnumber;
    int count = 0, menu;
    int index =0;
    int id = idcheck();
    teamfillmethod(a);
    printf("평봉필드 이용 : 1\n히딩크 잔디 이용 : 2");
    scanf("%d",&selectnumber);
    count = loadData(s,selectnumber);
    while (1){//1->인원찾기(기능) 2->팀 예약 3->다른 팀 찾기
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            listproduct(s,index);
        }
        else if (menu == 2){
            s[index]=(Person *)malloc(sizeof(Person));
            count += createProduct(s[index++]);
        }
        else if (menu == 3){
            int no = selectdatano(s,index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(s[no-1]);
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
                if(deleteproduct(s[no-1])) count--;
            }
        }
        else if (menu == 5){
            saveData(s,index,selectnumber);
        }
        else if (menu == 6){
            searchName(s,index);
        }
        else if (menu == 7){
            printTeam(a);
        }
        else if (menu == 8){
            reserveSystem(a);
        }

        else if(menu == 9){
            printf("취소하실 팀의 리더의 이름을 입력해주세요! : ");
            getchar();
            scanf("%[^\n]s",y);
            deleteTeam(a,y);
        }
    }
    printf("종료됨!\n");
    return 0;
}

#include <stdio.h>
typedef struct{
    char name[20];
    int kor;
    int eng;
    int math;
} Score;


int addScore(Score *s){
    printf("이름은?");
    scanf("%s",s->name);
    printf("국어는?");
    scanf("%d",&s->kor);
    printf("영어는?");
    scanf("%d",&s->eng);
    printf("수학는?");
    scanf("%d",&s->math);
    printf("=> 추가됨! \n");
    return 0;
};
void readScore(Score s){

};
int updateScore(Score *s){

};
int deleteScore(Score *s){

};
int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회 2. 추가 3. 수정 4. 삭제 0. 종료 >> ");
    scanf("%d", &menu);
    return menu;
}
int main(void){
    Score *s[100];
    int count = 0, menu;


    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){

        }
        else if (menu == 2){

        }
        else if (menu == 3){

        }
        else if (menu == 4){

        }
    }
    printf("종료됨!\n");
    return 0;
}


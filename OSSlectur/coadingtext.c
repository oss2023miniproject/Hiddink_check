#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 


typedef struct{
    int count[3];
    char name[100];
    char Rank[3];
    char comment[100];
    int money;
    int del;
} Score;


void saveData(Score *s, int count){
    FILE *fp;
    fp = fopen("datalist.txt", "wt");
    for(int i=0; i<count; i++){
        if(s[i].money==-1) continue;
        fprintf(fp, "%d-%d-%d %s %s  %d %s\n",s[i].count[0],s[i].count[1],s[i].count[2],s[i].name,s[i].Rank,s[i].money,s[i].comment);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}

int addScore(Score *s){
    int input1,input2,input3;
    int sum;
    printf("\n*** 우리 게스트하우스 ***\n");
    printf("\n1. 더블룸 	1박 30,000원\n");
    printf("2. 트윈룸 	1박 25,000원\n");
    printf("3. 패밀리룸	1박 60,000원\n");
    printf("\n*********\n");

    printf("유형별 개수는? ");
    scanf("%d",&s->count[0]);
    scanf("%d",&s->count[1]);
    scanf("%d",&s->count[2]);
    printf("예약자는? ");
    scanf("%s",s->name);
    printf("예약자 등급은(B,S,G)? ");
    scanf("%s",s->Rank);
    printf("요청사항은? ");
    getchar();
    scanf("%[^\n]s", s->comment);
    getchar();
    sum= s->count[0] *30000 + s->count[1]* 25000+ s->count[2]*60000;
    s->money = sum;
    printf("=> 예약됨!  총 금액 : %d원\n",sum);
    


    return 0;
};
int loadData(Score *s){
   int in =0;
    FILE *fp;
    fp=fopen("datalist.txt", "rt");
    if(fp==NULL){
        printf("=> 파일 없음");
    }
    else{
        while(!feof(fp)){
        fscanf(fp, "%d", &s[in].count[0]);
        if(feof(fp)) break;
        fscanf(fp, "%d", &s[in].count[2]);
        fscanf(fp, "%d", &s[in].count[2]);
        fscanf(fp, "%s", s[in].name);
        fscanf(fp, "%s", s[in].Rank);
        fscanf(fp, "%d", &s[in].money);
        fscanf(fp, "%[^\n]s", s[in].comment);
        in++;
    }
    fclose(fp);
    printf("=> 데이터 가져오는 중...\n");
    printf("=> %d 개의 예약 정보를 읽었습니다.!\n",in);
    }
    
    return in;
}

void readScore(Score s){
    double sum, avg;
    avg= sum/3;
    printf(" %d-%d-%d %s %s  %d %s\n",s.count[0],s.count[1],s.count[2],s.name,s.Rank,s.money,s.comment);
};

int listscore(Score *s, int count){
int minus =0;
   printf(" No  예약방  예약자   등급   가격   요청사항\n");
    printf("===========================\n");
    for(int i=0; i<count;i++){
        if(s[i].money ==-1){
            minus++;
            continue;
        } continue;
        printf("%2d",i+1);
        readScore(s[i]);
    }
    printf("=> 총 예약 %d건\n",count-minus);
    return 1;
};
void searchName(Score *s, int count){
   int scnt =0;
    char search[20];
    printf("이름은? ");
    scanf("%s", search);
    printf("\nNo  예약방  예약자   등급   가격      요청사항\n");
    printf("================================\n");
    for(int i=0;i<count;i++){
        if(s[i].money==-1) continue;
        if(strstr(s[i].name,search)){
            printf("%2d ", i+1);
            readScore(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된데이터없음!");
    printf("\n");
};



int selectdatano (Score *s, int count){
   int no;
    listscore(s, count);
    printf("번호는? (취소 :0)?");
    scanf("%d", &no);
    return no;
}

int deleteScore(Score *s){
    s->money=-1;
    printf("=> 삭제됨! \n");
    return 0;
};


int selectMenu(){
    int menu;
    printf("\n*** 우리 게스트하우스 ***\n");
    printf("1. 조회   2. 추가  3. 삭제   4. 저장   5. 예약자검색  0. 종료\n");
    scanf("%d", &menu);
    return menu;
};



int main(void){
    Score s[100];
    int count = 0, menu;
    int index =0;
    count = loadData(s);
    index =count;
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            listscore(s,index);;
        }
        else if (menu == 2){
            count += addScore(&s[index++]);
        }
        else if (menu == 3){
            int no = selectdatano(s,index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deletok;
            printf("정말로 삭제하시겠습까?(삭제 :1)");
            scanf("%d",&deletok);
            if(deletok ==1){
                if(deleteScore(&s[no-1])) count--;
            }
        }
        else if (menu == 4){
            saveData(s,index);
        }
        else if (menu == 5){
            searchName(s,index);
        }
        


    }
    printf("종료됨!\n");
    return 0;
}

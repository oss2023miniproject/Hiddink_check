#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 


typedef struct{
    char name [100];
    int kor;
    int eng;
    int math;
} Score;


void saveData(Score *s, int count){
    FILE *fp;
    fp = fopen("score.txt", "wt");
    for(int i=0; i<count; i++){
        if(s[i].kor==-1) continue;
        fprintf(fp, "%s %d %d %d\n",s[i].name, s[i].kor,s[i].eng,s[i].math);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}

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
int loadData(Score *s){
    int count =0;
    FILE *fp;
    fp=fopen("score.txt", "rt");
    if(fp==NULL){
        printf("=> 파일 없음");
    }
    else{
        while(!feof(fp)){
        fscanf(fp, "%s", s[count].name);
        if(feof(fp)) break;
        fscanf(fp, "%d", &s[count].kor);
        fscanf(fp, "%d", &s[count].eng);
        fscanf(fp, "%d", &s[count].math);
        count++;
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    }
    
    return count;
}

void readScore(Score s){
    double sum, avg;
    sum= s.kor+s.eng+s.math;
    avg= sum/3;
    printf("%4s %d %d %d %.0f %0.1f\n",s.name,s.kor,s.eng,s.math,sum,avg);
};

int listscore(Score *s, int count){
    printf("Name Kor Eng Math Sum Avg\n");
    printf("===========================\n");
    for(int i=0; i<count;i++){
        if(s[i].kor ==-1) continue;
        printf("%2d",i+1);
        readScore(s[i]);
    }
    printf("\n");
    return 1;
};
void searchName(Score *s, int count){
    int scnt =0;
    char search[20];
    printf("검색할 이름은? ");
    scanf("%s", search);
    printf("\nNo Name Kor Eng Math Sum Avg\n");
    printf("================================\n");
    for(int i=0;i<count;i++){
        if(s[i].kor==-1) continue;
        if(strstr(s[i].name,search)){
            printf("%2d ", i+1);
            readScore(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된데이터없음!");
    printf("\n");
};

int updateScore(Score *s){
    printf("이름은? ");
    scanf("%s",s->name);
    printf("국어는? ");
    scanf("%d",&s->kor);
    printf("영어는? ");
    scanf("%d",&s->eng);
    printf("수학는? ");
    scanf("%d",&s->math);
    printf("=>수정됨 \n");
    return 0;
};

int selectdatano (Score *s, int count){
    int no;
    listscore(s, count);
    printf("번호는? (취소 :0)?");
    scanf("%d", &no);
    return no;
}

int deleteScore(Score *s){
    s->eng=-1;
    s->kor=-1;
    s->math=-1;
    printf("=> 삭제됨! \n");
    return 0;
};


int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
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
            listscore(s,index);
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
            updateScore(&s[no-1]);
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
                if(deleteScore(&s[no-1])) count--;
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

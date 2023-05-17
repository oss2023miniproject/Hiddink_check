#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#include "main.h" 


int reserveTime(Team *t[]){ //이것은 적절한 시간으로 빌렸는지 확인하는 함수입니다.
    int startTime;
    int endTime;
    int count=0;
    while(1){
        printf("빌리고 싶은 시작 시간를 입력하세요(오후 5시는 17시로 입력!) : ");
        scanf("%d",&startTime);
        printf("\n끝나는 시간을 입력하세요(오후 6시는 18시로 입력!) : ");
        scanf("%d",&endTime);

        printf("%d %d",startTime,endTime);

        if(endTime - startTime  == 1) {
            t[startTime]->starttime = startTime;//t[start]에 넣은 것은 예약한 사람을 확인하는데 시간별로 확인하기 위해서 이렇게 사용했습니다.
            break;
        }

        else printf("\n빌리는 시간이 적절하지 않습니다. 다시 입력해주세요! : ");
    }
    return startTime;    
}

void reserveteamName(Team *t[],int time){
    char teamName[100];
    char teamLeader[100];

    printf("\n빌리는 팀 이름을 입력해주세요! : ");
    scanf("%[^\n]s",teamName);
    printf("\n대표자의 이름을 입력해주세요! : ");
    getchar();
    scanf("%[^\n]s",teamLeader);

    for(int i=0; i<24; i++){
        if(!strcmp(teamName,t[i]->teamname)) {
            printf("\n이미 빌린 팀입니다.\n");
            t[time]->starttime = 0;
            t[time]->endtime = 0;
            printf("자동적으로 예약시스템이 취소 후 종료됩니다.\n");
            return;
        }
        if(!strcmp(teamLeader,t[i]->name)) {
            printf("\n이미 빌린 사람입니다.\n");
            t[time]->starttime = 0;
            t[time]->endtime = 0;
            printf("자동적으로 예약시스템이 취소 후 종료됩니다.\n");
            return;
        }

    }
    strcpy(t[time]->teamname,teamName);
    strcpy(t[time]->name,teamLeader);    
}

void reserveSystem(Team **t){
    int number = reserveTime(t);
    reserveteamName(t,number);
}

void teamfillmethod(Team **t){ //team의 사이즈를 먼저 늘리기 이유 : 예약을 조회할 때 nullptr이라면 그 시간은 비어있다고 생각
    for(int i=0; i<24; i++){
        t[i] = (Team*)malloc(sizeof(Team));
        t[i]->starttime = 1004; //stattime에 시간을 초기화 시키는 것이다.
    }
}

void printeachTeam(Team *t){
    printf("%d시부터 %d시까지 예약한 팀: %s이고,예약한 사람: %s이다.\n",t->starttime,t->endtime,t->teamname,t->name);
}

void printTeam(Team **t){
    printf("예약한 팀을 보여드리겠습니다.\n");
    printf("------------------------------------------\n\n");
    for(int i=0; i<24; i++){
        if(t[i]->starttime == 1004) printf("%d시부터 %d시까지 예약한 팀은 없습니다!!!",i,i+1);
        else printeachTeam(t[i]);
    }
}

void deleteTeam(Team **t,char a[]){
    int check;
    printf("정말 취소하시겠습니까?(YES: 1, No: 2) ");
    scanf("%d",&check);

    if(check == 1){
        int count=0;
        for(int i=0; i<24; i++){
            if(!strcmp(t[i]->name,a)){
                t[i]->starttime = 1004;
                count++;
                strcpy(t[i]->name,"");
                strcpy(t[i]->teamname,"");
                printf("삭제되었습니다.\n\n");
                printf("%[^\n]s",t[i]->teamname);
            } 
        }

        if(count == 0) printf("리더의 이름과 같은 팀은 없습니다.\n");
    }
}

void saveTeamReserve(Team **t,int selectnumber){
    FILE *fp;
    if(selectnumber == 1) fp = fopen("poengbongTeam.txt", "wt");
    else fp = fopen("hidinkTeam.txt","wt");
    for(int i=0; i<24; i++){
        if(t[i]->starttime != 1024)
        fprintf(fp,"%d %s\n %s",t[i]->starttime,t[i]->teamname,t[i]->name);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}

void loadTeamReserve(Team **s, int selectnumber){
    FILE *fp;
    int index;
    if(selectnumber == 1) fp=fopen("poengbongTeam.txt", "rt");
    else fp = fopen("hidinkTeam.txt","rt");
    if(fp==NULL){
        printf("=> 파일 없음");
    }
    else{
        while(!feof(fp)){
        fscanf(fp, "%d",&index);
        if(feof(fp)) break;
        s[index]->starttime = index;
        s[index]->endtime = index+1;
        fscanf(fp, "%[^\n]s",s[index]->teamname);
        fscanf(fp, "%[^\n]s",s[index]->name);
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    }
}

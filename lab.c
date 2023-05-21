#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#include "main3.h" 


int selectMenu(){
    int menu;
    printf("\n*** FOOTBALL CHECK SYSTEM ***\n");
    printf("1. 경기장 예약옵션 \n");
    printf("2. 인원 찾기 옵션\n");
    printf("3. 다른 팀 찾기옵션 \n");
    printf("4. logout \n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
};


int selectMenu2(){
    int menu;
    printf("-----경기장 예약관련-----\n");
    printf("1. 예약 현황 보기\n");
    printf("2. 경기장 예약\n");
    printf("3. 팀 예약취소\n");
    printf("3. 팀 예약 변경\n");
    printf("4. 팀 예약한 것을 저장하기\n");
    printf("5. 팀이름 검색\n");
    printf("6. 뒤로가기\n");
    printf("=> 원하는 메뉴는? ");
    return menu;
};

int selectMenu3(){  //세분화 여기에 왜 이게 있는지 물어보기
    int menu;
    printf("-----인원 찾기 옵션-----\n");
    printf("1. 현재 업로드 된 인원 조회\n");
    printf("2. 인원 예약\n");
    printf("3. 인원 예약 수정\n");
    printf("4. 인원 예약 삭제\n");
    printf("5. 인원의 이름 검색\n");
    printf("6. 뒤로가기\n");
    printf("=> 원하는 메뉴는? ");
    return menu;
};

int selectMenu4(){  //세분화 여기에 왜 이게 있는지 물어보기
    int menu;
    printf("-----다른 팀 찾기옵션-----\n");
    printf("1. 자신의 팀 추가하기\n");
    printf("2. 자신의 팀 정보 수정하기\n");
    printf("3. 자신의 팀 삭제하기\n");
    printf("4. 업로드 된 팀 보기\n");
    printf("5. 자신의 팀 정보를 업로드하기\n");
    printf("6. 뒤로가기\n");
    printf("=> 원하는 메뉴는? ");
    return menu;
};

int logout(){  //세분화 여기에 왜 이게 있는지 물어보기
    printf("-----학번에 로그아웃되었습니다.-----\n");
    int input = idcheck();
    printf("-----학번이 변경되었습니다.-----\n");
    getchar();
    return input;
};


//---------------------------------------------------------
//인원을 조사를 위해서 필요한 함수들이다.

void saveData(Person **s, int count,int selectnumber){
    FILE *fp;
    if(selectnumber == 1) fp = fopen("poengbong.txt", "wt");
    else fp = fopen("hidink.txt","rt");
    for(int i=0; i<count; i++){
        if(s[i]->countnumber==-1) continue;
    fprintf(fp, "%s %d %d %s \n",s[i]->name,s[i]->countnumber,s[i]->studentnumber,s[i]->teamname);
    }
    fclose(fp);
    printf("=> 저장됨! ");
};

int loadData(Person **s, int selectnumber){
    int count =0;
    FILE *fp;
    if(selectnumber == 1) fp=fopen("poengbong.txt", "rt");
    else fp = fopen("hidink.txt","rt");
    if(fp==NULL){
        printf("=> 파일 없음");
    }
    else{
        while(!feof(fp)){
        s[count]=(Person *)malloc(sizeof(Person));
        fscanf(fp, "%s", s[count]->name);
        if(feof(fp)) break;
        fscanf(fp, "%d", &s[count]->countnumber);
        fscanf(fp, "%d", &s[count]->studentnumber);
        fscanf(fp, "%[^\n]s", s[count]->teamname);
        count++;
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    }
    
    return count;
};

int createProduct(Person *s, int studentnumber){
    printf("어느 경기장을 대여하시겠습니까?(평봉:0 히딩크:1) :");
    scanf("%d",&s->playground);
    if(s->playground !=1||s->playground !=0){
        printf("다시 입력하세요");
        scanf("%d",&s->playground);
    }
    printf("팀이름은 ? ");
    getchar();
    scanf("%[^\n]s", s->teamname);

    printf("팀 인원은? ");
    scanf("%d",&s->countnumber);

    printf("대표자 성함은? ");
    getchar();
    scanf("%[^\n]s", s->name);
    printf("=> 추가됨! \n");
    s->studentnumber = studentnumber;
    
    return 0;
};
void readProduct(Person *s){
    printf("대표자: %10s  인원: %d명 팀대표: %s \n",s->teamname,s->countnumber,s->name);
};

void listproduct(Person *s[], int count){
    printf("---------Check the Playground------------\n");    //수정하자
    printf("===========================\n");
    for(int i=0; i<count; i++){
        if(s[i]->countnumber ==-1) continue;
        printf("대표자   |  인원  | 팀대표 \n");
        readProduct(s[i]);
    }
    printf("\n");
};

int updateProduct(Person *s, int studentnumber){
    printf("어느 경기장을 대여하시겠습니까?(평봉:0 히딩크:1 )");
    scanf("%d",&s->playground);
    if(s->playground !=1||s->playground !=0){
        printf("다시 입력하세요");
        scanf("%d",&s->playground);
    }
    printf("팀이름은 ? ");
    getchar();
    scanf("%[^\n]s", s->teamname);

    printf("팀 인원은? ");
    scanf("%d",&s->countnumber);

    printf("대표자 성함은? ");
    getchar();
    scanf("%[^\n]s", s->name);
    printf("=> 추가됨! \n");
    s->studentnumber = studentnumber;
    printf("=> 수정되었습니다.! \n");
    return 0;
};

int selectdatano (Person *s[], int count){
    int no;
    listproduct(s, count);
    printf("번호는? (취소 :0)?");
    scanf("%d", &no);
    return no;
};

int selectdatano2 (Team *a[], int count){
    int no;
    
    printf("번호는? (취소 :0)?");
    scanf("%d", &no);
    return no;
};

int selectdatano3 (Search *q[], int count){
    int no;
    
    printf("번호는? (취소 :0)?");
    scanf("%d", &no);
    return no;
};



void searchName(Person **s, int count){
    int scnt =0;
    char search[20];
    printf("검색할 이름은? ");
    scanf("%s", search);
    printf("--현재 상황-- \n");
    printf("================================\n");
    for(int i=0;i<count;i++){
        if(s[i]->countnumber==-1) continue;
        if(strstr(s[i]->name,search)){
            printf("%2d ", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된데이터없음!");
    printf("\n");
};
int idcheck(){
    int input;

    while(1){
        printf("\n당신의 학번을 입력해주세요: ");
        scanf("%d",&input);
        if(input >= 11111111 && input <= 24000000){
            break;
        }
        else{
            printf("학번이 맞지 않습니다. 다시 입력하시길 바랍니다.\n ");
    }
}
    return input;
}



//-------------------------------------------------------------------------------
//여기는 팀단위를 예약하기 위해서 필요한 함수이다.
void saveTeamReserve(Team **t,int selectnumber){
    FILE *tp;
    if(selectnumber == 1) tp = fopen("poengbongTeam.txt", "wt");
    else tp = fopen("hidinkTeam.txt","wt");
    for(int i=0; i<24; i++){
        if(t[i]->starttime != 1004)
        fprintf(tp,"%d %s %s\n",t[i]->starttime,t[i]->name,t[i]->teamname);
    }
    fclose(tp);
    printf("=> 저장됨! ");
}

void loadTeamReserve(Team **s, int selectnumber){
    FILE *tp;
    int index;
    if(selectnumber == 1) tp=fopen("poengbongTeam.txt", "rt");
    else tp = fopen("hidinkTeam.txt","rt");
    if(tp==NULL){
        printf("=>팀 예약에 관한 파일은 없음");
    }
    else{
        while(!feof(tp)){
        fscanf(tp, "%d",&index);
        if(feof(tp)) break;
        s[index]->starttime = index;
        s[index]->endtime = index+1;
        fscanf(tp, "%s",s[index]->name);
        //getchar();
        fscanf(tp, "%[^\n]s",s[index]->teamname);
    }
    printf("=> 로딩성공!\n");
    }
    fclose(tp);
}


int reserveTime(Team *t[]){ //이것은 적절한 시간으로 빌렸는지 확인하는 함수입니다.
    int startTime;
    int endTime;
    int count=0;
    while(1){
        printf("빌리고 싶은 시작 시간를 입력하세요(오후 5시는 17시로 입력!) : ");
        scanf("%d",&startTime);
        printf("\n끝나는 시간을 입력하세요(오후 6시는 18시로 입력!) : ");
        scanf("%d",&endTime);

        if(t[startTime]->starttime == startTime) printf("\n그 시간엔 이미 사용자가 있습니다.\n");
        else if(endTime - startTime  == 1) {
            t[startTime]->starttime = startTime;//t[start]에 넣은 것은 예약한 사람을 확인하는데 시간별로 확인하기 위해서 이렇게 사용했습니다.
            t[startTime]->endtime = endTime; 
            break;
        }
        else printf("\n빌리는 시간이 적절하지 않습니다. 다시 입력해주세요!\n");
    }
    return startTime;    
}

void reserveteamName(Team *t[],int time){ //team의 이름과 리더를 찾는 함수이다.
    char teamName[100];
    char teamLeader[100];
    getchar();
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

void reserveSystem(Team **t){//위에 두 함수를 호출해서 사람을 받는다.
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
    printf("%d시부터 %d시까지 예약한 팀은 %s이고, 예약한 사람은 %s이다.\n",t->starttime,t->endtime,t->teamname,t->name);
}

void printTeam(Team **t){
    printf("예약한 팀을 보여드리겠습니다.\n");
    printf("------------------------------------------\n\n");
    for(int i=0; i<24; i++){
        if(t[i]->starttime == 1004) printf("%d시부터 %d시까지 예약한 팀은 없습니다!!!\n",i,i+1);
        else printeachTeam(t[i]);
    }
}

void deleteTeam(Team **t,char a[]){
    int check;
    printf("정말 삭제하시겠습니까?(YES: 1, No: 2) ");
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
                //printf("%[^\n]s",t[i]->teamname);
            } 
        }

        if(count == 0) printf("리더의 이름과 같은 팀은 없습니다.\n");
    }
}



// ------------------------------------------------------
// 여기서부터는 상대팀을 찾기 위해서 필요한 함수이다.
int checkid(int studentnumber,int checknumber){//내용을 지우거나 삭제하거나 추가하는데 자신인지를 확인하는 함수.
    if(studentnumber == checknumber) return 0;
    else return 1;
}
void inputPhonenumber(Search **q,int index){//팀의 대표의 전화번호를 집어넣는 함수이다.
    char number[12];
    int check =0;
    do{
        printf("전화번호를 적으세요(숫자만 입력) : ");
        getchar();
        scanf("%s",number);

        for(int i=0; i<11; i++){
            if(('0'>number[i]) || ('9'<number[i])) {
                check++;
            }
        }

        if((number[0] != '0') || (number[1] != '1') || (number [2] != '0')){
            check++;
        } 
        if(check != 0){
            printf("입력이 잘못됐습니다.\n");
            check = 0;
        }

        else break;
    }while(1);
    strcpy(q[index]->phonenumber,number);
}

void inputInformation(Search **q,int index){//팀의 정보를 집어넣는 함수이다.
    int number1,number2;//여기서 오류 생길수도 있다.(RuntimeError) ->type이 다르다.
    char name[100];
    int count =0;
    do{
        printf("가능한 시간을 적어주세요(ex: 17시부터 20시 ->17~20): ");
        scanf("%d~%d", &number1, &number2);
        getchar();
        if(((0<=number1)&&(number1<=24)) && ((0<=number2)&&(number2<=24))) break;
        else printf("시간을 잘못입력했습니다.\n\n");
    }while(1);

    q[index]->start = number1;
    q[index]->end = number2;

    while(1){
        printf("팀의 이름을 적어주세요! : ");
        getchar();
        scanf("%[^\n]s",name);
        for(int i=0; i<index; i++){
            if(strcmp(q[index]->teamname,name) == 0) count++;
        }
        if(count == 0){
            strcpy(q[index]->teamname,name);
            break;
        }
        else {
            printf("이미 팀의 이름이 존재합니다.\n");
            count =0;
        }
    }

    printf("원하는 팀이나 실력에 적어주세요: ");
    getchar();
    scanf("%[^\n]s",q[index]->detail);
}

int inputSearchInformation(Search **q,int index,int studentnumber){//add하는 함수
    for(int i =0; i<index; i++){
        if(checkid(q[i]->student,studentnumber) ==  0 ){
        printf("이미 등록한 학생입니다.\n");
        return index;
        }
    }
    q[index] = (Search*)malloc(sizeof(Search));
    q[index]->student = studentnumber;
    inputInformation(q,index);
    inputPhonenumber(q,index);
    return index+1;
}

void updateInformation(Search **q,int studentnumber){
    int index;
    int point;
    printf("고칠 번호를 적어주세요(취소 0) : ");
    scanf("%d",&index);
    if(index == 0 ) return;

    if(checkid(q[index-1]->student,studentnumber) == 1){
        printf("사용자가 다릅니다.\n\n");
        return;
    }

    printf("\n1. 전화번호\n2. 팀의정보\n3. 둘다\n\n 무엇을 고칠까요? : ");
    scanf("%d",&point);
    if(q[index-1]->start == -1) index = index+1;
    switch(point){
        case 1:
            inputPhonenumber(q,index-1);
            break;
        case 2:
            inputInformation(q,index-1);
            break;
        case 3:
            inputPhonenumber(q,index-1);
            inputInformation(q,index-1);
            break;
        default:
            break;
    }

    printf("수정했습니다.\n\n");
}

void deleteInformation(Search **q,int studentnumber,int dex){
    int index;
    printf("삭제할 번호를 적어주세요(취소는 0) : ");
    scanf("%d",&index);
    if(index == 0) return;
    
    if(q[index]->start == -1) printf("없는 번호입니다.");
    if(checkid(q[index-1]->student,studentnumber) == 1){
        printf("사용자가 다릅니다.\n\n");
        return;
    }
    q[index-1]->start = -1;
    q[index-1]->student = -1;
    printf("삭제했습니다.");
}

void printea(Search *q){
    printf("%d~%d시 | %s팀 | 조건: %s | 전화번호=> %s\n",q->start,q->end,q->teamname,q->detail,q->phonenumber);
}

void pritnInformation(Search **q,int index){
    int count =0;
    int number =1;
    printf("상대방 찾기 옵션!!\n--------------------------------------------------\n");
    for(int i=0; i<index; i++){
        if(q[i]->start != -1){
            printf("%d. |",i+1);
            printea(q[i]);
            count++;
        }
    }

    if(count == 0) printf("\n\n\n\t\t사람들이 없네요...\n\n\n");
}

void saveSearchTeam(Search **q,int selectnumber,int index){
    FILE *fp;
    if(selectnumber == 1) fp = fopen("poengbongSearch.txt", "wt");
    else fp = fopen("hidinkSearch.txt","wt");
    for(int i =0 ; i<index; i++){
        if(q[i]->start != -1)
        fprintf(fp,"%s %d %d %d %s,%s\n",q[i]->phonenumber,q[i]->start,q[i]->end,q[i]->student,q[i]->teamname,q[i]->detail);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}

int loadSearchTeam(Search **s, int selectnumber){
    FILE *fp;
    int index = 0;
    if(selectnumber == 1) fp=fopen("poengbongSearch.txt", "rt");
    else fp = fopen("hidinkSearch.txt","rt");
    if(fp==NULL){
        printf("=> 파일 없음");
    }
    else{
        while(!feof(fp)){
            s[index] = (Search*)malloc(sizeof(Search));
            fscanf(fp, "%s",s[index]->phonenumber);
            if(feof(fp)) break;
            fscanf(fp, "%d",&s[index]->start);
            fscanf(fp, "%d",&s[index]->end);
            fscanf(fp, "%d",&s[index]->student);
            fscanf(fp, "%[^,]s",s[index]->teamname);
            fscanf(fp, ",%[^\n]s",s[index]->detail);
            index++;
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    }
    return index;
}

void deleteInformation2(Search **q,int index){
    q[index]->start = -1;
    q[index]->student = -1;
}

void automatchingSystem(Search **q,Team ** t,int index,int selectnumber){//상대방 팀 자동 선택 매칭 시스템
    int start;
    int end;
    int count =0;
    int number;
    char reservename[30];
    char reserveteam[100];
    int a[index];

    do{//이용 시간 작성하기.
        printf("가능한 시간을 적어주세요\n(ex: 17시부터 20시 ->17 20) : ");
        scanf("%d~%d", &start, &end);
        if(((0<=start)&&(start<=24)) && ((0<=end)&&(end<=24))) break;
        else printf("시간을 잘못입력했습니다.\n\n");
    }while(1);
    getchar();
    printf("예약자 이름을 입력하세요 : ");
    scanf("%s",reservename);
    printf("예약할 팀 이름을 입력하세요 : ");
    getchar();
    scanf("%[^\n]s",reserveteam);


    printf("자동 선택 매칭 시스템을 시작하겠습니다.\n\n...띠링! 동시간대에 경기가 가능한 팀을 출력합니다.\n\n");
    for(int i=0; i<index; i++){
        if((start == q[i]->start) && (0<= q[i]->start && q[i]->start <=24)){
            printf("%d. ",count+1);
            printea(q[i]);
            a[count++] = i;
        }
    }

    if(count == 0){
        printf("가능한 팀이 없네요...");
        return;
    }
    getchar();
    printf("몇번을 선택하시겠습니까?(취소 : 0) : ");
    scanf("%d",&number);
    if(number == 0) return;

    
    for(int i=0; i<24; i++){
        if(t[i]->starttime == start){
            printf("이미 그 시간에는 예약이 되어있습니다.\n자동 매칭 선택시스템을 취소합니다.\n");
            return;
        }
        else if(!strcmp(t[i]->name,reservename)){
            printf("예약자는 이미 빌렸습니다.\n자동 매칭 선택시스템을 취소합니다.\n");
            return;
        }
        else if(!strcmp(t[i]->teamname,reserveteam)){
            printf("이 팀은 이미 빌렸습니다.\n자동 매칭 선택시스템을 취소합니다.\n");
            return;
        }
    }

    t[start]->starttime = start;
    t[start]->endtime = end;
    strcpy(t[start]->name,reservename);
    strcpy(t[start]->teamname,reserveteam);
    printf("팀 예약이 완료되었습니다.\n\n");
    printf("%s로 상대팀에게 예약이 완료되었다고 말해주세요!\n\n",q[a[number-1]]->phonenumber);

    deleteInformation2(q,a[number-1]);
    saveTeamReserve(t,selectnumber);
    saveSearchTeam(q,selectnumber,index);
}

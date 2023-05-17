#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#include "main.h" 

void inputPhonenumber(Search **q,int index){//팀의 대표의 전화번호를 집어넣는 함수이다.
    char number[8];
    int check =0;
    do{
        printf("전화번호를 적으세요(숫자만 입력) : ");
        scanf("%s",number);
        for(int i=0; i<8; i++){
        if('9' <= number[i] || '0' >= number[i]) check++;
        }
        if(number[0] != '0' || number[1] != '1' || number [2] != '0') check++;
        if(check != 0){
            printf("입력 방식이 틀렸습니다.\n");
            check =0;
        }
    }while(check != 0);
    q[index]->phonenumber = atoi(number);
}

void inputInformation(Search **q,int index){//팀의 정보를 집어넣는 함수이다.
    short number1,number2;//여기서 오류 생길수도 있다.(RuntimeError) ->type이 다르다.
    char name[100];
    int count =0;
    do{
        printf("가능한 시간을 적어주세요\n(ex: 17시부터 20시 ->17~20) : ");
        scanf("%d~%d",&number1,number2);
        if((0<=number1<=24)&& (0<=number2<=24)) break;
        else printf("시간을 잘못입력했습니다.\n\n");
    }while(1);

    q[index]->start = number1;
    q[index]->end = number2;

    while(1){
        printf("팀의 이름을 적어주세요! : ");
        scanf("%[^\n]s",name);
        for(int i=0; i<index; i++){
            if(strcmp(q[index]->teamname,name)) count++;
        }
        if(count == 0){
            strcpy(q[index]->teamname,name);
            break;
        }
        else printf("이미 팀의 이름이 존재합니다.\n");
    }

    printf("자신의 팀을 어필, 상대방의 조건와 같은 하고 싶은 말 작성! : ");
    scanf("%[^\n]s",q[index]->detail);
}

int inputSearchInformation(Search **q,int index,int studentnumber){//add하는 함수
    for(int i =0; i<index; i++){
        if(checkid(q[i]->student,studentnumber) == 1){
        printf("이미 등록한 학생입니다.\n");
        return;
        }
    }
    q[index] = (Search*)malloc(sizeof(Search));
    q[index]->student = studentnumber;
    inputInformation(q,index);
    inputPhonenumber(q,index);
    return index++;
}

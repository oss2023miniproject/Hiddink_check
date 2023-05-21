#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  Person *s[20];
  Team *a[24]; //팀의 예약을 나타내기 위해서 필요한 구조체이다.
  Search *q[24]; //상대방 찾기의 필요한 구조체이다.

  char y[100]; //팀의 리더의 이름을 받는 변수,삭제시킬 때 필요.

  int a_index = 0; //상대방 찾기의 인덱스이다.
  int a_count = 0;
  int selectnumber;
  int count = 0, menu;
  int index1 = 0;
  int index2 = 0;
  int index3 = 0;
  short number1, number2;
  int q_index = 0; //상대방 찾기 옵션의 인덱스이다.

  int id = idcheck(); //현재 이용자의 학번이다.

  teamfillmethod(a); //팀의 예약 구조체를 미리할당하는 것이다.(어차피 24시간 밖에 없으니!).

  printf("이용할 운동장을 고르세요: (평봉:1 히딩크:2) "); 
  scanf("%d", &selectnumber);
  count = loadData(s, selectnumber);         //인원 파일
  loadTeamReserve(a, selectnumber);          //팀 예약 파일
  q_index = loadSearchTeam(q, selectnumber); //상대팀 찾기 파일

  while (1) { // 1->인원찾기(기능) 2->팀 예약 3->다른 팀 찾기
    menu = selectMenu();
    if (menu == 0)
      break;
    if (menu == 1) {
      while(1){
        menu = selectMenu2();
      scanf("%d",&selectnumber);
      if(selectnumber == 1){
        listproduct(s,index1);
      }
      else if(selectnumber == 2){
        s[index1]=(Person *)malloc(sizeof(Person));
        count += createProduct(s[index1++],id);
      }
      else if(selectnumber == 4){
        int no = selectdatano(s,index1);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(s[no-1],id);
      }
      else if(selectnumber == 3){
       int no = selectdatano(s,index1);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deletok;
            printf("정말로 삭제하시겠습까?(삭제 :1)");
            scanf("%d",&deletok);
            if(deletok ==1){
              deleteproduct(s[no-1],id);
              printf("=>삭제됨 \n");
            }

      }
      else if(selectnumber == 5){
        saveData(s,index1);
      }

      else if(selectnumber == 6){
        searchName(s,index1);
      }
      else break;
      }

    } else if (menu == 2) {
      
      while(1){
        menu = selectMenu3();
        scanf("%d",&selectnumber);
        if(selectnumber==1){
          printTeam(a);
        }
        else if(selectnumber==2){
          //a[a_index]=(Team *)malloc(sizeof(Team));=>위에서 먼저 a에 동적메모리를 할당해서 다시 할 필요는 없을거 같습니다.
          reserveSystem(a,id);
        }
        else if(selectnumber==3){
            updateTeam(a,id);
        }

        else if(selectnumber==4){
            int check;
            getchar();
            printf("대표 예약자 이름을 입력해주세요 : ");
            scanf("%s",y);
            printf("정말 삭제하시겠습니까?(YES: 1, No: 2) ");
            scanf("%d",&check);
            if(check == 1) deleteTeam(a,y,id);
            else continue;
        }
        else if(selectnumber==5){
            getchar();
            printf("찾고 싶은 팀의 대표 예약자 이름을 입력해주세요 : ");
            scanf("%[^\n]s",y);
            detectTeam(a,y);
        }
        else break;
      }
      
    } else if (menu == 3) {
      while(1){
        menu = selectMenu4();
        scanf("%d",&selectnumber);
        if(selectnumber==1){//여기서 포인터의  메모리 할당을 안함 이유는 만약에 학번이 같으면 여기서 하면 인덱스가 저절로 늘어나기 때문이다.
            q_index = inputSearchInformation(q,q_index,id); 
            //
            
            
            printf("%d %d %s %s %s ",q_index,q[q_index]->student,q[q_index]->phonenumber,q[q_index]->teamname,q[q_index]->detail);
        }
        else if(selectnumber==2){
          int no = selectdatano3(q,q_index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateInformation(q,no,id);
        }
        else if(selectnumber==3){
          /*int no = selectdatano3(q,q_index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }*/
            deleteInformation(q,id,q_index);
        }
        else if(selectnumber==4){
          pritnInformation(q,q_index);
        }
        else if(selectnumber==5){
          saveSearchTeam(q,selectnumber,q_index);
        }
        else if(selectnumber == 6){
            automatchingSystem(q,a,q_index,selectnumber);
        }
        else break;
      }

      menu = selectMenu4();
      scanf("%d",&selectnumber);

    }
    else if (menu == 4) {
      id = logout();
    }
   
  }
  printf("종료됨!\n");
  return 0;
}

typedef struct{
    char name [100];  //대표자 이름
    int playground; //0일 경우 평봉, 1일 경우 히딩크
    char teamname[100];  //팀이름
    int countnumber;  //팀 전체 인원
    int studentnumber;
} Person;


typedef struct {
    int starttime;
    int endtime;
    char teamname [100];
    char name[100];
} Team;

typedef struct {
    char phonenumber[12]; //상대팀 대표의 전화번호
    int start;//축구를 할 수 있는 시간 
    int end;
    int student;//수정하거나 지울때 자신의 정보를 확인하기 위해서 필요.
    char teamname [100];//팀 이름
    char detail [100];//자신의 팀을 어필 or 상대방의 조건 or 끝까지 간다.
} Search;//팀이 부족해서 다른 상대팀을 찾는데 필요한 구조체


int selectMenu();
int selectMenu2();
int selectMenu3();
int selectMenu4();
int idcheck();//학번


int loadData(Person * *s,int selectnumber);
void saveData(Person **s, int count,int selectnumber);
int createProduct(Person *s, int studentnumber);
void readproduct(Person *s);
void listproduct(Person *s[], int count);
int updateProduct(Person *s, int studentnumber);
int selectdatano (Person *s[], int count);

int deleteproduct(Person *s, int studentnumber);
void searchName(Person **s, int count);


int logout();
int reserveTime(Team *t[]);
void reserveteamName(Team *t[],int time);
void reserveSystem(Team **t);
void teamfillmethod(Team **t);
void printeachTeam(Team *t);
void printTeam(Team **t);
void deleteTeam(Team **t,char a[]);
void saveTeamReserve(Team **t,int selectnumber);
void loadTeamReserve(Team **s, int selectnumber);
int selectdatano2 (Team *a[], int count);



int selectdatano3 (Search *q[], int count);
int checkid(int studentnumber,int checknumber);
void inputPhonenumber(Search **q,int index);
void inputInformation(Search **q,int index);
int inputSearchInformation(Search **q,int index,int studentnumber);
void updateInformation(Search **q,int studentnumber);
void deleteInformation(Search **q,int studentnumber,int dex);
void printea(Search *q);
void pritnInformation(Search **q,int index);
int loadSearchTeam(Search **s, int selectnumber);
void saveSearchTeam(Search **q,int selectnumber,int index);
void automatchingSystem(Search **q,Team ** t,int index,int selectnumber);//자동으로 상대팀을 매칭해주는 시스템입니다.
void deleteInformation2(Search **q,int index);//데이터를 지우는 함수입니다.

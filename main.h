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
    int student_number;
} Team;

int loadData(Person * *s,int selectnumber);
void saveData(Person **s, int count,int selectnumber);
int createProduct(Person *s, int studentnumber);
void readproduct(Person *s);
void listproduct(Person *s[], int count);
int updateProduct(Person *s, int studentnumber);
int selectdatano (Person *s[], int count);
int deleteproduct(Person *s, int studentnumber);
void searchName(Person **s, int count);
int reserveTime(Team *t[]);
void reserveteamName(Team *t[],int time);
void reserveSystem(Team **t);
void teamfillmethod(Team **t);
int selectMenu();
int idcheck();
void printeachTeam(Team *t);
void printTeam(Team **t);
void deleteTeam(Team **t,char a[]);

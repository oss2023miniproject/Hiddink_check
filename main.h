typedef struct{
    char name [100];
    int age;
    double length;
    double weight;
    char detail [100];
} Person;

typedef struct {
    int starttime;
    int endtime;
    char teamname [100];
    char name[100];
} Team;

int loadData(Person **s,int selectnumber);
void saveData(Person **s, int count,int selectnumber);
int createProduct(Person *s);
void readproduct(Person *s);
void listproduct(Person *s[], int count);
int updateProduct(Person *s);
int selectdatano (Person *s[], int count);
int deleteproduct(Person *s);
void searchName(Person **s, int count);
int reserveTime(Team *t[]);
void reserveteamName(Team *t[],int time);
void reserveSystem(Team **t);
void teamfillmethod(Team **t);
int selectMenu();
int idcheck();


typedef struct{
    char name [100];
    int age;
    double length;
    double weight;
    char detail [100];
} Person;

int loadData(Person **s);
void saveData(Person **s, int count);
int createProduct(Person *s);
void readproduct(Person *s);
void listproduct(Person *s[], int count);
int updateProduct(Person *s);
int selectdatano (Person *s[], int count);
int deleteproduct(Person *s);
void searchName(Person **s, int count);
int selectMenu();
int idcheck();

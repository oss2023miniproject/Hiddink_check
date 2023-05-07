typedef struct{
    char name [100];
    int kor;
    int eng;
    int math;
} Score;

int loadData(Score **s);
void saveData(Score **s, int count);
int addScore(Score *s);
void readScore(Score *s);
void listscore(Score *s[], int count);
int updateScore(Score *s);
int selectdatano (Score *s[], int count);
int deleteScore(Score *s);
void searchName(Score **s, int count);
int selectMenu();

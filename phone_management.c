#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 10
#define PHONE_LEN 15
#define MEMO_LEN 50


typedef struct __person{
    char name[NAME_LEN];
    char pNum[PHONE_LEN];
    char memo[MEMO_LEN];
}person;

person pList[50];
int perNum=0;

enum {ADD=1, SEARCH=2, DEL=3, SHOWALL=4, END=0};

void clearbuf(void){while(getchar()!='\n'){}}

int ShowMenu(void);
void addData(void);
void searchData(void);
void delData(void);
void ShowAllData(void);

int main()
{
    int sw;
    sw=ShowMenu();
    while(sw!=END)
    {
        switch(sw)
        {
        case ADD:
            addData(); break;
        case SEARCH:
            searchData(); break;
        case DEL:
             delData(); break;
        case SHOWALL:
            ShowAllData(); break;
        }
        sw=ShowMenu();
    }
    return 0;
}

int ShowMenu(void)
{
    system("cls");
    int n;
    puts("--------  Menu ---------");
    puts("1. 연 락 처 추 가  ");
    puts("2. 검          색 ");
    puts("3. 삭          제 ");
    puts("4. 전  체   목 록  ");
    puts("-------------------------");
    printf("선택 : ");scanf("%d",&n);
    clearbuf();
    return n;

}


void addData(void)
{
    puts("연락처 추가를 시작합니다.");
    printf("이   름 : ");gets(pList[perNum].name);
    printf("전화번호 : ");gets(pList[perNum].pNum);
    printf("메   모 : ");gets(pList[perNum].memo);
    perNum++;
    clearbuf();
}

void searchData(void)
{
    puts("연락처 검색을 시작합니다.");
    clearbuf();
}

void delData(void)
{
    puts("연락처를 삭제 합니다.");
    clearbuf();
}

void ShowAllData(void)
{
    int idx;
    for(idx=0;idx<perNum;idx++)
    {
        printf("┌──────────────────────────────\n");
        printf("│ ▶ 이   름 : %s \n",pList[idx].name);
        printf("│ ▶ 전화번호 : %s \n",pList[idx].pNum);
        printf("│ ▶ 메   모 : %s \n",pList[idx].memo);
        printf("└─────────────────────────────\n");
    }
    clearbuf();
}

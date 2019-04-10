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

person* pList[50];

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
    puts("1. �� �� ó �� ��  ");
    puts("2. ��          �� ");
    puts("3. ��          �� ");
    puts("4. ��  ü   �� ��  ");
    puts("-------------------------");
    printf("���� : ");scanf("%d",&n);
    clearbuf();
    return n;

}


void addData(void)
{
    puts("����ó �߰��� �����մϴ�.");
    clearbuf();
}

void searchData(void)
{
    puts("����ó �˻��� �����մϴ�.");
    clearbuf();
}

void delData(void)
{
    puts("����ó�� ���� �մϴ�.");
    clearbuf();
}

void ShowAllData(void)
{
    puts("��ü ����ó�� ��� �մϴ�.");
    clearbuf();
}

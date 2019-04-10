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

void SaveData(void);
void LoadData(void);

int main()
{
    int sw;
    LoadData();

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
    person buf;
    int ref;

    printf("��   �� : ");gets(buf.name);
    printf("��ȭ��ȣ : ");gets(buf.pNum);
    printf("��   �� : ");gets(buf.memo);

    printf("����ó�� �߰� �մϴ�. (1. Ȯ��, 0.���) : ");
    scanf("%d",&ref);

    if(ref==1)
    {
        pList[perNum]=buf;
        perNum++;
        SaveData();
    }

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
    int idx;
    for(idx=0;idx<perNum;idx++)
    {
        printf("��������������������������������������������������������������\n");
        printf("�� �� ��   �� : %s \n",pList[idx].name);
        printf("�� �� ��ȭ��ȣ : %s \n",pList[idx].pNum);
        printf("�� �� ��   �� : %s \n",pList[idx].memo);
        printf("������������������������������������������������������������\n");
    }
    clearbuf();
}

void SaveData(void)
{
    int idx;
    FILE* fps=fopen("PhoneData.bin","wb");

    fwrite(&perNum,sizeof(int),1,fps);
    for(idx=0;idx<perNum;idx++)
    {
        fwrite(&pList[idx],sizeof(person),1,fps);
    }
    fclose(fps);
}

void LoadData(void)
{
    int idx;

    FILE* fpr=fopen("PhoneData.bin", "rb");

    fread(&perNum,sizeof(int),1,fpr);
    for(idx=0;idx<perNum;idx++)
    {
        fread(&pList[idx],sizeof(person),1,fpr);
    }
    fclose(fpr);

}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


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

enum {ADD=1, SEARCH=2, DEL=3, SHOWALL=4, CHANGE=5, END=0};

void clearbuf(void){while(getchar()!='\n'){}}

int ShowMenu(void);
void addData(void);
void searchData(void);
void delData(void);
void ShowAllData(void);
void ChangeData(void);

void ShowPersonData(person ref);
void DelPersonData(int idx);
void changePersonData(int idx);

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
        case CHANGE:
            ChangeData();break;
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
    puts("5. 수          정");
    puts("0. 프 로 그 램 종 료");
    puts("-------------------------");
    printf("선택 : ");scanf("%d",&n);
    clearbuf();
    return n;

}


void addData(void)
{
    puts("연락처 추가를 시작합니다.");
    person buf;
    int ref=0;
    int idx=0;

    printf("이   름 : ");gets(buf.name);
    printf("전화번호 : ");gets(buf.pNum);
    printf("메   모 : ");gets(buf.memo);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(buf.name,pList[idx].name) && !strcmp(buf.pNum,pList[idx].pNum))
        {
            printf("연락처가 이미 존재합니다.");getchar();
            return;
         }
    }


    printf("연락처를 추가 합니다. (1. 확인, 0.취소) : ");
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
    int idx;
    char sName[NAME_LEN];
    printf("찾는 이름 : ");gets(sName);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(sName,pList[idx].name))
                    ShowPersonData(pList[idx]);
    }

    clearbuf();
}

void delData(void)
{
    int idx=0,i=0;
    int idxMatch[50]={0,};
    char sName[NAME_LEN];
    printf("삭제 할 이름 : ");gets(sName);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(sName,pList[idx].name))
        {
            idxMatch[i]=idx;
            i++;
        }
    }

    for(idx=0;idx<i;idx++)
    {
        printf("No. %d \n",idx+1);
        ShowPersonData(pList[idxMatch[idx]]);
    }

    printf("선택 : ");scanf("%d",&idx);clearbuf();
    DelPersonData(idxMatch[idx-1]);

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

void ChangeData(void)
{
    int idx=0,i=0;
    int idxMatch[50]={0,};
    char sName[NAME_LEN];
    printf("수정 할 이름 : ");gets(sName);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(sName,pList[idx].name))
        {
            idxMatch[i]=idx;
            i++;
        }
    }

    for(idx=0;idx<i;idx++)
    {
        printf("No. %d \n",idx+1);
        ShowPersonData(pList[idxMatch[idx]]);
    }


    printf("선택 : ");scanf("%d",&idx);clearbuf();
    changePersonData(idxMatch[idx-1]);
}

void ShowPersonData(person ref)
{
    printf("┌──────────────────────────────\n");
    printf("│ ▶ 이   름 : %s \n",ref.name);
    printf("│ ▶ 전화번호 : %s \n",ref.pNum);
    printf("│ ▶ 메   모 : %s \n",ref.memo);
    printf("└─────────────────────────────\n");
}

void DelPersonData(int idx)
{
    int i;

    while(idx<perNum)
    {
        pList[idx]=pList[idx+1];
        idx++;
    }

    perNum--;
    SaveData();
    puts("삭제가 완료 되었습니다.");
}

void changePersonData(int idx)
{
    person buf;
    int ref=0;
    int i=0;

    printf("이   름 : ");gets(buf.name);
    printf("전화번호 : ");gets(buf.pNum);
    printf("메   모 : ");gets(buf.memo);

    for(i=0;i<perNum;i++)
    {
        if(!strcmp(buf.name,pList[i].name) && !strcmp(buf.pNum,pList[i].pNum))
        {
            printf("연락처가 이미 존재합니다.");getchar();
            return;
         }
    }
    printf("연락처를 변경 합니다. (1. 확인, 0.취소) : ");
    scanf("%d",&ref);

    if(ref==1)
    {
        pList[idx]=buf;
        SaveData();
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

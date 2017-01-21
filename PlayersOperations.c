#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

FILE *fp;

struct player
{
    char name[100];
    int cur_level;
    double score;
    struct player *next;
};

int PlaysBefore(char name[100], struct player *list)
{
    struct player *current = list;
    for(; current != NULL; current = current->next)
        if(strcmp(name,current->name) == 0)
            return 1;
    return 0;
}

struct player *find_player(struct player *list,char name[100])
{

    struct player *current = (struct player *)malloc(sizeof(struct player));
    current = list;
    for(; current != NULL; current = current->next)
        if(strcmp(name,current->name) == 0)
            return current;
}

void IntializePlayer(struct player *list,int m)
{
    char numberOfFiles = 1;
    for(;; numberOfFiles++)
    {
        char FileName[50];
        strcpy(FileName,"levels/level-");
        char lev[10];
        sprintf(lev,"%d",numberOfFiles);
        strcat(FileName,lev);
        strcat(FileName,".txt");
        fp = fopen(FileName,"r");
        if(fp == NULL)
            break;
        fclose(fp);
    }
    numberOfFiles--;

    system("cls");
    system("color 70");
    struct player *p = (struct player *)malloc(sizeof(struct player));
    char name[100];
    printf("Enter your name: (at most 100 characters)\n");
    scanf(" %s",name);
    if(PlaysBefore(name, list))
    {
        p = find_player(list,name);
        p->cur_level = 1;
        p->score = 0;
        printf("Your plays before.\n");
        printf("Your level is: %d\n",p->cur_level);
        printf("Do you want to continue? Y / N\n");
        char c = getch();
        if(c == 'Y');

        else if(c == 'N')
        {
            printf("So enter the level would you like to start playing from: (a number from 1 to %d)\nYour score will set to 0.\n",numberOfFiles);
            p->score = 0.0;
            int level;
            while(1)
            {
                scanf("%d", &level);
                if(level <= 0 || level > numberOfFiles)
                {
                    printf("Invalid level number\n");
                    continue;
                }
                else
                {
                    p->cur_level = level;
                    break;
                }
            }
        }
    }
    else
    {
        p->score = 0.0;
        printf("Your are playing for the first time!\n");
        strcpy(p->name,name);
        printf("Which level would you like to play? (a number from 1 to %d)\n",numberOfFiles);
        int level;
        while(1)
        {
            scanf("%d", &level);
            if(level <= 0 || level > numberOfFiles)
            {
                printf("Invalid level number\n");
                continue;
            }
            else
            {
                p->cur_level = level;
                break;
            }
        }
        add_end_player(list,*p);
        p = find_player(list,name);
    }

    writeInFile(list);

    startingGameAlert();

    DoTheGame(list,p,m);
}

void startingGameAlert(void)
{
    int i = 4;
    for(; i > 0; i--)
    {
        system("cls");
        system("color 70");
        printf("The game will start in %d ...\n",i);
        Sleep(1000);
    }
}

struct player * GenaratePlayersLinkedList()
{
    struct player *PlayerList = (struct player *)malloc(sizeof(struct player));
    PlayerList->next = NULL;

    fp = fopen("players.typ","rb");
    struct player p;
    while(fread(&p, sizeof(p), 1, fp) == 1)
        add_end_player(PlayerList, p);
    fclose(fp);
    return PlayerList;
}

void add_end_player(struct player *list, struct player p)
{
    struct player *new_player = (struct player *)malloc(sizeof(struct player));
    strcpy(new_player->name,p.name);
    new_player->score = p.score;
    new_player->cur_level = p.cur_level;
    new_player->next = NULL;

    struct player *current = list;
    for(; current->next != NULL; current = current->next);
    current->next = new_player;
}

void SortPlayers(struct player *list)
{
    struct player *curi;
    struct player *curj;

    for(curi = list->next; curi->next != NULL; curi = curi->next)
        for(curj = curi->next; curj != NULL; curj = curj->next)
        {
            if((curj->score) >= (curi->score))
            {
                //swapping scores
                double tmp = curi->score;
                curi->score = curj->score;
                curj->score = tmp;

                //swapping levels
                int tmp1 = curi->cur_level;
                curi->cur_level = curj->cur_level;
                curj->cur_level = tmp;

                //swapping names
                char tmp3[100];
                strcpy(tmp3,curi->name);
                strcpy(curi->name,curj->name);
                strcpy(curj->name,tmp3);
            }
        }
}

void swap_players(struct player *p1, struct player *p2)
{
    printf("in swap\n");
    swap_int(&(p1->cur_level),&(p2->cur_level));
    swap_int(&(p1->score), &(p2->score));
    swap_string(p1->name, p2->name);
}

void swap_int(int *a,int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_string(char a[100], char b[100])
{
    char tmp[100];
    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(b,tmp);
}

void print_player(struct player *list)
{
    struct player *current = list->next;
    for(; current != NULL; current = current->next)
    {
        printf("\nname : %s\t level : %d\t score : %lf\n",current->name,current->cur_level,current->score);
    }
}

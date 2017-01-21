#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "print_words.h"

struct player
{
    char name[100];
    int cur_level;
    double score;
    struct player *next;
};

struct word
{
    char word[100];
    int id;
    struct word *next;
};


void DoTheGame(struct player *PlayerList,struct player *p,int m)
{
    char FileName[50];
    strcpy(FileName,"levels/level-");
    char lev[10];
    sprintf(lev,"%d",p->cur_level);
    strcat(FileName,lev);
    strcat(FileName,".txt");
    struct word *list = malloc(sizeof(struct word));
    list = GenerateWordLinkedList(FileName);
    while(list != NULL)
    {
        char word[100];
        getWord(&list,word);
        int i = 0, j = 0, wrongs = 0;
        int sleep_time = sleepTime(p->cur_level);
        time_t start, end;
        double duration = 0;
        start = clock();
        int unable = 0;

        while(1)
        {
            if(unable)
                break;
            system("cls");
            system("color 70");
            print_word(word,40,j);
            if(i == strlen(word))
            {
                end = clock();
                duration += (end - start);
                break;
            }
            if(j == 30)
            {
                unable = 1;
                continue;
            }

            if(kbhit())
            {
                char s;
                s = getch();
                if(s == 'Q')
                {
                    printf("Your data will be lost!\n\n\n");
                    Sleep(2000);
                    return;
                }
                else if(s == 'P')
                {
                    end = clock();
                    duration += (end - start);
                    while(1)
                    {
                        char s2 = getch();
                        if(s2 == 'R')
                        {
                            start = clock();
                            break;
                        }
                        else
                            printf("\nGame is paused. Press R to resume.\n");
                    }
                }
                else if(s == word[i])
                {
                    word[i] -= 32;
                    i++;
                    continue;
                }
                else
                    wrongs ++;
            }
            Sleep(sleep_time);
            j++;
        }
        if(unable)
            continue;

        double time = (duration) / CLOCKS_PER_SEC;
        double score_word = (strlen(word)*3 - wrongs) / time;
        if(m)
            score_word *= (p->cur_level / 10.0);
        p->score += score_word;
    }
    printf("Level ended!\n");
    printf("Total score is : %lf\n\n",p->score);
    Sleep(4000);
    p->cur_level++;
    if(p->cur_level > 10)
    {
        printf("Wow! You completed the game!\n.");
        Sleep(4000);
    }
    writeInFile(PlayerList);
}

void writeInFile(struct player *list)
{
    FILE *fPlayer = fopen("players.typ","wb");
    struct player *current = list->next;
    fflush(fPlayer);
    for(; current != NULL; current = current->next)
    {
        struct player p = *current;
        fwrite(&p,sizeof(p),1,fPlayer);
    }
    fclose(fPlayer);
}

void writingRanksInFile(struct player *list)
{
    FILE *franks = fopen("highscores/ranks.txt","w");
    if(franks == NULL)
        printf("not open!\n");
    fprintf(franks,"Highscores !\n\n===========================\n\n");
    int i = 1;
    struct player *current = list->next;
    for(; current != NULL; current = current->next, i++)
        if(i <= 10)
            fprintf(franks,"%d. name: %s\tlevel: %d\tscore: %lf\n\n",i,current->name,current->cur_level,current->score);

    fclose(franks);
}

int sleepTime(int level)
{
    int time = 550;
    int i;
    for(i = 1; i <= level; i++, time -= 50);
    return time;
}

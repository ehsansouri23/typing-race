/**

    In the name of god

    <<Typing Quick>>

    created by: Ehsan Souri

    Ehsan.souri@aut.ac.ir


**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "linked lists.h"
#include "show menus.h"
#include "PlayersOperations.h"
#include "print_words.h"
#include "doing_game.h"

#define GREEN 160
#define RED 206
#define USUAL 15
#define LIGHTBLUE 176

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


int main()
{
    time_t t = time(NULL);
    srand(t);
//    struct player *PlayerList = (struct player *)malloc(sizeof(struct player));
//    PlayerList->next = NULL;
//    PlayerList = GenaratePlayersLinkedList();
//    struct player p;
//    strcpy(p.name,"non1");
//    p.score = 30;
//    p.cur_level = -100;
//    add_end_player(PlayerList,p);
//    strcpy(p.name,"non2");
//    p.score = 200.0;
//    p.cur_level = -200;
//    add_end_player(PlayerList,p);
//    strcpy(p.name,"non3");
//    p.score = 50.0;
//    p.cur_level = -300;
//    add_end_player(PlayerList,p);
//    print_player(PlayerList);
//    printf("=================\n\n");
//    SortPlayers(PlayerList);
//    writeInFile(PlayerList);
//    writingRanksInFile(PlayerList);
//    print_player(PlayerList);

    printf("Welcome. Please maximize your window.\n\nPress any key to continue...\n");
    getch();
    printf("If you want new scoring system, please press N\n");
    int new_scoring = 0;
    if(getch() == 'N')
        new_scoring = 1;
    show_menu(new_scoring);
    return 0;
}


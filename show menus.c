#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define GREEN 160
#define RED 206
#define USUAL 15

struct player
{
    char name[100];
    int cur_level;
    double score;
    struct player *next;
};

void show_menu(int m)
{
    while(1)
    {
        struct player *list = (struct player *)malloc(sizeof(struct player));
        list->next = NULL;
        list = GenaratePlayersLinkedList();
        system("cls");
        system("color 70");
        HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD w ;
        w.X = 40;
        w.Y = 0;
        system("cls");
        SetConsoleCursorPosition(hstdout,w);
        time_t t = time(NULL);
        srand(t);
        char s[] = "TYPING QUICK!";
        int i;
        for(i = 0; i < strlen(s); i++)
        {
            SetConsoleTextAttribute(hstdout,(rand() % 7) + 192);
            printf("%c",s[i]);
            Sleep(100);
        }
        w.Y +=2;
        SetConsoleCursorPosition(hstdout,w);
        char s2[] = "Keep calm and type ;)";
        for(i = 0; i < strlen(s2); i++)
        {
            SetConsoleTextAttribute(hstdout,(rand() % 7) + 192);
            printf("%c",s2[i]);
            Sleep(100);
        }
        Sleep(100);
        w.Y ++;
        SetConsoleCursorPosition(hstdout,w);
        SetConsoleTextAttribute(hstdout,USUAL);
        printf("===========================");
        SetConsoleTextAttribute(hstdout,GREEN);
        w.Y += 5;
        SetConsoleCursorPosition(hstdout,w);
        Sleep(200);
        w.Y += 5;
        printf("1.Start the game\n\n\n");
        SetConsoleCursorPosition(hstdout,w);
        Sleep(200);
        w.Y += 5;
        printf("2.Top ten players\n\n\n");
        SetConsoleCursorPosition(hstdout,w);
        Sleep(200);
        w.Y += 5;
        printf("3.Open tutorial\n\n\n");
        SetConsoleCursorPosition(hstdout,w);
        Sleep(200);
        w.Y += 5;
        printf("4.Credits\n\n\n");
        SetConsoleCursorPosition(hstdout,w);
        Sleep(200);
        w.Y += 5;
        printf("5.Exit :(\n\n\n");

        int com = 0;
        while(1)
        {
            char c = getch();
            if(c == '1')
                com = 1;
            if(c == '2')
                com = 2;
            if(c == '3')
                com = 3;
            if(c == '4')
                com = 4;
            if(c == '5')
                com = 5;
            if(com != 0)
                break;
            else
                continue;
        }

        if(com == 1)
            IntializePlayer(list,m);
        if(com == 2)
        {
            system("cls");
            system("color 70");
            SortPlayers(list);
            printf("Here are the top players!\nThis is also available in file highscores/ranks.txt\n\n");
            print_player(list);
            writingRanksInFile(list);
            printf("\nPress Q to to go to main menu\n");
            char g = getch();
            while(g != 'Q')
                g = getch();
        }
        if(com == 3)
            show_tutorial();
        if(com == 4)
            show_credits();
        if(com == 5)
        {
            system("cls");
            system("color 70");
            printf("Are you sure?!\n");
            printf("Y / N\n");
            int com2 = 0;
            while(1)
            {
                char c = getch();
                if(c == 'Y')
                    com2 = 1;
                if(c == 'N')
                    com2 = 2;
                if(com2 != 0)
                    break;
                else
                    continue;
            }

            if(com2 == 1)
                exit(0);
            if(com2 == 2);
        }
        continue;
    }
}

void show_credits(void)
{
    system("cls");
    system("color 70");
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD w;
    w.Y = 30;
    w.X = 40;
    SetConsoleCursorPosition(hstdout,w);
    SetConsoleTextAttribute(hstdout,GREEN);
    for(; w.Y >= 1; w.Y-=9)
    {
        system("cls");
        system("color 70");
        SetConsoleTextAttribute(hstdout,GREEN);
        SetConsoleCursorPosition(hstdout,w);
        printf("credits: ");
        w.Y++;
        SetConsoleCursorPosition(hstdout,w);
        printf("Ehsan souri");
        w.Y++;
        SetConsoleCursorPosition(hstdout,w);
        printf("Computer engineering at Amirkabir University of Technology.");
        w.Y++;
        SetConsoleCursorPosition(hstdout,w);
        printf("Ehsan.souri@aut.ac.ir");
        w.Y++;
        SetConsoleCursorPosition(hstdout,w);
        printf("Ehsansouri23@gmail.com");
        w.Y++;
        SetConsoleCursorPosition(hstdout,w);
        printf("Website: ceit.aut.ac.ir/~9531040");
        w.Y++;
        SetConsoleCursorPosition(hstdout,w);
        printf("-----All right reserved-----");
        w.Y++;
        SetConsoleCursorPosition(hstdout,w);
        printf("Press Q to go to main menu");
        w.Y++;
        Sleep(50);
    }

    while(1)
    {
        if(getch() == 'Q')
            break;
        else
            continue;
    }
}

void show_tutorial(void)
{
    system("cls");
    system("color 70");
    printf("This is a very challenging game.\n");
    Sleep(400);
    printf("It lets you to improve your typing skills by giving you lots of practical exercises.\n");
    Sleep(400);
    printf("You should only type the displayed words as soon as possible.\n");
    Sleep(400);
    printf("Words come down during your typing so you should type so fast and do not let the words reaches the end line.\n");
    Sleep(400);
    printf("If any word reaches the end line, the level will restart.\n");
    Sleep(400);
    printf("By typing fast, your level will increase.\n");
    Sleep(400);
    printf("As your level increased, your challenge will be harder.\n");
    Sleep(400);
    printf("At end, we will show your tying speed musuered by WPM(word per minute).\n\n");
    Sleep(400);
    printf("Have a good time with TYPER QUICK!!!\n\n");
    Sleep(400);
    printf("press Q to go to main menu.\n\n");

    while(1)
    {
        if(getch() == 'Q')
            break;
        else
            continue;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define GREEN 160
#define RED 206
#define USUAL 15
#define LIGHTBLUE 176

void print(int n,char c,int consoleType)
{

    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if(consoleType != USUAL)
        SetConsoleTextAttribute(hstdout,consoleType);
    int i;
    for(i = 0; i < n; i++)
        printf("%c",c);
    SetConsoleTextAttribute(hstdout,USUAL);
}

void print_word(char s[],int new_lines,int printed_lines)
{
    system("cls");
    system("color 70");
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int i;
    print(42,' ',150);
    print(1,'\n',USUAL);
    for(i = 0; i < printed_lines; i++)
    {
        print(1,' ',150);
        print(40,' ',LIGHTBLUE);
        print(1,' ',150);
        print(1,'\n',USUAL);
    }
    print(1,' ',150);
    print(20,' ',LIGHTBLUE);
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            SetConsoleTextAttribute(hstdout,GREEN);
            printf("%c",s[i]);
            SetConsoleTextAttribute(hstdout,USUAL);
        }
        else if(s[i - 1] >= 'A' && s[i - 1] <= 'Z')
        {
            SetConsoleTextAttribute(hstdout,RED);
            printf("%c",s[i]);
            SetConsoleTextAttribute(hstdout,USUAL);
        }
        else
            printf("%c",s[i]);
    }
    print(20 - strlen(s),' ',LIGHTBLUE);
    print(1,' ',150);
    print(1,'\n',USUAL);
    for(i = 0; i < 30 - printed_lines; i++)
    {
        print(1,' ',150);
        print(40,' ',LIGHTBLUE);
        print(1,' ',150);
        print(1,'\n',USUAL);
    }
    print(42,' ',150);
    print(2,'\n',USUAL);
}

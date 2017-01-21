#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct word
{
    char word[100];
    int id;
    struct word *next;
};


struct word * GenerateWordLinkedList(char FileName[100])
{
    struct word *list = (struct word *)malloc(sizeof(struct word));
    list->next = NULL;
    FILE *fword = fopen(FileName,"r");
    char word1[100];
    fscanf(fword, " %s",word1);
    if(list->next == NULL)
    {
        strcpy(list->word,word1);
        list->id = 1;
    }
    while(!feof(fword))
    {
        fscanf(fword," %s",word1);
        add_end(word1,list);
    }
    delete_end(list);
    return list;
}

void add_end(char word1[100],struct word *list)
{
    struct word *current = list;
    int i = 2;
    for(; current->next != NULL; current = current->next, i++);
    struct word *new_word = (struct word *)malloc(sizeof(struct word));
    strcpy(new_word->word,word1);
    new_word->next = NULL;
    new_word->id = i;
    current->next = new_word;
    return;
}

void getWord(struct word **list, char word[100])
{
    struct word *current = *list;
    int i = 0;
    for(; current != NULL; current = current->next, i++);
    current = *list;
    int r = 0;
    int random = (rand() % i) + 1;
    for(; current != NULL; current = current->next)
    {
        if(current->id == random)
        {
            strcpy(word, current->word);
            delete(list,current->id);
            setIndex(*list);
            break;
        }
    }
}

void delete(struct word **list,int id)
{
    struct word *current = *list;
    for(; current->id != id && current->next != NULL; current = current->next);
    if(current == *list)
        delete_front(list);
    else if(current->next == NULL)
        delete_end(*list);
    else
        delete_inside(*list,id);
}

void delete_end(struct word *list)
{
    struct word *current = list;
    for(; current->next->next != NULL; current = current->next);
    free(current->next);
    current->next = NULL;
}

void delete_front(struct word **plist)
{
    struct word *tmp;
    struct word *current = (*plist);
    tmp = current;
    current = current->next;
    free(tmp);
    (*plist) = current;

}

void delete_inside(struct word *list, int id)
{
    struct word *current = list;
    struct word *tmp = (struct word *)malloc(sizeof(struct word));
    for(; current->next->id != id; current = current->next);
    tmp = current->next;
    current->next = tmp->next;
    free(tmp);
}

void setIndex(struct word *list)
{
    int i = 1;
    struct word *current = list;
    for(;current != NULL; current->id = (i++), current = current->next);
}

void print_list(struct word *list)
{
    struct word *current = list;
    for(; current != NULL; current = current->next)
        printf("Word is : %s\t id is : %d\n",current->word,current->id);
}

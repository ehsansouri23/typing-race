#ifndef LINKED_LISTS_H_INCLUDED
#define LINKED_LISTS_H_INCLUDED


struct word * GenerateLinkedList(char FileName[100]);

void add_end(char word1[100],struct word *list);

void getWord(struct word *list, char word[100]);

void delete_end(struct word *list);

void delete_front(struct word **list);

void delete_inside(struct word *list, int id);

void delete(struct word *list,int id);

void print_list(struct word *list);

#endif // LINKED_LISTS_H_INCLUDED

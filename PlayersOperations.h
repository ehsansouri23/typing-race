#ifndef PLAYERSOPERATIONS_H_INCLUDED
#define PLAYERSOPERATIONS_H_INCLUDED

int PlaysBefore(char name[100], struct player *);

struct player * find_player(struct player *,char name[100]);

void IntializePlayer(struct player *,int);

struct player * GenaratePlayersLinkedList(void);

void add_end_player(struct player *, struct player);

void print_player(struct player *);

struct player * SortPlayers(struct player *);

void swap_players(struct player *, struct player *);

void swap_int(int *,int *b);

void swap_string(char a[100], char b[100]);

void startingGameAlert(void);

#endif // PLAYERSOPERATIONS_H_INCLUDED

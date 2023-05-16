//Anthony Flores  
#ifndef GAME_F
#define GAME_F
#include "TicTacWowWeeWow.h"


typedef struct PLAYER {
	char player1_char;
	char player2_char;
	char player1_color;
	char player2_color;
	int** boardarray;
	int movenumber;
} PLAYER;

typedef struct PLAYER1 {
	int movenumber;
} PLAYER1;


typedef struct Moveslist MLIST;
typedef struct MovesEntry MENTRY;

struct Moveslist
{
	int Length;
	MENTRY* First;
	MENTRY* Last;
};

struct MovesEntry
{
	MLIST* List;
	MENTRY* Next;
	MENTRY* Prev;
	PLAYER1* players1;
};

PLAYER1* Newgamemove(int move);
//static MENTRY *NewMoveEntry(BOARD *b);


PLAYER1* RemoveLastMove(MLIST* l);

void AppendMove(MLIST* l, PLAYER1* players1);



extern MLIST* NewMovesList(void);

//static BOARD *DeleteMoveEntry(MENTRY *e);
//static MENTRY *NewMoveEntry(BOARD *b);
void DeleteBoard(PLAYER1* player1);

//void turnBintoplayers(BOARD *b, PLAYER *players);

void print_fun(PLAYER* players, int gamemove, int list);

int is_there_empty_cell(PLAYER* players);

int IsWin(PLAYER* players);

int* entered_one_char(PLAYER* players, int player_num, int movenumber);

extern void HumanVsHuman(PLAYER* players);

extern void Human_Vs_AI(PLAYER* players, MLIST* l, MENTRY* e);

void PrintMoveList(MLIST* l, PLAYER* players, int* xai, int* yai, int* pointer);

void PrintMove(PLAYER1* players1, PLAYER* players, int* xai, int* yai, int* pointer);

int takebackmove(PLAYER* players, int movenumber, int* xai, int* yai, int* pointer);




#endif

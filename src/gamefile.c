/*********************************************************************/
/*                                                                   */
/* Author: Anthony Flores                                            */
/*                                                                   */
/*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "gamefile.h"
#include "TicTacWowWeeWow.h"
// This function prints the board

PLAYER1* Newgamemove(int move)
{
	PLAYER1* players1;
	players1 = malloc(sizeof(PLAYER1));
	if (!players1)
	{
		perror("Out of memory! Aborting...");
		exit(10);
	} /* fi */
	players1->movenumber = move;
	return players1;
} /* end of NewStudent */

/* allocate a new move entry */
static MENTRY* NewMoveEntry(PLAYER1* players1)
{
	MENTRY* e;
	e = malloc(sizeof(MENTRY));
	if (!e)
	{
		perror("Out of memory! Aborting...");
		exit(10);
	} /* fi */
	e->List = NULL;
	e->Next = NULL;
	e->Prev = NULL;
	e->players1 = players1;
	return e;
}

void DeleteBoard(PLAYER1* players1)
{
	assert(players1);
	free(players1);
}

static PLAYER1* DeleteMoveEntry(MENTRY* e)
{
	PLAYER1* players1;
	assert(e);
	players1 = e->players1;
	free(e);
	return players1;
}

/* allocate a new move list */
MLIST* NewMovesList(void)
{
	MLIST* l;
	l = malloc(sizeof(MLIST));
	if (!l)
	{
		perror("Out of memory! Aborting...");
		exit(10);
	} /* fi */
	l->Length = 0;
	l->First = NULL;
	l->Last = NULL;
	return l;
}


void AppendMove(MLIST* l, PLAYER1* players1)
{
	MENTRY* e = NULL;
	assert(l);
	assert(players1);
	e = NewMoveEntry(players1);
	if (l->Last)
	{
		e->List = l;
		e->Next = NULL;
		e->Prev = l->Last;
		l->Last->Next = e;
		l->Last = e;
	}
	else
	{
		e->List = l;
		e->Next = NULL;
		e->Prev = NULL;
		l->First = e;
		l->Last = e;
	}
	l->Length++;
}

void PrintMoveList(MLIST* l, PLAYER* players, int* xai, int* yai, int* pointer)
{
	MENTRY* e;
	assert(l);
	e = l->First;
	while (e)
	{
		PrintMove(e->players1, players, xai, yai, pointer);
		e = e->Next;
	}
}


void PrintMove(PLAYER1* players1, PLAYER* players, int* xai, int* yai, int* pointer)
{
	if (players1->movenumber == 0) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				players->boardarray[i][j] = 0;
	}
	players->boardarray[xai[players1->movenumber]][yai[players1->movenumber]] = 2;
	players->boardarray[pointer[players1->movenumber]][pointer[(players1->movenumber) + 9]] = 1;
	int move = players1->movenumber;
	print_fun(players, move, 1);
}

PLAYER1* RemoveLastMove(MLIST* l)
{
	MENTRY* e = NULL;
	assert(l);
	if (l->Last)
	{
		e = l->Last;
		l->Last = e->Prev;
		if (l->Last)
		{
			l->Last->Next = NULL;
		}
		else
		{
			assert(l->First == e);
			l->First = NULL;
		}
		l->Length--;
		return DeleteMoveEntry(e);
	}
	else
	{
		return(NULL);
	}
} /* end of RemoveLastMove */


void print_fun(PLAYER* players, int gamemove, int list)
{

	FILE* fp;
	if (gamemove == 0)
		//         	fp = fopen("hello.txt","w");
	   //  else{
		fp = fopen("hello.txt", "a");
	//  }

	 // start with row
	for (int i = 0; i < 3; i++)
	{
		// print out vertical legend
		if (list == 1)
		{
			if (i == 0)
				fprintf(fp, "C ");
			if (i == 1)
				fprintf(fp, "B ");
			if (i == 2)
				fprintf(fp, "A ");
		}
		else {
			if (i == 0)
				printf("C ");
			if (i == 1)
				printf("B ");
			if (i == 2)
				printf("A ");
		}
		// find corresponding column    
		for (int j = 0; j < 3; j++)
		{
			if (list == 1) {
				if (players->boardarray[i][j] == 0) // empty space
					fprintf(fp, " ");
				else if (players->boardarray[i][j] == 1) // player 1
				{
					if (players->player1_color == 'r')
					{
						fprintf(fp, "\x1b[31m%c\x1b[0m", players->player1_char); //Red
					}
					else if (players->player1_color == 'g')
					{
						fprintf(fp, "\x1b[32m%c\x1b[0m", players->player1_char); //Green
					}
					else if (players->player1_color == 'y')
					{
						fprintf(fp, "\x1b[33m%c\x1b[0m", players->player1_char); // Yellow
					}
					else if (players->player1_color == 'b')
					{
						fprintf(fp, "\x1b[34m%c\x1b[0m", players->player1_char); // Blue
					}
					else
					{
						fprintf(fp, "%c\x1b[0m", players->player1_char); // Default color (theme dependent)
					}
				}
				else if (players->boardarray[i][j] == 2) // player 2
				{
					if (players->player2_color == 'r')
					{
						fprintf(fp, "\x1b[31m%c\x1b[0m", players->player2_char); //Red
					}
					else if (players->player2_color == 'g')
					{
						fprintf(fp, "\x1b[32m%c\x1b[0m", players->player2_char); //Green
					}
					else if (players->player2_color == 'y')
					{
						fprintf(fp, "\x1b[33m%c\x1b[0m", players->player2_char); // Yellow
					}
					else if (players->player2_color == 'b')
					{
						fprintf(fp, "\x1b[34m%c\x1b[0m", players->player2_char); // Blue
					}
					else
					{
						fprintf(fp, "%c\x1b[0m", players->player2_char); // Default color (theme dependent)
					}
				}
			}
			/*here*/	else {
				if (players->boardarray[i][j] == 0) // empty space
					printf(" ");
				else if (players->boardarray[i][j] == 1) // player 1
				{
					if (players->player1_color == 'r')
					{
						printf("\x1b[31m%c\x1b[0m", players->player1_char); //Red
					}
					else if (players->player1_color == 'g')
					{
						printf("\x1b[32m%c\x1b[0m", players->player1_char); //Green
					}
					else if (players->player1_color == 'y')
					{
						printf("\x1b[33m%c\x1b[0m", players->player1_char); // Yellow
					}
					else if (players->player1_color == 'b')
					{
						printf("\x1b[34m%c\x1b[0m", players->player1_char); // Blue
					}
					else
					{
						printf("%c\x1b[0m", players->player1_char); // Default color (theme dependent)
					}
				}
				else if (players->boardarray[i][j] == 2) // player 2
				{
					if (players->player2_color == 'r')
					{
						printf("\x1b[31m%c\x1b[0m", players->player2_char); //Red
					}
					else if (players->player2_color == 'g')
					{
						printf("\x1b[32m%c\x1b[0m", players->player2_char); //Green
					}
					else if (players->player2_color == 'y')
					{
						printf("\x1b[33m%c\x1b[0m", players->player2_char); // Yellow
					}
					else if (players->player2_color == 'b')
					{
						printf("\x1b[34m%c\x1b[0m", players->player2_char); // Blue
					}
					else
					{
						printf("%c\x1b[0m", players->player2_char); // Default color (theme dependent)
					}
				}
			}


			if (list == 1) {		// print out lines in between columns 
				if (j != 2)
					fprintf(fp, "|");
			}
			else {
				if (j != 2)
					printf("|");
			}
		}
		if (list == 1) {
			if (i != 2) // print out lines between rows
				fprintf(fp, "\n  -----\n");
			else if (i == 2) // prints out horizontal legend
				fprintf(fp, "\n  1 2 3\n");
		}
		else {
			if (i != 2) // print out lines between rows
				printf("\n  -----\n");
			else if (i == 2) // prints out horizontal legend
				printf("\n  1 2 3\n");

		}
	}
	fclose(fp);
}

//This function checks if there is empty place in board.
int is_there_empty_cell(PLAYER* players)
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (players->boardarray[i][j] == 0)
				count++;
		}
	}
	if (count != 0)
		return 1; // we have empty cell
	else
		return 0; // we do not have empty cell
}


// win condition
int IsWin(PLAYER* players)
{

	int win_flag = 0;
	if (((players->boardarray[0][0] == 1) && (players->boardarray[1][0] == 1) && (players->boardarray[2][0] == 1)) ||
		((players->boardarray[0][1] == 1) && (players->boardarray[1][1] == 1) && (players->boardarray[2][1] == 1)) ||
		((players->boardarray[0][2] == 1) && (players->boardarray[1][2] == 1) && (players->boardarray[2][2] == 1)) ||
		((players->boardarray[0][0] == 1) && (players->boardarray[0][1] == 1) && (players->boardarray[0][2] == 1)) ||
		((players->boardarray[1][0] == 1) && (players->boardarray[1][1] == 1) && (players->boardarray[1][2] == 1)) ||
		((players->boardarray[2][0] == 1) && (players->boardarray[2][1] == 1) && (players->boardarray[2][2] == 1)) ||
		((players->boardarray[0][0] == 1) && (players->boardarray[1][1] == 1) && (players->boardarray[2][2] == 1)) ||
		((players->boardarray[0][2] == 1) && (players->boardarray[1][1] == 1) && (players->boardarray[2][0] == 1)))
	{
		win_flag = 1;
	}

	else if (((players->boardarray[0][0] == 2) && (players->boardarray[1][0] == 2) && (players->boardarray[2][0] == 2)) ||
		((players->boardarray[0][1] == 2) && (players->boardarray[1][1] == 2) && (players->boardarray[2][1] == 2)) ||
		((players->boardarray[0][2] == 2) && (players->boardarray[1][2] == 2) && (players->boardarray[2][2] == 2)) ||
		((players->boardarray[0][0] == 2) && (players->boardarray[0][1] == 2) && (players->boardarray[0][2] == 2)) ||
		((players->boardarray[1][0] == 2) && (players->boardarray[1][1] == 2) && (players->boardarray[1][2] == 2)) ||
		((players->boardarray[2][0] == 2) && (players->boardarray[2][1] == 2) && (players->boardarray[2][2] == 2)) ||
		((players->boardarray[0][0] == 2) && (players->boardarray[1][1] == 2) && (players->boardarray[2][2] == 2)) ||
		((players->boardarray[0][2] == 2) && (players->boardarray[1][1] == 2) && (players->boardarray[2][0] == 2)))
	{
		win_flag = 2;
	}

	return win_flag;
}

// enters int 1 or 2 in desired position.
int* entered_one_char(PLAYER* players, int player_num, int gamemove)
{
	int valid_entered = 0;
	int c;
	int r;
	int* playerxy = malloc(sizeof(int) * 18);
	while (valid_entered == 0)
	{
		char letters_num[3];
		c = 0;
		r = 0;
		scanf("%s", letters_num);

		if (letters_num[0] == 'A')
		{
			r = 2;
		}
		else if (letters_num[0] == 'B')
		{
			r = 1;
		}
		else if (letters_num[0] == 'C')
		{
			r = 0;
		}

		if (letters_num[1] == '1')
		{
			c = 0;
		}
		else if (letters_num[1] == '2')
		{
			c = 1;
		}
		else if (letters_num[1] == '3')
		{
			c = 2;
		}

		if (players->boardarray[r][c] == 0)
		{
			valid_entered = 1;
		}
		else
		{
			printf("The entered position is not available! Please try again...\n");
		}
	}
	playerxy[gamemove] = r;
	playerxy[gamemove + 9] = c;
	players->boardarray[r][c] = player_num;
	return playerxy;
}

// Handle a Human v. Human game
void HumanVsHuman(PLAYER* players)
{
	printf("Human v. Human game started\n");
	print_fun(players, 0, 0);
	int tie = 1;
	while ((is_there_empty_cell(players)))
	{
		printf("Player 1, please choose your move:");
		entered_one_char(players, 1, 0);
		print_fun(players, 0, 0);
		int win_flag = IsWin(players);
		if (win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("Player 2 wins! Game Over!\n\n");
			}
			tie = 0;
			break;
		}
		else if (is_there_empty_cell(players) == 0)
			break;

		printf("Player 2, please choose your move:");
		entered_one_char(players, 2, 0);
		print_fun(players, 0, 0);
		win_flag = IsWin(players);
		if (win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
			}
			else if (win_flag == 2)
			{
				printf("Player 2 wins! Game Over!\n\n");
			}
			tie = 0;
			break;
		}
	}
	if (tie == 1)
		printf("The game is a tie!\n");
}

// Handle a Human v. AI game
void Human_Vs_AI(PLAYER* players, MLIST* l, MENTRY* e) // Human is always player1 and AI is player2
{
	printf("Human v. AI game started\n");
	print_fun(players, 0, 0);
	int ailevel;
	printf("\n choose ai level 1 - 3");
	scanf("%d", &ailevel);
	getchar();
	int tie = 1;
	int movenumberAI = 0;
	int newmovenumber;
	int xai[9] = { 0,0,0,0,0,0,0,0,0 };
	int yai[9] = { 0,0,0,0,0,0,0,0,0 };
	int* playerxy;
	PLAYER1* players1 = NULL;
	while ((is_there_empty_cell(players)))
	{

		players1 = Newgamemove(movenumberAI);
		AppendMove(l, players1);
		printf("Player 1, please choose your move:");
		playerxy = entered_one_char(players, 1, movenumberAI);
		print_fun(players, 0, 0);
		int win_flag = IsWin(players);
		if (win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");

			}
			else if (win_flag == 2)
			{
				printf("AI wins! Game Over!\n\n");
			}
			tie = 0;
			break;
		}
		else if (is_there_empty_cell(players) == 0)
			break;

		printf("AI is choosing its move:\n");
		int foundMove = 0;
		movenumberAI = movenumberAI + 1;
		//AI level 1
		if (ailevel == 1) {
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (players->boardarray[i][j] == 0)
					{
						xai[movenumberAI - 1] = i;
						yai[movenumberAI - 1] = j;
						players->boardarray[i][j] = 2;
						foundMove = 1;
						break;
					}
				}

				if (foundMove)
				{
					break;
				}
			}
		}

		//AI level 2
		if (ailevel == 2) {
			int r1, r2;
			while (foundMove != 1) {
				r1 = (rand() % 3);
				r2 = (rand() % 3);
				if (players->boardarray[r1][r2] == 0)
				{
					xai[movenumberAI - 1] = r1;
					yai[movenumberAI - 1] = r2;
					players->boardarray[r1][r2] = 2;
					foundMove = 1;

				}

			}
		}
		//ai level 3
		if (ailevel == 3) {
			if (((players->boardarray[0][0] == 1) && (players->boardarray[0][1] == 1) && (players->boardarray[0][2] == 0))) {
				players->boardarray[0][2] = 2;
				xai[movenumberAI - 1] = 0;
				yai[movenumberAI - 1] = 2;
				foundMove = 1;
			}
			else if (((players->boardarray[0][0] == 1) && (players->boardarray[1][1] == 1) && (players->boardarray[2][2] == 0))) {
				players->boardarray[2][2] = 2;
				xai[movenumberAI - 1] = 2;
				yai[movenumberAI - 1] = 2;
				foundMove = 1;
			}
			else if (((players->boardarray[0][0] == 1) && (players->boardarray[1][0] == 1) && (players->boardarray[2][0] == 0))) {
				players->boardarray[2][0] = 2;
				xai[movenumberAI - 1] = 2;
				yai[movenumberAI - 1] = 0;
				foundMove = 1;
			}
			else if (((players->boardarray[0][2] == 1) && (players->boardarray[0][1] == 1) && (players->boardarray[0][0] == 0))) {
				players->boardarray[0][0] = 2;
				xai[movenumberAI - 1] = 0;
				yai[movenumberAI - 1] = 0;
				foundMove = 1;
			}
			else if (((players->boardarray[0][2] == 1) && (players->boardarray[1][1] == 1) && (players->boardarray[2][0] == 0))) {
				players->boardarray[2][0] = 2;
				xai[movenumberAI - 1] = 2;
				yai[movenumberAI - 1] = 0;
				foundMove = 1;
			}
			else if (((players->boardarray[0][2] == 1) && (players->boardarray[1][2] == 1) && (players->boardarray[2][2] == 0))) {
				players->boardarray[2][2] = 2;
				xai[movenumberAI - 1] = 2;
				yai[movenumberAI - 1] = 2;
				foundMove = 1;
			}
			else if (((players->boardarray[2][0] == 1) && (players->boardarray[1][0] == 1) && (players->boardarray[0][0] == 0))) {
				players->boardarray[0][0] = 2;
				xai[movenumberAI - 1] = 0;
				yai[movenumberAI - 1] = 0;
				foundMove = 1;
			}
			else if (((players->boardarray[2][0] == 1) && (players->boardarray[1][1] == 1) && (players->boardarray[0][2] == 0))) {
				players->boardarray[0][2] = 2;
				xai[movenumberAI - 1] = 0;
				yai[movenumberAI - 1] = 2;
				foundMove = 1;
			}
			else if (((players->boardarray[2][0] == 1) && (players->boardarray[2][1] == 1) && (players->boardarray[2][2] == 0))) {
				players->boardarray[2][2] = 2;
				xai[movenumberAI - 1] = 2;
				yai[movenumberAI - 1] = 2;
				foundMove = 1;
			}
			else if (((players->boardarray[2][2] == 1) && (players->boardarray[2][1] == 1) && (players->boardarray[2][0] == 0))) {
				players->boardarray[2][0] = 2;
				xai[movenumberAI - 1] = 2;
				yai[movenumberAI - 1] = 0;
				foundMove = 1;
			}
			else if (((players->boardarray[2][2] == 1) && (players->boardarray[1][1] == 1) && (players->boardarray[0][0] == 0))) {
				players->boardarray[0][0] = 2;
				xai[movenumberAI - 1] = 0;
				yai[movenumberAI - 1] = 0;
				foundMove = 1;
			}
			else if (((players->boardarray[2][2] == 1) && (players->boardarray[1][2] == 1) && (players->boardarray[0][2] == 0))) {
				players->boardarray[0][2] = 2;
				xai[movenumberAI - 1] = 0;
				yai[movenumberAI - 1] = 2;
				foundMove = 1;
			}
			else if (((players->boardarray[1][1] == 1) && (players->boardarray[0][1] == 1) && (players->boardarray[2][1] == 0))) {
				players->boardarray[2][1] = 2;
				xai[movenumberAI - 1] = 2;
				yai[movenumberAI - 1] = 1;
				foundMove = 1;
			}
			else if (((players->boardarray[1][1] == 1) && (players->boardarray[1][2] == 1) && (players->boardarray[1][0] == 0))) {
				players->boardarray[1][0] = 2;
				xai[movenumberAI - 1] = 1;
				yai[movenumberAI - 1] = 0;
				foundMove = 1;
			}
			else if (((players->boardarray[1][1] == 1) && (players->boardarray[2][1] == 1) && (players->boardarray[0][1] == 0))) {
				players->boardarray[0][1] = 2;
				xai[movenumberAI - 1] = 0;
				yai[movenumberAI - 1] = 1;
				foundMove = 1;
			}
			else if (((players->boardarray[1][1] == 1) && (players->boardarray[1][0] == 1) && (players->boardarray[1][2] == 0))) {
				players->boardarray[1][2] = 2;
				xai[movenumberAI - 1] = 1;
				yai[movenumberAI - 1] = 2;
				foundMove = 1;
			}
			else if (((players->boardarray[0][0] == 1) && (players->boardarray[0][2] == 1) && (players->boardarray[0][1] == 0))) {
				players->boardarray[0][1] = 2;
				xai[movenumberAI - 1] = 0;
				yai[movenumberAI - 1] = 1;
				foundMove = 1;
			}
			else if (((players->boardarray[0][0] == 1) && (players->boardarray[2][0] == 1) && (players->boardarray[1][0] == 0))) {
				players->boardarray[1][0] = 2;
				xai[movenumberAI - 1] = 1;
				yai[movenumberAI - 1] = 0;
				foundMove = 1;
			}
			else if (((players->boardarray[2][0] == 1) && (players->boardarray[2][2] == 1) && (players->boardarray[2][1] == 0))) {
				players->boardarray[2][1] = 2;
				xai[movenumberAI - 1] = 2;
				yai[movenumberAI - 1] = 1;
				foundMove = 1;
			}
			else if (((players->boardarray[2][2] == 1) && (players->boardarray[0][2] == 1) && (players->boardarray[1][2] == 0))) {
				players->boardarray[1][2] = 2;
				xai[movenumberAI - 1] = 1;
				yai[movenumberAI - 1] = 2;
				foundMove = 1;
			}
			else if (((players->boardarray[0][1] == 1) && (players->boardarray[2][1] == 1) && (players->boardarray[1][1] == 0))) {
				players->boardarray[1][1] = 2;
				xai[movenumberAI - 1] = 1;
				yai[movenumberAI - 1] = 1;
				foundMove = 1;
			}
			else if (((players->boardarray[1][0] == 1) && (players->boardarray[1][2] == 1) && (players->boardarray[1][1] == 0))) {
				players->boardarray[1][1] = 2;
				xai[movenumberAI - 1] = 1;
				yai[movenumberAI - 1] = 1;
				foundMove = 1;
			}
			else if (((players->boardarray[0][0] == 1) && (players->boardarray[2][2] == 1) && (players->boardarray[1][1] == 0))) {
				players->boardarray[1][1] = 2;
				xai[movenumberAI - 1] = 1;
				yai[movenumberAI - 1] = 1;
				foundMove = 1;
			}
			else if (((players->boardarray[2][0] == 1) && (players->boardarray[0][2] == 1) && (players->boardarray[1][1] == 0))) {
				players->boardarray[1][1] = 2;
				xai[movenumberAI - 1] = 1;
				yai[movenumberAI - 1] = 1;
				foundMove = 1;
			}

			else {
				int r3, r4;
				while (foundMove != 1) {
					r3 = (rand() % 3);
					r4 = (rand() % 3);
					if (players->boardarray[r3][r4] == 0)
					{
						xai[movenumberAI - 1] = r3;
						yai[movenumberAI - 1] = r4;
						players->boardarray[r3][r4] = 2;
						foundMove = 1;

					}

				}
			}
		}
		print_fun(players, 0, 0);
		newmovenumber = takebackmove(players, movenumberAI, xai, yai, playerxy);
		movenumberAI = newmovenumber;
		win_flag = IsWin(players);
		if (win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("Player 1 wins! Game Over!\n\n");
				//	printf("hello %d hello", **(e->players->board));
			}
			else if (win_flag == 2)
			{
				printf("AI wins! Game Over!\n\n");
			}
			tie = 0;
			break;
		}
		else if (is_there_empty_cell(players) == 0)
			break;
	}
	if (tie == 1)
	{
		printf("The game is a tie!\n");
	}
	/*work in progress*/
	//PrintMoveList(l, players, xai, yai, playerxy);

}

//takes back move
int takebackmove(PLAYER* players, int movenumber, int* xai, int* yai, int* pointer)
{
	int choice;
	int newmovenumber = movenumber;
	printf("would you like to take back move, enter 1 for yes or 0 for no");
	scanf("%d", &choice);
	getchar();
	if (choice == 1)
	{
		players->boardarray[xai[movenumber - 1]][yai[movenumber - 1]] = 0;
		players->boardarray[pointer[movenumber - 1]][pointer[(movenumber - 1) + 9]] = 0;
		print_fun(players, 0, 0);
		newmovenumber = movenumber - 1;
	}
	return newmovenumber;

}
/* EOF */

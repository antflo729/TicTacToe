/*********************************************************************/
/* EECS 22 @ UCI Winter 2021 */
/*                                                                   */
/* Authors: Anthony Flores                                           */
/*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TicTacWowWeeWow.h"
#include "settings.h"
#include "gamefile.h"


// Handle Menu Options
int print_menu()
{
	int select = 0;
	printf("1. Start New Game (Human v. Human)\n");
	printf("2. Start New Game (Human v. AI)\n");
	printf("3. Game Settings\n");
	printf("4. Exit Game\n");
	printf("Choose Option: ");
	scanf("%d", &select);
	getchar(); // one solution for clearing the "\n" char from the input
	return select;
}
//Main Program for Tic-Tac-Whoa
int main()
{
	// initialize game
/*	char player1_char='X';
	char player2_char='O';
	char player1_color='d';
	char player2_color='d';
*/
//	PLAYER playerss;
	PLAYER* players = malloc(sizeof(PLAYER));
	players->player1_char = 'X';
	players->player2_char = 'O';
	players->player1_color = 'd';
	players->player2_color = 'd';
	players->boardarray = malloc(sizeof(int*) * 3);
	int i, j, k;
	for (i = 0; i < 3; i++) {
		players->boardarray[i] = malloc(sizeof(int) * 3);
	}
	printf("Welcome to Secure-Tic-Tac-Whoa!\n");
	int done = 0;
	while (done == 0)
	{
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				players->boardarray[j][k] = 0;
		//	printf("hello %d hello", *(*(players->boardarray+2)+2));
		int option = print_menu();

		MLIST* l = NULL;
		MENTRY* e = NULL;
		l = NewMovesList();

		switch (option)
		{
		case 1:
			HumanVsHuman(players);
			break;
		case 2:
			Human_Vs_AI(players, l, e);
			break;
		case 3:
			settings(players);
			break;
		case 4:
			printf("Thanks for playing. Exiting game...\n");
			done = 1;
			break;
		}
		//		free(l);
		 //       	free(e);

	}
	for (i = 0; i < 3; i++) {
		//	free(players->boardarray[i]);
	}
	//free(players->boardarray);
	//free(players);
	return 0;
}

/* EOF */

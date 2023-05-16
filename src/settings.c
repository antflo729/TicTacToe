// Anthony Flores game settings

#include "settings.h"
#include <stdio.h>


void settings(PLAYER* players)
{
    int valid_entered = 0;
    while (valid_entered == 0)
    {
        int select = 0;
        printf("Entering Settings...\n");
        printf("Please enter the setting options below...\n");
        printf("1. Changing the players' character\n");
        printf("2. Changing players' character color\n");
        printf("3. Exiting setting\n");
        scanf("%d", &select);
        getchar();

        if (select == 1)
        {
            choose_char(players);
        }
        else if (select == 2)
        {
            choose_color(players);
        }
        else if (select == 3)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please try again...\n");
        }
    }
    printf("Setting completed!\n");
}


void choose_char(PLAYER* players)
{
    printf("player 1 choose your char between A to Z\n");
    scanf("%c", &players->player1_char);
    getchar();
    printf("player 2 choose your char between A to Z\n");
    scanf("%c", &players->player2_char);
    getchar();
}


void choose_color(PLAYER* players)
{
    int valid_entered = 0;
    printf("player 1 choose from the following list for your color please...\n");
    printf("'r' for red, 'g' for green, 'y' for yellow, 'b' for blue', 'd' for default\n");
    while (valid_entered == 0)
    {
        char col;
        scanf("%c", &col);
        getchar();

        if (col == 'r' || col == 'g' || col == 'y' || col == 'b' || col == 'd')
        {
            players->player1_color = col;
            printf("%c", players->player1_color);
            valid_entered = 1;
        }
        else
        {
            printf("Invalid input, please try agian ...\n");
        }
    }
    valid_entered = 0;
    printf("player 2 choose from the following list for your color please...\n");
    printf("'r' for red, 'g' for green, 'y' for yellow, 'b' for blue', 'd' for default\n");
    while (valid_entered == 0)
    {
        char col;
        scanf("%c", &col);
        getchar();
        if (col == 'r' || col == 'g' || col == 'y' || col == 'b' || col == 'd')
        {
            players->player2_color = col;
            valid_entered = 1;
        }
        else
        {
            printf("Invalid input, please try agian ...\n");
        }
    }

}


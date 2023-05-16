# TicTacToe
This is a Tic-Tac-Toe game implemented in C. The game allows players to play against each other or against an AI opponent. It also provides settings options for customizing player characters and colors.

Introduction<a name="introduction"></a>
The Tic-Tac-Toe game is a classic two-player game where the goal is to get three of your own marks (X or O) in a row, column, or diagonal on a 3x3 grid. This implementation extends the game by adding an AI opponent and customizable settings.

The game is implemented in C and uses the standard input/output functions for user interaction.

Menu Options<a name="menu-options"></a>
The game provides the following menu options:

Start New Game (Human v. Human): Allows two human players to play against each other.
Start New Game (Human v. AI): Allows a human player to play against an AI opponent.
Game Settings: Allows customization of player characters and colors.
Exit Game: Exits the game.
Main Program<a name="main-program"></a>
The main function serves as the entry point for the game. It initializes the game state and presents the menu options to the user. Based on the user's selection, it calls the corresponding functions to handle the selected option.

The game state includes the player characters, colors, and the game board represented as a 2D array.

Settings<a name="settings"></a>
The game provides a settings menu where players can customize their characters and colors. The settings function is responsible for handling the settings menu.

Function Signature
c
Copy code
void settings(PLAYER* players);
Description
The settings function allows players to customize their characters and colors by calling the choose_char and choose_color functions. It continuously prompts the user for setting options until they choose to exit.

Function Signature
c
Copy code
void choose_char(PLAYER* players);
Description
The choose_char function prompts the players to choose their characters. Each player can choose a character between A to Z. The chosen characters are stored in the players structure.

Function Signature
c
Copy code
void choose_color(PLAYER* players);
Description
The choose_color function prompts the players to choose their colors. Each player can choose a color from the following options: 'r' for red, 'g' for green, 'y' for yellow, 'b' for blue, or 'd' for default. The chosen colors are stored in the players structure.

Choosing Characters<a name="choosing-characters"></a>
The choose_char function allows players to choose their characters. Each player can input a character between A to Z.

Choosing Colors<a name="choosing-colors"></a>
The choose_color function allows players to choose their colors. Players can select their color from the following options: 'r' for red, 'g' for green, 'y' for yellow, 'b' for blue, or 'd' for default.

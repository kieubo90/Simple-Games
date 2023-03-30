#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void draw_board(char board[][COLS]) 
{
    printf("\n");
    for(int i = 0; i < ROWS; i++) 
	{
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i != ROWS-1)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Function to get the user's move
void get_move(int *row, int *col) 
{
    printf("Enter row and column (1-3): ");
    scanf("%d %d", row, col);
    (*row)--;
    (*col)--;
}

int is_game_over(char board[ROWS][COLS]) 
{
    // Check for horizontal win
    for(int i = 0; i < ROWS; i++) 
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
            return 1;
    
	// Check for vertical win
    for(int j = 0; j < COLS; j++) 
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return 1;
    
	// Check for diagonal win
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    // Check for tie game
    int count = 0;
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            if(board[i][j] != ' ')
                count++;

    if(count == ROWS*COLS)
        return 0;

    // Game is not over
    return -1;
}


int main(void) 
{
    char board[ROWS][COLS];
    int player = 1, row, col, game_over = 0, result;

    // Initialize the board with empty spaces
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            board[i][j] = ' ';

    // Play the game
    while(!game_over) 
	{
		// Draw the board
		draw_board(board);

		// Get the player's move
		printf("Player %d's turn:\n", player);
		get_move(&row, &col);

		// Check if the move is valid
		if(board[row][col] != ' ') 
		{
			printf("Invalid move. Please try again.\n");
			continue;
		}

		// Update the board with the player's move
		if(player == 1) 
		{
			board[row][col] = 'X';
			player = 2;
		}
		else 
		{
			board[row][col] = 'O';
			player = 1;
		}

		// Check if the game is over
		result = is_game_over(board);
		if(result == 1)
		{
			printf("Player %d wins!\n", (player == 1) ? 2 : 1);
			game_over = 1;
		} 
		else if(result == 0)
		{
			printf("Tie game.\n");
			game_over = 1;
		}
	}
	draw_board(board);
	return (0);
}
/*
	printf("Board:\n");
	printf("|-------------|-------------|-------------|\n");
	printf("|             |             |             |\n");
	printf("|      X      |      O      |      X      |\n");
	printf("|             |             |             |\n");
	printf("|      1      |      2      |      3      |\n");
	printf("|-------------|-------------|-------------|\n");
	printf("|             |             |             |\n");
	printf("|      O      |      X      |      O      |\n");
	printf("|             |             |             |\n");
	printf("|      4      |      5      |      6      |\n");
	printf("|-------------|-------------|-------------|\n");
	printf("|             |             |             |\n");
	printf("|      X      |      O      |      X      |\n");
	printf("|             |             |             |\n");
	printf("|      7      |      8      |      9      |\n");
	printf("|-------------|-------------|-------------|\n");
*/

#include "tictactoe.h"
#include "computer.h"
#include <string.h>
#include <stdint.h>

char positions[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} }; //initialize value of all positions as ' '.
/*******README***************
positions[row][column] -> positions[0,1,2][0,1,2]

(posno = position on board (1 to 9))
values of row and column must be 0, 1, 2. However position on board is a number from 1 to 9, and we must convert it to our format of [row][column] and this is how:

value of row = (posno-1)/3 (For example: 1-1 = 0, 0%3 = 0 || 2-1 = 1, 1%3 = 1 || 8-1 = 7, 7%3 = 1)

value of column = (posno-1)%3 (For example: 1-1 = 0, 0/3 = 0 || 2-1 = 1, 1/3 = 0 || 8-1 = 7, 7/3 = 2)

posno = (row*3)+1+column;
****************************/

int posno;

char activeplayer = 'X';

void computerconfirm(char *compconfirm, uint8_t *isComp) {
	printf("Play against computer? (Yes/No): ");
	fgets(compconfirm, 8, stdin);
	
	if (strcmp(compconfirm, "Yes\n") == 0) *isComp = 1;
	else if (strcmp(compconfirm, "No\n") == 0) *isComp = 0;
	else { printf("Enter Yes or No only.\n\n"); computerconfirm(compconfirm, isComp); }
}

void enterpos() {
	printf("\nEnter position number: ");
	scanf("%d",&posno);
	if (posno < 1 || posno > 9) { printf("\nEnter a number from 1 to 9 and retry."); enterpos(); }
	
	if (positions[(posno-1)/3][(posno-1)%3] != ' ') { printf("\nThat position has already been occupied. Please enter a different location."); enterpos(); }
	
	printf("\n");
}

int _checkrows(char activeplayer, int posno) {
	int row = (posno-1)/3;
	for (int i = 0; i < 3; ++i) {
		if (positions[row][i] != activeplayer) return 0;
	}
	return 1;
}

int _checkcolumns(char activeplayer, int posno) {
	int col = (posno-1)%3;
	for (int i = 0; i < 3; ++i) {
		if (positions[i][col] != activeplayer) return 0;
	}
	return 1;	
}

int _checkdiagonals(char activeplayer, int posno) {
	int row = (posno-1)/3;
	int col = (posno-1)%3;
	
	switch (posno) {
		case 2: return 0;
		case 4: return 0;
		case 6: return 0;
		case 8: return 0;
		
		case 1:
			if (positions[row+1][col+1] == activeplayer && positions[row+2][col+2] == activeplayer) return 1;
		case 9:
			if (positions[row-1][col-1] == activeplayer && positions[row-2][col-2] == activeplayer) return 1;
			
		case 3:
			if (positions[row+1][col-1] == activeplayer && positions[row+2][col-2] == activeplayer) return 1;
		case 7:
			if (positions[row-1][col+1] == activeplayer && positions[row-2][col+2] == activeplayer) return 1;
			
		case 5:
			if ( (positions[row+1][col+1] == activeplayer && positions[row-1][col-1] == activeplayer) || (positions[row-1][col+1] == activeplayer && positions[row+1][col-1] == activeplayer) ) return 1;
	}
	return 0;
}

int checkall(char activeplayer, int posno) {
	int rows = _checkrows(activeplayer, posno);
	int cols = _checkcolumns(activeplayer, posno);
	int diags = _checkdiagonals(activeplayer, posno);
	printf("Rows, cols, diags: %d %d %d\n",rows,cols,diags);
	if (rows == 1 || cols == 1 || diags == 1) return 1;
	return 0;
}

int checkdraw() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (positions[i][j] == ' ') return 0;
		}
	}
	return 1;
}

int mainloop() {
	
	char compconfirm[8];
	uint8_t isComp;
	computerconfirm(compconfirm, &isComp);
	
	while (1) {
		
		printf("\n\nBoard:\n");
		printf("|-------------|-------------|-------------|\n");
		printf("|             |             |             |\n");
		printf("|      %c      |      %c      |      %c      |\n", positions[0][0], positions[0][1], positions[0][2]);
		printf("|             |             |             |\n");
		printf("|      1      |      2      |      3      |\n");
		printf("|-------------|-------------|-------------|\n");
		printf("|             |             |             |\n");
		printf("|      %c      |      %c      |      %c      |\n", positions[1][0], positions[1][1], positions[1][2]);
		printf("|             |             |             |\n");
		printf("|      4      |      5      |      6      |\n");
		printf("|-------------|-------------|-------------|\n");
		printf("|             |             |             |\n");
		printf("|      %c      |      %c      |      %c      |\n", positions[2][0], positions[2][1], positions[2][2]);
		printf("|             |             |             |\n");
		printf("|      7      |      8      |      9      |\n");
		printf("|-------------|-------------|-------------|\n");
			
		
		switch (activeplayer) {
			case 'X': printf("\nX's turn:"); break;
			case 'O': printf("\nO's turn:"); break;
			default: return 10;
		}
		
		if (isComp == 0) {
			enterpos();
			//set position of a board to a value (x or o)
			positions[(posno-1)/3][(posno-1)%3] = activeplayer;
		}
		
		else if (activeplayer == 'X') {
			enterpos();
			//set position of a board to a value (x or o)
			positions[(posno-1)/3][(posno-1)%3] = activeplayer;
		}
		
		else evaluate();
		
		switch (checkall(activeplayer, posno)) {
			case 1: printf("\nGame Over.\n"); return 0;
			case 0: printf("\n\n"); break;
			default: return 20;
		}
		
		if (checkdraw() == 1) { printf("Game Over.\n"); return -1; }
		
		//swap the activeplayer (X to O or O to X)
		switch (activeplayer) {
			case 'X': activeplayer = 'O'; break;
			case 'O': activeplayer = 'X'; break;
			default: return 11;
		}
	}
	
	return 1;
}
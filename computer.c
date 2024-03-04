#include "computer.h"
#include "tictactoe.h"


void checkX(int check[]) {
	//check rows
	for (int i = 0; i < 3; ++i) {
		char a = positions[i][0];
		char b = positions[i][1];
		char c = positions[i][2];
		
		if (a=='X' && b=='X' && c==' ') { check[0] = i; check[1] = 2; return; }
		
		if (a=='X' && c=='X' && b==' ') { check[0] = i; check[1] = 1; return; }
		
		if (b=='X' && c=='X' && a==' ') { check[0] = i; check[1] = 0; return; }
	}
	
	//check columns
	for (int i = 0; i < 3; ++i) {
		char a = positions[0][i];
		char b = positions[1][i];
		char c = positions[2][i];
		
		if (a=='X' && b=='X' && c==' ') { check[0] = 2; check[1] = i; return; }
		
		if (a=='X' && c=='X' && b==' ') { check[0] = 1; check[1] = i; return; }
		
		if (b=='X' && c=='X' && a==' ') { check[0] = 0; check[1] = i; return; }
	}
	
	//check diagonals
	char a = positions[0][0];
	char b = positions[1][1];
	char c = positions[2][2];
	
	if (a=='X' && b=='X' && c==' ') { check[0] = 2; check[1] = 2; return; }
		
	if (a=='X' && c=='X' && b==' ') { check[0] = 1; check[1] = 1; return; }
	
	if (b=='X' && c=='X' && a==' ') { check[0] = 0; check[1] = 0; return; }
	
	a = positions[0][2];
	b = positions[1][1];
	c = positions[2][0];
	
	if (a=='X' && b=='X' && c==' ') { check[0] = 2; check[1] = 0; return; }
		
	if (a=='X' && c=='X' && b==' ') { check[0] = 1; check[1] = 1; return; }
	
	if (b=='X' && c=='X' && a==' ') { check[0] = 0; check[1] = 2; return; }
	
	check[0] = -1; check[1] = -1;
	return;
}

void checkO(int check[]) {
	//check rows
	for (int i = 0; i < 3; ++i) {
		char a = positions[i][0];
		char b = positions[i][1];
		char c = positions[i][2];
		
		if (a=='O' && b=='O' && c==' ') { check[0] = i; check[1] = 2; return; }
		
		if (a=='O' && c=='O' && b==' ') { check[0] = i; check[1] = 1; return; }
		
		if (b=='O' && c=='O' && a==' ') { check[0] = i; check[1] = 0; return; }
	}
	
	//check columns
	for (int i = 0; i < 3; ++i) {
		char a = positions[0][i];
		char b = positions[1][i];
		char c = positions[2][i];
		
		if (a=='O' && b=='O' && c==' ') { check[0] = 2; check[1] = i; return; }
		
		if (a=='O' && c=='O' && b==' ') { check[0] = 1; check[1] = i; return; }
		
		if (b=='O' && c=='O' && a==' ') { check[0] = 0; check[1] = i; return; }
	}
	
	//check diagonals
	char a = positions[0][0];
	char b = positions[1][1];
	char c = positions[2][2];
	
	if (a=='O' && b=='O' && c==' ') { check[0] = 2; check[1] = 2; return; }
		
	if (a=='O' && c=='O' && b==' ') { check[0] = 1; check[1] = 1; return; }
	
	if (b=='O' && c=='O' && a==' ') { check[0] = 0; check[1] = 0; return; }
	
	a = positions[0][2];
	b = positions[1][1];
	c = positions[2][0];
	
	if (a=='O' && b=='O' && c==' ') { check[0] = 2; check[1] = 0; return; }
		
	if (a=='O' && c=='O' && b==' ') { check[0] = 1; check[1] = 1; return; }
	
	if (b=='O' && c=='O' && a==' ') { check[0] = 0; check[1] = 2; return; }
	
	check[0] = -1; check[1] = -1;
	return;
}

void inputatpos() {
	for (int posno = 1; posno < 10; ++posno) {
		int row = ((posno-1)/3);
		int col = ((posno-1)%3);
		
		//looks for a position filled with O, then looks for empty spots around that one and fills the first one it finds with O
		if (positions[row][col] == 'O') {
			
			if ( (row+1) < 3 ) {
				if (positions[row+1][col] == ' ') {positions[row+1][col] = 'O'; return;}
			}
			
			if ( (col+1) < 3 ) {
				if (positions[row][col+1] == ' ') {positions[row][col+1] = 'O'; return;}
			}
			
			if ( (row-1) > -1) {
				if (positions[row-1][col] == ' ') {positions[row-1][col] = 'O'; return;}
			}
			
			if ( (col-1) > -1) {
				if (positions[row][col-1] == ' ') {positions[row][col-1] = 'O'; return;}
			}
			
			if ( ((row-1)>-1) && ((col-1)>-1) ) {
				if (positions[row-1][col-1] == ' ') {positions[row-1][col-1] = 'O'; return;}
			}
			
			if ( ((row-1)>-1) && ((col+1)<3) ) {
				if (positions[row-1][col+1] == ' ') {positions[row-1][col+1] = 'O'; return;}
			}
			
			if ( ((row+1)<3) && ((col-1)>-1) ) {
				if (positions[row+1][col-1] == ' ') {positions[row+1][col-1] = 'O'; return;}
			}
			
			if ( ((row+1)<3) && ((col+1)<3) ) {
				if (positions[row+1][col+1] == ' ') {positions[row+1][col+1] = 'O'; return;}
			}
		}
	}
	//if a suitable position wasn't found and thus a return statement was not executed, then this loop will execute
	//this finds the first blank space and fills it
	for (int posno = 1; posno < 10; ++posno) {
		int row = ((posno-1)/3);
		int col = ((posno-1)%3);
		
		if (positions[row][col] == ' ') { positions[row][col] = 'O'; return; }
	}
}

void evaluate() {
	int check[2];
	
	checkO(check);
	//checking result of checkO
	if (check[0]==-1 && check[1]==-1) checkX(check);
	else { positions[check[0]][check[1]] = 'O'; posno = (check[0]*3)+1+check[1]; return; }
	
	//checking result of checkX
	if (check[0]==-1 && check[1]==-1) inputatpos();
	else { positions[check[0]][check[1]] = 'O'; posno = (check[0]*3)+1+check[1]; return; }
}
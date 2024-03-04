#include "tictactoe.h"
#include <string.h>

void replayconfirm();

int main() {
	
	int exitcode = mainloop();
	
	printf("Board:\n");
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
	
	if (exitcode != 0 && exitcode != -1) { fprintf(stderr, "\n\nAn error occurred somewhere. Exiting with exit code %d...", exitcode); return 1; }
	
	if (exitcode == -1) { printf("Draw. No one won!\n"); return 0; }
	
	switch (activeplayer) {
		case 'X': printf("X won!\n"); break;
		case 'O': printf("O won!\n"); break;
		default: fprintf(stderr, "\n\nAn error occured somewhere. Exiting with code main10..."); return 1;
	}
	
	replayconfirm();
	
	return 0;
}

void replayconfirm() {
	char repconf[8];
	printf("Play again? (Yes/No): ");
	fgets(repconf, 8, stdin);
	if (strcmp(repconf,"Yes\n") == 0) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				positions[i][j] = ' ';
			}
		}
		activeplayer = 'X';
		main();
	}
	else if (strcmp(repconf,"No\n") == 0) return;
	else { printf("Enter Yes or No only.\n\n"); replayconfirm(); }
}
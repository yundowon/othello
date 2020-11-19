#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

extern void print_othello();
extern void print_status();
extern void init_othello();

int main(int argc, char *argv[]) {
	
	int row, col;
	int player = 0;
	 
	init_othello();
	
	while(isGameEnd() == 0)
	{
		print_othello();
	} 
	
	print_status();
	
	return 0;
}

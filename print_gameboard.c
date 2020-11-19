#include <stdio.h>
#include <stdlib.h>
#define N 6

int gameboard[N][N];
int row, col;

//돌의 개수 출력 
void print_status(void)
{
	int white = 0;
	int black = 0;
	 
	for(row=0;row<N;row++) //백돌 개수 상태 
	{
		for(col=0;col<N;col++)
		{
			if(gameboard[row][col]=='O')
				white++;
		}
	}
	
	for(row=0;row<N;row++) //흑돌 개수 상태 
	{
		for(col=0;col<N;col++)
		{
			if(gameboard[row][col]=='X')
				black++;
		}
	}
	
	printf("\n STATUS - WHITE : %i, BLACK : %i", white, black);
}

//돌의 배치 출력
void print_othello(void)
{
	printf("  0 1 2 3 4 5\n"); // 좌표(열) 출력 
	for(row=0;row<N;row++)
	{
		printf(" -------------\n"); // 가로선 
		printf("%i|", row);
		for(col=0;col<N;col++) // 세로선 
		{
			printf("%c|", gameboard[row][col]);
			
		}
		printf("\n");
	}
	printf(" -------------\n"); // 가장 아래 가로선 
}
	
//게임 초기화 
void init_othello(void)
{
	for(row=0;row<N;row++) //보드의 빈칸 
	{
		for(col=0;col<N;col++)
			gameboard[row][col] = ' ';
	}
	
	gameboard[(N/2)-1][(N/2)-1]='O'; //보드 칸이 N개일 때 돌의 기본 위치 배정 
	gameboard[N/2][N/2]='O';
	gameboard[N/2][(N/2)-1]='X';
	gameboard[(N/2)-1][N/2]='X';
 }

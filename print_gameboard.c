#include <stdio.h>
#include <stdlib.h>
#define N 6

int gameboard[N][N];
int row, col;
int i;

//돌의 개수 출력 
void print_status(void)
{
	int white = 0;
	int black = 0;
	 
	for(row=0; row<N; row++) //백돌 개수 상태 
	{
		for(col=0; col<N; col++)
		{
			if(gameboard[row][col] == 'O')
				white++;
		}
	}
	
	for(row=0; row<N; row++) //흑돌 개수 상태 
	{
		for(col=0; col<N; col++)
		{
			if(gameboard[row][col] == 'X')
				black++;
		}
	}
	
	printf("\n STATUS - WHITE : %i, BLACK : %i\n", white, black);
}

//돌의 배치 출력
void print_othello(void)
{
	printf(" "); // 좌표(열)앞의 빈칸 출력
	for(col=0; col<N; col++) // 좌표(열) 출력
	{
		printf(" %i", col);
	}
	printf("\n");
	 
	for(row=0; row<N; row++)
	{
		for(i=0;i<=N;i++) // 가로선
		{
			printf("--");
		}
		printf("\n");
		 
		printf("%i|", row); // 좌표(행) 출력
		
		for(col=0; col<N; col++) // 세로선 
		{
			printf("%c|", gameboard[row][col]);
		}
		printf("\n");
	}
	for(i=0;i<=N;i++) // 가장 아래 가로선
		{
			printf("--");
		}
		printf("\n"); 
}
	
//게임 초기화 
void init_othello(void)
{
	for(row=0; row<N; row++) //보드의 빈칸 
	{
		for(col=0; col<N; col++)
			gameboard[row][col] = ' ';
	}
	
	gameboard[(N/2)-1][(N/2)-1] = 'O'; //보드 칸이 N개일 때 돌의 기본 위치 배정 
	gameboard[N/2][N/2] = 'O';
	gameboard[N/2][(N/2)-1] = 'X';
	gameboard[(N/2)-1][N/2] = 'X';
 }

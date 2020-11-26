#include <stdio.h>
#include <stdlib.h>
#define N 6

extern int check_white();
extern int check_black();

int gameboard[N][N]; 

/*게임 종료 조건 
	1. 모든 돌이 한 색깔로 통일됨 
	2. 모든 칸이 가득 참 
	3. 더 이상 둘 수 있는 칸이 없음(빈칸 존재) */
int isGameEnd(void)
{
	int row, col;
	int white = 0;
	int black = 0;
	int result_white = 0;
	int result_black = 0;
	
	for(row=0; row<N; row++) //백돌 개수 상태 
	{
		for(col=0; col<N; col++)
		{
			if(gameboard[row][col] == 'O')
				white++;
		}
	}
	
	for(row=0;row<N;row++) //흑돌 개수 상태 
	{
		for(col=0;col<N;col++)
		{
			if(gameboard[row][col] == 'X')
				black++;
		}
	}
	
	/* 1. 모든 돌이 한 색깔로 통일 */	
	if(black == 0 || white == 0) //흑돌이나 백돌 중 한 종류가 없다면 
		return 1; //종료 
		
	/* 2. 모든 칸이 가득 참 */ 
	if(black + white == N*N) //흑돌과 백돌의 총 개수가 칸의 수라면
		return 1; //종료 
		
	/*3. 더 이상 둘 수 있는 칸이 없음(빈칸 존재) */
	for(row=0; row<N; row++)
	{
		for(col=0; col<N; col++)
		{
			result_black *= check_black(row, col); //돌을 둘 수 있다면 0을, 없다면 1을 리턴하는 함수
			result_white *= check_white(row, col); //둘 수 있는 칸이 전혀 없다면 모두 곱한 값이 1이 됨
		}
	}
	if(result_black + result_white == 2) //백돌 흑돌 모두 둘 수 있는 칸이 전혀 없을 때는 더해서 2가 됨
		return 1; //종료 
	else
		return 0; //진행	
 } 

/* 결과 입력 */
void result(void)
{
	int row, col;
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
	
	for(row=0;row<N;row++) //흑돌 개수 상태 
	{
		for(col=0;col<N;col++)
		{
			if(gameboard[row][col] == 'X')
				black++;
		}
	}
	
	if(black > white)
		printf("BLACK WIN!!");
	if(black < white)
		printf("WHITE WIN!!");
	else
		printf("BLACK AND WHITE TIED");
 } 

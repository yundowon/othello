#include <stdio.h>
#include <stdlib.h>
#define N 6

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
extern void print_othello();
extern void print_status();
extern void init_othello();
extern int check_white();
extern int check_black();
extern int isGameEnd();
extern void result();

int gameboard[N][N];

int main(int argc, char *argv[]) {
	
	int row, col;
	int player = 1;
	 
	init_othello();
	
	while(isGameEnd() == 0) //게임종료조건이 만족하여 0이 되기 전까지 반복 
	{
		print_othello(); //보드 틀 출력
		print_status(); //돌의 개수 출력
		if(isGameEnd() == 1)
			continue;
					
		if(player%2 == 1)// 백돌턴(홀수턴 
		{	
			if(check_white() == 1) //백돌 둘 수 있는 칸이 없다면 
			{
				printf("\nno space to put white othello, skip the turn\n");//없으면 패스 
				player++;
				continue;
			}
			while(1) //좌표를 제대로 입력할 때까지 반복 
			{
				printf("\nput a new white othello : "); //좌표 입력 
				scanf("%i %i", &row, &col); 
								
				if((row >= 0 && row < N)||(col >= 0 && col < N)) //숫자 외에 다른 것 입력
				{
						break; //반복문 빠져나옴
				}
				else if(gameboard[row][col] == 'O'||gameboard[row][col] == 'X') //이미 돌이 있는 곳
				{
					printf("invalid input! (already occupied)\n");
					continue; //다시 반복
				}
				else if(check_white(row, col) == 1) //둘 수 없는 곳
				{
					printf("invalid input! (no flip happens)\n");
					continue; //다시 반복
				}
				else if((row >= N && row < 0)||(col >= N && col < 0)) //입력값이 범위를 벗어남 
				{
					printf("invalid input! (should be less than %i)\n", N);
					continue; //다시 반복
				}
				else //숫자 외에 다른 것 입력
				{
					printf("invalid input format!!\n");
					continue; //다시 반복
				}
		 	}
		
			//좌표가 적절한 경우
			gameboard[row][col] = 'O'; //빈칸을 백돌로 바꾸고
			//그 사이의 흑돌을 백돌로 바꿈
			player++; 			
		}
		else// 흑돌턴(짝수턴 
		{	
			if(check_black() == 1) //흑돌 둘 수 있는 칸이 없다면 
			{
				printf("\nno space to put black othello, skip the turn\n");//없으면 패스 
				player++;
				continue;
			}
			while(1) //좌표를 제대로 입력할 때까지 반복 
			{
				printf("\nput a new black othello : "); //좌표 입력
				scanf("%i %i", &row, &col); 
				
				if((row >= 0 && row < N)||(col >= 0 && col < N)) //숫자 외에 다른 것 입력
				{
					break; //반복문 빠져나옴
				}
				else if(gameboard[row][col] == 'O'||gameboard[row][col] == 'X') //이미 돌이 있는 곳
				{
					printf("invalid input! (already occupied)\n");
					continue; //다시 반복
				}
				else if(check_white(row, col) == 1) //둘 수 없는 곳
				{
					printf("invalid input! (no flip happens)\n");
					continue; //다시 반복
				}
				else if((row >= N && row < 0)||(col >= N && col < 0)) //입력값이 범위를 벗어남 
				{
					printf("invalid input! (should be less than %i)\n", N);
					continue; //다시 반복
				}
				else //숫자 외에 다른 것 입력
				{
					printf("invalid input format!!\n");
					continue; //다시 반복
				}
		 	}
		
			//좌표가 적절한 경우
			gameboard[row][col] = 'X'; //빈칸을 흑돌로 바꾸고
			//그 사이의 백돌을 흑돌로 바꿈
			player++; 			
		}
	
		return 0;
	}
	result();
}

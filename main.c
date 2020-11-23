#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
extern void print_othello();
extern void print_status();
extern void init_othello();
extern int isGameEnd();

int main(int argc, char *argv[]) {
	
	int row, col;
	int player = 1;
	 
	init_othello();
	
	while(isGameEnd() == 0) //게임종료조건이 만족하여 0이 되기 전까지 반복 
	{
		print_othello(); // 배치 상태 출력 
		//놓을 수 있는 칸 있는지
		//놓을 수 있는 칸 없으면 게임 종료
		
		if(player%2 == 1)// 백돌턴(홀수턴 
		{	
			/*백돌 둘 수 있는 칸 있는지
			없으면 패쓰(no space to put white othello, skip the turn)
			printf("put a new white othello : ")
			scanf("%i %i", &row,&col)있으면 좌표 입력
			좌표가 부적절한 경우
			printf("invalid input! (already occupied)")1)이미 돌이 있는 곳
			printf("invalid inpu! (no flip happens)")2)둘 수 없는 곳 
			printf("invalid input! (should be less than %i)", N)3)숫자가 N보다 크거나 같음 (invalid input! (should be less than N))
			printf("invalid input format!!")4)숫자 외에 다른 것 입력 
				이후 다시 좌표 입력
			좌표가 적절한 경우
				빈칸을 백돌로 바꾸고 그 사이의 흑돌을 백돌로 바꿈 
		*/
		
		else// 흑돌턴(짝수턴 
		{	
			/* 흑돌 둘 수 있는 칸 있는지
			없으면 패쓰(no space to put white othello, skip the turn)
			있으면 좌표 입력 (put a new white othello : )
			좌표가 부적절한 경우
				1)이미 돌이 있는 곳 (invalid input! (already occupied))
				2)둘 수 없는 곳 (invalid inpu! (no flip happens))
				3)숫자가 N보다 크거나 같음 (invalid input! (should be less than N))
				4)숫자 외에 다른 것 입력 (invalid input format!!) 
				이후 다시 좌표 입력
			좌표가 적절한 경우
				빈칸을 흑돌로 바꾸고 그 사이의 백돌을 흑돌로 바꿈 
		*/
	} 
	
	print_status();
	
	return 0;
}

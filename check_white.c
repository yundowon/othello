#include <stdio.h>
#include <stdlib.h>
#define N 6
/* up, down, left, right, upright, upleft, downright, downleft
	방향을 따라 돌을 둘 수 없는 곳의 경우 1을 리턴하고
	돌을 둘 수 있는 곳에 0을 리턴*/
int gameboard[N][N];

int up_white(int x, int y)
{
	int i;
		
	if(x-1 < 0)  //한칸 위가 모서리인지 확인 
		return 1;
	else
	{
		if(gameboard[x-1][y] == 'O') //이웃한 칸이 같은 백돌
			return 1;
		else if(gameboard[x-1][y] == ' ') //이웃한 칸이 빈칸 
			return 1;
		else
		{
			if(gameboard[x-1][y] == 'X') //이웃한 칸이 흑돌이라면
			{
				for(i=0; i<N; i++)
				{
 					if(x-2-i < 0) //위로 이웃한 칸이 모서리면 
						break; //반복문 빠져나옴 
					if(gameboard[x-2-i][y] == ' ') //위로 이웃한 칸이 빈칸이라면 
						break; //반복문 빠져나옴 
 					if(gameboard[x-2-i][y] == 'X') //위로 이웃한 칸이 흑돌이라면 
						continue; //다음 반복으로 
 					if(gameboard[x-2-i][y] == 'O') //위로 이웃한 칸이 백돌이라면 
						return 0;
				}
				return 1;
			}	
		}
	}
}

int down_white(int x, int y)
{
	int i;
	
	if(x+1 >= N)  //한칸 아래가 모서리인지 확인
		return 1;
	else
	{
		if(gameboard[x+1][y] == 'O') //이웃한 칸이 같은 백돌
			return 1;
		else if(gameboard[x+1][y] == ' ') //이웃한 칸이 빈칸 
			return 1;
		else
		{
			if(gameboard[x+1][y] == 'X') //이웃한 칸이 흑돌이라면
			{
				for(i=0; i<N; i++)
				{
 					if(x+2+i >= N) //아래로 이웃한 칸이 모서리면 
						break; //반복문 빠져나옴
					if(gameboard[x+2+i][y] == ' ') //아래로 이웃한 칸이 빈칸이라면
						break; //반복문 빠져나옴
 					if(gameboard[x+2+i][y] == 'X') //아래로 이웃한 칸이 흑돌이라면
						continue; //다음 반복으로
 					if(gameboard[x+2+i][y] == 'O') //아래로 이웃한 칸이 백돌이라면
						return 0;
				}
				return 1;
			}	
		}
	}
}

int left_white(int x, int y)
{
	int i;
	
	if(y-1<0)  //한칸 왼쪽이 모서리인지 확인
		return 1;
	else
	{
		if(gameboard[x][y-1] == 'O') //이웃한 칸이 같은 백돌
			return 1;
		else if(gameboard[x][y-1] == ' ') //이웃한 칸이 빈칸 
			return 1;
		else
		{
			if(gameboard[x][y-1] == 'X') //이웃한 칸이 흑돌이라면
			{
				for(i=0; i<N; i++)
				{
 					if(y-2-i < 0) //왼쪽으로 이웃한 칸이 모서리면
						break; //반복문 빠져나옴
					if(gameboard[x][y-2-i] == ' ') //왼쪽으로 이웃한 칸이 빈칸이라면
						break; //반복문 빠져나옴
 					if(gameboard[x][y-2-i] == 'X') //왼쪽으로 이웃한 칸이 흑돌이라면
						continue; //다음 반복으로
 					if(gameboard[x][y-2-i] == 'O') //왼쪽로 이웃한 칸이 백돌이라면
						return 0;
				}
				return 1;
			}	
		}
	}
}

int right_white(int x, int y)
{
	int i;
	
	if(y+1 >= N)  //한칸 오른쪽이 모서리인지 확인
		return 1;
	else
	{
		if(gameboard[x][y+1] == 'O') //이웃한 칸이 같은 백돌
			return 1;
		else if(gameboard[x][y+1] == ' ') //이웃한 칸이 빈칸 
			return 1;
		else
		{
			if(gameboard[x][y+1] == 'X') //이웃한 칸이 흑돌이라면
			{
				for(i=0; i<N; i++)
				{
 					if(y+2+i >= N) //오른쪽으로 이웃한 칸이 모서리면
						break; //반복문 빠져나옴
					if(gameboard[x][y+2+i] == ' ') //오른쪽으로 이웃한 칸이 빈칸이라면
						break; //반복문 빠져나옴
 					if(gameboard[x][y+2+i] == 'X') //오른쪽으로 이웃한 칸이 훅돌이라면
						continue; //다음 반복으로
 					if(gameboard[x][y+2+i] == 'O') //오른쪽으로 이웃한 칸이 백돌이라면
						return 0;
				}
				return 1;
			}	
		}
	}
}

int upright_white(int x, int y)
{
	int i;
	
	if((x-1 < 0)||(y+1 >= N))  //한칸 위, 한칸 오른쪽이 모서리인지 확인
		return 1;
	else
	{
		if(gameboard[x-1][y+1] == 'O') //이웃한 칸이 같은 백돌
			return 1;
		else if(gameboard[x-1][y+1] == ' ') //이웃한 칸이 빈칸 
			return 1;
		else
		{
			if(gameboard[x-1][y+1] == 'X') //이웃한 칸이 흑돌이라면
			{
				for(i=0; i<N; i++)
				{
 					if((x-2-i < 0)||(y+2+i >= N)) //오른쪽 위로 이웃한 칸이 모서리면
						break; //반복문 빠져나옴
					if(gameboard[x-2-i][y+2+i] == ' ') //오른쪽 위로 이웃한 칸이 빈칸이라면
						break; //반복문 빠져나옴
 					if(gameboard[x-2-i][y+2+i] == 'X') //오른쪽 위로 이웃한 칸이 흑돌이라면
						continue; //다음 반복으로
 					if(gameboard[x-2-i][y+2+i] == 'O') //오른쪽 위로 이웃한 칸이 백돌이라면
						return 0;
				}
				return 1;
			}	
		}
	}
}

int upleft_white(int x, int y)
{
	int i;
	
	if((x-1 < 0)||(y-1 < 0))  //한칸 위, 한칸 왼쪽이 모서리인지 확인
		return 1;
	else
	{
		if(gameboard[x-1][y-1] == 'O') //이웃한 칸이 같은 백돌
			return 1;
		else if(gameboard[x-1][y-1] == ' ') //이웃한 칸이 빈칸 
			return 1;
		else
		{
			if(gameboard[x-1][y-1] == 'X') //이웃한 칸이 흑돌이라면
			{
				for(i=0; i<N; i++)
				{
 					if((x-2-i < 0)||(y-2-i < 0)) //왼쪽 위로 이웃한 칸이 모서리면
						break; //반복문 빠져나옴
					if(gameboard[x-2-i][y-2-i] == ' ') //왼쪽 위로 이웃한 칸이 빈칸이라면
						break; //반복문 빠져나옴
 					if(gameboard[x-2-i][y-2-i] == 'X') //왼쪽 위로 이웃한 칸이 흑돌이라면
						continue; //다음 반복으로
 					if(gameboard[x-2-i][y-2-i] == 'O') //왼쪽 위로 이웃한 칸이 백돌이라면
						return 0;
				}
				return 1;
			}	
		}
	}
}

int downright_white(int x, int y)
{
	int i;
	
	if((x+1 >= N)||(y+1 >= N))  //한칸 아래, 한칸 오른쪽이 모서리인지 확인
		return 1;
	else
	{
		if(gameboard[x+1][y+1] == 'O') //이웃한 칸이 같은 백돌
			return 1;
		else if(gameboard[x+1][y+1] == ' ') //이웃한 칸이 빈칸 
			return 1;
		else
		{
			if(gameboard[x+1][y+1] == 'X') //이웃한 칸이 흑돌이라면
			{
				for(i=0; i<N; i++)
				{
 					if((x+2+i >= N)||(y+2+i >= N)) //오른쪽 아래로 이웃한 칸이 모서리면
						break; //반복문 빠져나옴
					if(gameboard[x+2+i][y+2+i] == ' ') //오른쪽 아래로 이웃한 칸이 빈칸이라면
						break; //반복문 빠져나옴
 					if(gameboard[x+2+i][y+2+i] == 'X') //오른쪽 아래로 이웃한 칸이 흑돌이라면
						continue; //다음 반복으로
 					if(gameboard[x+2+i][y+2+i] == 'O') //오른쪽 아래로 이웃한 칸이 백돌이라면
						return 0;
				}
				return 1;
			}	
		}
	}
}

int downleft_white(int x, int y)
{
	int i;
	
	if((x+1 >= N)||(y-1 < 0))  //한칸 아래, 한칸 왼쪽이 모서리인지 확인
		return 1;
	else
	{
		if(gameboard[x+1][y-1] == 'O') //이웃한 칸이 같은 백돌
			return 1;
		else if(gameboard[x+1][y-1] == ' ') //이웃한 칸이 빈칸 
			return 1;
		else
		{
			if(gameboard[x+1][y-1] == 'X') //이웃한 칸이 흑돌이라면
			{
				for(i=0; i<N; i++)
				{
 					if((x+2+i >= N)||(y-1-i < 0)) //왼쪽 아래로 이웃한 칸이 모서리면
						break; //반복문 빠져나옴
					if(gameboard[x+2+i][y-1-i] == ' ') //왼쪽 아래로 이웃한 칸이 빈칸이라면
						break; //반복문 빠져나옴
 					if(gameboard[x+2+i][y-1-i] == 'X') //왼쪽 아래로 이웃한 칸이 흑돌이라면
						continue; //다음 반복으로
 					if(gameboard[x+2+i][y-1-i] == 'O') //왼쪽 아래로 이웃한 칸이 백돌이라면
						return 0;
				}
				return 1;
			}	
		}
	}
}


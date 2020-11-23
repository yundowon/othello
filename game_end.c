#include <stdio.h>
#include <stdlib.h>
#define N 6

/*���� ���� ���� 
	1. ��� ���� �� ����� ���ϵ� 
	2. ��� ĭ�� ���� �� 
	3. �� �̻� �� �� �ִ� ĭ�� ����(��ĭ ����) */
int gameboard[N][N]; 
	
int isGameEnd(void)
{
	int row, col;
	int white = 0;
	int black = 0;
	
	for(row=0;row<N;row++) //�鵹 ���� ���� 
	{
		for(col=0;col<N;col++)
		{
			if(gameboard[row][col]=='O')
				white++;
		}
	}
	
	for(row=0;row<N;row++) //�浹 ���� ���� 
	{
		for(col=0;col<N;col++)
		{
			if(gameboard[row][col]=='X')
				black++;
		}
	}
	
	/* 1. ��� ���� �� ����� ���� */	
	if(black == 0 || white == 0) //�浹�̳� �鵹 �� �� ������ ���ٸ� 
		return 1; //���� 
		
	/* 2. ��� ĭ�� ���� �� */ 
	if(black + white == N*N) //�浹�� �鵹�� �� ������ ĭ�� �����
		return 1; //���� 
		
	/*3. �� �̻� �� �� �ִ� ĭ�� ����(��ĭ ����) */
	
 } 

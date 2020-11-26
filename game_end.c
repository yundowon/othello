#include <stdio.h>
#include <stdlib.h>
#define N 6

extern int check_white();
extern int check_black();

int gameboard[N][N]; 

/*���� ���� ���� 
	1. ��� ���� �� ����� ���ϵ� 
	2. ��� ĭ�� ���� �� 
	3. �� �̻� �� �� �ִ� ĭ�� ����(��ĭ ����) */
int isGameEnd(void)
{
	int row, col;
	int white = 0;
	int black = 0;
	int result_white = 0;
	int result_black = 0;
	
	for(row=0; row<N; row++) //�鵹 ���� ���� 
	{
		for(col=0; col<N; col++)
		{
			if(gameboard[row][col] == 'O')
				white++;
		}
	}
	
	for(row=0;row<N;row++) //�浹 ���� ���� 
	{
		for(col=0;col<N;col++)
		{
			if(gameboard[row][col] == 'X')
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
	for(row=0; row<N; row++)
	{
		for(col=0; col<N; col++)
		{
			result_black *= check_black(row, col); //���� �� �� �ִٸ� 0��, ���ٸ� 1�� �����ϴ� �Լ�
			result_white *= check_white(row, col); //�� �� �ִ� ĭ�� ���� ���ٸ� ��� ���� ���� 1�� ��
		}
	}
	if(result_black + result_white == 2) //�鵹 �浹 ��� �� �� �ִ� ĭ�� ���� ���� ���� ���ؼ� 2�� ��
		return 1; //���� 
	else
		return 0; //����	
 } 

/* ��� �Է� */
void result(void)
{
	int row, col;
	int white = 0;
	int black = 0;
	
	for(row=0; row<N; row++) //�鵹 ���� ���� 
	{
		for(col=0; col<N; col++)
		{
			if(gameboard[row][col] == 'O')
				white++;
		}
	}
	
	for(row=0;row<N;row++) //�浹 ���� ���� 
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

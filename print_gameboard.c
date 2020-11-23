#include <stdio.h>
#include <stdlib.h>
#define N 6

int gameboard[N][N];
int row, col;

//���� ���� ��� 
void print_status(void)
{
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
	
	for(row=0; row<N; row++) //�浹 ���� ���� 
	{
		for(col=0; col<N; col++)
		{
			if(gameboard[row][col] == 'X')
				black++;
		}
	}
	
	printf("\n STATUS - WHITE : %i, BLACK : %i", white, black);
}

//���� ��ġ ���
void print_othello(void)
{
	printf(" "); // ��ǥ(��)���� ��ĭ ���
	for(col=0; col<N; col++) // ��ǥ(��) ���
	{
		printf(" %i", col);
	}
	printf("\n");
	 
	for(row=0; row<N; row++)
	{
		printf(" -------------\n"); // ���μ� 
		printf("%i|", row);
		for(col=0; col<N; col++) // ���μ� 
		{
			printf("%c|", gameboard[row][col]);
			
		}
		printf("\n");
	}
	printf(" -------------\n"); // ���� �Ʒ� ���μ� 
}
	
//���� �ʱ�ȭ 
void init_othello(void)
{
	for(row=0; row<N; row++) //������ ��ĭ 
	{
		for(col=0; col<N; col++)
			gameboard[row][col] = ' ';
	}
	
	gameboard[(N/2)-1][(N/2)-1] = 'O'; //���� ĭ�� N���� �� ���� �⺻ ��ġ ���� 
	gameboard[N/2][N/2] = 'O';
	gameboard[N/2][(N/2)-1] = 'X';
	gameboard[(N/2)-1][N/2] = 'X';
 }

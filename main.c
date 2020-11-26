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
	
	while(isGameEnd() == 0) //�������������� �����Ͽ� 0�� �Ǳ� ������ �ݺ� 
	{
		print_othello(); //���� Ʋ ���
		print_status(); //���� ���� ���
		if(isGameEnd() == 1)
			continue;
					
		if(player%2 == 1)// �鵹��(Ȧ���� 
		{	
			if(check_white() == 1) //�鵹 �� �� �ִ� ĭ�� ���ٸ� 
			{
				printf("\nno space to put white othello, skip the turn\n");//������ �н� 
				player++;
				continue;
			}
			while(1) //��ǥ�� ����� �Է��� ������ �ݺ� 
			{
				printf("\nput a new white othello : "); //��ǥ �Է� 
				scanf("%i %i", &row, &col); 
								
				if((row >= 0 && row < N)||(col >= 0 && col < N)) //���� �ܿ� �ٸ� �� �Է�
				{
						break; //�ݺ��� ��������
				}
				else if(gameboard[row][col] == 'O'||gameboard[row][col] == 'X') //�̹� ���� �ִ� ��
				{
					printf("invalid input! (already occupied)\n");
					continue; //�ٽ� �ݺ�
				}
				else if(check_white(row, col) == 1) //�� �� ���� ��
				{
					printf("invalid input! (no flip happens)\n");
					continue; //�ٽ� �ݺ�
				}
				else if((row >= N && row < 0)||(col >= N && col < 0)) //�Է°��� ������ ��� 
				{
					printf("invalid input! (should be less than %i)\n", N);
					continue; //�ٽ� �ݺ�
				}
				else //���� �ܿ� �ٸ� �� �Է�
				{
					printf("invalid input format!!\n");
					continue; //�ٽ� �ݺ�
				}
		 	}
		
			//��ǥ�� ������ ���
			gameboard[row][col] = 'O'; //��ĭ�� �鵹�� �ٲٰ�
			//�� ������ �浹�� �鵹�� �ٲ�
			player++; 			
		}
		else// �浹��(¦���� 
		{	
			if(check_black() == 1) //�浹 �� �� �ִ� ĭ�� ���ٸ� 
			{
				printf("\nno space to put black othello, skip the turn\n");//������ �н� 
				player++;
				continue;
			}
			while(1) //��ǥ�� ����� �Է��� ������ �ݺ� 
			{
				printf("\nput a new black othello : "); //��ǥ �Է�
				scanf("%i %i", &row, &col); 
				
				if((row >= 0 && row < N)||(col >= 0 && col < N)) //���� �ܿ� �ٸ� �� �Է�
				{
					break; //�ݺ��� ��������
				}
				else if(gameboard[row][col] == 'O'||gameboard[row][col] == 'X') //�̹� ���� �ִ� ��
				{
					printf("invalid input! (already occupied)\n");
					continue; //�ٽ� �ݺ�
				}
				else if(check_white(row, col) == 1) //�� �� ���� ��
				{
					printf("invalid input! (no flip happens)\n");
					continue; //�ٽ� �ݺ�
				}
				else if((row >= N && row < 0)||(col >= N && col < 0)) //�Է°��� ������ ��� 
				{
					printf("invalid input! (should be less than %i)\n", N);
					continue; //�ٽ� �ݺ�
				}
				else //���� �ܿ� �ٸ� �� �Է�
				{
					printf("invalid input format!!\n");
					continue; //�ٽ� �ݺ�
				}
		 	}
		
			//��ǥ�� ������ ���
			gameboard[row][col] = 'X'; //��ĭ�� �浹�� �ٲٰ�
			//�� ������ �鵹�� �浹�� �ٲ�
			player++; 			
		}
	
		return 0;
	}
	result();
}

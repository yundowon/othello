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
	
	while(isGameEnd() == 0) //�������������� �����Ͽ� 0�� �Ǳ� ������ �ݺ� 
	{
		print_othello(); // ��ġ ���� ��� 
		//���� �� �ִ� ĭ �ִ���
		//���� �� �ִ� ĭ ������ ���� ����
		
		if(player%2 == 1)// �鵹��(Ȧ���� 
		{	
			/*�鵹 �� �� �ִ� ĭ �ִ���
			������ �о�(no space to put white othello, skip the turn)
			printf("put a new white othello : ")
			scanf("%i %i", &row,&col)������ ��ǥ �Է�
			��ǥ�� �������� ���
			printf("invalid input! (already occupied)")1)�̹� ���� �ִ� ��
			printf("invalid inpu! (no flip happens)")2)�� �� ���� �� 
			printf("invalid input! (should be less than %i)", N)3)���ڰ� N���� ũ�ų� ���� (invalid input! (should be less than N))
			printf("invalid input format!!")4)���� �ܿ� �ٸ� �� �Է� 
				���� �ٽ� ��ǥ �Է�
			��ǥ�� ������ ���
				��ĭ�� �鵹�� �ٲٰ� �� ������ �浹�� �鵹�� �ٲ� 
		*/
		
		else// �浹��(¦���� 
		{	
			/* �浹 �� �� �ִ� ĭ �ִ���
			������ �о�(no space to put white othello, skip the turn)
			������ ��ǥ �Է� (put a new white othello : )
			��ǥ�� �������� ���
				1)�̹� ���� �ִ� �� (invalid input! (already occupied))
				2)�� �� ���� �� (invalid inpu! (no flip happens))
				3)���ڰ� N���� ũ�ų� ���� (invalid input! (should be less than N))
				4)���� �ܿ� �ٸ� �� �Է� (invalid input format!!) 
				���� �ٽ� ��ǥ �Է�
			��ǥ�� ������ ���
				��ĭ�� �浹�� �ٲٰ� �� ������ �鵹�� �浹�� �ٲ� 
		*/
	} 
	
	print_status();
	
	return 0;
}

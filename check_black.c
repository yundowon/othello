#include <stdio.h>
#include <stdlib.h>
#define N 6
/* up, down, left, right, upright, upleft, downright, downleft 
	���⿡ ���� ���� ���� �� �� �ִ��� Ȯ��*/
int gameboard[N][N];

int up_black(int x, int y)
{
	int i;
		
	if(x-1 < 0)  //��ĭ ���� �𼭸����� Ȯ�� 
		return 1; //���� �� �� ���� 
	else
	{
		if(gameboard[x-1][y] == 'X') //�̿��� ĭ�� ���� �浹
			return 1; //���� �� �� ���� 
		else if(gameboard[x-1][y] == ' ') //�̿��� ĭ�� ��ĭ 
			return 1; //���� �� �� ���� 
		else
		{
			if(gameboard[x-1][y] == 'O') //�̿��� ĭ�� �鵹�̶��
			{
				for(i=0; i<N; i++)
				{
 					if(x-2-i < 0) //���� �̿��� ĭ�� �𼭸��� 
						break; //�ݺ��� �������� 
					if(gameboard[x-2-i][y] == ' ') //���� �̿��� ĭ�� ��ĭ�̶�� 
						break; //�ݺ��� �������� 
 					if(gameboard[x-2-i][y] == 'O') //���� �̿��� ĭ�� �鵹�̶�� 
						continue; //���� �ݺ����� 
 					if(gameboard[x-2-i][y] == 'X') //���� �̿��� ĭ�� �浹�̶�� 
						return 0; //���� �� �� ���� 
				}
				return 1; //���� �� �� ���� 
			}	
		}
	}
}

int down_black(int x, int y)
{
	int i;
	
	if(x+1 >= N)  //��ĭ �Ʒ��� �𼭸����� Ȯ��
		return 1; //���� �� �� ���� 
	else
	{
		if(gameboard[x+1][y] == 'X') //�̿��� ĭ�� ���� �浹
			return 1; //���� �� �� ���� 
		else if(gameboard[x+1][y] == ' ') //�̿��� ĭ�� ��ĭ 
			return 1; //���� �� �� ���� 
		else
		{
			if(gameboard[x+1][y] == 'O') //�̿��� ĭ�� �鵹�̶��
			{
				for(i=0; i<N; i++)
				{
 					if(x+2+i >= N) //�Ʒ��� �̿��� ĭ�� �𼭸��� 
						break; //�ݺ��� ��������
					if(gameboard[x+2+i][y] == ' ') //�Ʒ��� �̿��� ĭ�� ��ĭ�̶��
						break; //�ݺ��� ��������
 					if(gameboard[x+2+i][y] == 'O') //�Ʒ��� �̿��� ĭ�� �鵹�̶��
						continue; //���� �ݺ�����
 					if(gameboard[x+2+i][y] == 'X') //�Ʒ��� �̿��� ĭ�� �浹�̶��
						return 0; //���� �� �� ���� 
				}
				return 1; //���� �� �� ���� 
			}	
		}
	}
}

int left_black(int x, int y)
{
	int i;
	
	if(y-1<0)  //��ĭ ������ �𼭸����� Ȯ��
		return 1; //���� �� �� ���� 
	else
	{
		if(gameboard[x][y-1] == 'X') //�̿��� ĭ�� ���� �浹
			return 1; //���� �� �� ���� 
		else if(gameboard[x][y-1] == ' ') //�̿��� ĭ�� ��ĭ 
			return 1; //���� �� �� ���� 
		else
		{
			if(gameboard[x][y-1] == 'O') //�̿��� ĭ�� �鵹�̶��
			{
				for(i=0; i<N; i++)
				{
 					if(y-2-i < 0) //�������� �̿��� ĭ�� �𼭸���
						break; //�ݺ��� ��������
					if(gameboard[x][y-2-i] == ' ') //�������� �̿��� ĭ�� ��ĭ�̶��
						break; //�ݺ��� ��������
 					if(gameboard[x][y-2-i] == 'O') //�������� �̿��� ĭ�� �鵹�̶��
						continue; //���� �ݺ�����
 					if(gameboard[x][y-2-i] == 'X') //���ʷ� �̿��� ĭ�� �浹�̶��
						return 0; //���� �� �� ���� 
				}
				return 1; //���� �� �� ���� 
			}	
		}
	}
}

int right_black(int x, int y)
{
	int i;
	
	if(y+1 >= N)  //��ĭ �������� �𼭸����� Ȯ��
		return 1; //���� �� �� ���� 
	else
	{
		if(gameboard[x][y+1] == 'X') //�̿��� ĭ�� ���� �浹
			return 1; //���� �� �� ���� 
		else if(gameboard[x][y+1] == ' ') //�̿��� ĭ�� ��ĭ 
			return 1; //���� �� �� ���� 
		else
		{
			if(gameboard[x][y+1] == 'O') //�̿��� ĭ�� �鵹�̶��
			{
				for(i=0; i<N; i++)
				{
 					if(y+2+i >= N) //���������� �̿��� ĭ�� �𼭸���
						break; //�ݺ��� ��������
					if(gameboard[x][y+2+i] == ' ') //���������� �̿��� ĭ�� ��ĭ�̶��
						break; //�ݺ��� ��������
 					if(gameboard[x][y+2+i] == 'O') //���������� �̿��� ĭ�� �鵹�̶��
						continue; //���� �ݺ�����
 					if(gameboard[x][y+2+i] == 'X') //���������� �̿��� ĭ�� �浹�̶��
						return 0; //���� �� �� ���� 
				}
				return 1; //���� �� �� ���� 
			}	
		}
	}
}

int upright_black(int x, int y)
{
	int i;
	
	if((x-1 < 0)||(y+1 >= N))  //��ĭ ��, ��ĭ �������� �𼭸����� Ȯ��
		return 1; //���� �� �� ���� 
	else
	{
		if(gameboard[x-1][y+1] == 'X') //�̿��� ĭ�� ���� �浹
			return 1; //���� �� �� ���� 
		else if(gameboard[x-1][y+1] == ' ') //�̿��� ĭ�� ��ĭ 
			return 1; //���� �� �� ���� 
		else
		{
			if(gameboard[x-1][y+1] == 'O') //�̿��� ĭ�� �鵹�̶��
			{
				for(i=0; i<N; i++)
				{
 					if((x-2-i < 0)||(y+2+i >= N)) //������ ���� �̿��� ĭ�� �𼭸���
						break; //�ݺ��� ��������
					if(gameboard[x-2-i][y+2+i] == ' ') //������ ���� �̿��� ĭ�� ��ĭ�̶��
						break; //�ݺ��� ��������
 					if(gameboard[x-2-i][y+2+i] == 'O') //������ ���� �̿��� ĭ�� �鵹�̶��
						continue; //���� �ݺ�����
 					if(gameboard[x-2-i][y+2+i] == 'X') //������ ���� �̿��� ĭ�� �浹�̶��
						return 0; //���� �� �� ���� 
				}
				return 1; //���� �� �� ���� 
			}	
		}
	}
}

int upleft_black(int x, int y)
{
	int i;
	
	if((x-1 < 0)||(y-1 < 0))  //��ĭ ��, ��ĭ ������ �𼭸����� Ȯ��
		return 1; //���� �� �� ���� 
	else
	{
		if(gameboard[x-1][y-1] == 'X') //�̿��� ĭ�� ���� �浹
			return 1; //���� �� �� ���� 
		else if(gameboard[x-1][y-1] == ' ') //�̿��� ĭ�� ��ĭ 
			return 1; //���� �� �� ���� 
		else
		{
			if(gameboard[x-1][y-1] == 'O') //�̿��� ĭ�� �鵹�̶��
			{
				for(i=0; i<N; i++)
				{
 					if((x-2-i < 0)||(y-2-i < 0)) //���� ���� �̿��� ĭ�� �𼭸���
						break; //�ݺ��� ��������
					if(gameboard[x-2-i][y-2-i] == ' ') //���� ���� �̿��� ĭ�� ��ĭ�̶��
						break; //�ݺ��� ��������
 					if(gameboard[x-2-i][y-2-i] == 'O') //���� ���� �̿��� ĭ�� �鵹�̶��
						continue; //���� �ݺ�����
 					if(gameboard[x-2-i][y-2-i] == 'X') //���� ���� �̿��� ĭ�� �浹�̶��
						return 0; //���� �� �� ���� 
				}
				return 1; //���� �� �� ���� 
			}	
		}
	}
}

int downright_black(int x, int y)
{
	int i;
	
	if((x+1 >= N)||(y+1 >= N))  //��ĭ �Ʒ�, ��ĭ �������� �𼭸����� Ȯ��
		return 1; //���� �� �� ���� 
	else
	{
		if(gameboard[x+1][y+1] == 'X') //�̿��� ĭ�� ���� �浹
			return 1; //���� �� �� ���� 
		else if(gameboard[x+1][y+1] == ' ') //�̿��� ĭ�� ��ĭ 
			return 1; //���� �� �� ���� 
		else
		{
			if(gameboard[x+1][y+1] == 'O') //�̿��� ĭ�� �鵹�̶��
			{
				for(i=0; i<N; i++)
				{
 					if((x+2+i >= N)||(y+2+i >= N)) //������ �Ʒ��� �̿��� ĭ�� �𼭸���
						break; //�ݺ��� ��������
					if(gameboard[x+2+i][y+2+i] == ' ') //������ �Ʒ��� �̿��� ĭ�� ��ĭ�̶��
						break; //�ݺ��� ��������
 					if(gameboard[x+2+i][y+2+i] == 'O') //������ �Ʒ��� �̿��� ĭ�� �鵹�̶��
						continue; //���� �ݺ�����
 					if(gameboard[x+2+i][y+2+i] == 'X') //������ �Ʒ��� �̿��� ĭ�� �浹�̶��
						return 0; //���� �� �� ���� 
				}
				return 1; //���� �� �� ���� 
			}	
		}
	}
}

int downleft_black(int x, int y)
{
	int i;
	
	if((x+1 >= N)||(y-1 < 0))  //��ĭ �Ʒ�, ��ĭ ������ �𼭸����� Ȯ��
		return 1; //���� �� �� ���� 
	else
	{
		if(gameboard[x+1][y-1] == 'X') //�̿��� ĭ�� ���� �浹
			return 1; //���� �� �� ���� 
		else if(gameboard[x+1][y-1] == ' ') //�̿��� ĭ�� ��ĭ 
			return 1; //���� �� �� ���� 
		else
		{
			if(gameboard[x+1][y-1] == 'O') //�̿��� ĭ�� �鵹�̶��
			{
				for(i=0; i<N; i++)
				{
 					if((x+2+i >= N)||(y-1-i < 0)) //���� �Ʒ��� �̿��� ĭ�� �𼭸���
						break; //�ݺ��� ��������
					if(gameboard[x+2+i][y-1-i] == ' ') //���� �Ʒ��� �̿��� ĭ�� ��ĭ�̶��
						break; //�ݺ��� ��������
 					if(gameboard[x+2+i][y-1-i] == 'O') //���� �Ʒ��� �̿��� ĭ�� �鵹�̶��
						continue; //���� �ݺ�����
 					if(gameboard[x+2+i][y-1-i] == 'X') //���� �Ʒ��� �̿��� ĭ�� �浹�̶��
						return 0; //���� �� �� ���� 
				}
				return 1; //���� �� �� ���� 
			}	
		}
	}
}

/* up(=u), down(=d), left(=l), right(=r),
	upright(=ur), upleft(=ul), downright(=dr), downleft(=dl) 
	���� ���� �� �ִ��� ���� ���� üũ */
int check_black(int a, int b)
{
	int u, d, l, r, ur, ul, dr, dl;
	
	u = up_black(a, b);
	d = down_black(a, b);
	l = left_black(a, b);
	r = right_black(a, b);
	ur = upright_black(a, b);
	ul = upleft_black(a, b);
	dr = downright_black(a, b);
	dl = downleft_black(a, b);
	
	if(gameboard[a][b] != ' ') // ��ĭ�� �ƴϸ�
		return 1; //���� �� �� ���� 
	else
	{
		if(u == 0||d == 0||l == 0||r == 0||ur == 0||ul == 0||dr == 0||dl == 0) 
				//return�� 0�� ����(���� ���� �� ����)�� �ϳ��� �ִٸ�
			return 0; //���� 
		else
			return 1; //�н� 
	}
}

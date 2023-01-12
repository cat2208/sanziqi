#define _CRT_SECURE_NO_WARNINGS 1
#include "tou.h"



//��ʼ������
void InitializaBoard(char board[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void PrintBoard(char board[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < lin - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) 
		{
			for (int j = 0; j < lin; j++)
			{
				printf("---");
				if (j < lin - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}

}

//�����
void Player(char board[ROW][LIN], int row, int lin)
{
	printf("�����>:\n");
	int x, y;
	x = 0;
	y = 0;
	while (1)
	{
		printf("�������������>:");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= lin)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("��λ���ѱ�ռ��\n");
			}
		}
		else
		{
			printf("�������\n");
		}
	}
}

//������
void Computer(char board[ROW][LIN], int row, int lin)
{
	//����㷨 �������㷨
	printf("������>:\n");
	int x, y;
	x = 0;
	y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % lin;
		if (x > 0 && x <= row && y>0 && y <= lin)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
		}
	}
}

//�ж���Ӯ
//1.���Ӯ--*
//2.����Ӯ--#
//3.ƽ��--p
//4.����--c
char IsWin(char board[ROW][LIN], int row, int lin)
{
	//�ж���
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin-2; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
			{
				return board[i][j];
			}
		}
	}

	//�ж���
	for (int i = 0; i < row-2; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			if (board[i][j] != ' ' && board[i + 1][j] == board[i][j] && board[i + 1][j] == board[i + 2][j])
			{
				return board[i][j];
			}
		}
	}

	//�ж���Խ���
	for (int i = 0; i < row-2; i++)
	{
		for (int j = 0; j < lin-2; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2])
			{
				return board[i][j];
			}
		}
	}

	//�ж��ҶԽ���
	for (int i = 0; i < row-2; i++)
	{
		for (int j = lin-1; j > 1; j--)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2])
			{
				return board[i][j];
			}
		}
	}

	//ƽ��
	int p = Dogfall(board, row, lin);
	if (p)
	{
		return 'p';
	}
	//����
	return 'c';
}

//ƽ��--1
int Dogfall(char board[ROW][LIN], int row, int lin)
{
	int sum = 0;
	int together;
	together = (row + 1) * (lin + 1);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			if (board[i][j] != ' ')
			{
				sum++;
			}
		}
	}
	if (sum == together)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
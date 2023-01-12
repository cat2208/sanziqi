#define _CRT_SECURE_NO_WARNINGS 1
#include "tou.h"



//初始化棋盘
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

//打印棋盘
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

//玩家走
void Player(char board[ROW][LIN], int row, int lin)
{
	printf("玩家走>:\n");
	int x, y;
	x = 0;
	y = 0;
	while (1)
	{
		printf("请玩家输入坐标>:");
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
				printf("该位置已被占用\n");
			}
		}
		else
		{
			printf("输入错误\n");
		}
	}
}

//电脑走
void Computer(char board[ROW][LIN], int row, int lin)
{
	//随机算法 非智能算法
	printf("电脑走>:\n");
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

//判断输赢
//1.玩家赢--*
//2.电脑赢--#
//3.平局--p
//4.继续--c
char IsWin(char board[ROW][LIN], int row, int lin)
{
	//判断行
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

	//判断列
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

	//判断左对角线
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

	//判断右对角线
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

	//平局
	int p = Dogfall(board, row, lin);
	if (p)
	{
		return 'p';
	}
	//继续
	return 'c';
}

//平局--1
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
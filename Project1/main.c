#define _CRT_SECURE_NO_WARNINGS 1
#include "tou.h"

//打印游戏菜单
void menu()
{
	printf("***************************************\n");
	printf("*********      1.开始游戏     *********\n");
	printf("*********      0.退出游戏     *********\n");
	printf("***************************************\n");
}

void game()
{
	//定义棋盘
	char board[ROW][LIN];
	//初始化棋盘
	InitializaBoard(board, ROW, LIN);
	//打印棋盘
	PrintBoard(board,ROW,LIN);
	char ch = 0;
	while (1)
	{
		
		//玩家走
		Player(board, ROW, LIN);
		PrintBoard(board, ROW, LIN);
		ch = IsWin(board, ROW, LIN);
		
		if (ch != 'c')
		{
			break;
		}

		//电脑走
		Computer(board, ROW, LIN);
		PrintBoard(board, ROW, LIN);
		ch = IsWin(board, ROW, LIN);

		if (ch != 'c')
		{
			break;
		}

	}
	if (ch == '*')
	{
		printf("玩家赢\n");
	}
	else if (ch == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	PrintBoard(board, ROW, LIN);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "tou.h"

//��ӡ��Ϸ�˵�
void menu()
{
	printf("***************************************\n");
	printf("*********      1.��ʼ��Ϸ     *********\n");
	printf("*********      0.�˳���Ϸ     *********\n");
	printf("***************************************\n");
}

void game()
{
	//��������
	char board[ROW][LIN];
	//��ʼ������
	InitializaBoard(board, ROW, LIN);
	//��ӡ����
	PrintBoard(board,ROW,LIN);
	char ch = 0;
	while (1)
	{
		
		//�����
		Player(board, ROW, LIN);
		PrintBoard(board, ROW, LIN);
		ch = IsWin(board, ROW, LIN);
		
		if (ch != 'c')
		{
			break;
		}

		//������
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
		printf("���Ӯ\n");
	}
	else if (ch == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
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
			printf("�����������������\n");
			break;
		}
	} while (input);
	
	return 0;
}
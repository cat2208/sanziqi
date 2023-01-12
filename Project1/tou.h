#define _CRT_SECURE_NO_WARNINGS 1
//调用头文件
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定义大小
#define LIN 3
#define ROW 3

//函数声明

//打印游戏菜单
void menu();
//初始化棋盘
void InitializaBoard(char board[ROW][LIN], int row, int lin);
//打印棋盘
void PrintBoard(char board[ROW][LIN], int row, int lin);
//玩家走
void Player(char board[ROW][LIN], int row, int lin);
//电脑走
void Computer(char board[ROW][LIN], int row, int lin);
//判断输赢
char IsWin(char board[ROW][LIN], int row, int lin);
//判断平局
int Dogfall(char board[ROW][LIN],int row,int lin);
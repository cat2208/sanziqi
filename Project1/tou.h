#define _CRT_SECURE_NO_WARNINGS 1
//����ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�����С
#define LIN 3
#define ROW 3

//��������

//��ӡ��Ϸ�˵�
void menu();
//��ʼ������
void InitializaBoard(char board[ROW][LIN], int row, int lin);
//��ӡ����
void PrintBoard(char board[ROW][LIN], int row, int lin);
//�����
void Player(char board[ROW][LIN], int row, int lin);
//������
void Computer(char board[ROW][LIN], int row, int lin);
//�ж���Ӯ
char IsWin(char board[ROW][LIN], int row, int lin);
//�ж�ƽ��
int Dogfall(char board[ROW][LIN],int row,int lin);
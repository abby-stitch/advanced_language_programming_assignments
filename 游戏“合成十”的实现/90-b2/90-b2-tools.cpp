/* 1850917 ���� ��ʫ�� */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
//#include <windows.h>
//#include <cctype>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/*��һЩ�ڲ�����/ͼ�η�ʽ���õĺ��������жϽ�����*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����
  ���������const char *prompt, ������ʾ��
			const int min, �������Сֵ��ǰ�պ󿪣�
			const int max, ��������ֵ
			int& val, ������ı���
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input_int(const char* prompt, const int min, const int max, int& val)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

	int x, y;//�������
	/*����ֵ*/
	int input_val = 0;
	cout << prompt;
	cct_getxy(x, y);
	while (1)
	{
		cct_gotoxy(x + 1, y);
		cin >> input_val;;
		if (cin.good() && input_val >= min && input_val < max)
			break;
		else
		{
			cct_gotoxy(x + 1, y);
			cout << setw(50) << setfill(' ') << ' ' << endl;//�����������
			cout << "���벻�Ϸ�������������";
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	cout << setw(50) << setfill(' ') << ' ';
	cct_getxy(x, y);
	cct_gotoxy(0, y);//���ص����еĿ�ͷ

	cin.clear();
	cin.ignore(100, '\n');
	val = input_val;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������������
  ���������int row,����
			int col,����
			int& row_pos,������ 
			int& col_pos,������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input_coordinate(const int row, const int col, int& row_pos, int& col_pos, int matrix[][N])
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

	int x, y;//�������

	char coordinate[3] = { 0 };
	/*cout << "row=" << row << endl;
	cout << "col=" << col << endl;*/
	while (1)
	{
		cout << "������ĸ+������ʽ[����c2]����������꣺";
		cct_getxy(x, y);

		while (1)
		{
			cct_gotoxy(x + 1, y);
			cin.get(coordinate, 3);
			for (int i = 0; i < 2; i++)
			{
				if (coordinate[i] >= 'a' && coordinate[i] <= 'z')
				{
					coordinate[i] = coordinate[i] - 'a' + 'A';
				}
			}
			//cout << pos << endl;

			if (coordinate[0] >= 'A' && coordinate[0] < row + 'A' && coordinate[1] >= '0' && coordinate[1] < col + '0')
				break;
			else
			{
				cct_gotoxy(x + 1, y);
				cout << setw(50) << setfill(' ') << ' ' << endl; //�����������
				cout << "�����������������.";
				cin.clear();
				cin.ignore(100, '\n');
			}
		}

		row_pos = int(coordinate[0] - 'A');
		col_pos = int(coordinate[1] - '0');

		cout << setw(50) << setfill(' ') << ' ';//�������������ʾ
		cct_getxy(x, y);
		cct_gotoxy(0, y);//���ص����еĿ�ͷ

		cin.clear();
		cin.ignore(100, '\n');


		
			cout << "����Ϊ" << coordinate[0] << "��" << coordinate[1] << "��" << endl;

			if (is_adjacent_same(row, col, row_pos, col_pos, matrix))
				break;
			else
			{
				cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
			}
		
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ʾ��Ϣ�����س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
//static void to_be_continued(const char* prompt)
//{
//	cct_setcolor(); //�ָ�ȱʡ��ɫ
//
//	if (prompt)
//		cout << prompt << "�����س�������...";
//	else
//		cout << "���س�������...";
//
//	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
//	while (_getch() != '\r')
//		;
//
//	cct_cls();
//
//	return;
//}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ʾ��Ϣ������End
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input_End()
{
	cct_setcolor(); //�ָ�ȱʡ��ɫ

	cout << "��С�������������End����...";
	int x, y;//�������
	cct_getxy(x, y);
	char End[4] = { 0 };

	while (1)
	{
		cin.get(End, 4);
		for (int i = 0; i < 3; i++)
		{
			if (End[i] >= 'a' && End[i] <= 'z')
			{
				End[i] = End[i] - 'a' + 'A';
			}
		}

		/*cout << End << endl;
		cout << strcmp(End, "END") << endl;*/

		if (!strcmp(End, "END"))
			break;
		else
		{
			cout << "�����������������.";
			cct_gotoxy(x, y);
			cout << setw(50) << setfill(' ') << ' ' << endl; //�����������
			cct_gotoxy(x, y);
			cin.clear();
			cin.ignore(100, '\n');
		}

	}
	cct_cls();

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������ϲ�
  ���������const int row_pos, 
			const int col_pos,
			����Ϊ����ʾ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char input_is_merge(const int row_pos, const int col_pos)
{
	cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << char(row_pos + 'A') << char(col_pos + '0') << "��(Y/N/Q)��";
	int x, y;//�������
	cct_getxy(x, y);

	char ch;

	while (1)
	{
		ch = _getche();

		if (ch >= 'a' || ch <= 'z')//Сдת��д
			ch = ch - 'a' + 'A';

		if (ch == 'Y' || ch == 'N' || ch == 'Q')
		{
			cout << endl;
			break;
		}
		else
			cct_gotoxy(x, y);
	}

	return ch;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ʾ��Ϣ�����س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter(const char* prompt)
{
	cct_setcolor(); //�ָ�ȱʡ��ɫ

	cout << "���س���" << prompt << "...";

	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
	while (_getch() != '\r')
		;

	cout << endl;
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���������(��ά���飩
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void reset(const int row, const int col, int arr[][N])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = 0;
		}
	}
}
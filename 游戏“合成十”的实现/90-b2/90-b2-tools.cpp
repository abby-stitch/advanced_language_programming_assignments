/* 1850917 电信 梁诗瑶 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
//#include <windows.h>
//#include <cctype>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/*放一些内部数组/图形方式公用的函数，如判断结束等*/

/***************************************************************************
  函数名称：
  功    能：输入
  输入参数：const char *prompt, 输入提示语
			const int min, 输入的最小值（前闭后开）
			const int max, 输入的最大值
			int& val, 被输入的变量
  返 回 值：
  说    明：
***************************************************************************/
void input_int(const char* prompt, const int min, const int max, int& val)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

	int x, y;//光标坐标
	/*输入值*/
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
			cout << setw(50) << setfill(' ') << ' ' << endl;//清除错误输入
			cout << "输入不合法，请重新输入";
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	cout << setw(50) << setfill(' ') << ' ';
	cct_getxy(x, y);
	cct_gotoxy(0, y);//光标回到该行的开头

	cin.clear();
	cin.ignore(100, '\n');
	val = input_val;
}

/***************************************************************************
  函数名称：
  功    能：输入矩阵坐标
  输入参数：int row,行数
			int col,列数
			int& row_pos,行坐标 
			int& col_pos,列坐标
  返 回 值：
  说    明：
***************************************************************************/
void input_coordinate(const int row, const int col, int& row_pos, int& col_pos, int matrix[][N])
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

	int x, y;//光标坐标

	char coordinate[3] = { 0 };
	/*cout << "row=" << row << endl;
	cout << "col=" << col << endl;*/
	while (1)
	{
		cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
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
				cout << setw(50) << setfill(' ') << ' ' << endl; //清除错误输入
				cout << "输入错误，请重新输入.";
				cin.clear();
				cin.ignore(100, '\n');
			}
		}

		row_pos = int(coordinate[0] - 'A');
		col_pos = int(coordinate[1] - '0');

		cout << setw(50) << setfill(' ') << ' ';//清除错误输入提示
		cct_getxy(x, y);
		cct_gotoxy(0, y);//光标回到该行的开头

		cin.clear();
		cin.ignore(100, '\n');


		
			cout << "输入为" << coordinate[0] << "行" << coordinate[1] << "列" << endl;

			if (is_adjacent_same(row, col, row_pos, col_pos, matrix))
				break;
			else
			{
				cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
			}
		
	}
}

/***************************************************************************
  函数名称：
  功    能：显示提示信息，按回车键
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
//static void to_be_continued(const char* prompt)
//{
//	cct_setcolor(); //恢复缺省颜色
//
//	if (prompt)
//		cout << prompt << "，按回车键继续...";
//	else
//		cout << "按回车键继续...";
//
//	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
//	while (_getch() != '\r')
//		;
//
//	cct_cls();
//
//	return;
//}

/***************************************************************************
  函数名称：
  功    能：显示提示信息，输入End
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input_End()
{
	cct_setcolor(); //恢复缺省颜色

	cout << "本小题结束，请输入End继续...";
	int x, y;//光标坐标
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
			cout << "输入错误，请重新输入.";
			cct_gotoxy(x, y);
			cout << setw(50) << setfill(' ') << ' ' << endl; //清除错误输入
			cct_gotoxy(x, y);
			cin.clear();
			cin.ignore(100, '\n');
		}

	}
	cct_cls();

	return;
}

/***************************************************************************
  函数名称：
  功    能：输入否合并
  输入参数：const int row_pos, 
			const int col_pos,
			（仅为了显示）
  返 回 值：
  说    明：
***************************************************************************/
char input_is_merge(const int row_pos, const int col_pos)
{
	cout << "请确认是否把相邻的相同值合并到" << char(row_pos + 'A') << char(col_pos + '0') << "中(Y/N/Q)：";
	int x, y;//光标坐标
	cct_getxy(x, y);

	char ch;

	while (1)
	{
		ch = _getche();

		if (ch >= 'a' || ch <= 'z')//小写转大写
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
  函数名称：
  功    能：显示提示信息，按回车键
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter(const char* prompt)
{
	cct_setcolor(); //恢复缺省颜色

	cout << "按回车键" << prompt << "...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	cout << endl;
	return;
}

/***************************************************************************
  函数名称：
  功    能：重置数组(二维数组）
  输入参数：
  返 回 值：
  说    明：
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
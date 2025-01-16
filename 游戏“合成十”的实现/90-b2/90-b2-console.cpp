/* 1850917 电信 梁诗瑶 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;
/*放cmd伪图形界面方式实现的各函数*/

/***************************************************************************
  函数名称：
  功    能：显示当前数组外框
  输入参数：int x_pos, 数组方框左上角x坐标
			int y_pos, 数组方框左上角y坐标
			const int row, 数组行数
			const int col, 数组列数
			int mode, 模式
					1：数字色块间无分隔线
					2：数字色块间有分隔线
					3：数字色块间有分隔线(无时间间隔）
  返 回 值：
  说    明：
***************************************************************************/
void show_outer_frame(int x_pos, int y_pos,const int row, const int col,int mode)
{
	int line =0;//窗口行
	int column = 0;//窗口列

	int x = 0, y = 0;//光标坐标

	switch (mode)
	{
		case 1://数字色块间无分隔线
		{
			line = row * 3 + 7;//窗口行
			column = col * 6 + 5;//窗口列

			/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
			cct_setconsoleborder(column, line, column, 9000);

			cct_setcolor(COLOR_WHITE, COLOR_BLACK);

			/*上横线*/
			cct_gotoxy(x_pos, y_pos);

			cout << "╔";

			Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "═══";

				Sleep(TIME);
			}

			cout << "╗";

			Sleep(TIME);

			cct_getxy(x, y);
			/*cout << "x=" << x << endl;
			cout << "y=" << y << endl;*/

			/*打印两边竖线*/
			for (int i = 0; i < 3 * row; i++)
			{
				y++;
				for (int j = 0; j < col; j++)
				{

					if (j == 0)
					{
						cct_gotoxy(0, y);

						cout << "║";

						Sleep(TIME);
					}
					else if (j = col - 1)
					{
						cct_gotoxy(x - 2, y);

						cout << "║";

						Sleep(TIME);
					}
				}
			}

			cct_getxy(x, y);

			/*下横线*/
			cct_gotoxy(0, y + 1);

			cout << "╚";

			Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "═══";

				Sleep(TIME);
			}

			cout << "╝";

			Sleep(TIME);

			cct_setcolor();
			break;
		}
		case 2://数字色块间有分隔线
		{
			line = row * 3 + row - 1 + 7;//窗口行
			column = col * 6 + (col - 1) * 2 + 5;//窗口列

			/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
			cct_setconsoleborder(column, line, column, 9000);

			cct_setcolor(COLOR_WHITE, COLOR_BLACK);

			/*上横线*/
			cct_gotoxy(x_pos, y_pos);
			cout << "╔";
			Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "═══";
				if (i != col - 1)
					cout << "╤";

				Sleep(TIME);
			}

			cout << "╗";

			Sleep(TIME);

			cct_getxy(x, y);

			/*cout << "x=" << x << endl;
			cout << "y=" << y << endl;*/

			/*打印两边竖线*/
			for (int i = 0; i < 3 * row; i++)
			{
				y++;//下移一行

				for (int j = 0; j < col; j++)
				{

					if (j == 0)
					{

						if (i % 3 == 0 && i != 0)
						{
							cct_gotoxy(0, y);

							cout << "╟";

							/*打印中间分隔横线*/
							for (int k = 0; k < col; k++)
							{
								cout << "───";
								if (k != col - 1)
									cout << "┼";

								Sleep(TIME);
							}
							cout << "╢";

							y++;//下移一行
						}

						cct_gotoxy(0, y);

						cout << "║";

						/*打印中间分隔竖线*/
						for (int k = 0; k < col; k++)
						{
							cout << setw(6) << ' ';
							if (k == col - 1)
								cout << "║";
							else
								cout << "│";

							Sleep(TIME);
						}
					}
				}
			}

			cct_getxy(x, y);

			/*下横线*/
			cct_gotoxy(0, y + 1);

			cout << "╚";

			Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "═══";
				if (i != col - 1)
					cout << "╧";
				Sleep(TIME);
			}

			cout << "╝";

			Sleep(TIME);

			cct_setcolor();

			break;
		}
		case 3://数字色块间有分隔线(无时间间隔）
		{
			line = row * 3 + row - 1 + 7;//窗口行
			column = col * 6 + (col - 1) * 2 + 5;//窗口列

			/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
			cct_setconsoleborder(column, line, column, 9000);

			cct_setcolor(COLOR_WHITE, COLOR_BLACK);

			/*上横线*/
			cct_gotoxy(x_pos, y_pos);
			cout << "╔";
			//Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "═══";
				if (i != col - 1)
					cout << "╤";

				//Sleep(TIME);
			}

			cout << "╗";

			//Sleep(TIME);

			cct_getxy(x, y);

			/*cout << "x=" << x << endl;
			cout << "y=" << y << endl;*/

			/*打印两边竖线*/
			for (int i = 0; i < 3 * row; i++)
			{
				y++;//下移一行

				for (int j = 0; j < col; j++)
				{

					if (j == 0)
					{

						if (i % 3 == 0 && i != 0)
						{
							cct_gotoxy(0, y);

							cout << "╟";

							/*打印中间分隔横线*/
							for (int k = 0; k < col; k++)
							{
								cout << "───";
								if (k != col - 1)
									cout << "┼";

								//Sleep(TIME);
							}
							cout << "╢";

							y++;//下移一行
						}

						cct_gotoxy(0, y);

						cout << "║";

						/*打印中间分隔竖线*/
						for (int k = 0; k < col; k++)
						{
							cout << setw(6) << ' ';
							if (k == col - 1)
								cout << "║";
							else
								cout << "│";

							//Sleep(TIME);
						}
					}
				}
			}

			cct_getxy(x, y);

			/*下横线*/
			cct_gotoxy(0, y + 1);

			cout << "╚";

			//Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "═══";
				if (i != col - 1)
					cout << "╧";
				//Sleep(TIME);
			}

			cout << "╝";

			//Sleep(TIME);

			cct_setcolor();

			break;
		}
	}
	

	cct_setcolor();
}
/***************************************************************************
  函数名称：
  功    能：显示每个小格
  输入参数：const int x, 每小格左上角的x坐标
			const int y, 每小格左上角的y坐标
			int val, 小格中显示的值
			int mode,
				0：颜色与值有关
				1：置空为背景色
  返 回 值：
  说    明：
***************************************************************************/
void show_cube(const int x, const int y, int val,int mode)
{
	if (mode == 0)
	{
		cct_setcolor(val, COLOR_BLACK);
	}
	else if (mode == 1)
	{
		cct_setcolor(COLOR_WHITE, COLOR_WHITE);
	}
	cct_gotoxy(x, y);
	cout << "╔";
	cout << "═";
	cout << "╗";

	cct_gotoxy(x, y + 1);
	cout << "║";
	cout << setw(2) << val;
	cout << "║";

	cct_gotoxy(x, y + 2);
	cout << "╚";
	cout << "═";
	cout << "╝";

	cct_setcolor();

}

/***************************************************************************
  函数名称：
  功    能：显示数组里的所有小格
  输入参数：int x_pos, 数组方框左上角x坐标
			int y_pos, 数组方框左上角y坐标 
			const int row, 数组行数
			const int col, 数组列数
			int matrix[][N],
			int mode, 模式
					1：数字色块间无分隔线
					2：数字色块间有分隔线
					3：数字色块间有分隔线(无时间间隔）+用箭头键移动，回车键选择
  返 回 值：
  说    明：
***************************************************************************/
void show_arr_cube(int x_pos, int y_pos, const int row, const int col, int matrix[][N],int mode)
{
	int line = 0;//窗口行
	int column = 0;//窗口列

	int x = x_pos + 2;
	int y = y_pos + 1;

	switch (mode)
	{
		case 1://数字色块间无分隔线
		{
			line = row * 3 + 7;//窗口行
			column = col * 6 + 5;//窗口列

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					show_cube(x, y, matrix[i][j]);
					Sleep(TIME);
					x += 6;
				}
				y += 3;
				x = x_pos + 2;
			}

			cct_gotoxy(x_pos, y_pos - 1);
			cct_setcolor();
			cout << "屏幕当前设置为：" << line << "行" << column << "列";
			cct_gotoxy(x_pos, y_pos + row * 3 + 2);

			break;
		}
		case 2://数字色块间有分隔线
		{
			line = row * 3 + row - 1 + 7;//窗口行
			column = col * 6 + (col - 1) * 2 + 5;//窗口列

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					show_cube(x, y, matrix[i][j]);
					Sleep(TIME);
					x += 8;
				}
				y += 4;
				x = x_pos + 2;
			}

			cct_gotoxy(x_pos, y_pos - 1);
			cct_setcolor();
			cout << "屏幕当前设置为：" << line << "行" << column << "列";
			cct_gotoxy(x_pos, y_pos + row * 4 + 1);

			break;
		}
		case 3://数字色块间有分隔线(无时间间隔）
		{
			line = row * 3 + row - 1 + 7;//窗口行
			column = col * 6 + (col - 1) * 2 + 5;//窗口列

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					show_cube(x, y, matrix[i][j]);
					//Sleep(TIME);
					x += 8;
				}
				y += 4;
				x = x_pos + 2;
			}

			cct_gotoxy(x_pos, y_pos - 1);
			cct_setcolor();
			cout << "屏幕当前设置为：" << line << "行" << column << "列";

			break;
		}
	}	
}

/***************************************************************************
  函数名称：
  功    能：伪图形界面下显示当前所选色块
  输入参数：const int x, 每小格左上角的x坐标
			const int y, 每小格左上角的y坐标
			int val, 小格中显示的值
  返 回 值：
  说    明：
***************************************************************************/
void show_sel_cube(const int x, const int y, int val, int mode)
{
	if (mode == 0)
	{
		cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
	}
	else if (mode == 1)
	{
		cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
	}

	cct_gotoxy(x, y);
	cout << "╔";
	cout << "═";
	cout << "╗";

	cct_gotoxy(x, y + 1);
	cout << "║";
	cout << setw(2) << val;
	cout << "║";

	cct_gotoxy(x, y + 2);
	cout << "╚";
	cout << "═";
	cout << "╝";

	cct_setcolor();
}

/***************************************************************************
  函数名称：
  功    能：伪图形界面下用箭头选择当前色块
  输入参数：int x_pos, 数组方框左上角x坐标
			int y_pos, 数组方框左上角y坐标
			int& row_pos, 
			int& col_pos, 开始移动的初始坐标，以及变化后的坐标
			const int row, 数组行数
			const int col, 数组列数
			int matrix[][N],
  返 回 值：
  说    明：
***************************************************************************/
void move_by_arrow(const int x_pos, const int y_pos, int& row_pos, int& col_pos, const int row, const int col, int matrix[][N],int pos[][N],int mode)
{
	cct_setcursor(CURSOR_INVISIBLE);//设置光标不显示

	cct_gotoxy(x_pos, y_pos + row * 4 + 1);
	cout << "箭头键移动，回车键选择";
	
	int x = x_pos + 2;//光标x坐标
	int y = y_pos + 1;//光标y坐标

	/*row_pos = 0;
	col_pos = 0;*/

	show_sel_cube(x, y, matrix[row_pos][col_pos]);

	char chInput = 0;

	while (1)
	{
		chInput = _getch();

		if (mode == 0)
		{
			if (chInput == '\r')
			{
				//进行选择
				cct_gotoxy(x_pos, y_pos + row * 4 + 1);
				cout << setw(50) << ' ';
				cct_gotoxy(x_pos, y_pos + row * 4 + 1);

				break;
			}
		}
		else if (mode == 1)
		{
			if (chInput == '\r')
			{
				//进行选择
				if (is_adjacent_same(row, col, row_pos, col_pos, matrix))
				{
					cct_gotoxy(x_pos, y_pos + row * 4 + 1);
					cout << setw(50) << ' ';

					cct_gotoxy(x_pos, y_pos + row * 4 + 1);
					cout << "箭头键移动并取消当前选择，回车键合成";
					mode = 0;

					/*找相邻相同值（递归方式）*/
					seek_same_val_recursive(row, col, row_pos, col_pos, matrix, pos);

					/*显示相邻相同值*/
					show_arr(x_pos, y_pos, row, col, matrix, pos);
					
					/*所选位置的前景色变为红色*/
					show_sel_cube(x, y, matrix[row_pos][col_pos], 1);

					continue;
				}
				else
				{
					cct_gotoxy(x_pos, y_pos + row * 4 + 1);
					cout << setw(50) << ' ';

					cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cct_gotoxy(x_pos, y_pos + row * 4 + 1);
					cout << "周围无相同值，";
					cct_setcolor();

					cout << "箭头键移动，回车键选择";
					continue;
				}
			}
		}

		mode = 1;
		show_cube(x, y, matrix[row_pos][col_pos]);//恢复未选中时颜色
		show_arr(x_pos, y_pos, row, col, matrix, pos, 1);//恢复未选中时颜色

		/*重置记录位置数组*/
		reset(row, col, pos);

		if (mode == 1)
		{
			cct_gotoxy(x_pos, y_pos + row * 4 + 1);
			cout << setw(50) << ' ';
			cct_gotoxy(x_pos, y_pos + row * 4 + 1);
			cout << "箭头键移动，回车键选择";
		}

		/*用箭头进行光标移动*/
		if (int(chInput) == -32)
		{
			chInput = _getch();
			if (int(chInput) == 72)//上
			{
				row_pos--;

				if (row_pos >= 0 && row_pos < row)
				{
					y = y_pos + 1 + row_pos * 4;
				}
				else
				{
					row_pos = row - 1;
					y = y_pos + 1 + row_pos * 4;
				}
			}
			else if (int(chInput) == 80)//下
			{
				row_pos++;

				if (row_pos >= 0 && row_pos < row)
				{
					y = y_pos + 1 + row_pos * 4;
				}
				else
				{
					row_pos = 0;
					y = y_pos + 1 + row_pos * 4;
				}
			}
			else if (int(chInput) == 75)//左
			{
				col_pos--;

				if (col_pos >= 0 && col_pos < col)
				{
					x = x_pos + 2 + col_pos * 8;
				}
				else
				{
					col_pos = col - 1;
					x = x_pos + 2 + col_pos * 8;
				}
			}
			else if (int(chInput) == 77)//右
			{
				col_pos++;

				if (col_pos >= 0 && col_pos < col)
				{
					x = x_pos + 2 + col_pos * 8;
				}
				else
				{
					col_pos = 0;
					x = x_pos + 2 + col_pos * 8;
				}
			}
			else
			{
				continue;
			}
		}

		show_sel_cube(x, y, matrix[row_pos][col_pos]);
	}
}

/***************************************************************************
  函数名称：
  功    能：伪图形界面下显示当前数组相邻相同值色块的不同操作
  输入参数：const int row, 行数
			const int col, 列数
			int matrix[][N], 存放随机数的矩阵
			int pos[][N], 存放位置信息的矩阵
			int mode, 
			0：显示数组中选中位置相邻相同值色块
			1：恢复数组中相邻相同值色块
			2：置零后清空
			3：显示新值

  返 回 值：
  说    明：
***************************************************************************/
void show_arr(int x_pos, int y_pos, const int row, const int col, int matrix[][N], int pos[][N],int mode)
{
	int x_start, y_start;
	cct_getxy(x_start, y_start);

	int x = 0;//光标x坐标
	int y = 0;//光标y坐标
	if (mode == 0)
	{
		for (int row_pos = 0; row_pos < row; row_pos++)
		{
			for (int col_pos = 0; col_pos < col; col_pos++)
			{
				if (pos[row_pos][col_pos])
				{
					x = x_pos + 2 + col_pos * 8;
					y = y_pos + 1 + row_pos * 4;
					show_sel_cube(x, y, matrix[row_pos][col_pos]);
				}
			}
		}
	}
	else if (mode == 1)
	{
		for (int row_pos = 0; row_pos < row; row_pos++)
		{
			for (int col_pos = 0; col_pos < col; col_pos++)
			{
				if (pos[row_pos][col_pos])
				{
					x = x_pos + 2 + col_pos * 8;
					y = y_pos + 1 + row_pos * 4;
					show_cube(x, y, matrix[row_pos][col_pos]);
				}
			}
		}
	}
	else if (mode == 2)
	{
		for (int row_pos = 0; row_pos < row; row_pos++)
		{
			for (int col_pos = 0; col_pos < col; col_pos++)
			{
				if (pos[row_pos][col_pos])
				{
					x = x_pos + 2 + col_pos * 8;
					y = y_pos + 1 + row_pos * 4;
					show_cube(x, y, matrix[row_pos][col_pos],1);
				}
			}
		}
	}
	else if (mode == 3)
	{
		for (int row_pos = 0; row_pos < row; row_pos++)
		{
			for (int col_pos = 0; col_pos < col; col_pos++)
			{
				if (pos[row_pos][col_pos] > 0)
				{
					x = x_pos + 2 + col_pos * 8;
					y = y_pos + 1 + row_pos * 4;
					show_cube(x, y, matrix[row_pos][col_pos], 0);
					Sleep(TIME);
				}
			}
		}
	}

	cct_gotoxy(x_start, y_start);
}

/***************************************************************************
  函数名称：
  功    能：伪图形界面下显示数组下落除0
  输入参数：int x_pos, 数组方框左上角x坐标
			int y_pos, 数组方框左上角y坐标
			const int row, 行数
			const int col, 列数
			int matrix[][N]， 存放数值的数组
			int pos[][N], 存放位置信息的数组
  返 回 值：
  说    明：
***************************************************************************/
void fall_down(const int x_pos, const int y_pos, const int row, const int col, const int row_pos, const int col_pos, int matrix[][N], int pos[][N])
{
	/*int row_pos = 0;
	int col_pos = 0;*/

	int x = 0;
	int y = 0;


	for (int i = 0; i < col; i++)//列
	{
		for (int j = row - 1; j > 0; j--)//行
		{
			if (pos[j][i])//0的位置
			{
				for (int top = j; top >=0; top--)//向上找不为零的位置
				{
					if (pos[top][i]==0)//不为零的位置
					{
						pos[top][i] = -1;
						int move_top = top;

						x = x_pos + 2 + i * 8;
						y = y_pos + 1 + top * 4;
						int val = matrix[top][i];

						while (move_top <j)//向下移动
						{
							for (int p = 0; p < 4; p++)
							{
								show_cube(x, y, val, 1);
								Sleep(TIME);
								y++;
								show_cube(x, y, val);
								Sleep(TIME);
							}
							/*补框线*/
							cct_gotoxy(x, y - 1);
							cct_setcolor(COLOR_WHITE, COLOR_BLACK);
							cout << "───";
							cct_setcolor();
							//show_outer_frame(0, 1, row, col, 3);
							move_top++;
						}
						j--;
					}
				}
			}
		}
	}
}


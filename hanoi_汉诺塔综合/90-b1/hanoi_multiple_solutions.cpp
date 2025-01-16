/* 电信 1850917 梁诗瑶 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/*用三个全局简单变量表示三个栈的栈项指针
   三个全局一维数组来记录三根圆柱中的圆盘数及编号
   一个计数用的全局变量*/
const int MAX_LENGTH = 10;
int Top_A = 0, Top_B = 0, Top_C = 0;
int Column_A[MAX_LENGTH] = { 0 }, Column_B[MAX_LENGTH] = { 0 }, Column_C[MAX_LENGTH] = { 0 };
int STEP = 1;
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
  
/*功能函数*/

/***************************************************************************
  函数名称：
  功    能：进栈
  输入参数：char col:进栈柱符号
			int n:进栈数据
			int length:数组长度
  返 回 值：
  说    明：
***************************************************************************/
void push(char col, int n, int length)
{
	/*确定进栈柱*/
	switch (col)
	{
		case 'A':
			if (Top_A < length)
				Column_A[Top_A++] = n;
			break;
		case 'B':
			if (Top_B < length)
				Column_B[Top_B++] = n;
			break;
		case 'C':
			if (Top_C < length)
				Column_C[Top_C++] = n;
			break;
	}

}

/***************************************************************************
  函数名称：
  功    能：出栈
  输入参数：char col:出栈柱符号
			int arr[]:作为栈的数组
			int length:数组长度
  返 回 值：
  说    明：
***************************************************************************/
int pop(char col, int length)
{
	/*确定出栈柱*/
	switch (col)
	{
		case'A':
			if (Top_A > 0)
			{
				int tmp;
				tmp = Column_A[--Top_A];
				Column_A[Top_A] = 0;
				return tmp;
			}
			break;
		case'B':
			if (Top_B > 0)
			{
				int tmp;
				tmp = Column_B[--Top_B];
				Column_B[Top_B] = 0;
				return tmp;
			}
			break;
		case'C':
			if (Top_C > 0)
			{
				int tmp;
				tmp = Column_C[--Top_C];
				Column_C[Top_C] = 0;
				return tmp;
			}
			break;
	}
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：初始化起始柱
  输入参数：char starColumn:起始柱符号
			int n:圆盘层数
  返 回 值：
  说    明：
***************************************************************************/
void initStartColumn(char startColumn, int n)
{
	for (int i = n; i > 0; i--)
	{
		push(startColumn, i, n);
	}
}

/***************************************************************************
  函数名称：
  功    能：横向显示
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void showColumn_horizontal()
{
	cout << " A:";
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (Column_A[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_A[i];
	}

	cout << " B:";
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (Column_B[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_B[i];
	}

	cout << " C:";
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (Column_C[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_C[i];
	}
	cout << endl;
}

/***************************************************************************
  函数名称：
  功    能：纵向显示初始状态
  输入参数：int const X  :最小横坐标（缺省为9）
			int const Y  :最大纵坐标（缺省为12）
  返 回 值：
  说    明：
***************************************************************************/
void showColumn_vertical(int const X, int const Y )
{
	int x = X;
	int y = Y;

	cct_setcolor(); //恢复缺省颜色
	/*光标不显示*/
	cct_setcursor(CURSOR_INVISIBLE);

	/*显示========*/
	cct_gotoxy(x, y);
	cout << "=========================";

	/*显示A，B，C*/
	x += 2;
	y += 1;
	cct_gotoxy(x, y);
	cout << 'A';

	x += 10;
	cct_gotoxy(x, y);
	cout << 'B';

	x += 10;
	cct_gotoxy(x, y);
	cout << 'C';

	/*纵向打印ABC数组中的元素*/
	//打印A数组
	x = X + 1;
	y = Y - 1;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		cct_gotoxy(x, y);
		if (Column_A[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_A[i];
		y--;
	}

	//打印B数组
	x += 10;
	y = Y - 1;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		cct_gotoxy(x, y);
		if (Column_B[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_B[i];
		y--;
	}

	//打印C数组
	x += 10;
	y = Y - 1;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		cct_gotoxy(x, y);
		if (Column_C[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_C[i];
		y--;
	}
}

/***************************************************************************
  函数名称：
  功    能：纵向显示变化
  输入参数：char src       :起始柱
			char dst	   :目标柱
			int const X    :=====最左横坐标
			int const Y    :====坐标
  返 回 值：
  说    明：
***************************************************************************/
void showVerticalChange(char src, char dst, int const X , int const Y )
{
	/*光标不显示*/
	cct_setcursor(CURSOR_INVISIBLE);

	int x = X + 1;
	int y = Y - 1;

	switch (src)
	{
		case'A':
		{
			y -= Top_A;
			cct_gotoxy(x, y);
			cout << setw(2) << ' ';
			break;
		}
		case'B':
		{
			x += 10;
			y = y - Top_B;
			cct_gotoxy(x, y);
			cout << setw(2) << ' ';
			break;
		}
		case'C':
		{
			x += 20;
			y = y - Top_C;
			cct_gotoxy(x, y);
			cout << setw(2) << ' ';
			break;
		}
	}

	x = X + 1;
	y = Y - 1;

	switch (dst)
	{
		case'A':
		{
			y = y - Top_A + 1;
			cct_gotoxy(x, y);
			cout << setw(2) << Column_A[Top_A - 1];
			break;
		}
		case'B':
		{
			x += 10;
			y = y - Top_B + 1;
			cct_gotoxy(x, y);
			cout << setw(2) << Column_B[Top_B - 1];
			break;
		}
		case'C':
		{
			x += 20;
			y = y - Top_C + 1;
			cct_gotoxy(x, y);
			cout << setw(2) << Column_C[Top_C - 1];
			break;
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：画三个圆柱
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void drawColumn()
{
	int x = 0;
	int y = 0;

	/*设置圆柱颜色*/
	cct_setcolor(COLOR_HYELLOW, COLOR_HYELLOW);


	/*开始打印圆柱，从左到右，从上到下*/
	//三个圆盘底部
	x = BOTTOM_X;
	for (int i = 0; i < 3; i++)
	{
		/*设置光标状态为全高*/
		cct_setcursor(CURSOR_VISIBLE_FULL);
		/*打印*/
		cct_showch(x, BOTTOM_Y, 'x', COLOR_HYELLOW, COLOR_HYELLOW, BOTTOM_LENGTH);
		/*光标不显示*/
		cct_setcursor(CURSOR_INVISIBLE);
		x += (BOTTOM_GAP + BOTTOM_LENGTH);
	}
	//三个柱子
	for (y = BOTTOM_Y - 1; y >= COLUMN_TOP_Y; y--)
	{
		x = COLUMN_X;
		for (int i = 0; i < 3; i++)
		{
			/*设置光标状态为全高*/
			cct_setcursor(CURSOR_VISIBLE_FULL);
			/*打印*/
			cct_showch(x, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
			/*光标不显示*/
			cct_setcursor(CURSOR_INVISIBLE);

			Sleep(50);
			x += COLUMN_GAP;
		}
	}

	cct_setcolor(); //恢复缺省颜色
}


/***************************************************************************
  函数名称：
  功    能：在起始柱上画n个盘子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void drawPlate()
{
	int x = 0;
	int y = 0;
	int i = 0;

	/*打印A柱*/
	for (y = BOTTOM_Y - 1, i = 0; Column_A[i] > 0; i++)
	{
		x = COLUMN_X - Column_A[i];

		/*设置光标状态为全高*/
		cct_setcursor(CURSOR_VISIBLE_FULL);
		/*打印*/
		cct_showch(x, y, 'x', Column_A[i], Column_A[i], 2 * Column_A[i] + 1);
		/*光标不显示*/
		cct_setcursor(CURSOR_INVISIBLE);
		y--;

		Sleep(50);
	}

	/*打印B柱*/
	for (y = BOTTOM_Y - 1, i = 0; Column_B[i] > 0; i++)
	{
		x = COLUMN_X + COLUMN_GAP - Column_B[i];

		/*设置光标状态为全高*/
		cct_setcursor(CURSOR_VISIBLE_FULL);
		/*打印*/
		cct_showch(x, y, 'x', Column_B[i], Column_B[i], 2 * Column_B[i] + 1);
		/*光标不显示*/
		cct_setcursor(CURSOR_INVISIBLE);
		y--;

		Sleep(50);
	}

	/*打印C柱*/
	for (y = BOTTOM_Y - 1, i = 0; Column_C[i] > 0; i++)
	{
		x = COLUMN_X + 2 * COLUMN_GAP - Column_C[i];

		/*设置光标状态为全高*/
		cct_setcursor(CURSOR_VISIBLE_FULL);
		/*打印*/
		cct_showch(x, y, 'x', Column_C[i], Column_C[i], 2 * Column_C[i] + 1);
		/*光标不显示*/
		cct_setcursor(CURSOR_INVISIBLE);
		y--;

		Sleep(50);
	}

	cct_setcolor(); //恢复缺省颜色
}


/***************************************************************************
  函数名称：
  功    能：盘移动
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void move(char src, char dst)
{
	int x = 0;
	int y = 0;
	int column_x_start = 0;
	int column_x_target = 0;

	int* startColumn;
	startColumn = Column_A;

	int* targetColumn;
	targetColumn = Column_A;

	int* top_start;
	top_start = &Top_A;

	int* top_target;
	top_target = &Top_A;

	int distance = (int(dst) - int(src)) * COLUMN_GAP;//水平移动的距离


	/*确定起始柱*/
	switch (src)
	{
		case'A':
			startColumn = Column_A;
			top_start = &Top_A;
			column_x_start = COLUMN_X;//确定上移的横坐标
			break;
		case'B':
			startColumn = Column_B;
			top_start = &Top_B;
			column_x_start = COLUMN_X + COLUMN_GAP;//确定上移的横坐标
			break;
		case'C':
			startColumn = Column_C;
			top_start = &Top_C;
			column_x_start = COLUMN_X + 2 * COLUMN_GAP;//确定上移的横坐标
			break;
	}
	y = BOTTOM_Y - 1 - *top_start;//确定上移的起始纵坐标


	/*确定目标柱*/
	switch (dst)
	{
		case'A':
			targetColumn = Column_A;
			top_target = &Top_A;
			column_x_target = COLUMN_X;//确定下移的横坐标
			break;
		case'B':
			targetColumn = Column_B;
			top_target = &Top_B;
			column_x_target = COLUMN_X + COLUMN_GAP;//确定下移的横坐标
			break;
		case'C':
			targetColumn = Column_C;
			top_target = &Top_C;
			column_x_target = COLUMN_X + 2 * COLUMN_GAP;//确定下移的横坐标
			break;
	}

	//打印宽度为目标柱顶部盘宽度，即为目标柱栈顶数值:targetColumn[*Top_target-1]
	//x -= targetColumn[*top_target - 1];//开始覆盖的横坐标

	/*向上移动*/
	for (; y > MOVE_TOP; y--)
	{
		/*设置光标状态为全高*/
		cct_setcursor(CURSOR_VISIBLE_FULL);
		if (y < COLUMN_TOP_Y)
		{
			/*高于柱子，全覆盖*/
			cct_showch(column_x_start- targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK, 2 * targetColumn[*top_target - 1] + 1);
		}
		else
		{
			/*覆盖左边*/
			cct_showch(column_x_start - targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
			/*不覆盖柱子*/
			cct_showch(column_x_start, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
			/*覆盖右边*/
			cct_showch(column_x_start + 1, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
		}
		/*光标不显示*/
		cct_setcursor(CURSOR_INVISIBLE);

		/*设置光标状态为全高*/
		cct_setcursor(CURSOR_VISIBLE_FULL);
		/*打印新的盘*/
		cct_showch(column_x_start - targetColumn[*top_target - 1], y - 1, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
		/*光标不显示*/
		cct_setcursor(CURSOR_INVISIBLE);

		Sleep(TIME);
	}

	x = column_x_start;//确定上移的起始中间横坐标

	/*水平移动*/
	if (distance > 0)
	{
		for (int i = 0; i < distance; i++)
		{
			/*设置光标状态为全高*/
			cct_setcursor(CURSOR_VISIBLE_FULL);

			/*覆盖最左边*/
			cct_showch(x - targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK);

			/*打印新的盘*/
			cct_showch(x - targetColumn[*top_target - 1] + 1, y, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
			
			/*光标不显示*/
			cct_setcursor(CURSOR_INVISIBLE);

			x++;//右移
			Sleep(TIME);
		}
	}
	else
	{
		for (int i = 0; i < (-1 * distance); i++)
		{
			/*设置光标状态为全高*/
			cct_setcursor(CURSOR_VISIBLE_FULL);

			/*覆盖最右边*/
			cct_showch(x + targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK);

			/*打印新的盘*/
			cct_showch(x - targetColumn[*top_target - 1]-1, y, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
			

			/*光标不显示*/
			cct_setcursor(CURSOR_INVISIBLE);

			x--;//左移
			Sleep(TIME);
		}
	}

	/*向下移动*/
	for (; y < BOTTOM_Y - *top_target; y++)
	{
		/*设置光标状态为全高*/
		cct_setcursor(CURSOR_VISIBLE_FULL);

		if (y < COLUMN_TOP_Y)
		{
			/*覆盖*/
			cct_showch(column_x_target - targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK, 2 * targetColumn[*top_target - 1] + 1);
		}
		else
		{
			/*覆盖左边*/
			cct_showch(column_x_target - targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
			/*不覆盖柱子*/
			cct_showch(column_x_target, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
			/*覆盖右边*/
			cct_showch(column_x_target + 1, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
		}
		/*光标不显示*/
		cct_setcursor(CURSOR_INVISIBLE);

		/*设置光标状态为全高*/
		cct_setcursor(CURSOR_VISIBLE_FULL);
		/*打印新的盘*/
		cct_showch(column_x_target - targetColumn[*top_target - 1], y + 1, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
		/*光标不显示*/
		cct_setcursor(CURSOR_INVISIBLE);

		Sleep(TIME);
	}

	cct_setcolor(); //恢复缺省颜色
}

/***************************************************************************
  函数名称：
  功    能：重置step;
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void resetSTEP()
{
	STEP = 1;
}


/***************************************************************************
  函数名称：
  功    能：重置数组
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void resetColumn()
{
	/*重置指针*/
	Top_A = 0;
	Top_B = 0;
	Top_C = 0;

	/*重置A柱*/
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		Column_A[i] = 0;
	}

	/*重置B柱*/
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		Column_B[i] = 0;
	}

	/*重置C柱*/
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		Column_C[i] = 0;
	}
}






/* ==================================================================================
		基本信息输入
====================================================================================== */
int inputBaseInfo(char mode, int* n, char* src, char* tmp, char* dst)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

	/*输入层数*/
	int layer = 0;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> layer;
		if (cin.good() && layer > 0 && layer <= 16)
			break;
		else
		{
			cin.clear();
			cin.ignore();
		}
	}
	cin.clear();
	cin.ignore();
	*n = layer;

	/*输入起始柱*/
	char startColumn = 'A';
	while (1)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> startColumn;
		if (cin.good() && (startColumn >= 'A' && startColumn <= 'C' || startColumn >= 'a' && startColumn <= 'c'))
			break;
		else
		{
			cin.clear();
			cin.ignore();
		}
	}
	cin.clear();
	cin.ignore();

	if (int(startColumn) >= int('a'))
	{
		startColumn = startColumn - 'a' + 'A';
	}
	*src = startColumn;

	/*输入目标柱*/
	char targetColumn = 'A';
	while (1)
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> targetColumn;
		if (cin.good() && (targetColumn >= 'A' && targetColumn <= 'C' || targetColumn >= 'a' && targetColumn <= 'c'))
		{
			if (int(targetColumn) >= ('a'))
			{
				targetColumn = targetColumn - 'a' + 'A';
			}
			if (targetColumn != startColumn)
				break;
		}
		cin.clear();
		cin.ignore();
	}
	cin.clear();
	cin.ignore();
	*dst = targetColumn;

	/*判断中间柱*/
	char transitColumn = ('A' + 'B' + 'C') - (startColumn + targetColumn);
	*tmp = transitColumn;

	if (mode == '4' || mode == '8')
	{
		int speed = 0;
		while (1)
		{
			cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短) ";
			cin >> speed;
			if (cin.good() && speed >= 0 && speed <= 5)
				break;
			else
			{
				cin.clear();
				cin.ignore();
			}
		}
		cin.clear();
		cin.ignore();
		return speed;
	}
	else
		return 0;
}











/* =============================================================================================
	hanio递归函数

	1.基本解					: hanoi(int n, char src, char tmp, char dst, char mode);
	2.基本解（步数记录）		: hanoi(int n, char src, char tmp, char dst, char mode);
	3.内部数组显示（横向）		: hanoi(int n, char src, char tmp, char dst, char mode, int layer);
	4.内部数组显示（纵向+横向）	: hanoi(int n, char src, char tmp, char dst, char mode, int layer, int speed)
	7.图形解-预备-第一次移动	: hanoi(int n, char src, char tmp, char dst, char mode);
	8.图形解-自动移动版本		: hanoi(int n, char src, char tmp, char dst, char mode, int layer, int speed)
================================================================================================ */
/***************************************************************************
  函数名称：
  功    能：汉诺塔递归函数
  输入参数：int n       ：汉诺塔层数
			char src    ：起始柱
			char tmp    ：中间柱
			char dst    ：目标柱
			char mode   ：模式
			int layer   ：汉诺塔层数（缺省为0）
			int speed   ：移动速度（缺省为0）
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, char mode, int layer, int speed)
{
	int temp = 0;

	if (n == 1)
	{
		switch (mode)
		{
			case '1':// 1.基本解
				cout << setw(2) << n << '#' << ' ' << src << "---->" << dst << endl;
				break;


			case '2'://2.基本解（步数记录）
				cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << '#' << ' ' << src << "-->" << dst << ')' << endl;
				STEP++;
				break;


			case '3'://3.内部数组显示（横向）
				temp = pop(src, layer);
				push(dst, temp, layer);

				cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << '#' << ':' << ' ' << src << "-->" << dst << ')' << ' ';
				showColumn_horizontal();

				STEP++;
				break;


			case '4'://4.内部数组显示（纵向+横向）
				temp = pop(src, layer);
				push(dst, temp, layer);

				if (speed == 0)
				{
					if (_getch() == char(13))
					{
						cct_gotoxy(0, 17);
						cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
						showColumn_horizontal();
						showVerticalChange(src, dst);
					}
				}
				else
				{
					Sleep(TIME / speed);
					cct_gotoxy(0, 17);
					cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
					showColumn_horizontal();

					Sleep(TIME / speed);
					showVerticalChange(src, dst);
				}

				STEP++;
				break;


			case '7'://7.图形解 - 预备 - 第一次移动
				temp = pop(src, layer);
				push(dst, temp, layer);

				Sleep(10 * TIME);

				move(src, dst);
				break;

			case '8'://8.图形解-自动移动版本
				temp = pop(src, layer);
				push(dst, temp, layer);

				if (speed == 0)
				{
					if (_getch() == char(13))
					{
						cct_gotoxy(0, HORIZONTAL_Y);
						cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
						showColumn_horizontal();
						showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);
						move(src, dst);
					}
				}
				else
				{
					Sleep(TIME/ speed);
					cct_gotoxy(0, HORIZONTAL_Y);
					cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
					showColumn_horizontal();

					Sleep(TIME / speed);
					showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);

					Sleep(TIME / speed);
					move(src, dst);
				}
				STEP++;
				break;
		}
	}
	else
	{
		switch (mode)
		{
			case '1':// 1.基本解
				hanoi(n - 1, src, dst, tmp, '1');
				cout << setw(2) << n << '#' << ' ' << src << "---->" << dst << endl;
				hanoi(n - 1, tmp, src, dst, '1');
				break;


			case '2': //2.基本解（步数记录）
				hanoi(n - 1, src, dst, tmp, '2');
				cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << '#' << ' ' << src << "-->" << dst << ')' << endl;
				STEP++;
				hanoi(n - 1, tmp, src, dst, '2');
				break;


			case '3'://3.内部数组显示（横向）
				hanoi(n - 1, src, dst, tmp, '3', layer);

				temp = pop(src, layer);
				push(dst, temp, layer);

				cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << '#' << ':' << ' ' << src << "-->" << dst << ')' << ' ';
				showColumn_horizontal();
				STEP++;
				hanoi(n - 1, tmp, src, dst, '3', layer);
				break;


			case '4'://4.内部数组显示（纵向+横向）
				hanoi(n - 1, src, dst, tmp, '4', layer, speed);

				temp = pop(src, layer);
				push(dst, temp, layer);

				if (speed == 0)
				{
					if (_getch() == char(13))
					{
						cct_gotoxy(0, 17);
						cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
						showColumn_horizontal();
						showVerticalChange(src, dst);
					}	
				}
				else
				{
					Sleep(TIME / speed);
					cct_gotoxy(0, 17);
					cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
					showColumn_horizontal();

					Sleep(TIME/ speed);
					showVerticalChange(src, dst);
				}

				STEP++;
				hanoi(n - 1, tmp, src, dst, '4', layer, speed);
				break;


			case '7'://7.图形解 - 预备 - 第一次移动
				hanoi(n - 1, src, dst, tmp, '7', layer);
				break;


			case'8'://8.图形解-自动移动版本
				hanoi(n - 1, src, dst, tmp, '8', layer, speed);
				temp = pop(src, layer);
				push(dst, temp, layer);

				if (speed == 0)
				{
					if (_getch() == char(13))
					{
						cct_gotoxy(0, HORIZONTAL_Y);
						cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
						showColumn_horizontal();
						showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);
						move(src, dst);
					}
				}
				else
				{
					Sleep(TIME/ speed);
					cct_gotoxy(0, HORIZONTAL_Y);
					cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
					showColumn_horizontal();

					Sleep(TIME/ speed);
					showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);

					Sleep(TIME/ speed);
					move(src, dst);
				}

				STEP++;
				hanoi(n - 1, tmp, src, dst, '8', layer, speed);
				break;


		}
	}
}





/* ==================================================================================
		人工操作移动步骤
====================================================================================== */
void game(int layer, char startColumn, char targetColumn)
{
	int temp = 0;
	int isEND = 0;

	int* SRC;
	SRC = Column_A;
	int* TOP_SRC;
	TOP_SRC = &Top_A;
	int* DST;
	DST = Column_A;
	int* TOP_DST;
	TOP_DST = &Top_A;

	char src = 'A';
	char dst = 'A';
	int x = 0;
	int y = 0;
	int column_x_start = 0;
	int column_x_target = 0;

	int* startColumn_move;
	startColumn_move = Column_A;

	int* targetColumn_move;
	targetColumn_move = Column_A;

	int* top_start;
	top_start = &Top_A;

	int* top_target;
	top_target = &Top_A;

	/*确定起始柱*/
	switch (startColumn)
	{
		case'A':
			SRC = Column_A;
			TOP_SRC = &Top_A;
			break;
		case'B':
			SRC = Column_B;
			TOP_SRC = &Top_B;
			break;
		case'C':
			SRC =  Column_C;
			TOP_SRC = &Top_C;
			break;
	}
	/*确定目标柱*/
	switch (dst)
	{
		case'A':
			DST = Column_A;
			TOP_DST = &Top_A;
			break;
		case'B':
			DST = Column_B;
			TOP_DST = &Top_B;
			break;
		case'C':
			DST = Column_C;
			TOP_DST = &Top_C;
			break;
	}

	/*进入移动模式*/
	while (1)
	{
		cct_setcolor(); //恢复缺省颜色
		cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

		cct_gotoxy(0, HORIZONTAL_Y + 2);
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";

		/*输入起始柱、目标柱*/
		while (1)
		{
			cct_gotoxy(60, HORIZONTAL_Y + 2);
			cout << "                                                 ";
			cct_gotoxy(60, HORIZONTAL_Y + 2);


			/*输入*/
			src = _getche();
			if (src == 'q' || src == 'Q')
			{
				isEND = 1;
				break;//跳出输入循环
			}

			dst = _getche();
			//while (_getch() != '\r')
			//	;

			/*判断起始柱是否输入正确*/
			if (src == 'a' || src == 'b' || src == 'c'
				|| src == 'A' || src == 'B' || src == 'C')
			{
				if (int(src) >= int('a'))
				{
					src = src - 'a' + 'A';
				}
			}
			else
			{
				cout << ' ' << char(8);
				cin.ignore();
				continue;
			}

			/*判断目标柱是否输入正确*/
			if (dst == 'a' || dst == 'b' || dst == 'c'
				|| dst == 'A' || dst == 'B' || dst == 'C')
			{
				if (int(dst) >= int('a'))
				{
					dst = dst - 'a' + 'A';
				}
			}
			else
			{
				cout << ' ' << char(8);
				cin.ignore();
				continue;
			}

			/*判断起始柱、目标柱是否相同*/
			if (src == dst)
			{
				cin.ignore();
				continue;
			}
			else
			{
				cin.putback('\n');
				cin.ignore(10000, '\n');
				break;
			}//不相同，完成输入
		}



		if (isEND)
			break;
		else
		{
			/*确定起始柱*/
			switch (src)
			{
				case'A':
					startColumn_move = Column_A;
					top_start = &Top_A;
					column_x_start = COLUMN_X;//确定上移的横坐标
					break;
				case'B':
					startColumn_move = Column_B;
					top_start = &Top_B;
					column_x_start = COLUMN_X + COLUMN_GAP;//确定上移的横坐标
					break;
				case'C':
					startColumn_move = Column_C;
					top_start = &Top_C;
					column_x_start = COLUMN_X + 2 * COLUMN_GAP;//确定上移的横坐标
					break;
			}
			/*确定目标柱*/
			switch (dst)
			{
				case'A':
					targetColumn_move = Column_A;
					top_target = &Top_A;
					column_x_target = COLUMN_X;//确定下移的横坐标
					break;
				case'B':
					targetColumn_move = Column_B;
					top_target = &Top_B;
					column_x_target = COLUMN_X + COLUMN_GAP;//确定下移的横坐标
					break;
				case'C':
					targetColumn_move = Column_C;
					top_target = &Top_C;
					column_x_target = COLUMN_X + 2 * COLUMN_GAP;//确定下移的横坐标
					break;
			}

			if (*top_start == 0)
			{
				cct_setcolor(); //恢复缺省颜色
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				cct_gotoxy(0, HORIZONTAL_Y + 3);
				cout << "柱源为空!";
				Sleep(10 * TIME);
				cct_gotoxy(0, HORIZONTAL_Y + 3);
				cout << "                                                 ";

				continue;
			}
			else if (*top_target > 0 && startColumn_move[*top_start - 1] > targetColumn_move[*top_target - 1])
			{
				cct_setcolor(); //恢复缺省颜色
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				cct_gotoxy(0, HORIZONTAL_Y + 3);
				cout << "大盘压小盘，非法移动!";
				Sleep(10 * TIME);
				cct_gotoxy(0, HORIZONTAL_Y + 3);
				cout << "                                                 ";

				continue;
			}
			else//可交换
			{
				temp = pop(src, layer);
				push(dst, temp, layer);
			}

			cct_setcolor(); //恢复缺省颜色
			cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认
			showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);
			cct_gotoxy(0, HORIZONTAL_Y);
			cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << targetColumn_move[*top_target - 1] << "#: " << src << "-->" << dst << ") ";
			showColumn_horizontal();
			move(src, dst);

			STEP++;

			if (*top_target == layer)//完成所有移动
			{
				isEND = 2;
				break;
			}
		}		
	}

	cct_gotoxy(0, HORIZONTAL_Y + 3);
	switch (isEND)
	{
		case 1:
			cct_setcolor(); //恢复缺省颜色
			cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认
			cout << "游戏中止!!!!!";
			break;
		case 2:
			cct_setcolor(); //恢复缺省颜色
			cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认
			cout << "游戏结束!!!!!";
			break;
	}
}
/* 电信 1850917 梁诗瑶 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);

	char mode;
	int layer;
	char startColumn;
	char targetColumn;
	char transitColumn;
	int speed = 0;

	while (1)
	{
		//cct_cls();

		/*菜单的显示与选择*/
		mode = printAndselctMenu();

		/*若选择退出，直接退出*/
		if (mode == '0')
			break;

		switch (mode)
		{
			case '1':// 1.基本解
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				hanoi(layer, startColumn, transitColumn, targetColumn, '1');

				cout <<endl<< "按回车键继续...";
				break;


			case '2'://2.基本解（步数记录）
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				hanoi(layer, startColumn, transitColumn, targetColumn, '2');

				cout << endl << "按回车键继续...";
				break;


			case '3'://3.内部数组显示（横向）
				
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				hanoi(layer, startColumn, transitColumn, targetColumn, '3', layer);

				cout << endl << "按回车键继续...";
				break;


			case '4'://4.内部数组显示（纵向+横向）
				speed=inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();

				cout << "从 " << startColumn << " 移动到 " << targetColumn << "，共" << layer << " 层，延时设置为 " << speed;

				cct_gotoxy(0, 17);
				cout << "初始:" << setw(15) << ' ';
				showColumn_horizontal();
				showColumn_vertical();

				hanoi(layer, startColumn, transitColumn, targetColumn, '4', layer, speed);

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				cout << endl << "按回车键继续...";
				break;


			case '5'://5.图形解-预备-画三个圆柱
				/*清屏*/
				cct_cls();

				drawColumn();

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				cout << endl << "按回车键继续...";
				break;


			case '6'://6.图形解-预备-在起始柱上画n个盘子
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();//清屏

				drawColumn();
				drawPlate();

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				cout << endl << "按回车键继续";
				break;


			case '7'://7.图形解 - 预备 - 第一次移动
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();//清屏

				cout << "从 " << startColumn << " 移动到 " << targetColumn << "，共" << layer << " 层";

				drawColumn();
				drawPlate();

				hanoi(layer, startColumn, transitColumn, targetColumn, '7', layer);

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				cout << endl << "按回车键继续...";
				break;


			case '8'://8.图形解-自动移动版本
				speed = inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();//清屏

				cout << "从 " << startColumn << " 移动到 " << targetColumn << "，共" << layer << " 层，延时设置为 " << speed;

				cct_gotoxy(0, HORIZONTAL_Y);
				cout << "初始:" << setw(15) << ' ';
				showColumn_horizontal();

				showColumn_vertical(VERTICAL_X, VERTICAL_Y);

				drawColumn();
				drawPlate();

				hanoi(layer, startColumn, transitColumn, targetColumn, '8', layer, speed);

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				cout << endl << "按回车键继续...";
				break;


			case '9'://9.图形解-游戏版
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();//清屏

				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				/*初始显示*/
				cout << "从 " << startColumn << " 移动到 " << targetColumn << "，共" << layer << " 层";
				cct_gotoxy(0, HORIZONTAL_Y);
				cout << "初始:" << setw(15) << ' ';

				showColumn_horizontal();

				showColumn_vertical(VERTICAL_X, VERTICAL_Y);

				drawColumn();
				drawPlate();

				game(layer, startColumn, targetColumn);

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//设置光标为默认

				cout << endl << "按回车键继续...";
				break;
		}
		

		/*重置*/
		resetSTEP();//重置计数
		resetColumn();//重置数组

		while (_getch() != '\r')
			;

		cct_cls();


	}
	

	return 0;
}

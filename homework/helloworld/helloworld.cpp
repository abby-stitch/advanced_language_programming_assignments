/* 1850917 梁诗瑶 电信 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	   /*有位置重合的时候？*/
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
char menu()
{
	char chInput_choice;
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止,按左箭头时不向下移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕,按左箭头时不向下移动)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0 - 6] ";
	while (1)
	{
		chInput_choice = _getche();
		if (chInput_choice == '0' || chInput_choice == '1' || chInput_choice == '2' || chInput_choice == '3' || chInput_choice == '4' || chInput_choice == '5' || chInput_choice == '6')
			break;
	}
	return chInput_choice;
}

void move_by_ijkl(const HANDLE hout, char chInput_choice)
{
	int X = 35, Y = 8;
	char chInput;

	while (1)
	{
		chInput = _getch();

		/*用i/j/k/l进行光标移动*/
		if (chInput_choice == '5' || chInput_choice == '6')//按左键不向下移动
		{
			/*左键用强制类型转换的得到的ASCII码为：-32和75，其中75与“K”的ASCII码一致*/
			/*判断字符的ASCII是否先为-32即可区别左键和K*/
			if (int(chInput) == -32)
			{
				chInput = _getch();
				continue;
			}
		}
		if (chInput == 'i' || chInput == 'I')//上
		{
			Y--;
		}
		if (chInput == 'k' || chInput == 'K')//下
		{
			Y++;
		}
		if (chInput == 'j' || chInput == 'J')//左
		{
			X--;
		}
		if (chInput == 'l' || chInput == 'L')//右
		{
			X++;
		}
		if (chInput == ' ')
		{
			cout << ' ' << char(8);
		}
		if (chInput == 'q' || chInput == 'Q')//按Q/q结束游戏
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单." << endl;
			break;
		}

		/*边界停止*/
		if (chInput_choice == '1' || chInput_choice == '5')
		{
			if (X > 68)
				X = 68;
			if (X < 1)
				X = 1;
			if (Y > 17)
				Y = 17;
			if (Y < 1)
				Y = 1;
			if (X > 0 && X < 69 && Y>0 && Y <= 17)
			{
				gotoxy(hout, X, Y);
			}
		}
		/*边界回绕*/
		if (chInput_choice == '2' || chInput_choice == '6')
		{
			if (X > 68)
				X = 1;
			if (X < 1)
				X = 68;
			if (Y > 17)
				Y = 1;
			if (Y < 1)
				Y = 17;
			if (X > 0 && X < 69 && Y>0 && Y <= 17)
			{
				gotoxy(hout, X, Y);
			}
		}
	}
}


void move_by_arrow(const HANDLE hout, char chInput_choice)
{
	int X = 35, Y = 8;
	char chInput;

	while (1)
	{
		chInput = _getch();

		/*用箭头进行光标移动*/
		if (int(chInput) == -32)
		{
			chInput = _getch();
			if (int(chInput) == 72)//上
			{
				Y--;
			}
			else if (int(chInput) == 80)//下
			{
				Y++;
			}
			else if (int(chInput) == 75)//左
			{
				X--;
			}
			else if (int(chInput) == 77)//右
			{
				X++;
			}
			else
			{
				continue;
			}
		}
		if (chInput == ' ')
		{
			cout << ' ' << char(8);
		}
		if (chInput == 'q' || chInput == 'Q')//按Q/q结束游戏
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单." << endl;
			break;
		}

		/*边界停止*/
		if (chInput_choice == '3')
		{
			if (X > 68)
				X = 68;
			if (X < 1)
				X = 1;
			if (Y > 17)
				Y = 17;
			if (Y < 1)
				Y = 1;
			if (X > 0 && X < 69 && Y>0 && Y <= 17)
			{
				gotoxy(hout, X, Y);
			}
		}
		/*边界回绕*/
		if (chInput_choice == '4')
		{
			if (X > 68)
				X = 1;
			if (X < 1)
				X = 68;
			if (Y > 17)
				Y = 1;
			if (Y < 1)
				Y = 17;
			if (X > 0 && X < 69 && Y>0 && Y <= 17)
			{
				gotoxy(hout, X, Y);
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	while (1)
	{
		const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

		/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
		srand((unsigned int)(time(0)));

		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);

		/*显示菜单，并选择菜单*/
		char chInput_choice;
		chInput_choice = menu();
		/*若选择退出，直接退出*/
		if (chInput_choice == '0')
			break;

		/* 显示初始的边框及其中的随机字符 */
		init_border(hout);

		/*使光标停在由“*”组成的边框的中心位置*/
		gotoxy(hout, 35, 8);

		/*进入菜单相应模式*/
		if (chInput_choice == '1' || chInput_choice == '2'|| chInput_choice == '5' || chInput_choice == '6')
			move_by_ijkl(hout, chInput_choice);
		if (chInput_choice == '3' || chInput_choice == '4')
			move_by_arrow(hout, chInput_choice);

		while (1)
		{
			char enter;
			enter = _getch();
			if (enter == char(13))
				break;
		}
	}

	return 0;
}

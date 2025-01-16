/* 1850917 电信 梁诗瑶 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 定义符号常量
				 定义const型变量
		不允许 ：定义全局变量
   ----------------------------------------------------------------------------------- */

char print_letters(char start_ch, char end_ch, int order);
void print_space(int n);
void print_tower_with_space(char start_ch, char end_ch, int order, int numOfspace);

/***************************************************************************
	 函数名称：
	 功    能：正向或反向打印三角塔
	 输入参数：order - 0 ：正三角形塔
			   order - 1 ：倒三角形塔
	 返 回 值：
	 说    明：
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* 按需实现，函数中不允许任何形式的循环，不允许定义静态局部变量 */
	int numOfspace = 0;
	print_tower_with_space(start_ch, end_ch, order, numOfspace);
	
}
void print_tower_with_space(char start_ch, char end_ch, int order,int numOfspace)
{
	/* 按需实现，函数中不允许任何形式的循环，不允许定义静态局部变量 */
	char keyLetter = end_ch;
	if (order == 0)
	{
		if (end_ch == start_ch)
		{
			print_space(numOfspace);
			print_letters(start_ch, end_ch, order);
			cout << endl;
		}
		else
		{
			print_tower_with_space(start_ch, char(end_ch - 1), order, numOfspace + 1);
			print_space(numOfspace);
			print_letters(start_ch, end_ch, order);
			cout << endl;
		}
	}
	else if (order == 1)
	{
		if (start_ch == end_ch)
		{
			print_space(numOfspace);
			print_letters(start_ch, end_ch, order);
			cout << endl;
		}
		else
		{
			print_space(numOfspace);
			print_letters(start_ch, end_ch, order);
			cout << endl;
			print_tower_with_space(char(start_ch + 1), end_ch, order,numOfspace+1);
		}
	}
}

/***************************************************************************
	函数名称：
	功    能：打印每行字母
	输入参数：order - 0 ：正三角形塔
			  order - 1 ：倒三角形塔
	返 回 值：
	说    明：
  ***************************************************************************/
char print_letters(char start_ch, char end_ch, int order)
{
	if (order == 0)
	{
		if (start_ch == end_ch)
		{
			cout << start_ch;
		}
		else
		{

			cout << end_ch;
			print_letters(start_ch, end_ch - 1, order);
			cout << end_ch;
		}
		return end_ch;
	}
	if (order == 1)
	{
		if (start_ch == end_ch)
		{
			cout << end_ch;
		}
		else
		{
			cout << start_ch;
			print_letters(start_ch + 1, end_ch, order);
			cout << start_ch;
		}
		return start_ch;
	}
}


void print_space(int n)
{
	if (n != 0)
	{
		cout << ' ';
		print_space(n - 1);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	while (1) {
		cout << "请输入结束字符(A~Z)" << endl;
		end_ch = getchar();			//读缓冲区第一个字符
		while (getchar() != '\n')	//清空缓冲区剩余字符
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}

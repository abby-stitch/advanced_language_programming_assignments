/* 1850917 电信 梁诗瑶 */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
/*放内部数组方式实现的各函数*/

/***************************************************************************
  函数名称：
  功    能：生成随机值
  输入参数：const int row, 行数
			const int col, 列数
			int matrix[][N], 存放随机数的矩阵
  返 回 值：
  说    明：
***************************************************************************/
void generate_matrix(const int row, const int col, int matrix[][N])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % 3 + 1;
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：显示数组
  输入参数：int mode, 模式：
							1. 显示"当前数组："
							2. 显示"查找结果数组："
							//3. 显示"当前数组(不同色标识)："
			char* prompt,
			const int row, 行数
			const int col, 列数
			int str[][N], 要显示的矩阵
  返 回 值：
  说    明：
***************************************************************************/
void print_matrix(int mode,const char *prompt, const int row, const int col, int str[][N])
{
	cout << prompt << endl;
	/*横栏*/
	cout << setw(2) << ' ';
	cout << '|';
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;
	}
	cout << endl;
	/*分界线*/
	cout << "--+";
	for (int i = 0; i < col; i++)
	{
		cout << "---";
	}
	cout << endl;
	/*打印数组*/
	for (int i = 0; i < row; i++)
	{
		cout << char('A' + i) << " |";
		for (int j = 0; j < col; j++)
		{
			cout << setw(3);
			switch (mode)
			{
				case 1:
					cout << str[i][j];
					break;
				case 2:
				{
					if (str[i][j])
						cout << '*';
					else
						cout << str[i][j];
					break;
				}
			}
		}
		cout << endl;
	}
}

/***************************************************************************
  函数名称：
  功    能：显示数组(不同色标识)
  输入参数：const int row, 行数
			const int col, 列数
			int matrix[][N], 存放随机数的矩阵
			int pos[][N], 存放位置信息的矩阵
  返 回 值：
  说    明：
***************************************************************************/
void print_matrix_color(const char *prompt,const int row, const int col, int matrix[][N],int pos[][N])
{
	cout << prompt << "(不同色标识)：" << endl;
	/*横栏*/
	cout << setw(2) << ' ';
	cout << '|';
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;
	}
	cout << endl;
	/*分界线*/
	cout << "--+";
	for (int i = 0; i < col; i++)
	{
		cout << "---";
	}
	cout << endl;
	/*打印数组*/
	for (int i = 0; i < row; i++)
	{
		cout << char('A' + i) << " |";
		for (int j = 0; j < col; j++)
		{
			cout << setw(3);
			if (pos[i][j])
			{
				cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
				cout << matrix[i][j];
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			}
			else
				cout << matrix[i][j];
		}
		cout << endl;
	}
}

/***************************************************************************
  函数名称：
  功    能：判断该位置是否有相邻的相同值
  输入参数：const int row, 行数
			const int col, 列数
			const int row_pos, 位置行坐标
			const int col_pos, 位置列坐标
			int matrix[][N]， 存放数值的数组
  返 回 值：1 该位置有相邻的相同值
			0 该位置无相邻的相同值
  说    明：
***************************************************************************/
int is_adjacent_same(const int row, const int col, const int row_pos, const int col_pos, int matrix[][N])
{
	int val = matrix[row_pos][col_pos];

	//上
	if (matrix[row_pos - 1][col_pos] == val && row_pos > 0)
		return 1;
	//下
	else if (matrix[row_pos + 1][col_pos] == val && row_pos < row - 1)
		return 1;
	//左
	else if (matrix[row_pos][col_pos - 1] == val && col_pos > 0)
		return 1;
	//右
	else if (matrix[row_pos][col_pos + 1] == val && col_pos < col - 1)
		return 1;
	else
		return 0;
}

/***************************************************************************
  函数名称：
  功    能：找与该坐标相邻的所有相同值（上下左右值相同）(非递归方式)
  输入参数：const int row, 行数
			const int col, 列数
			const int row_pos, 位置行坐标
			const int col_pos, 位置列坐标
			int matrix[][N]， 存放数值的数组
			int pos[][N], 存放位置信息的数组
  返 回 值：
  说    明：
***************************************************************************/
void seek_same_val_nonrecursive(const int row, const int col,int row_pos, int col_pos,int matrix[][N], int pos[][N])
{
	int val = matrix[row_pos][col_pos];//该坐标的值
	pos[row_pos][col_pos] = 1;

	int r = 0;
	int c = 0;//比较位置

	/*先从row_pos行开始向上、向下一行行查找*/
	/*每行从col_pos列开始向左、向右一列列查找，查找到的相邻相同值pos置1*/

	r = row_pos;//从row_pos行开始

	c = col_pos;//从col_pos列开始向左
	c--;
	while (c >= 0)
	{
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;
			c--;
		}
		else
			break;//该行继续向左无相邻的相同值
	}

	c = col_pos;//从col_pos列开始向右
	c++;
	while (c < col)
	{
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;
			c++;
		}
		else
			break;//该行继续向右无相邻的相同值
	}

	r = row_pos - 1;//从row_pos行开始向上
	while (r >= 0)
	{
		c = col_pos;
		if (matrix[r][c] == val && pos[r + 1][c] == 1)//值相等且下方为相邻相同值
		{
			pos[r][c] = 1;
		}

		c = col_pos;//从col_pos列开始向左
		c--;

		while (c >= 0)
		{
			if (matrix[r][c] == val && (pos[r + 1][c] == 1 || pos[r][c + 1] == 1))//值相等且下方为相邻相同值或右方为相邻相同值
			{
				pos[r][c] = 1;
				if (matrix[r + 1][c] == val && pos[r + 1][c] == 0)//若下方未与所在行的col_pos位置相连，但也为相同值
					pos[r + 1][c] = 1;
				if (matrix[r][c + 1] == val && pos[r][c + 1] == 0)//若右方未与所在行的col_pos位置相连，但也为相同值
					pos[r][c + 1] = 1;
			}
			
			c--;
		}

		c = col_pos;//从col_pos列开始向右
		c++;
		while (c < col)
		{
			if (matrix[r][c] == val && (pos[r + 1][c] == 1 || pos[r][c - 1] == 1))//值相等且下方为相邻相同值或左方为相邻相同值
			{
				pos[r][c] = 1;
				if (matrix[r + 1][c] == val && pos[r + 1][c] == 0)//若下方未与所在行的col_pos位置相连，但也为相同值
					pos[r + 1][c] = 1;
				if (matrix[r][c - 1] == val && pos[r][c - 1] == 0)//若左方未与所在行的col_pos位置相连，但也为相同值
					pos[r][c - 1] = 1;
			}
			c++;
		}

		r--;
	}

	r = row_pos + 1;//从row_pos行开始向下
	while (r < row)
	{
		c = col_pos;
		if (matrix[r][c] == val && pos[r - 1][c] == 1)//值相等且下方为相邻相同值
		{
			pos[r][c] = 1;
		}
		c = col_pos;//从col_pos列开始向左
		c--;
		while (c >= 0)
		{
			if (matrix[r][c] == val && (pos[r - 1][c] == 1 || pos[r][c + 1] == 1))//值相等且上方为相邻相同值或右方为相邻相同值
			{
				pos[r][c] = 1;
				if (matrix[r - 1][c] == val && pos[r - 1][c] == 0)//若上方未与所在行的col_pos位置相连，但也为相同值
					pos[r - 1][c] = 1;
				if (matrix[r][c + 1] == val && pos[r][c + 1] == 0)//若右方未与所在行的col_pos位置相连，但也为相同值
					pos[r][c + 1] = 1;
			}
			c--;
		}

		c = col_pos;//从col_pos列开始向右
		c++;
		while (c < col)
		{
			if (matrix[r][c] == val && (pos[r - 1][c] == 1 || pos[r][c - 1] == 1))//值相等且上方为相邻相同值或左方为相邻相同值
			{
				pos[r][c] = 1;
				if (matrix[r - 1][c] == val && pos[r - 1][c] == 0)//若上方未与所在行的col_pos位置相连，但也为相同值
					pos[r - 1][c] = 1;
				if (matrix[r][c - 1] == val && pos[r][c - 1] == 0)//若左方未与所在行的col_pos位置相连，但也为相同值
					pos[r][c - 1] = 1;
			}
			c++;
		}

		r++;
	}
}

/***************************************************************************
  函数名称：
  功    能：找与该坐标相邻的所有相同值（上下左右值相同）(递归方式)
  输入参数：const int row, 行数
			const int col, 列数
			int row_pos, 位置行坐标
			int col_pos, 位置列坐标
			int matrix[][N]， 存放数值的数组
			int pos[][N], 存放位置信息的数组
  返 回 值：
  说    明：
***************************************************************************/
void seek_same_val_recursive(const int row, const int col, int row_pos, int col_pos, int matrix[][N], int pos[][N])
{
	//从（row_pos,col_pos）开始，找上下左右是否有值相同的，
	//若有，则pos置1，继续从相邻位置找，
	//若某位置的pos已置1，说明该位置已被查找过，则不继续查找
	if (row_pos >= 0 && row_pos < row && col_pos >= 0 && col_pos < col && pos[row_pos][col_pos] == 0)
	{
		int val = matrix[row_pos][col_pos];//该坐标的值
		pos[row_pos][col_pos] = 1;

		//上
		if (matrix[row_pos - 1][col_pos] == val)
			seek_same_val_recursive(row, col, row_pos - 1, col_pos, matrix, pos);
		//下
		if (matrix[row_pos + 1][col_pos] == val)
			seek_same_val_recursive(row, col, row_pos + 1, col_pos, matrix, pos);
		//左
		if (matrix[row_pos][col_pos - 1] == val)
			seek_same_val_recursive(row, col, row_pos, col_pos - 1, matrix, pos);
		//右
		if (matrix[row_pos][col_pos + 1] == val)
			seek_same_val_recursive(row, col, row_pos, col_pos + 1, matrix, pos);
	}
}

/***************************************************************************
  函数名称：
  功    能：把相邻的相同值合并
  输入参数：const int row, 行数
			const int col, 列数
			const int row_pos, 位置行坐标
			const int col_pos, 位置列坐标
			int matrix[][N]， 存放数值的数组
			int pos[][N], 存放位置信息的数组
			int &point, 总分
			int goal, 目标分数
			int &max, 目前数组中的最大值
  返 回 值：
  说    明：
***************************************************************************/
void merge(const int row,const int col,const int row_pos, const int col_pos, int matrix[][N], int pos[][N],int &point,int goal,int &max,int mode)
{
	int val = matrix[row_pos][col_pos];
	if (val == max)
	{
		max++;
	}
	int add_point = 0;
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		count++;
		for (int j = 0; j < col; j++)
		{
			if (pos[i][j])
			{
				if (i == row_pos && j == col_pos)
					matrix[i][j]++;//合并后值+1
				else
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
	add_point = val * count * 3;
	point += add_point;

	if (mode == 0)
	{
		print_matrix_color("相同值归并后的数组", row, col, matrix, pos);
		cout << "本次得分：" << add_point << ' ';
		cout << "总得分：" << point << ' ';
		cout << "合成目标：" << goal << endl;
	}
	else if (mode == 1)
	{
		int x, y;
		cct_getxy(x, y);
		cct_gotoxy(0, 0);
		cout << "本次得分：" << add_point << ' ';
		cout << "总得分：" << point << ' ';
		cout << "合成目标：" << goal << endl;
		cct_gotoxy(x, y);
	}
}

/***************************************************************************
  函数名称：
  功    能：数组下落除0
  输入参数：const int row, 行数
			const int col, 列数
			const int row_pos, 位置行坐标
			const int col_pos, 位置列坐标
			int matrix[][N]， 存放数值的数组
			int pos[][N], 存放位置信息的数组
			int mode,
				0：0向上移动，打印除0后数组
				1：将合并位置信息置零
				2：0向上移动，不打印数组
  返 回 值：
  说    明：
***************************************************************************/
void drop_down(const int row, const int col, const int row_pos, const int col_pos, int matrix[][N], int pos[][N], int mode)
{
	if (mode == 0)
	{
		pos[row_pos][col_pos] = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (pos[i][j])
				{
					for (int k = i; k > 0; k--)
					{
						pos[k][j] = pos[k - 1][j];
						pos[k - 1][j] = 1;

						int temp = matrix[k][j];
						matrix[k][j] = matrix[k - 1][j];
						matrix[k - 1][j] = temp;
					}
				}
			}
		}

		print_matrix_color("除0后的数组", row, col, matrix, pos);
	}
	else if (mode == 1)
	{
		pos[row_pos][col_pos] = 0;//先不改变数组里的信息
	}
	else if (mode == 2)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (pos[i][j]>0)
				{
					for (int k = i; k > 0; k--)
					{
						pos[k][j] = pos[k - 1][j];
						pos[k - 1][j] = 1;

						int temp = matrix[k][j];
						matrix[k][j] = matrix[k - 1][j];
						matrix[k - 1][j] = temp;
					}
				}
			}
		}
	}

}

/***************************************************************************
  函数名称：
  功    能：新值填充
  输入参数：const int row, 行数
			const int col, 列数
			int matrix[][N]， 存放数值的数组
			int pos[][N], 存放位置信息的数组
			const int max, 目前数组中的最大值

  返 回 值：
  说    明：
***************************************************************************/
void fill_new_val(const int row, const int col, int matrix[][N], int pos[][N],const int max,int mode)
{
	int count = 0;//记录pos中置1位置的个数，即数组中为0、需要填充新值的位置个数
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (pos[i][j])
				count++;
		}
	}
	if (max == 3)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (pos[i][j])
					matrix[i][j] = rand() % 3 + 1;
			}
		}
	}
	else if (max == 4)
	{
		int num = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (pos[i][j])
				{
					num = rand() % 100 + 1;
					if (num > 0 && num <= 30)
						matrix[i][j] = 1;
					else if (num > 30 && num <= 60)
						matrix[i][j] = 2;
					else if (num > 60 && num <= 90)
						matrix[i][j] = 3;
					else
						matrix[i][j] = 4;
				}
			}
		}
	}
	else if (max == 5)
	{
		int num = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (pos[i][j])
				{
					num = rand() % 100 + 1;
					if (num > 0 && num <= 25)
						matrix[i][j] = 1;
					else if (num > 25 && num <= 50)
						matrix[i][j] = 2;
					else if (num > 50 && num <= 75)
						matrix[i][j] = 3;
					else if (num > 70 && num <= 85)
						matrix[i][j] = 4;
					else
						matrix[i][j] = 5;
				}
			}
		}
	}
	else if (max == 6)
	{
		int num = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (pos[i][j])
				{
					num = rand() % 100 + 1;
					if (num > 0 && num <= 20)
						matrix[i][j] = 1;
					else if (num > 20 && num <= 40)
						matrix[i][j] = 2;
					else if (num > 40 && num <= 60)
						matrix[i][j] = 3;
					else if (num > 60 && num <= 80)
						matrix[i][j] = 4;
					else if (num > 80 && num <= 95)
						matrix[i][j] = 5;
					else
						matrix[i][j] = 6;
				}
			}
		}
	}
	else
	{
		int num = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (pos[i][j])
				{
					num = rand() % 100 + 1;
					if (num > 0 && num <= 80)
					{
						int p = 80 / (max - 3);

						matrix[i][j] = num / p + 1;
					}
					else if (num > 80 && num <= 90)
						matrix[i][j] = max - 2;
					else if (num > 90 && num <= 95)
						matrix[i][j] = max - 1;
					else
						matrix[i][j] = max;;
				}
			}
		}
	}
	if (mode == 0)
	{
		print_matrix_color("新值填充后的数组", row, col, matrix, pos);
	}
}

/***************************************************************************
  函数名称：
  功    能：判断整个数组是否存在相邻位置相等
  输入参数：const int row, 行数
			const int col, 列数
			int matrix[][N]， 存放数值的数组
			int pos[][N], 存放位置信息的数组
  返 回 值：1 该数组有相邻的相同值
			0 该数组无相邻的相同值
  说    明：
***************************************************************************/
int is_array_adjacent_same(const int row, const int col, int matrix[][N])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int pos[M][N] = { 0 };

			if (is_adjacent_same(row, col, i, j, matrix))
				return 1;
		}
	}

	return 0;
}


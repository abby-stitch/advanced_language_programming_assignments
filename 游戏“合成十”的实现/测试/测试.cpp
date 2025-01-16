#include <iostream>
#include <conio.h>

using namespace std;
#define M 8
#define N 10
#define START_MAX 3
#define TIME 50

void seek_same_val(const int row, const int col, int row_pos, int col_pos, int matrix[][N], int pos[][N])
{
	int val = matrix[row_pos][col_pos];//该坐标的值

	int r = 0;
	int c = 0;//比较位置
	int up = 1, down = 1, left = 1, right = 1;//上下左右是否有相同值的标记

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
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;

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

			r--;
		}
		else
			break;//继续向上无相邻的相同值
	}

	r = row_pos + 1;//从row_pos行开始向下
	while (r < row)
	{
		c = col_pos;
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;

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

			r++;
		}
		else
			break;//继续向下无相邻的相同值
	}


	/*再从col_pos列开始向左、向右一列列查找*/
	/*每列从row_pos行开始向上、向下一行行查找，查找到的相邻相同值pos置1*/




	//右
	if (col_pos < col - 1)
	{
		r = row_pos;
		c = col_pos + 1;
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;
			right = 1;
		}
	}




	//上
	if (row_pos > 0)
	{
		r = row_pos - 1;
		c = col_pos;
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;
			up = 1;
		}
	}
	//下
	if (row_pos < row - 1)
	{
		r = row_pos + 1;
		c = col_pos;
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;
			down = 1;
		}
	}


	/*继续一行一行找*/
	//本行
	r = row_pos;
	//向左
	if (left)
	{
		c = col_pos;//列变化
		c--;
		while (c >= 0)
		{
			if (matrix[r][c] == val)
				pos[r][c] = 1;
			c--;
		}
	}
	//向右
	if (right)
	{
		c = col_pos;//列变化
		c++;
		while (c < col)
		{
			if (matrix[r][c] == val)
				pos[r][c] = 1;
			c++;
		}
	}

	//向上一行一行找
	if (up)
	{
		r = row_pos - 1;//从row_pos的上一行开始

		while (r >= 0)
		{
			//向左
			c = col_pos;//列变化
			c--;
			while (c >= 0)
			{
				if (matrix[r][c] == val)
					pos[r][c] = 1;
				c--;
			}
			//向右
			c = col_pos;//列变化
			c++;
			while (c < col)
			{
				if (matrix[r][c] == val)
					pos[r][c] = 1;
				c++;
			}

			r--;//该行检查完毕
		}
	}

}

cct_cls();

int is_continue = 1;//若所有数字无法合并，则置0

/*输入行列数，目标值*/
input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
input_int("请输入列数(5-10)：", 5, 11, col);//输入列数
input_int("请输入合成目标(5-20)：", 5, 21, goal);//输入合成目标

generate_matrix(row, col, matrix);

while (1)
{
	if (is_array_adjacent_same(row, col, matrix))
		is_continue = 1;
	else
		is_continue = 0;

	/*一次合并*/
	while (1)
	{
		/*重置记录位置数组*/
		reset(row, col, pos_1);

		cout << endl;
		print_matrix(1, "当前数组：", row, col, matrix);
		cout << endl;

		if (is_continue)
		{
			/*输入矩阵坐标*/
			input_coordinate(row, col, row_pos, col_pos, matrix);

			/*找相邻相同值（递归方式）*/
			seek_same_val_recursive(row, col, row_pos, col_pos, matrix, pos_1);

			cout << endl;
			print_matrix(2, "查找结果数组：", row, col, pos_1);
			cout << endl;

			cout << endl;
			print_matrix_color("当前数组", row, col, matrix, pos_1);
			cout << endl;

			/*选择是否合并*/
			char sel = input_is_merge(row_pos, col_pos);

			if (sel == 'Y')//完成本次合并
			{
				/*合并相邻的相同值，并显示*/
				cout << endl;
				merge(row, col, row_pos, col_pos, matrix, pos_1, point, goal, max);
				cout << endl;

				wait_for_enter("进行数组下落除0操作");

				drop_down(row, col, row_pos, col_pos, matrix, pos_1);
				cout << endl;

				wait_for_enter("进行新值填充");

				fill_new_val(row, col, matrix, pos_1, max);
				cout << endl;

				break;
			}
			else if (sel == 'N')
			{
				cout << endl;
				continue;
			}
			else if (sel == 'Q')
			{
				is_continue = 0;
				cout << endl;
				break;
			}
		}
		else
		{
			cout << "游戏失败" << endl;//所有数字无法合并，游戏失败
			break;
		}
	}
	if (is_continue == 0)
		break;

	/*完成一次合并后*/
	cout << "本次合成结束，";
	wait_for_enter("新一次的合成");

	if (max >= goal)
	{
		goal = max + 1;
		cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
		cout << "已经合成到" << max;
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);;//恢复缺省颜色
		cout << endl;

		wait_for_enter("向更高目标进发");
	}
}

input_End();



int main()
{
	char pos[3] = { 0 };
	cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
	for (int i = 0; i < 5; i++)
	{
		cin.get(pos, 3);
		cout << pos << '*' << endl;
	}

	

	return 0;
}
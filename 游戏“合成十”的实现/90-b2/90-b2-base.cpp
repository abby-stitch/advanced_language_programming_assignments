/* 1850917 ���� ��ʫ�� */
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
/*���ڲ����鷽ʽʵ�ֵĸ�����*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������ֵ
  ���������const int row, ����
			const int col, ����
			int matrix[][N], ���������ľ���
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ���ʾ����
  ���������int mode, ģʽ��
							1. ��ʾ"��ǰ���飺"
							2. ��ʾ"���ҽ�����飺"
							//3. ��ʾ"��ǰ����(��ͬɫ��ʶ)��"
			char* prompt,
			const int row, ����
			const int col, ����
			int str[][N], Ҫ��ʾ�ľ���
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_matrix(int mode,const char *prompt, const int row, const int col, int str[][N])
{
	cout << prompt << endl;
	/*����*/
	cout << setw(2) << ' ';
	cout << '|';
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;
	}
	cout << endl;
	/*�ֽ���*/
	cout << "--+";
	for (int i = 0; i < col; i++)
	{
		cout << "---";
	}
	cout << endl;
	/*��ӡ����*/
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
  �������ƣ�
  ��    �ܣ���ʾ����(��ͬɫ��ʶ)
  ���������const int row, ����
			const int col, ����
			int matrix[][N], ���������ľ���
			int pos[][N], ���λ����Ϣ�ľ���
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_matrix_color(const char *prompt,const int row, const int col, int matrix[][N],int pos[][N])
{
	cout << prompt << "(��ͬɫ��ʶ)��" << endl;
	/*����*/
	cout << setw(2) << ' ';
	cout << '|';
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;
	}
	cout << endl;
	/*�ֽ���*/
	cout << "--+";
	for (int i = 0; i < col; i++)
	{
		cout << "---";
	}
	cout << endl;
	/*��ӡ����*/
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
  �������ƣ�
  ��    �ܣ��жϸ�λ���Ƿ������ڵ���ֵͬ
  ���������const int row, ����
			const int col, ����
			const int row_pos, λ��������
			const int col_pos, λ��������
			int matrix[][N]�� �����ֵ������
  �� �� ֵ��1 ��λ�������ڵ���ֵͬ
			0 ��λ�������ڵ���ֵͬ
  ˵    ����
***************************************************************************/
int is_adjacent_same(const int row, const int col, const int row_pos, const int col_pos, int matrix[][N])
{
	int val = matrix[row_pos][col_pos];

	//��
	if (matrix[row_pos - 1][col_pos] == val && row_pos > 0)
		return 1;
	//��
	else if (matrix[row_pos + 1][col_pos] == val && row_pos < row - 1)
		return 1;
	//��
	else if (matrix[row_pos][col_pos - 1] == val && col_pos > 0)
		return 1;
	//��
	else if (matrix[row_pos][col_pos + 1] == val && col_pos < col - 1)
		return 1;
	else
		return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������������ڵ�������ֵͬ����������ֵ��ͬ��(�ǵݹ鷽ʽ)
  ���������const int row, ����
			const int col, ����
			const int row_pos, λ��������
			const int col_pos, λ��������
			int matrix[][N]�� �����ֵ������
			int pos[][N], ���λ����Ϣ������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void seek_same_val_nonrecursive(const int row, const int col,int row_pos, int col_pos,int matrix[][N], int pos[][N])
{
	int val = matrix[row_pos][col_pos];//�������ֵ
	pos[row_pos][col_pos] = 1;

	int r = 0;
	int c = 0;//�Ƚ�λ��

	/*�ȴ�row_pos�п�ʼ���ϡ�����һ���в���*/
	/*ÿ�д�col_pos�п�ʼ��������һ���в��ң����ҵ���������ֵͬpos��1*/

	r = row_pos;//��row_pos�п�ʼ

	c = col_pos;//��col_pos�п�ʼ����
	c--;
	while (c >= 0)
	{
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;
			c--;
		}
		else
			break;//���м������������ڵ���ֵͬ
	}

	c = col_pos;//��col_pos�п�ʼ����
	c++;
	while (c < col)
	{
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;
			c++;
		}
		else
			break;//���м������������ڵ���ֵͬ
	}

	r = row_pos - 1;//��row_pos�п�ʼ����
	while (r >= 0)
	{
		c = col_pos;
		if (matrix[r][c] == val && pos[r + 1][c] == 1)//ֵ������·�Ϊ������ֵͬ
		{
			pos[r][c] = 1;
		}

		c = col_pos;//��col_pos�п�ʼ����
		c--;

		while (c >= 0)
		{
			if (matrix[r][c] == val && (pos[r + 1][c] == 1 || pos[r][c + 1] == 1))//ֵ������·�Ϊ������ֵͬ���ҷ�Ϊ������ֵͬ
			{
				pos[r][c] = 1;
				if (matrix[r + 1][c] == val && pos[r + 1][c] == 0)//���·�δ�������е�col_posλ����������ҲΪ��ֵͬ
					pos[r + 1][c] = 1;
				if (matrix[r][c + 1] == val && pos[r][c + 1] == 0)//���ҷ�δ�������е�col_posλ����������ҲΪ��ֵͬ
					pos[r][c + 1] = 1;
			}
			
			c--;
		}

		c = col_pos;//��col_pos�п�ʼ����
		c++;
		while (c < col)
		{
			if (matrix[r][c] == val && (pos[r + 1][c] == 1 || pos[r][c - 1] == 1))//ֵ������·�Ϊ������ֵͬ����Ϊ������ֵͬ
			{
				pos[r][c] = 1;
				if (matrix[r + 1][c] == val && pos[r + 1][c] == 0)//���·�δ�������е�col_posλ����������ҲΪ��ֵͬ
					pos[r + 1][c] = 1;
				if (matrix[r][c - 1] == val && pos[r][c - 1] == 0)//����δ�������е�col_posλ����������ҲΪ��ֵͬ
					pos[r][c - 1] = 1;
			}
			c++;
		}

		r--;
	}

	r = row_pos + 1;//��row_pos�п�ʼ����
	while (r < row)
	{
		c = col_pos;
		if (matrix[r][c] == val && pos[r - 1][c] == 1)//ֵ������·�Ϊ������ֵͬ
		{
			pos[r][c] = 1;
		}
		c = col_pos;//��col_pos�п�ʼ����
		c--;
		while (c >= 0)
		{
			if (matrix[r][c] == val && (pos[r - 1][c] == 1 || pos[r][c + 1] == 1))//ֵ������Ϸ�Ϊ������ֵͬ���ҷ�Ϊ������ֵͬ
			{
				pos[r][c] = 1;
				if (matrix[r - 1][c] == val && pos[r - 1][c] == 0)//���Ϸ�δ�������е�col_posλ����������ҲΪ��ֵͬ
					pos[r - 1][c] = 1;
				if (matrix[r][c + 1] == val && pos[r][c + 1] == 0)//���ҷ�δ�������е�col_posλ����������ҲΪ��ֵͬ
					pos[r][c + 1] = 1;
			}
			c--;
		}

		c = col_pos;//��col_pos�п�ʼ����
		c++;
		while (c < col)
		{
			if (matrix[r][c] == val && (pos[r - 1][c] == 1 || pos[r][c - 1] == 1))//ֵ������Ϸ�Ϊ������ֵͬ����Ϊ������ֵͬ
			{
				pos[r][c] = 1;
				if (matrix[r - 1][c] == val && pos[r - 1][c] == 0)//���Ϸ�δ�������е�col_posλ����������ҲΪ��ֵͬ
					pos[r - 1][c] = 1;
				if (matrix[r][c - 1] == val && pos[r][c - 1] == 0)//����δ�������е�col_posλ����������ҲΪ��ֵͬ
					pos[r][c - 1] = 1;
			}
			c++;
		}

		r++;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������������ڵ�������ֵͬ����������ֵ��ͬ��(�ݹ鷽ʽ)
  ���������const int row, ����
			const int col, ����
			int row_pos, λ��������
			int col_pos, λ��������
			int matrix[][N]�� �����ֵ������
			int pos[][N], ���λ����Ϣ������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void seek_same_val_recursive(const int row, const int col, int row_pos, int col_pos, int matrix[][N], int pos[][N])
{
	//�ӣ�row_pos,col_pos����ʼ�������������Ƿ���ֵ��ͬ�ģ�
	//���У���pos��1������������λ���ң�
	//��ĳλ�õ�pos����1��˵����λ���ѱ����ҹ����򲻼�������
	if (row_pos >= 0 && row_pos < row && col_pos >= 0 && col_pos < col && pos[row_pos][col_pos] == 0)
	{
		int val = matrix[row_pos][col_pos];//�������ֵ
		pos[row_pos][col_pos] = 1;

		//��
		if (matrix[row_pos - 1][col_pos] == val)
			seek_same_val_recursive(row, col, row_pos - 1, col_pos, matrix, pos);
		//��
		if (matrix[row_pos + 1][col_pos] == val)
			seek_same_val_recursive(row, col, row_pos + 1, col_pos, matrix, pos);
		//��
		if (matrix[row_pos][col_pos - 1] == val)
			seek_same_val_recursive(row, col, row_pos, col_pos - 1, matrix, pos);
		//��
		if (matrix[row_pos][col_pos + 1] == val)
			seek_same_val_recursive(row, col, row_pos, col_pos + 1, matrix, pos);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������ڵ���ֵͬ�ϲ�
  ���������const int row, ����
			const int col, ����
			const int row_pos, λ��������
			const int col_pos, λ��������
			int matrix[][N]�� �����ֵ������
			int pos[][N], ���λ����Ϣ������
			int &point, �ܷ�
			int goal, Ŀ�����
			int &max, Ŀǰ�����е����ֵ
  �� �� ֵ��
  ˵    ����
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
					matrix[i][j]++;//�ϲ���ֵ+1
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
		print_matrix_color("��ֵͬ�鲢�������", row, col, matrix, pos);
		cout << "���ε÷֣�" << add_point << ' ';
		cout << "�ܵ÷֣�" << point << ' ';
		cout << "�ϳ�Ŀ�꣺" << goal << endl;
	}
	else if (mode == 1)
	{
		int x, y;
		cct_getxy(x, y);
		cct_gotoxy(0, 0);
		cout << "���ε÷֣�" << add_point << ' ';
		cout << "�ܵ÷֣�" << point << ' ';
		cout << "�ϳ�Ŀ�꣺" << goal << endl;
		cct_gotoxy(x, y);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������0
  ���������const int row, ����
			const int col, ����
			const int row_pos, λ��������
			const int col_pos, λ��������
			int matrix[][N]�� �����ֵ������
			int pos[][N], ���λ����Ϣ������
			int mode,
				0��0�����ƶ�����ӡ��0������
				1�����ϲ�λ����Ϣ����
				2��0�����ƶ�������ӡ����
  �� �� ֵ��
  ˵    ����
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

		print_matrix_color("��0�������", row, col, matrix, pos);
	}
	else if (mode == 1)
	{
		pos[row_pos][col_pos] = 0;//�Ȳ��ı����������Ϣ
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
  �������ƣ�
  ��    �ܣ���ֵ���
  ���������const int row, ����
			const int col, ����
			int matrix[][N]�� �����ֵ������
			int pos[][N], ���λ����Ϣ������
			const int max, Ŀǰ�����е����ֵ

  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fill_new_val(const int row, const int col, int matrix[][N], int pos[][N],const int max,int mode)
{
	int count = 0;//��¼pos����1λ�õĸ�������������Ϊ0����Ҫ�����ֵ��λ�ø���
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
		print_matrix_color("��ֵ���������", row, col, matrix, pos);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж����������Ƿ��������λ�����
  ���������const int row, ����
			const int col, ����
			int matrix[][N]�� �����ֵ������
			int pos[][N], ���λ����Ϣ������
  �� �� ֵ��1 �����������ڵ���ֵͬ
			0 �����������ڵ���ֵͬ
  ˵    ����
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


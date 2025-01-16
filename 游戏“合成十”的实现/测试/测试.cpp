#include <iostream>
#include <conio.h>

using namespace std;
#define M 8
#define N 10
#define START_MAX 3
#define TIME 50

void seek_same_val(const int row, const int col, int row_pos, int col_pos, int matrix[][N], int pos[][N])
{
	int val = matrix[row_pos][col_pos];//�������ֵ

	int r = 0;
	int c = 0;//�Ƚ�λ��
	int up = 1, down = 1, left = 1, right = 1;//���������Ƿ�����ֵͬ�ı��

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
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;

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

			r--;
		}
		else
			break;//�������������ڵ���ֵͬ
	}

	r = row_pos + 1;//��row_pos�п�ʼ����
	while (r < row)
	{
		c = col_pos;
		if (matrix[r][c] == val)
		{
			pos[r][c] = 1;

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

			r++;
		}
		else
			break;//�������������ڵ���ֵͬ
	}


	/*�ٴ�col_pos�п�ʼ��������һ���в���*/
	/*ÿ�д�row_pos�п�ʼ���ϡ�����һ���в��ң����ҵ���������ֵͬpos��1*/




	//��
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




	//��
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
	//��
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


	/*����һ��һ����*/
	//����
	r = row_pos;
	//����
	if (left)
	{
		c = col_pos;//�б仯
		c--;
		while (c >= 0)
		{
			if (matrix[r][c] == val)
				pos[r][c] = 1;
			c--;
		}
	}
	//����
	if (right)
	{
		c = col_pos;//�б仯
		c++;
		while (c < col)
		{
			if (matrix[r][c] == val)
				pos[r][c] = 1;
			c++;
		}
	}

	//����һ��һ����
	if (up)
	{
		r = row_pos - 1;//��row_pos����һ�п�ʼ

		while (r >= 0)
		{
			//����
			c = col_pos;//�б仯
			c--;
			while (c >= 0)
			{
				if (matrix[r][c] == val)
					pos[r][c] = 1;
				c--;
			}
			//����
			c = col_pos;//�б仯
			c++;
			while (c < col)
			{
				if (matrix[r][c] == val)
					pos[r][c] = 1;
				c++;
			}

			r--;//���м�����
		}
	}

}

cct_cls();

int is_continue = 1;//�����������޷��ϲ�������0

/*������������Ŀ��ֵ*/
input_int("����������(5-8)��", 5, 9, row);//��������
input_int("����������(5-10)��", 5, 11, col);//��������
input_int("������ϳ�Ŀ��(5-20)��", 5, 21, goal);//����ϳ�Ŀ��

generate_matrix(row, col, matrix);

while (1)
{
	if (is_array_adjacent_same(row, col, matrix))
		is_continue = 1;
	else
		is_continue = 0;

	/*һ�κϲ�*/
	while (1)
	{
		/*���ü�¼λ������*/
		reset(row, col, pos_1);

		cout << endl;
		print_matrix(1, "��ǰ���飺", row, col, matrix);
		cout << endl;

		if (is_continue)
		{
			/*�����������*/
			input_coordinate(row, col, row_pos, col_pos, matrix);

			/*��������ֵͬ���ݹ鷽ʽ��*/
			seek_same_val_recursive(row, col, row_pos, col_pos, matrix, pos_1);

			cout << endl;
			print_matrix(2, "���ҽ�����飺", row, col, pos_1);
			cout << endl;

			cout << endl;
			print_matrix_color("��ǰ����", row, col, matrix, pos_1);
			cout << endl;

			/*ѡ���Ƿ�ϲ�*/
			char sel = input_is_merge(row_pos, col_pos);

			if (sel == 'Y')//��ɱ��κϲ�
			{
				/*�ϲ����ڵ���ֵͬ������ʾ*/
				cout << endl;
				merge(row, col, row_pos, col_pos, matrix, pos_1, point, goal, max);
				cout << endl;

				wait_for_enter("�������������0����");

				drop_down(row, col, row_pos, col_pos, matrix, pos_1);
				cout << endl;

				wait_for_enter("������ֵ���");

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
			cout << "��Ϸʧ��" << endl;//���������޷��ϲ�����Ϸʧ��
			break;
		}
	}
	if (is_continue == 0)
		break;

	/*���һ�κϲ���*/
	cout << "���κϳɽ�����";
	wait_for_enter("��һ�εĺϳ�");

	if (max >= goal)
	{
		goal = max + 1;
		cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
		cout << "�Ѿ��ϳɵ�" << max;
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);;//�ָ�ȱʡ��ɫ
		cout << endl;

		wait_for_enter("�����Ŀ�����");
	}
}

input_End();



int main()
{
	char pos[3] = { 0 };
	cout << "������ĸ+������ʽ[����c2]����������꣺";
	for (int i = 0; i < 5; i++)
	{
		cin.get(pos, 3);
		cout << pos << '*' << endl;
	}

	

	return 0;
}
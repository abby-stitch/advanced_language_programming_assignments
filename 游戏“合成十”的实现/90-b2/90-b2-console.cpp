/* 1850917 ���� ��ʫ�� */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;
/*��cmdαͼ�ν��淽ʽʵ�ֵĸ�����*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ǰ�������
  ���������int x_pos, ���鷽�����Ͻ�x����
			int y_pos, ���鷽�����Ͻ�y����
			const int row, ��������
			const int col, ��������
			int mode, ģʽ
					1������ɫ����޷ָ���
					2������ɫ����зָ���
					3������ɫ����зָ���(��ʱ������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void show_outer_frame(int x_pos, int y_pos,const int row, const int col,int mode)
{
	int line =0;//������
	int column = 0;//������

	int x = 0, y = 0;//�������

	switch (mode)
	{
		case 1://����ɫ����޷ָ���
		{
			line = row * 3 + 7;//������
			column = col * 6 + 5;//������

			/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
			cct_setconsoleborder(column, line, column, 9000);

			cct_setcolor(COLOR_WHITE, COLOR_BLACK);

			/*�Ϻ���*/
			cct_gotoxy(x_pos, y_pos);

			cout << "�X";

			Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "�T�T�T";

				Sleep(TIME);
			}

			cout << "�[";

			Sleep(TIME);

			cct_getxy(x, y);
			/*cout << "x=" << x << endl;
			cout << "y=" << y << endl;*/

			/*��ӡ��������*/
			for (int i = 0; i < 3 * row; i++)
			{
				y++;
				for (int j = 0; j < col; j++)
				{

					if (j == 0)
					{
						cct_gotoxy(0, y);

						cout << "�U";

						Sleep(TIME);
					}
					else if (j = col - 1)
					{
						cct_gotoxy(x - 2, y);

						cout << "�U";

						Sleep(TIME);
					}
				}
			}

			cct_getxy(x, y);

			/*�º���*/
			cct_gotoxy(0, y + 1);

			cout << "�^";

			Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "�T�T�T";

				Sleep(TIME);
			}

			cout << "�a";

			Sleep(TIME);

			cct_setcolor();
			break;
		}
		case 2://����ɫ����зָ���
		{
			line = row * 3 + row - 1 + 7;//������
			column = col * 6 + (col - 1) * 2 + 5;//������

			/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
			cct_setconsoleborder(column, line, column, 9000);

			cct_setcolor(COLOR_WHITE, COLOR_BLACK);

			/*�Ϻ���*/
			cct_gotoxy(x_pos, y_pos);
			cout << "�X";
			Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "�T�T�T";
				if (i != col - 1)
					cout << "�h";

				Sleep(TIME);
			}

			cout << "�[";

			Sleep(TIME);

			cct_getxy(x, y);

			/*cout << "x=" << x << endl;
			cout << "y=" << y << endl;*/

			/*��ӡ��������*/
			for (int i = 0; i < 3 * row; i++)
			{
				y++;//����һ��

				for (int j = 0; j < col; j++)
				{

					if (j == 0)
					{

						if (i % 3 == 0 && i != 0)
						{
							cct_gotoxy(0, y);

							cout << "�c";

							/*��ӡ�м�ָ�����*/
							for (int k = 0; k < col; k++)
							{
								cout << "������";
								if (k != col - 1)
									cout << "��";

								Sleep(TIME);
							}
							cout << "�f";

							y++;//����һ��
						}

						cct_gotoxy(0, y);

						cout << "�U";

						/*��ӡ�м�ָ�����*/
						for (int k = 0; k < col; k++)
						{
							cout << setw(6) << ' ';
							if (k == col - 1)
								cout << "�U";
							else
								cout << "��";

							Sleep(TIME);
						}
					}
				}
			}

			cct_getxy(x, y);

			/*�º���*/
			cct_gotoxy(0, y + 1);

			cout << "�^";

			Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "�T�T�T";
				if (i != col - 1)
					cout << "�k";
				Sleep(TIME);
			}

			cout << "�a";

			Sleep(TIME);

			cct_setcolor();

			break;
		}
		case 3://����ɫ����зָ���(��ʱ������
		{
			line = row * 3 + row - 1 + 7;//������
			column = col * 6 + (col - 1) * 2 + 5;//������

			/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
			cct_setconsoleborder(column, line, column, 9000);

			cct_setcolor(COLOR_WHITE, COLOR_BLACK);

			/*�Ϻ���*/
			cct_gotoxy(x_pos, y_pos);
			cout << "�X";
			//Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "�T�T�T";
				if (i != col - 1)
					cout << "�h";

				//Sleep(TIME);
			}

			cout << "�[";

			//Sleep(TIME);

			cct_getxy(x, y);

			/*cout << "x=" << x << endl;
			cout << "y=" << y << endl;*/

			/*��ӡ��������*/
			for (int i = 0; i < 3 * row; i++)
			{
				y++;//����һ��

				for (int j = 0; j < col; j++)
				{

					if (j == 0)
					{

						if (i % 3 == 0 && i != 0)
						{
							cct_gotoxy(0, y);

							cout << "�c";

							/*��ӡ�м�ָ�����*/
							for (int k = 0; k < col; k++)
							{
								cout << "������";
								if (k != col - 1)
									cout << "��";

								//Sleep(TIME);
							}
							cout << "�f";

							y++;//����һ��
						}

						cct_gotoxy(0, y);

						cout << "�U";

						/*��ӡ�м�ָ�����*/
						for (int k = 0; k < col; k++)
						{
							cout << setw(6) << ' ';
							if (k == col - 1)
								cout << "�U";
							else
								cout << "��";

							//Sleep(TIME);
						}
					}
				}
			}

			cct_getxy(x, y);

			/*�º���*/
			cct_gotoxy(0, y + 1);

			cout << "�^";

			//Sleep(TIME);

			for (int i = 0; i < col; i++)
			{
				cout << "�T�T�T";
				if (i != col - 1)
					cout << "�k";
				//Sleep(TIME);
			}

			cout << "�a";

			//Sleep(TIME);

			cct_setcolor();

			break;
		}
	}
	

	cct_setcolor();
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾÿ��С��
  ���������const int x, ÿС�����Ͻǵ�x����
			const int y, ÿС�����Ͻǵ�y����
			int val, С������ʾ��ֵ
			int mode,
				0����ɫ��ֵ�й�
				1���ÿ�Ϊ����ɫ
  �� �� ֵ��
  ˵    ����
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
	cout << "�X";
	cout << "�T";
	cout << "�[";

	cct_gotoxy(x, y + 1);
	cout << "�U";
	cout << setw(2) << val;
	cout << "�U";

	cct_gotoxy(x, y + 2);
	cout << "�^";
	cout << "�T";
	cout << "�a";

	cct_setcolor();

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ�����������С��
  ���������int x_pos, ���鷽�����Ͻ�x����
			int y_pos, ���鷽�����Ͻ�y���� 
			const int row, ��������
			const int col, ��������
			int matrix[][N],
			int mode, ģʽ
					1������ɫ����޷ָ���
					2������ɫ����зָ���
					3������ɫ����зָ���(��ʱ������+�ü�ͷ���ƶ����س���ѡ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void show_arr_cube(int x_pos, int y_pos, const int row, const int col, int matrix[][N],int mode)
{
	int line = 0;//������
	int column = 0;//������

	int x = x_pos + 2;
	int y = y_pos + 1;

	switch (mode)
	{
		case 1://����ɫ����޷ָ���
		{
			line = row * 3 + 7;//������
			column = col * 6 + 5;//������

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
			cout << "��Ļ��ǰ����Ϊ��" << line << "��" << column << "��";
			cct_gotoxy(x_pos, y_pos + row * 3 + 2);

			break;
		}
		case 2://����ɫ����зָ���
		{
			line = row * 3 + row - 1 + 7;//������
			column = col * 6 + (col - 1) * 2 + 5;//������

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
			cout << "��Ļ��ǰ����Ϊ��" << line << "��" << column << "��";
			cct_gotoxy(x_pos, y_pos + row * 4 + 1);

			break;
		}
		case 3://����ɫ����зָ���(��ʱ������
		{
			line = row * 3 + row - 1 + 7;//������
			column = col * 6 + (col - 1) * 2 + 5;//������

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
			cout << "��Ļ��ǰ����Ϊ��" << line << "��" << column << "��";

			break;
		}
	}	
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�αͼ�ν�������ʾ��ǰ��ѡɫ��
  ���������const int x, ÿС�����Ͻǵ�x����
			const int y, ÿС�����Ͻǵ�y����
			int val, С������ʾ��ֵ
  �� �� ֵ��
  ˵    ����
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
	cout << "�X";
	cout << "�T";
	cout << "�[";

	cct_gotoxy(x, y + 1);
	cout << "�U";
	cout << setw(2) << val;
	cout << "�U";

	cct_gotoxy(x, y + 2);
	cout << "�^";
	cout << "�T";
	cout << "�a";

	cct_setcolor();
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�αͼ�ν������ü�ͷѡ��ǰɫ��
  ���������int x_pos, ���鷽�����Ͻ�x����
			int y_pos, ���鷽�����Ͻ�y����
			int& row_pos, 
			int& col_pos, ��ʼ�ƶ��ĳ�ʼ���꣬�Լ��仯�������
			const int row, ��������
			const int col, ��������
			int matrix[][N],
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void move_by_arrow(const int x_pos, const int y_pos, int& row_pos, int& col_pos, const int row, const int col, int matrix[][N],int pos[][N],int mode)
{
	cct_setcursor(CURSOR_INVISIBLE);//���ù�겻��ʾ

	cct_gotoxy(x_pos, y_pos + row * 4 + 1);
	cout << "��ͷ���ƶ����س���ѡ��";
	
	int x = x_pos + 2;//���x����
	int y = y_pos + 1;//���y����

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
				//����ѡ��
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
				//����ѡ��
				if (is_adjacent_same(row, col, row_pos, col_pos, matrix))
				{
					cct_gotoxy(x_pos, y_pos + row * 4 + 1);
					cout << setw(50) << ' ';

					cct_gotoxy(x_pos, y_pos + row * 4 + 1);
					cout << "��ͷ���ƶ���ȡ����ǰѡ�񣬻س����ϳ�";
					mode = 0;

					/*��������ֵͬ���ݹ鷽ʽ��*/
					seek_same_val_recursive(row, col, row_pos, col_pos, matrix, pos);

					/*��ʾ������ֵͬ*/
					show_arr(x_pos, y_pos, row, col, matrix, pos);
					
					/*��ѡλ�õ�ǰ��ɫ��Ϊ��ɫ*/
					show_sel_cube(x, y, matrix[row_pos][col_pos], 1);

					continue;
				}
				else
				{
					cct_gotoxy(x_pos, y_pos + row * 4 + 1);
					cout << setw(50) << ' ';

					cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cct_gotoxy(x_pos, y_pos + row * 4 + 1);
					cout << "��Χ����ֵͬ��";
					cct_setcolor();

					cout << "��ͷ���ƶ����س���ѡ��";
					continue;
				}
			}
		}

		mode = 1;
		show_cube(x, y, matrix[row_pos][col_pos]);//�ָ�δѡ��ʱ��ɫ
		show_arr(x_pos, y_pos, row, col, matrix, pos, 1);//�ָ�δѡ��ʱ��ɫ

		/*���ü�¼λ������*/
		reset(row, col, pos);

		if (mode == 1)
		{
			cct_gotoxy(x_pos, y_pos + row * 4 + 1);
			cout << setw(50) << ' ';
			cct_gotoxy(x_pos, y_pos + row * 4 + 1);
			cout << "��ͷ���ƶ����س���ѡ��";
		}

		/*�ü�ͷ���й���ƶ�*/
		if (int(chInput) == -32)
		{
			chInput = _getch();
			if (int(chInput) == 72)//��
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
			else if (int(chInput) == 80)//��
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
			else if (int(chInput) == 75)//��
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
			else if (int(chInput) == 77)//��
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
  �������ƣ�
  ��    �ܣ�αͼ�ν�������ʾ��ǰ����������ֵͬɫ��Ĳ�ͬ����
  ���������const int row, ����
			const int col, ����
			int matrix[][N], ���������ľ���
			int pos[][N], ���λ����Ϣ�ľ���
			int mode, 
			0����ʾ������ѡ��λ��������ֵͬɫ��
			1���ָ�������������ֵͬɫ��
			2����������
			3����ʾ��ֵ

  �� �� ֵ��
  ˵    ����
***************************************************************************/
void show_arr(int x_pos, int y_pos, const int row, const int col, int matrix[][N], int pos[][N],int mode)
{
	int x_start, y_start;
	cct_getxy(x_start, y_start);

	int x = 0;//���x����
	int y = 0;//���y����
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
  �������ƣ�
  ��    �ܣ�αͼ�ν�������ʾ���������0
  ���������int x_pos, ���鷽�����Ͻ�x����
			int y_pos, ���鷽�����Ͻ�y����
			const int row, ����
			const int col, ����
			int matrix[][N]�� �����ֵ������
			int pos[][N], ���λ����Ϣ������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fall_down(const int x_pos, const int y_pos, const int row, const int col, const int row_pos, const int col_pos, int matrix[][N], int pos[][N])
{
	/*int row_pos = 0;
	int col_pos = 0;*/

	int x = 0;
	int y = 0;


	for (int i = 0; i < col; i++)//��
	{
		for (int j = row - 1; j > 0; j--)//��
		{
			if (pos[j][i])//0��λ��
			{
				for (int top = j; top >=0; top--)//�����Ҳ�Ϊ���λ��
				{
					if (pos[top][i]==0)//��Ϊ���λ��
					{
						pos[top][i] = -1;
						int move_top = top;

						x = x_pos + 2 + i * 8;
						y = y_pos + 1 + top * 4;
						int val = matrix[top][i];

						while (move_top <j)//�����ƶ�
						{
							for (int p = 0; p < 4; p++)
							{
								show_cube(x, y, val, 1);
								Sleep(TIME);
								y++;
								show_cube(x, y, val);
								Sleep(TIME);
							}
							/*������*/
							cct_gotoxy(x, y - 1);
							cct_setcolor(COLOR_WHITE, COLOR_BLACK);
							cout << "������";
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


/* 1850917 ���� ��ʫ�� */
/*���������˵����ֺ���*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
	�������ƣ�
	��    �ܣ��˵�����ʾ��ѡ��
	���������
	�� �� ֵ��
	˵    ����
  ***************************************************************************/
char printAndselctMenu()
{
	char sel;
	cout << "-----------------------------------" << endl;
	cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
	cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
	cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
	cout << "4.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
	cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
	cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
	cout << "7.αͼ�ν������ü�ͷ��ѡ��ǰɫ��" << endl;
	cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
	cout << "9.αͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "-----------------------------------" << endl;
	cout << "[��ѡ��0-9] ";

	while (1)
	{
		//cct_gotoxy(10, 12);
		sel = _getche();

		if (sel == '0' ||
			sel == '1' ||
			sel == '2' ||
			sel == '3' ||
			sel == '4' ||
			sel == '5' ||
			sel == '6' ||
			sel == '7' ||
			sel == '8' ||
			sel == '9')

			break;
	}

	cout << endl;
	cout << endl;
	cout << endl;

	return sel;
}



int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	char mode;

	

	while (1)
	{
		/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
		cct_setconsoleborder(120, 40, 120, 9000);

		int max = START_MAX;//�����е����ֵ

		int row = 0;//����
		int col = 0;//����
		
		int goal = 0;//�ϳ�Ŀ��ֵ
		int point = 0;//�ܷ���

		int matrix[M][N] = { 0 };//������ֵ�ľ���
		int pos_1[M][N] = { 0 };//��¼ֵͬλ��
		//int pos_2[M][N] = { 0 };//��¼ֵͬλ��

		int row_pos = 0;
		int col_pos = 0;

		/*�˵�����ʾ��ѡ��*/
		mode = printAndselctMenu();

		/*��ѡ���˳���ֱ���˳�*/
		if (mode == '0')
			break;

		switch (mode)
		{
			case '1'://1.�������ҳ��ɺϳ����ʶ���ǵݹ飩
			{
				/*����*/
				cct_cls();

				/*����������*/
				input_int("����������(5-8)��", 5, 9, row);//��������
				input_int("����������(5-10)��", 5, 11, col);//��������

				/*�������ֵ����*/
				generate_matrix(row, col, matrix);

				/*��ʾ��ǰ����*/
				cout << endl;
				print_matrix(1, "��ǰ���飺", row, col, matrix);
				cout << endl;
				
				if (is_array_adjacent_same(row, col, matrix))
				{
					/*�����������*/
					input_coordinate(row, col, row_pos, col_pos, matrix);

					/*��������ֵͬ���ǵݹ鷽ʽ��*/
					seek_same_val_nonrecursive(row, col, row_pos, col_pos, matrix, pos_1);

					/*��ʾ���ҽ������*/
					cout << endl;
					print_matrix(2, "���ҽ�����飺", row, col, pos_1);
					cout << endl;

					/*��ʾ��ǰ���飨��ͬɫ��ʶ��*/
					cout << endl;
					print_matrix_color("��ǰ����", row, col, matrix, pos_1);
					cout << endl;
				}
				else
				{
					cout << "��Ϸʧ��" << endl;//���������޷��ϲ�����Ϸʧ��
				}
				/*����������End*/
				input_End();
				break;
			}
			case '2'://2.�������ҳ��ɺϳ����ʶ���ݹ飩
			{
				/*����*/
				cct_cls();

				/*����������*/
				input_int("����������(5-8)��", 5, 9, row);//��������
				input_int("����������(5-10)��", 5, 11, col);//��������

				/*�������ֵ����*/
				generate_matrix(row, col, matrix);

				/*��ʾ��ǰ����*/
				cout << endl;
				print_matrix(1, "��ǰ���飺", row, col, matrix);
				cout << endl;

				if (is_array_adjacent_same(row, col, matrix))
				{
					/*�����������*/
					input_coordinate(row, col, row_pos, col_pos, matrix);

					/*��������ֵͬ���ݹ鷽ʽ��*/
					seek_same_val_recursive(row, col, row_pos, col_pos, matrix, pos_1);

					/*��ʾ���ҽ������*/
					cout << endl;
					print_matrix(2, "���ҽ�����飺", row, col, pos_1);
					cout << endl;

					/*��ʾ��ǰ���飨��ͬɫ��ʶ��*/
					cout << endl;
					print_matrix_color("��ǰ����", row, col, matrix, pos_1);
					cout << endl;
				}
				else
				{
					cout << "��Ϸʧ��" << endl;//���������޷��ϲ�����Ϸʧ��
				}

				/*����������End*/
				input_End();
				break;
			}
			case '3'://3.���������һ�κϳɣ��ֲ�����ʾ��
			{
				cct_cls();

				/*������������Ŀ��ֵ*/
				input_int("����������(5-8)��", 5, 9, row);//��������
				input_int("����������(5-10)��", 5, 11, col);//��������
				input_int("������ϳ�Ŀ��(5-20)��", 5, 21, goal);//����ϳ�Ŀ��

				generate_matrix(row, col, matrix);


				cout << endl;
				print_matrix(1, "��ǰ���飺", row, col, matrix);
				cout << endl;

				if (is_array_adjacent_same(row, col, matrix))
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

						//break;
					}
					else if (sel == 'N')
					{
						cout << endl;
						//reset(row, col, pos_1);
						//continue;
					}
					else if (sel == 'Q')
					{
						cout << endl;
						//break;
					}
				}
				else
				{
					cout << "��Ϸʧ��" << endl;//���������޷��ϲ�����Ϸʧ��
				}
				input_End();
				break;
			}
			case '4'://4.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�
			{
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
						cout << "�Ѿ��ϳɵ�" << max ;
						cct_setcolor(COLOR_BLACK, COLOR_WHITE);;//�ָ�ȱʡ��ɫ
						cout << endl;

						wait_for_enter("�����Ŀ�����");
					}
				}

				input_End();
				break;
			}
			case '5'://5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�
			{
				/*����*/
				cct_cls();

				/*����������*/
				input_int("����������(5-8)��", 5, 9, row);//��������
				input_int("����������(5-10)��", 5, 11, col);//��������

				/*�������ֵ����*/
				generate_matrix(row, col, matrix);

				/*��ӡ���*/
				show_outer_frame(0, 1, row, col, 1);

				/*��ӡ�ڲ�����*/
				show_arr_cube(0, 1, row, col, matrix, 1);

				input_End();
				break;
			}
			case '6'://6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�
			{
				/*����*/
				cct_cls();

				/*����������*/
				input_int("����������(5-8)��", 5, 9, row);//��������
				input_int("����������(5-10)��", 5, 11, col);//��������

				/*�������ֵ����*/
				generate_matrix(row, col, matrix);

				/*��ӡ���*/
				show_outer_frame(0, 1, row, col, 2);

				/*��ӡ�ڲ�����*/
				show_arr_cube(0, 1, row, col, matrix, 2);

				input_End();
				break;
			}
			case '7'://7.αͼ�ν������ü�ͷ��ѡ��ǰɫ��
			{
				/*����*/
				cct_cls();

				/*����������*/
				input_int("����������(5-8)��", 5, 9, row);//��������
				input_int("����������(5-10)��", 5, 11, col);//��������

				/*�������ֵ����*/
				generate_matrix(row, col, matrix);

				/*��ӡ���*/
				show_outer_frame(0, 1, row, col, 3);

				/*��ӡ�ڲ�����*/
				show_arr_cube(0, 1, row, col, matrix, 3);

				/*�ü�ͷ���ƶ����س���ѡ��*/
				/*row_pos = 0;
				col_pos = 0;*/
				move_by_arrow(0, 1, row_pos, col_pos, row, col, matrix, pos_1);//��matirx[0][0]��ʼ�ƶ�

				input_End();
				break;			
			}
			case '8'://8.αͼ�ν������һ�κϳɣ��ֲ��裩"
			{
				/*����*/
				cct_cls();
				int is_continue = 1;//�����������޷��ϲ�������0

				/*����������*/
				input_int("����������(5-8)��", 5, 9, row);//��������
				input_int("����������(5-10)��", 5, 11, col);//��������
				input_int("������ϳ�Ŀ��(5-20)��", 5, 21, goal);//����ϳ�Ŀ��

				/*�������ֵ����*/
				generate_matrix(row, col, matrix);

				/*��ӡ���*/
				show_outer_frame(0, 1, row, col, 3);

				/*��ӡ�ڲ�����*/
				show_arr_cube(0, 1, row, col, matrix, 3);


				if (is_array_adjacent_same(row, col, matrix))
					is_continue = 1;
				else
					is_continue = 0;

				/*һ�κϲ�*/

				/*���ü�¼λ������*/
				reset(row, col, pos_1);

				/*���Ҫ�ϲ�λ�þ�������*/
				move_by_arrow(0, 1, row_pos, col_pos, row, col, matrix, pos_1, 1);//��matirx[0][0]��ʼ�ƶ�

				/*�ϲ����ڵ���ֵͬ*/
				merge(row, col, row_pos, col_pos, matrix, pos_1, point, goal, max, 1);
				show_arr(0, 1, row, col, matrix, pos_1, 2);

				/*��˸*/
				for (int i = 0; i < 3; i++)
				{
					show_sel_cube(2 + col_pos * 8, 2 + row_pos * 4, matrix[row_pos][col_pos]);
					Sleep(TIME);
					show_cube(2 + col_pos * 8, 2 + row_pos * 4, matrix[row_pos][col_pos]);
					Sleep(TIME);
				}

				cct_gotoxy(0, 1 + row * 4 + 1);
				cout << "�ϳ���ɣ��س�������0";
				while (_getch() != '\r')
					;

				/*�������������0����*/
				drop_down(row, col, row_pos, col_pos, matrix, pos_1,1);//�ϲ���λ������
				/*cct_gotoxy(0,60);
				cout << row_pos << endl;
				cout << col_pos << endl;*/

				/*��ʾ�������*/
				fall_down(0, 1, row, col, row_pos, col_pos, matrix, pos_1);

				/*���������0*/
				drop_down(row, col, row_pos, col_pos, matrix, pos_1, 2);//�ϲ���λ������

				/*�����µ����ֵ*/
				cct_gotoxy(0, 1 + row * 4 + 1);
				cout << "����0��ɣ��س��������ֵ";
				while (_getch() != '\r')
					;
				fill_new_val(row, col, matrix, pos_1, max,1);

				/*��ʾ�µ����ֵ*/
				show_arr(0, 1, row, col, matrix, pos_1, 3);

				cct_gotoxy(0, 1 + row * 4 + 1);
				input_End();
				break;	
			}
			case '9'://9.αͼ�ν���������
			{
				/*����*/
				cct_cls();
				int is_continue = 1;//�����������޷��ϲ�������0

				/*����������*/
				input_int("����������(5-8)��", 5, 9, row);//��������
				input_int("����������(5-10)��", 5, 11, col);//��������
				input_int("������ϳ�Ŀ��(5-20)��", 5, 21, goal);//����ϳ�Ŀ��

				/*�������ֵ����*/
				generate_matrix(row, col, matrix);

				/*��ӡ���*/
				show_outer_frame(0, 1, row, col, 3);

				/*��ӡ�ڲ�����*/
				show_arr_cube(0, 1, row, col, matrix, 3);
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

						if (is_continue)
						{
							/*���Ҫ�ϲ�λ�þ�������*/
							move_by_arrow(0, 1, row_pos, col_pos, row, col, matrix, pos_1, 1);//��matirx[0][0]��ʼ�ƶ�

							/*�ϲ����ڵ���ֵͬ*/
							merge(row, col, row_pos, col_pos, matrix, pos_1, point, goal, max, 1);
							show_arr(0, 1, row, col, matrix, pos_1, 2);

							/*��˸*/
							for (int i = 0; i < 3; i++)
							{
								show_sel_cube(2 + col_pos * 8, 2 + row_pos * 4, matrix[row_pos][col_pos]);
								Sleep(TIME);
								show_cube(2 + col_pos * 8, 2 + row_pos * 4, matrix[row_pos][col_pos]);
								Sleep(TIME);
							}

							cct_gotoxy(0, 1 + row * 4 + 1);
							cout << setw(50) << ' ';
							/*while (_getch() != '\r')
								;*/

							/*�������������0����*/
							drop_down(row, col, row_pos, col_pos, matrix, pos_1, 1);//�ϲ���λ������
							/*cct_gotoxy(0,60);
							cout << row_pos << endl;
							cout << col_pos << endl;*/

							/*��ʾ�������*/
							fall_down(0, 1, row, col, row_pos, col_pos, matrix, pos_1);

							/*���������0*/
							drop_down(row, col, row_pos, col_pos, matrix, pos_1, 2);//�ϲ���λ������

							/*�����µ����ֵ*/
							cct_gotoxy(0, 1 + row * 4 + 1);
							/*cout << "����0��ɣ��س��������ֵ";
							while (_getch() != '\r')
								;*/
							fill_new_val(row, col, matrix, pos_1, max, 1);

							/*��ʾ�µ����ֵ*/
							show_arr(0, 1, row, col, matrix, pos_1, 3);
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
					if (max >= goal)
					{
						goal = max + 1;
						cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
						cout << "�Ѿ��ϳɵ�" << max;
						cct_setcolor(COLOR_BLACK, COLOR_WHITE);;//�ָ�ȱʡ��ɫ
						cout << endl;

						wait_for_enter("�����Ŀ�����");
					}

				}
				break;
			}
		}
	}
	return 0;
}
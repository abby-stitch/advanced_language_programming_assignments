/* 1850917 电信 梁诗瑶 */
/*主函数及菜单部分函数*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
	函数名称：
	功    能：菜单的显示与选择
	输入参数：
	返 回 值：
	说    明：
  ***************************************************************************/
char printAndselctMenu()
{
	char sel;
	cout << "-----------------------------------" << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成（分步骤显示）" << endl;
	cout << "4.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << "-----------------------------------" << endl;
	cout << "[请选择0-9] ";

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
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	char mode;

	

	while (1)
	{
		/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
		cct_setconsoleborder(120, 40, 120, 9000);

		int max = START_MAX;//数组中的最大值

		int row = 0;//行数
		int col = 0;//列数
		
		int goal = 0;//合成目标值
		int point = 0;//总分数

		int matrix[M][N] = { 0 };//存放随机值的矩阵
		int pos_1[M][N] = { 0 };//记录同值位置
		//int pos_2[M][N] = { 0 };//记录同值位置

		int row_pos = 0;
		int col_pos = 0;

		/*菜单的显示与选择*/
		mode = printAndselctMenu();

		/*若选择退出，直接退出*/
		if (mode == '0')
			break;

		switch (mode)
		{
			case '1'://1.命令行找出可合成项并标识（非递归）
			{
				/*清屏*/
				cct_cls();

				/*输入行列数*/
				input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
				input_int("请输入列数(5-10)：", 5, 11, col);//输入列数

				/*生成随机值数组*/
				generate_matrix(row, col, matrix);

				/*显示当前数组*/
				cout << endl;
				print_matrix(1, "当前数组：", row, col, matrix);
				cout << endl;
				
				if (is_array_adjacent_same(row, col, matrix))
				{
					/*输入矩阵坐标*/
					input_coordinate(row, col, row_pos, col_pos, matrix);

					/*找相邻相同值（非递归方式）*/
					seek_same_val_nonrecursive(row, col, row_pos, col_pos, matrix, pos_1);

					/*显示查找结果数组*/
					cout << endl;
					print_matrix(2, "查找结果数组：", row, col, pos_1);
					cout << endl;

					/*显示当前数组（不同色标识）*/
					cout << endl;
					print_matrix_color("当前数组", row, col, matrix, pos_1);
					cout << endl;
				}
				else
				{
					cout << "游戏失败" << endl;//所有数字无法合并，游戏失败
				}
				/*结束，输入End*/
				input_End();
				break;
			}
			case '2'://2.命令行找出可合成项并标识（递归）
			{
				/*清屏*/
				cct_cls();

				/*输入行列数*/
				input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
				input_int("请输入列数(5-10)：", 5, 11, col);//输入列数

				/*生成随机值数组*/
				generate_matrix(row, col, matrix);

				/*显示当前数组*/
				cout << endl;
				print_matrix(1, "当前数组：", row, col, matrix);
				cout << endl;

				if (is_array_adjacent_same(row, col, matrix))
				{
					/*输入矩阵坐标*/
					input_coordinate(row, col, row_pos, col_pos, matrix);

					/*找相邻相同值（递归方式）*/
					seek_same_val_recursive(row, col, row_pos, col_pos, matrix, pos_1);

					/*显示查找结果数组*/
					cout << endl;
					print_matrix(2, "查找结果数组：", row, col, pos_1);
					cout << endl;

					/*显示当前数组（不同色标识）*/
					cout << endl;
					print_matrix_color("当前数组", row, col, matrix, pos_1);
					cout << endl;
				}
				else
				{
					cout << "游戏失败" << endl;//所有数字无法合并，游戏失败
				}

				/*结束，输入End*/
				input_End();
				break;
			}
			case '3'://3.命令行完成一次合成（分步骤显示）
			{
				cct_cls();

				/*输入行列数，目标值*/
				input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
				input_int("请输入列数(5-10)：", 5, 11, col);//输入列数
				input_int("请输入合成目标(5-20)：", 5, 21, goal);//输入合成目标

				generate_matrix(row, col, matrix);


				cout << endl;
				print_matrix(1, "当前数组：", row, col, matrix);
				cout << endl;

				if (is_array_adjacent_same(row, col, matrix))
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
					cout << "游戏失败" << endl;//所有数字无法合并，游戏失败
				}
				input_End();
				break;
			}
			case '4'://4.伪图形界面显示初始数组（无分隔线）
			{
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
						cout << "已经合成到" << max ;
						cct_setcolor(COLOR_BLACK, COLOR_WHITE);;//恢复缺省颜色
						cout << endl;

						wait_for_enter("向更高目标进发");
					}
				}

				input_End();
				break;
			}
			case '5'://5.伪图形界面显示初始数组（无分隔线）
			{
				/*清屏*/
				cct_cls();

				/*输入行列数*/
				input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
				input_int("请输入列数(5-10)：", 5, 11, col);//输入列数

				/*生成随机值数组*/
				generate_matrix(row, col, matrix);

				/*打印外框*/
				show_outer_frame(0, 1, row, col, 1);

				/*打印内部格子*/
				show_arr_cube(0, 1, row, col, matrix, 1);

				input_End();
				break;
			}
			case '6'://6.伪图形界面显示初始数组（有分隔线）
			{
				/*清屏*/
				cct_cls();

				/*输入行列数*/
				input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
				input_int("请输入列数(5-10)：", 5, 11, col);//输入列数

				/*生成随机值数组*/
				generate_matrix(row, col, matrix);

				/*打印外框*/
				show_outer_frame(0, 1, row, col, 2);

				/*打印内部格子*/
				show_arr_cube(0, 1, row, col, matrix, 2);

				input_End();
				break;
			}
			case '7'://7.伪图形界面下用箭头键选择当前色块
			{
				/*清屏*/
				cct_cls();

				/*输入行列数*/
				input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
				input_int("请输入列数(5-10)：", 5, 11, col);//输入列数

				/*生成随机值数组*/
				generate_matrix(row, col, matrix);

				/*打印外框*/
				show_outer_frame(0, 1, row, col, 3);

				/*打印内部格子*/
				show_arr_cube(0, 1, row, col, matrix, 3);

				/*用箭头键移动，回车键选择*/
				/*row_pos = 0;
				col_pos = 0;*/
				move_by_arrow(0, 1, row_pos, col_pos, row, col, matrix, pos_1);//从matirx[0][0]开始移动

				input_End();
				break;			
			}
			case '8'://8.伪图形界面完成一次合成（分步骤）"
			{
				/*清屏*/
				cct_cls();
				int is_continue = 1;//若所有数字无法合并，则置0

				/*输入行列数*/
				input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
				input_int("请输入列数(5-10)：", 5, 11, col);//输入列数
				input_int("请输入合成目标(5-20)：", 5, 21, goal);//输入合成目标

				/*生成随机值数组*/
				generate_matrix(row, col, matrix);

				/*打印外框*/
				show_outer_frame(0, 1, row, col, 3);

				/*打印内部格子*/
				show_arr_cube(0, 1, row, col, matrix, 3);


				if (is_array_adjacent_same(row, col, matrix))
					is_continue = 1;
				else
					is_continue = 0;

				/*一次合并*/

				/*重置记录位置数组*/
				reset(row, col, pos_1);

				/*获得要合并位置矩阵坐标*/
				move_by_arrow(0, 1, row_pos, col_pos, row, col, matrix, pos_1, 1);//从matirx[0][0]开始移动

				/*合并相邻的相同值*/
				merge(row, col, row_pos, col_pos, matrix, pos_1, point, goal, max, 1);
				show_arr(0, 1, row, col, matrix, pos_1, 2);

				/*闪烁*/
				for (int i = 0; i < 3; i++)
				{
					show_sel_cube(2 + col_pos * 8, 2 + row_pos * 4, matrix[row_pos][col_pos]);
					Sleep(TIME);
					show_cube(2 + col_pos * 8, 2 + row_pos * 4, matrix[row_pos][col_pos]);
					Sleep(TIME);
				}

				cct_gotoxy(0, 1 + row * 4 + 1);
				cout << "合成完成，回车键下落0";
				while (_getch() != '\r')
					;

				/*进行数组下落除0操作*/
				drop_down(row, col, row_pos, col_pos, matrix, pos_1,1);//合并后位置置零
				/*cct_gotoxy(0,60);
				cout << row_pos << endl;
				cout << col_pos << endl;*/

				/*显示下落过程*/
				fall_down(0, 1, row, col, row_pos, col_pos, matrix, pos_1);

				/*数组下落除0*/
				drop_down(row, col, row_pos, col_pos, matrix, pos_1, 2);//合并后位置置零

				/*产生新的随机值*/
				cct_gotoxy(0, 1 + row * 4 + 1);
				cout << "下落0完成，回车键填充新值";
				while (_getch() != '\r')
					;
				fill_new_val(row, col, matrix, pos_1, max,1);

				/*显示新的随机值*/
				show_arr(0, 1, row, col, matrix, pos_1, 3);

				cct_gotoxy(0, 1 + row * 4 + 1);
				input_End();
				break;	
			}
			case '9'://9.伪图形界面完整版
			{
				/*清屏*/
				cct_cls();
				int is_continue = 1;//若所有数字无法合并，则置0

				/*输入行列数*/
				input_int("请输入行数(5-8)：", 5, 9, row);//输入行数
				input_int("请输入列数(5-10)：", 5, 11, col);//输入列数
				input_int("请输入合成目标(5-20)：", 5, 21, goal);//输入合成目标

				/*生成随机值数组*/
				generate_matrix(row, col, matrix);

				/*打印外框*/
				show_outer_frame(0, 1, row, col, 3);

				/*打印内部格子*/
				show_arr_cube(0, 1, row, col, matrix, 3);
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

						if (is_continue)
						{
							/*获得要合并位置矩阵坐标*/
							move_by_arrow(0, 1, row_pos, col_pos, row, col, matrix, pos_1, 1);//从matirx[0][0]开始移动

							/*合并相邻的相同值*/
							merge(row, col, row_pos, col_pos, matrix, pos_1, point, goal, max, 1);
							show_arr(0, 1, row, col, matrix, pos_1, 2);

							/*闪烁*/
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

							/*进行数组下落除0操作*/
							drop_down(row, col, row_pos, col_pos, matrix, pos_1, 1);//合并后位置置零
							/*cct_gotoxy(0,60);
							cout << row_pos << endl;
							cout << col_pos << endl;*/

							/*显示下落过程*/
							fall_down(0, 1, row, col, row_pos, col_pos, matrix, pos_1);

							/*数组下落除0*/
							drop_down(row, col, row_pos, col_pos, matrix, pos_1, 2);//合并后位置置零

							/*产生新的随机值*/
							cct_gotoxy(0, 1 + row * 4 + 1);
							/*cout << "下落0完成，回车键填充新值";
							while (_getch() != '\r')
								;*/
							fill_new_val(row, col, matrix, pos_1, max, 1);

							/*显示新的随机值*/
							show_arr(0, 1, row, col, matrix, pos_1, 3);
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
					if (max >= goal)
					{
						goal = max + 1;
						cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
						cout << "已经合成到" << max;
						cct_setcolor(COLOR_BLACK, COLOR_WHITE);;//恢复缺省颜色
						cout << endl;

						wait_for_enter("向更高目标进发");
					}

				}
				break;
			}
		}
	}
	return 0;
}
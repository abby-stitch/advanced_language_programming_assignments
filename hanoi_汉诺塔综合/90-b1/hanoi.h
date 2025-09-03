
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
   /*圆盘显示信息*/
#define BOTTOM_X       1   //圆盘底部横坐标
#define BOTTOM_Y       15  //圆盘底部纵坐标
#define BOTTOM_LENGTH  23  //圆盘底部长度
#define BOTTOM_GAP     9   //圆盘底部间隔

/*圆柱信息*/
#define COLUMN_X       12  //圆柱横坐标
#define COLUMN_TOP_Y   3   //圆柱顶部纵坐标
#define COLUMN_LENGTH  12  //圆柱长度
#define COLUMN_GAP     32  //圆柱间隔

/*移动信息*/
#define MOVE_TOP       1   //圆盘移动最高纵坐标

/*纵向显示信息*/
#define VERTICAL_Y     27  //纵向显示=====纵坐标
#define VERTICAL_X     9   //纵向显示=====最左边横坐标

/*横向显示信息*/
#define HORIZONTAL_Y   32  //8.横向显示纵坐标
//#define HORIZONTAL_X   9  //8.横向显示横坐标

#define END_Y          38  //显示继续的纵坐标
#define TIME           100 




/*菜单的显示与选择*/
char printAndselctMenu();



/*功能函数*/
void push(char col, int n, int length);
int pop(char col, int length);
void initStartColumn(char startColumn, int n);
void showColumn_horizontal();
void showColumn_vertical(int const X = VERTICAL_X, int const Y = 12);
void showVerticalChange(char src, char dst, int const X = VERTICAL_X, int const Y = 12);
void drawColumn();
void drawPlate();
void move(char src, char dst);
void game(int layer, char startColumn, char targetColumn);

/*重置*/
void resetSTEP();
void resetColumn();



/*基本信息输入*/
int inputBaseInfo(char mode, int* n, char* src, char* tmp, char* dst);



/* =============================================================================================
    hanio递归函数（选项1-4）

    1.基本解: hanoi(int n, char src, char tmp, char dst, char mode);
    2.基本解（步数记录）: hanoi(int n, char src, char tmp, char dst, char mode);
    3.内部数组显示（横向）: hanoi(int n, char src, char tmp, char dst,char mode,int layer);
    4.内部数组显示（纵向+横向）: hanoi(int n, char src, char tmp, char dst, char mode,int layer,int speed)

    6.图形解-预备-在起始柱上画n个盘子:hanoi(int n, char src, char tmp, char dst, char mode);
    7.图形解-预备-第一次移动:hanoi(int n, char src, char tmp, char dst, char mode,int layer,int speed)
================================================================================================ */

void hanoi(int n, char src, char tmp, char dst, char mode, int layer = 0, int speed = 0);

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "cmd_console_tools.h"
using namespace std;

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
#define VERTICAL_Y     27  //8.纵向显示=====纵坐标
#define VERTICAL_X     9   //8.纵向显示=====最左边横坐标

/*横向显示信息*/
#define HORIZONTAL_Y   32  //8.横向显示纵坐标

/*用三个全局简单变量表示三个栈的栈项指针
   三个全局一维数组来记录三根圆柱中的圆盘数及编号
   一个计数用的全局变量*/
const int MAX_LENGTH = 10;
int Top_A = 0, Top_B = 0, Top_C = 0;
int Column_A[MAX_LENGTH] = { 0 }, Column_B[MAX_LENGTH] = { 0 }, Column_C[MAX_LENGTH] = { 0 };
int STEP = 1;







/*功能函数*/

/***************************************************************************
  函数名称：
  功    能：进栈
  输入参数：char col:进栈柱符号
            int n:进栈数据
            int length:数组长度
  返 回 值：
  说    明：
***************************************************************************/
void push(char col, int n, int length)
{
    /*确定进栈柱*/
    switch (col)
    {
        case 'A':
            if (Top_A < length)
                Column_A[Top_A++] = n;
            break;
        case 'B':
            if (Top_B < length)
                Column_B[Top_B++] = n;
            break;
        case 'C':
            if (Top_C < length)
                Column_C[Top_C++] = n;
            break;
    }

}

/***************************************************************************
  函数名称：
  功    能：出栈
  输入参数：char col:出栈柱符号
            int arr[]:作为栈的数组
            int length:数组长度
  返 回 值：
  说    明：
***************************************************************************/
int pop(char col, int length)
{
    /*确定出栈柱*/
    switch (col)
    {
        case'A':
            if (Top_A > 0)
            {
                int tmp;
                tmp = Column_A[--Top_A];
                Column_A[Top_A] = 0;
                return tmp;
            }
            break;
        case'B':
            if (Top_B > 0)
            {
                int tmp;
                tmp = Column_B[--Top_B];
                Column_B[Top_B] = 0;
                return tmp;
            }
            break;
        case'C':
            if (Top_C > 0)
            {
                int tmp;
                tmp = Column_C[--Top_C];
                Column_C[Top_C] = 0;
                return tmp;
            }
            break;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：初始化起始柱
  输入参数：char starColumn:起始柱符号
            int n:圆盘层数
  返 回 值：
  说    明：
***************************************************************************/
void initStartColumn(char startColumn, int n)
{
    for (int i = n; i > 0; i--)
    {
        push(startColumn, i, n);
    }
}

/***************************************************************************
  函数名称：
  功    能：横向显示
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void showColumn_horizontal(int const x = 0, int const y = 17)
{
    cct_gotoxy(x, y);
    cout << "A:";
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (Column_A[i] <= 0)
            cout << setw(3) << ' ';
        else
            cout << setw(2) << Column_A[i] << ' ';
    }

    cout << "B:";
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (Column_B[i] <= 0)
            cout << setw(3) << ' ';
        else
            cout << setw(2) << Column_B[i] << ' ';
    }

    cout << "C:";
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (Column_C[i] <= 0)
            cout << setw(3) << ' ';
        else
            cout << setw(2) << Column_C[i] << ' ';
    }
}

/***************************************************************************
  函数名称：
  功    能：纵向显示
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void showColumn_vertical(int const X = VERTICAL_X, int const Y = 12)
{
    int x = X;
    int y = Y;

    cct_setcolor(); //恢复缺省颜色
    /*光标不显示*/
    cct_setcursor(CURSOR_INVISIBLE);

    /*显示========*/
    cct_gotoxy(x, y);
    cout << "=========================";

    /*显示A，B，C*/
    x += 2;
    y += 1;
    cct_gotoxy(x, y);
    cout << 'A';

    x += 10;
    cct_gotoxy(x, y);
    cout << 'B';

    x += 10;
    cct_gotoxy(x, y);
    cout << 'C';

    /*纵向打印ABC数组中的元素*/
    //打印A数组
    x = X + 1;
    y = Y - 1;
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        cct_gotoxy(x, y);
        if (Column_A[i] <= 0)
            cout << setw(2) << ' ';
        else
            cout << setw(2) << Column_A[i];
        y--;
    }

    //打印B数组
    x += 10;
    y = Y - 1;
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        cct_gotoxy(x, y);
        if (Column_B[i] <= 0)
            cout << setw(2) << ' ';
        else
            cout << setw(2) << Column_B[i];
        y--;
    }

    //打印C数组
    x += 10;
    y = Y - 1;
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        cct_gotoxy(x, y);
        if (Column_C[i] <= 0)
            cout << setw(2) << ' ';
        else
            cout << setw(2) << Column_C[i];
        y--;
    }
}

/***************************************************************************
  函数名称：
  功    能：纵向显示变化
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void showVerticalChange(char src, char dst, int const X = VERTICAL_X, int const Y = 12)
{
    int x = X + 1;
    int y = Y - 1;

    switch (src)
    {
        case'A':
        {
            y -= Top_A;
            cct_gotoxy(x, y);
            cout << setw(2) << ' ';
            break;
        }
        case'B':
        {
            x += 10;
            y = y - Top_B;
            cct_gotoxy(x, y);
            cout << setw(2) << ' ';
            break;
        }
        case'C':
        {
            x += 20;
            y = y - Top_C;
            cct_gotoxy(x, y);
            cout << setw(2) << ' ';
            break;
        }
    }

	x = X + 1;
	y = Y - 1;

    switch (dst)
    {
        case'A':
        {
            y = y - Top_A + 1;
            cct_gotoxy(x, y);
            cout << setw(2) << Column_A[Top_A - 1];
            break;
        }
        case'B':
        {
            x += 10;
            y = y - Top_B + 1;
            cct_gotoxy(x, y);
            cout << setw(2) << Column_B[Top_B - 1];
            break;
        }
        case'C':
        {
            x += 20;
            y = y - Top_C + 1;
            cct_gotoxy(x, y);
            cout << setw(2) << Column_C[Top_C - 1];
            break;
        }
    }
}
/*=======================================================================================
        5.图形解-预备-画三个圆柱
========================================================================================= */
/***************************************************************************
  函数名称：
  功    能：画三个圆柱
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void drawColumn()
{
    int x = 0;
    int y = 0;

    /*清屏*/
    cct_cls();
    /*设置圆柱颜色*/
    cct_setcolor(COLOR_HYELLOW, COLOR_HYELLOW);


    /*开始打印圆柱，从左到右，从上到下*/
    //三个圆盘底部
    x = BOTTOM_X;
    for (int i = 0; i < 3; i++)
    {
        /*设置光标状态为全高*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*打印*/
        cct_showch(x, BOTTOM_Y, 'x', COLOR_HYELLOW, COLOR_HYELLOW, BOTTOM_LENGTH);
        /*光标不显示*/
        cct_setcursor(CURSOR_INVISIBLE);
        x += (BOTTOM_GAP + BOTTOM_LENGTH);
    }
    //三个柱子
    for (y = BOTTOM_Y - 1; y >= COLUMN_TOP_Y; y--)
    {
        x = COLUMN_X;
        for (int i = 0; i < 3; i++)
        {
            /*设置光标状态为全高*/
            cct_setcursor(CURSOR_VISIBLE_FULL);
            /*打印*/
            cct_showch(x, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
            /*光标不显示*/
            cct_setcursor(CURSOR_INVISIBLE);

            Sleep(50);
            x += COLUMN_GAP;
        }
    }

    cct_setcolor(); //恢复缺省颜色
}






/*=======================================================================================
        6.图形解-预备-在起始柱上画n个盘子
========================================================================================= */
/***************************************************************************
  函数名称：
  功    能：在起始柱上画n个盘子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void drawPlate(int n)
{
    int x = 0;
    int y = 0;
    int i = 0;

    /*打印A柱*/
    for (y = BOTTOM_Y - 1, i = 0; Column_A[i] > 0; i++)
    {
        x = COLUMN_X - Column_A[i];

        /*设置光标状态为全高*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*打印*/
        cct_showch(x, y, 'x', Column_A[i], Column_A[i], 2 * Column_A[i] + 1);
        /*光标不显示*/
        cct_setcursor(CURSOR_INVISIBLE);
        y--;

        Sleep(50);
    }

    /*打印B柱*/
    for (y = BOTTOM_Y - 1, i = 0; Column_B[i] > 0; i++)
    {
        x = COLUMN_X + COLUMN_GAP - Column_B[i];

        /*设置光标状态为全高*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*打印*/
        cct_showch(x, y, 'x', Column_B[i], Column_B[i], 2 * Column_B[i] + 1);
        /*光标不显示*/
        cct_setcursor(CURSOR_INVISIBLE);
        y--;

        Sleep(50);
    }

    /*打印C柱*/
    for (y = BOTTOM_Y - 1, i = 0; Column_C[i] > 0; i++)
    {
        x = COLUMN_X + 2 * COLUMN_GAP - Column_C[i];

        /*设置光标状态为全高*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*打印*/
        cct_showch(x, y, 'x', Column_C[i], Column_C[i], 2 * Column_C[i] + 1);
        /*光标不显示*/
        cct_setcursor(CURSOR_INVISIBLE);
        y--;

        Sleep(50);
    }

    cct_setcolor(); //恢复缺省颜色
    cct_gotoxy(0, 39);
}


/*=======================================================================================
        7.图形解-预备-第一次移动
========================================================================================= */

/***************************************************************************
  函数名称：
  功    能：盘移动
  输入参数：
  返 回 值：
  说    明：数组变化后才移动，及起始柱顶部的盘已变为目的柱顶部的盘
***************************************************************************/
void move(char src, char dst)
{
    int x = 0;
    int y = BOTTOM_Y - 1;
    int column_x_start = 0;
    int column_x_target = 0;

    int* starColumn;
    starColumn = Column_A;

    int* targetColumn;
    targetColumn = Column_A;

    int* top_start;
    top_start = &Top_A;

    int* top_target;
    top_target = &Top_A;

    int distance = (int(dst) - int(src)) * COLUMN_GAP;


    /*确定起始柱*/
    switch (src)
    {
        case'A':
            starColumn = Column_A;
            top_start = &Top_A;
            x = COLUMN_X;
            column_x_start = COLUMN_X;
            break;
        case'B':
            starColumn = Column_B;
            top_start = &Top_B;
            x = COLUMN_X + COLUMN_GAP;
            column_x_start = COLUMN_X + COLUMN_GAP;
            break;
        case'C':
            starColumn = Column_C;
            top_start = &Top_C;
            x = COLUMN_X + 2 * COLUMN_GAP;
            column_x_start = COLUMN_X + 2 * COLUMN_GAP;
            break;
    }


    /*确定目标柱*/
    switch (dst)
    {
        case'A':
            targetColumn = Column_A;
            top_target = &Top_A;
            column_x_target = COLUMN_X;
            break;
        case'B':
            targetColumn = Column_B;
            top_target = &Top_B;
            column_x_target = COLUMN_X + COLUMN_GAP;
            break;
        case'C':
            targetColumn = Column_C;
            top_target = &Top_C;
            column_x_target = COLUMN_X + 2 * COLUMN_GAP;
            break;
    }

    x -= targetColumn[*top_target - 1];//打印宽度为目标柱顶部盘宽度，即为目标数组最后一个数的数值

    /*向上移动*/
    y = y - *top_start + 1;
    for (; y > MOVE_TOP; y--)
    {
        /*设置光标状态为全高*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        if (y < COLUMN_TOP_Y)
        {
            /*覆盖*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK, 2 * targetColumn[*top_target - 1] + 1);
        }
        else
        {
            /*覆盖左边*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
            /*不覆盖柱子*/
            cct_showch(column_x_start, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
            /*覆盖右边*/
            cct_showch(column_x_start + 1, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
        }
        /*光标不显示*/
        cct_setcursor(CURSOR_INVISIBLE);

        /*设置光标状态为全高*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*打印新的盘*/
        cct_showch(x, y - 1, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
        /*光标不显示*/
        cct_setcursor(CURSOR_INVISIBLE);

        Sleep(100);
    }

    /*水平移动*/
    if (distance > 0)
    {
        for (int i = 0; i < distance; i++)
        {
            /*设置光标状态为全高*/
            cct_setcursor(CURSOR_VISIBLE_FULL);

            /*打印新的盘*/
            cct_showch(x + 1, y, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
            /*覆盖最左边*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK);

            /*光标不显示*/
            cct_setcursor(CURSOR_INVISIBLE);

            x++;//右移
            Sleep(100);
        }
    }
    else
    {
        for (int i = 0; i < (-1 * distance); i++)
        {
            /*设置光标状态为全高*/
            cct_setcursor(CURSOR_VISIBLE_FULL);

            /*打印新的盘*/
            cct_showch(x - 1, y, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
            /*覆盖最右边*/
            cct_showch(x + starColumn[*top_start - 1] + 1, y, 'x', COLOR_BLACK, COLOR_BLACK);

            /*光标不显示*/
            cct_setcursor(CURSOR_INVISIBLE);

            x--;//左移
            Sleep(100);
        }
    }

    /*向下移动*/
    x = column_x_target - targetColumn[*top_target - 1];
    for (; y < BOTTOM_Y + *top_target; y++)
    {
        /*设置光标状态为全高*/
        cct_setcursor(CURSOR_VISIBLE_FULL);

        if (y < COLUMN_TOP_Y)
        {
            /*覆盖*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK, 2 * targetColumn[*top_target - 1] + 1);
        }
        else
        {
            /*覆盖左边*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
            /*不覆盖柱子*/
            cct_showch(column_x_target, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
            /*覆盖右边*/
            cct_showch(column_x_target + 1, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
        }
        /*光标不显示*/
        cct_setcursor(CURSOR_INVISIBLE);

        /*设置光标状态为全高*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*打印新的盘*/
        cct_showch(x, y + 1, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
        /*光标不显示*/
        cct_setcursor(CURSOR_INVISIBLE);

        Sleep(100);
    }
}





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
    cout << "---------------------------------" << endl;
    cout << "1.基本解" << endl;
    cout << "2.基本解(步数记录)" << endl;
    cout << "3.内部数组显示(横向)" << endl;
    cout << "4.内部数组显示(纵向+横向)" << endl;
    cout << "5.图形解-预备-画三个圆柱" << endl;
    cout << "6.图形解-预备-在起始柱上画n个盘子" << endl;
    cout << "7.图形解-预备-第一次移动" << endl;
    cout << "8.图形解-自动移动版本" << endl;
    cout << "9.图形解-游戏版" << endl;
    cout << "0.退出" << endl;
    cout << "---------------------------------" << endl;
    cout << "[请选择:] ";

    while (1)
    {
        sel = _getche();
        switch (sel)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case '0':
                break;
            default:
                continue;
        }
    }
    cout << endl;
    cout << endl;
    return sel;
}





/* ==================================================================================
        基本信息输入
====================================================================================== */
void inputBaseInfo(int* n, char* src, char* tmp, char* dst, char mode, int speed = 0)
{
    /*输入层数*/
    int layer = 0;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> layer;
        if (cin.good() && layer > 0 && layer <= 16)
            break;
        else
        {
            cin.clear();
            cin.ignore();
        }
    }
    cin.clear();
    cin.ignore();
    *n = layer;

    /*输入起始柱*/
    char startColumn = 'A';
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> startColumn;
        if (cin.good() && (startColumn >= 'A' && startColumn <= 'C' || startColumn >= 'a' && startColumn <= 'c'))
            break;
        else
        {
            cin.clear();
            cin.ignore();
        }
    }
    cin.clear();
    cin.ignore();

    if (int(startColumn) >= int('a'))
    {
        startColumn = startColumn - 'a' + 'A';
    }
    *src = startColumn;

    /*输入目标柱*/
    char targetColumn = 'A';
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> targetColumn;
        if (cin.good() && (targetColumn >= 'A' && targetColumn <= 'C' || targetColumn >= 'a' && targetColumn <= 'c'))
        {
            if (int(targetColumn) >= ('a'))
            {
                targetColumn = targetColumn - 'a' + 'A';
            }
            if (targetColumn != startColumn)
                break;
        }
        cin.clear();
        cin.ignore();
    }
    cin.clear();
    cin.ignore();
    *dst = targetColumn;

    /*判断中间柱*/
    char transitColumn = 'A';
    if (startColumn == 'A')
    {
        if (targetColumn == 'B')
            transitColumn = 'C';
        else
            transitColumn = 'B';
    }
    else if (startColumn == 'B')
    {
        if (targetColumn == 'A')
            transitColumn = 'C';
        else
            transitColumn = 'A';
    }
    else
    {
        if (targetColumn == 'A')
            transitColumn = 'B';
        else
            transitColumn = 'A';
    }
    *tmp = transitColumn;
}


/* =============================================================================================
    hanio递归函数（选项1-4）

    1.基本解: hanoi(int n, char src, char tmp, char dst, char mode);
    2.基本解（步数记录）: hanoi(int n, char src, char tmp, char dst, char mode);
    3.内部数组显示（横向）: hanoi(int n, char src, char tmp, char dst,char mode,int layer);
    4.内部数组显示（纵向+横向）: hanoi(int n, char src, char tmp, char dst, char mode,int layer,int speed)

    6.图形解-预备-在起始柱上画n个盘子:hanoi(int n, char src, char tmp, char dst, char mode);
    7.图形解-预备-第一次移动:hanoi(int n, char src, char tmp, char dst, char mode,int layer,int speed)
================================================================================================ */
void hanoi(int n, char src, char tmp, char dst, char mode, int layer=0, int speed=0)
{
    static int count = 1;
    int temp = 0;

    if (n == 1)
    {
        switch (mode)
        {
			case '1':// 1.基本解
            {
                cout << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
                break;
            }

			case '2'://2.基本解（步数记录）
            {
                cout << setw(5) << count << ':' << setw(3) << n << '#' << ' ' << src << "-->" << dst << endl;
                count++;
                break;
            }
            case '3'://3.内部数组显示（横向）
            {
                temp = pop(src, layer);
                push(dst, temp, layer);
                cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << ')' << ' ' << src << "-->" << dst << ' ';
                showColumn_horizontal();
                STEP++;
            }
            case '4'://4.内部数组显示（纵向+横向）
            {
                temp = pop(src, layer);
                push(dst, temp, layer);

                if (speed == 0)
                {
                    if (_getch() == char(13))
                    {
                        cct_gotoxy(0, 17);
                        cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
                        showColumn_horizontal();
                    }
                    if (_getch() == char(13))
                        showVerticalChange(src, dst);
                }
                else
                {
                    Sleep(1000 / speed);
                    cct_gotoxy(0, 17);
                    cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
                    showColumn_horizontal();

                    Sleep(1000 / speed);
                    showVerticalChange(src, dst);
                }

                STEP++;
            }
            
        }
    }
    else
    {
        switch (mode)
        {
            case '1':// 1.基本解
            {
                hanoi(n - 1, src, dst, tmp, '1');
                cout << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
                hanoi(n - 1, tmp, src, dst, '1');
                break;
            }
            case '2': //2.基本解（步数记录）
            {
                hanoi(n - 1, src, dst, tmp, '2');
                cout << setw(5) << count << ':' << setw(3) << n << '#' << ' ' << src << "-->" << dst << endl;
                count++;
                hanoi(n - 1, tmp, src, dst, '2');
                break;
            }
            case '3'://3.内部数组显示（横向）
            {
                hanoi(n - 1, src, dst, tmp, '3', layer);
                temp = pop(src, layer);
                push(dst, temp, layer);
                cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << ')' << ' ' << src << "-->" << dst << ' ';
                showColumn_horizontal();
                STEP++;
                hanoi(n - 1, tmp, src, dst, '3', layer);
                break;
            }
            case '4'://4.内部数组显示（纵向+横向）
            {
                hanoi(n - 1, src, dst, tmp,'4', layer, speed);
                temp = pop(src, layer);
                push(dst, temp, layer);

                if (speed == 0)
                {
                    if (_getch() == char(13))
                    {
                        cct_gotoxy(0, 17);
                        cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
                        showColumn_horizontal();
                    }

                    if (_getch() == char(13))
                        showVerticalChange(src, dst);
                }
                else
                {
                    Sleep(1000 / speed);
                    cct_gotoxy(0, 17);
                    cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
                    showColumn_horizontal();

                    Sleep(1000 / speed);
                    showVerticalChange(src, dst);
                }

                STEP++;
                hanoi(n - 1, tmp, src, dst, '4', layer, speed);
                break;
            }
            case'8':
            {
                hanoi(n - 1, src, dst, tmp, '8', layer, speed);
                temp = pop(src, layer);
                push(dst, temp, layer);

                if (speed == 0)
                {
                    if (_getch() == char(13))
                    {
                        cct_gotoxy(0, HORIZONTAL_Y);
                        cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
                        showColumn_horizontal();
                    }

                    if (_getch() == char(13))
                        showVerticalChange(src, dst);

                    if (_getch() == char(13))             
                        move(src, dst);
                }

                else
                {
                    Sleep(1000 / speed);
                    cct_gotoxy(0, HORIZONTAL_Y);
                    cout << "第" << setw(4) << STEP << ' ' << "步" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
                    showColumn_horizontal();

                    Sleep(1000 / speed);
                    showVerticalChange(src, dst);

                    Sleep(1000 / speed);
                    move(src, dst);
                }

                STEP++;
                hanoi(n - 1, tmp, src, dst, '8', layer, speed);
                break;
            }
           
        }
    }
}













int main()
{
    int layer;
    char startColumn, targetColumn, transitColumn;
    int speed = 0;
    char mode;

    //mode = printAndselctMenu();
    //inputBaseInfo(&layer, &startColumn, &transitColumn, &targetColumn, mode);
    initStartColumn('B', 5);
    //hanoi(layer, startColumn, transitColumn, targetColumn, mode);
    drawColumn();
    drawPlate(5);
    move('B', 'A');


    cct_setcolor(); //恢复缺省颜色
    cct_gotoxy(0, 39);
    return 0;
}
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "cmd_console_tools.h"
using namespace std;

/*Բ����ʾ��Ϣ*/
#define BOTTOM_X       1   //Բ�̵ײ�������
#define BOTTOM_Y       15  //Բ�̵ײ�������
#define BOTTOM_LENGTH  23  //Բ�̵ײ�����
#define BOTTOM_GAP     9   //Բ�̵ײ����

/*Բ����Ϣ*/
#define COLUMN_X       12  //Բ��������
#define COLUMN_TOP_Y   3   //Բ������������
#define COLUMN_LENGTH  12  //Բ������
#define COLUMN_GAP     32  //Բ�����

/*�ƶ���Ϣ*/
#define MOVE_TOP       1   //Բ���ƶ����������

/*������ʾ��Ϣ*/
#define VERTICAL_Y     27  //8.������ʾ=====������
#define VERTICAL_X     9   //8.������ʾ=====����ߺ�����

/*������ʾ��Ϣ*/
#define HORIZONTAL_Y   32  //8.������ʾ������

/*������ȫ�ּ򵥱�����ʾ����ջ��ջ��ָ��
   ����ȫ��һά��������¼����Բ���е�Բ���������
   һ�������õ�ȫ�ֱ���*/
const int MAX_LENGTH = 10;
int Top_A = 0, Top_B = 0, Top_C = 0;
int Column_A[MAX_LENGTH] = { 0 }, Column_B[MAX_LENGTH] = { 0 }, Column_C[MAX_LENGTH] = { 0 };
int STEP = 1;







/*���ܺ���*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ջ
  ���������char col:��ջ������
            int n:��ջ����
            int length:���鳤��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void push(char col, int n, int length)
{
    /*ȷ����ջ��*/
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
  �������ƣ�
  ��    �ܣ���ջ
  ���������char col:��ջ������
            int arr[]:��Ϊջ������
            int length:���鳤��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop(char col, int length)
{
    /*ȷ����ջ��*/
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
  �������ƣ�
  ��    �ܣ���ʼ����ʼ��
  ���������char starColumn:��ʼ������
            int n:Բ�̲���
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void initStartColumn(char startColumn, int n)
{
    for (int i = n; i > 0; i--)
    {
        push(startColumn, i, n);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�������ʾ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void showColumn_vertical(int const X = VERTICAL_X, int const Y = 12)
{
    int x = X;
    int y = Y;

    cct_setcolor(); //�ָ�ȱʡ��ɫ
    /*��겻��ʾ*/
    cct_setcursor(CURSOR_INVISIBLE);

    /*��ʾ========*/
    cct_gotoxy(x, y);
    cout << "=========================";

    /*��ʾA��B��C*/
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

    /*�����ӡABC�����е�Ԫ��*/
    //��ӡA����
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

    //��ӡB����
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

    //��ӡC����
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
  �������ƣ�
  ��    �ܣ�������ʾ�仯
  ���������
  �� �� ֵ��
  ˵    ����
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
        5.ͼ�ν�-Ԥ��-������Բ��
========================================================================================= */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�������Բ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void drawColumn()
{
    int x = 0;
    int y = 0;

    /*����*/
    cct_cls();
    /*����Բ����ɫ*/
    cct_setcolor(COLOR_HYELLOW, COLOR_HYELLOW);


    /*��ʼ��ӡԲ���������ң����ϵ���*/
    //����Բ�̵ײ�
    x = BOTTOM_X;
    for (int i = 0; i < 3; i++)
    {
        /*���ù��״̬Ϊȫ��*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*��ӡ*/
        cct_showch(x, BOTTOM_Y, 'x', COLOR_HYELLOW, COLOR_HYELLOW, BOTTOM_LENGTH);
        /*��겻��ʾ*/
        cct_setcursor(CURSOR_INVISIBLE);
        x += (BOTTOM_GAP + BOTTOM_LENGTH);
    }
    //��������
    for (y = BOTTOM_Y - 1; y >= COLUMN_TOP_Y; y--)
    {
        x = COLUMN_X;
        for (int i = 0; i < 3; i++)
        {
            /*���ù��״̬Ϊȫ��*/
            cct_setcursor(CURSOR_VISIBLE_FULL);
            /*��ӡ*/
            cct_showch(x, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
            /*��겻��ʾ*/
            cct_setcursor(CURSOR_INVISIBLE);

            Sleep(50);
            x += COLUMN_GAP;
        }
    }

    cct_setcolor(); //�ָ�ȱʡ��ɫ
}






/*=======================================================================================
        6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������
========================================================================================= */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ʼ���ϻ�n������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void drawPlate(int n)
{
    int x = 0;
    int y = 0;
    int i = 0;

    /*��ӡA��*/
    for (y = BOTTOM_Y - 1, i = 0; Column_A[i] > 0; i++)
    {
        x = COLUMN_X - Column_A[i];

        /*���ù��״̬Ϊȫ��*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*��ӡ*/
        cct_showch(x, y, 'x', Column_A[i], Column_A[i], 2 * Column_A[i] + 1);
        /*��겻��ʾ*/
        cct_setcursor(CURSOR_INVISIBLE);
        y--;

        Sleep(50);
    }

    /*��ӡB��*/
    for (y = BOTTOM_Y - 1, i = 0; Column_B[i] > 0; i++)
    {
        x = COLUMN_X + COLUMN_GAP - Column_B[i];

        /*���ù��״̬Ϊȫ��*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*��ӡ*/
        cct_showch(x, y, 'x', Column_B[i], Column_B[i], 2 * Column_B[i] + 1);
        /*��겻��ʾ*/
        cct_setcursor(CURSOR_INVISIBLE);
        y--;

        Sleep(50);
    }

    /*��ӡC��*/
    for (y = BOTTOM_Y - 1, i = 0; Column_C[i] > 0; i++)
    {
        x = COLUMN_X + 2 * COLUMN_GAP - Column_C[i];

        /*���ù��״̬Ϊȫ��*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*��ӡ*/
        cct_showch(x, y, 'x', Column_C[i], Column_C[i], 2 * Column_C[i] + 1);
        /*��겻��ʾ*/
        cct_setcursor(CURSOR_INVISIBLE);
        y--;

        Sleep(50);
    }

    cct_setcolor(); //�ָ�ȱʡ��ɫ
    cct_gotoxy(0, 39);
}


/*=======================================================================================
        7.ͼ�ν�-Ԥ��-��һ���ƶ�
========================================================================================= */

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ƶ�
  ���������
  �� �� ֵ��
  ˵    ��������仯����ƶ�������ʼ�����������ѱ�ΪĿ������������
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


    /*ȷ����ʼ��*/
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


    /*ȷ��Ŀ����*/
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

    x -= targetColumn[*top_target - 1];//��ӡ���ΪĿ���������̿�ȣ���ΪĿ���������һ��������ֵ

    /*�����ƶ�*/
    y = y - *top_start + 1;
    for (; y > MOVE_TOP; y--)
    {
        /*���ù��״̬Ϊȫ��*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        if (y < COLUMN_TOP_Y)
        {
            /*����*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK, 2 * targetColumn[*top_target - 1] + 1);
        }
        else
        {
            /*�������*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
            /*����������*/
            cct_showch(column_x_start, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
            /*�����ұ�*/
            cct_showch(column_x_start + 1, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
        }
        /*��겻��ʾ*/
        cct_setcursor(CURSOR_INVISIBLE);

        /*���ù��״̬Ϊȫ��*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*��ӡ�µ���*/
        cct_showch(x, y - 1, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
        /*��겻��ʾ*/
        cct_setcursor(CURSOR_INVISIBLE);

        Sleep(100);
    }

    /*ˮƽ�ƶ�*/
    if (distance > 0)
    {
        for (int i = 0; i < distance; i++)
        {
            /*���ù��״̬Ϊȫ��*/
            cct_setcursor(CURSOR_VISIBLE_FULL);

            /*��ӡ�µ���*/
            cct_showch(x + 1, y, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
            /*���������*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK);

            /*��겻��ʾ*/
            cct_setcursor(CURSOR_INVISIBLE);

            x++;//����
            Sleep(100);
        }
    }
    else
    {
        for (int i = 0; i < (-1 * distance); i++)
        {
            /*���ù��״̬Ϊȫ��*/
            cct_setcursor(CURSOR_VISIBLE_FULL);

            /*��ӡ�µ���*/
            cct_showch(x - 1, y, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
            /*�������ұ�*/
            cct_showch(x + starColumn[*top_start - 1] + 1, y, 'x', COLOR_BLACK, COLOR_BLACK);

            /*��겻��ʾ*/
            cct_setcursor(CURSOR_INVISIBLE);

            x--;//����
            Sleep(100);
        }
    }

    /*�����ƶ�*/
    x = column_x_target - targetColumn[*top_target - 1];
    for (; y < BOTTOM_Y + *top_target; y++)
    {
        /*���ù��״̬Ϊȫ��*/
        cct_setcursor(CURSOR_VISIBLE_FULL);

        if (y < COLUMN_TOP_Y)
        {
            /*����*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK, 2 * targetColumn[*top_target - 1] + 1);
        }
        else
        {
            /*�������*/
            cct_showch(x, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
            /*����������*/
            cct_showch(column_x_target, y, 'x', COLOR_HYELLOW, COLOR_HYELLOW);
            /*�����ұ�*/
            cct_showch(column_x_target + 1, y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
        }
        /*��겻��ʾ*/
        cct_setcursor(CURSOR_INVISIBLE);

        /*���ù��״̬Ϊȫ��*/
        cct_setcursor(CURSOR_VISIBLE_FULL);
        /*��ӡ�µ���*/
        cct_showch(x, y + 1, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
        /*��겻��ʾ*/
        cct_setcursor(CURSOR_INVISIBLE);

        Sleep(100);
    }
}





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
    cout << "---------------------------------" << endl;
    cout << "1.������" << endl;
    cout << "2.������(������¼)" << endl;
    cout << "3.�ڲ�������ʾ(����)" << endl;
    cout << "4.�ڲ�������ʾ(����+����)" << endl;
    cout << "5.ͼ�ν�-Ԥ��-������Բ��" << endl;
    cout << "6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������" << endl;
    cout << "7.ͼ�ν�-Ԥ��-��һ���ƶ�" << endl;
    cout << "8.ͼ�ν�-�Զ��ƶ��汾" << endl;
    cout << "9.ͼ�ν�-��Ϸ��" << endl;
    cout << "0.�˳�" << endl;
    cout << "---------------------------------" << endl;
    cout << "[��ѡ��:] ";

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
        ������Ϣ����
====================================================================================== */
void inputBaseInfo(int* n, char* src, char* tmp, char* dst, char mode, int speed = 0)
{
    /*�������*/
    int layer = 0;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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

    /*������ʼ��*/
    char startColumn = 'A';
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
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

    /*����Ŀ����*/
    char targetColumn = 'A';
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
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

    /*�ж��м���*/
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
    hanio�ݹ麯����ѡ��1-4��

    1.������: hanoi(int n, char src, char tmp, char dst, char mode);
    2.�����⣨������¼��: hanoi(int n, char src, char tmp, char dst, char mode);
    3.�ڲ�������ʾ������: hanoi(int n, char src, char tmp, char dst,char mode,int layer);
    4.�ڲ�������ʾ������+����: hanoi(int n, char src, char tmp, char dst, char mode,int layer,int speed)

    6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������:hanoi(int n, char src, char tmp, char dst, char mode);
    7.ͼ�ν�-Ԥ��-��һ���ƶ�:hanoi(int n, char src, char tmp, char dst, char mode,int layer,int speed)
================================================================================================ */
void hanoi(int n, char src, char tmp, char dst, char mode, int layer=0, int speed=0)
{
    static int count = 1;
    int temp = 0;

    if (n == 1)
    {
        switch (mode)
        {
			case '1':// 1.������
            {
                cout << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
                break;
            }

			case '2'://2.�����⣨������¼��
            {
                cout << setw(5) << count << ':' << setw(3) << n << '#' << ' ' << src << "-->" << dst << endl;
                count++;
                break;
            }
            case '3'://3.�ڲ�������ʾ������
            {
                temp = pop(src, layer);
                push(dst, temp, layer);
                cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << ')' << ' ' << src << "-->" << dst << ' ';
                showColumn_horizontal();
                STEP++;
            }
            case '4'://4.�ڲ�������ʾ������+����
            {
                temp = pop(src, layer);
                push(dst, temp, layer);

                if (speed == 0)
                {
                    if (_getch() == char(13))
                    {
                        cct_gotoxy(0, 17);
                        cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
                        showColumn_horizontal();
                    }
                    if (_getch() == char(13))
                        showVerticalChange(src, dst);
                }
                else
                {
                    Sleep(1000 / speed);
                    cct_gotoxy(0, 17);
                    cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
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
            case '1':// 1.������
            {
                hanoi(n - 1, src, dst, tmp, '1');
                cout << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
                hanoi(n - 1, tmp, src, dst, '1');
                break;
            }
            case '2': //2.�����⣨������¼��
            {
                hanoi(n - 1, src, dst, tmp, '2');
                cout << setw(5) << count << ':' << setw(3) << n << '#' << ' ' << src << "-->" << dst << endl;
                count++;
                hanoi(n - 1, tmp, src, dst, '2');
                break;
            }
            case '3'://3.�ڲ�������ʾ������
            {
                hanoi(n - 1, src, dst, tmp, '3', layer);
                temp = pop(src, layer);
                push(dst, temp, layer);
                cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << ')' << ' ' << src << "-->" << dst << ' ';
                showColumn_horizontal();
                STEP++;
                hanoi(n - 1, tmp, src, dst, '3', layer);
                break;
            }
            case '4'://4.�ڲ�������ʾ������+����
            {
                hanoi(n - 1, src, dst, tmp,'4', layer, speed);
                temp = pop(src, layer);
                push(dst, temp, layer);

                if (speed == 0)
                {
                    if (_getch() == char(13))
                    {
                        cct_gotoxy(0, 17);
                        cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
                        showColumn_horizontal();
                    }

                    if (_getch() == char(13))
                        showVerticalChange(src, dst);
                }
                else
                {
                    Sleep(1000 / speed);
                    cct_gotoxy(0, 17);
                    cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
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
                        cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
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
                    cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
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


    cct_setcolor(); //�ָ�ȱʡ��ɫ
    cct_gotoxy(0, 39);
    return 0;
}
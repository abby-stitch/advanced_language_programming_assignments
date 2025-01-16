/* ���� 1850917 ��ʫ�� */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/*������ȫ�ּ򵥱�����ʾ����ջ��ջ��ָ��
   ����ȫ��һά��������¼����Բ���е�Բ���������
   һ�������õ�ȫ�ֱ���*/
const int MAX_LENGTH = 10;
int Top_A = 0, Top_B = 0, Top_C = 0;
int Column_A[MAX_LENGTH] = { 0 }, Column_B[MAX_LENGTH] = { 0 }, Column_C[MAX_LENGTH] = { 0 };
int STEP = 1;
/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
  
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
void showColumn_horizontal()
{
	cout << " A:";
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (Column_A[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_A[i];
	}

	cout << " B:";
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (Column_B[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_B[i];
	}

	cout << " C:";
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (Column_C[i] <= 0)
			cout << setw(2) << ' ';
		else
			cout << setw(2) << Column_C[i];
	}
	cout << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ��ʼ״̬
  ���������int const X  :��С�����꣨ȱʡΪ9��
			int const Y  :��������꣨ȱʡΪ12��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void showColumn_vertical(int const X, int const Y )
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
  ���������char src       :��ʼ��
			char dst	   :Ŀ����
			int const X    :=====���������
			int const Y    :====����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void showVerticalChange(char src, char dst, int const X , int const Y )
{
	/*��겻��ʾ*/
	cct_setcursor(CURSOR_INVISIBLE);

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


/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ʼ���ϻ�n������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void drawPlate()
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
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ����ƶ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void move(char src, char dst)
{
	int x = 0;
	int y = 0;
	int column_x_start = 0;
	int column_x_target = 0;

	int* startColumn;
	startColumn = Column_A;

	int* targetColumn;
	targetColumn = Column_A;

	int* top_start;
	top_start = &Top_A;

	int* top_target;
	top_target = &Top_A;

	int distance = (int(dst) - int(src)) * COLUMN_GAP;//ˮƽ�ƶ��ľ���


	/*ȷ����ʼ��*/
	switch (src)
	{
		case'A':
			startColumn = Column_A;
			top_start = &Top_A;
			column_x_start = COLUMN_X;//ȷ�����Ƶĺ�����
			break;
		case'B':
			startColumn = Column_B;
			top_start = &Top_B;
			column_x_start = COLUMN_X + COLUMN_GAP;//ȷ�����Ƶĺ�����
			break;
		case'C':
			startColumn = Column_C;
			top_start = &Top_C;
			column_x_start = COLUMN_X + 2 * COLUMN_GAP;//ȷ�����Ƶĺ�����
			break;
	}
	y = BOTTOM_Y - 1 - *top_start;//ȷ�����Ƶ���ʼ������


	/*ȷ��Ŀ����*/
	switch (dst)
	{
		case'A':
			targetColumn = Column_A;
			top_target = &Top_A;
			column_x_target = COLUMN_X;//ȷ�����Ƶĺ�����
			break;
		case'B':
			targetColumn = Column_B;
			top_target = &Top_B;
			column_x_target = COLUMN_X + COLUMN_GAP;//ȷ�����Ƶĺ�����
			break;
		case'C':
			targetColumn = Column_C;
			top_target = &Top_C;
			column_x_target = COLUMN_X + 2 * COLUMN_GAP;//ȷ�����Ƶĺ�����
			break;
	}

	//��ӡ���ΪĿ���������̿�ȣ���ΪĿ����ջ����ֵ:targetColumn[*Top_target-1]
	//x -= targetColumn[*top_target - 1];//��ʼ���ǵĺ�����

	/*�����ƶ�*/
	for (; y > MOVE_TOP; y--)
	{
		/*���ù��״̬Ϊȫ��*/
		cct_setcursor(CURSOR_VISIBLE_FULL);
		if (y < COLUMN_TOP_Y)
		{
			/*�������ӣ�ȫ����*/
			cct_showch(column_x_start- targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK, 2 * targetColumn[*top_target - 1] + 1);
		}
		else
		{
			/*�������*/
			cct_showch(column_x_start - targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
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
		cct_showch(column_x_start - targetColumn[*top_target - 1], y - 1, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
		/*��겻��ʾ*/
		cct_setcursor(CURSOR_INVISIBLE);

		Sleep(TIME);
	}

	x = column_x_start;//ȷ�����Ƶ���ʼ�м������

	/*ˮƽ�ƶ�*/
	if (distance > 0)
	{
		for (int i = 0; i < distance; i++)
		{
			/*���ù��״̬Ϊȫ��*/
			cct_setcursor(CURSOR_VISIBLE_FULL);

			/*���������*/
			cct_showch(x - targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK);

			/*��ӡ�µ���*/
			cct_showch(x - targetColumn[*top_target - 1] + 1, y, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
			
			/*��겻��ʾ*/
			cct_setcursor(CURSOR_INVISIBLE);

			x++;//����
			Sleep(TIME);
		}
	}
	else
	{
		for (int i = 0; i < (-1 * distance); i++)
		{
			/*���ù��״̬Ϊȫ��*/
			cct_setcursor(CURSOR_VISIBLE_FULL);

			/*�������ұ�*/
			cct_showch(x + targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK);

			/*��ӡ�µ���*/
			cct_showch(x - targetColumn[*top_target - 1]-1, y, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
			

			/*��겻��ʾ*/
			cct_setcursor(CURSOR_INVISIBLE);

			x--;//����
			Sleep(TIME);
		}
	}

	/*�����ƶ�*/
	for (; y < BOTTOM_Y - *top_target; y++)
	{
		/*���ù��״̬Ϊȫ��*/
		cct_setcursor(CURSOR_VISIBLE_FULL);

		if (y < COLUMN_TOP_Y)
		{
			/*����*/
			cct_showch(column_x_target - targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK, 2 * targetColumn[*top_target - 1] + 1);
		}
		else
		{
			/*�������*/
			cct_showch(column_x_target - targetColumn[*top_target - 1], y, 'x', COLOR_BLACK, COLOR_BLACK, targetColumn[*top_target - 1]);
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
		cct_showch(column_x_target - targetColumn[*top_target - 1], y + 1, 'x', targetColumn[*top_target - 1], targetColumn[*top_target - 1], 2 * targetColumn[*top_target - 1] + 1);
		/*��겻��ʾ*/
		cct_setcursor(CURSOR_INVISIBLE);

		Sleep(TIME);
	}

	cct_setcolor(); //�ָ�ȱʡ��ɫ
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����step;
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void resetSTEP()
{
	STEP = 1;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ���������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void resetColumn()
{
	/*����ָ��*/
	Top_A = 0;
	Top_B = 0;
	Top_C = 0;

	/*����A��*/
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		Column_A[i] = 0;
	}

	/*����B��*/
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		Column_B[i] = 0;
	}

	/*����C��*/
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		Column_C[i] = 0;
	}
}






/* ==================================================================================
		������Ϣ����
====================================================================================== */
int inputBaseInfo(char mode, int* n, char* src, char* tmp, char* dst)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

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
	char transitColumn = ('A' + 'B' + 'C') - (startColumn + targetColumn);
	*tmp = transitColumn;

	if (mode == '4' || mode == '8')
	{
		int speed = 0;
		while (1)
		{
			cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���) ";
			cin >> speed;
			if (cin.good() && speed >= 0 && speed <= 5)
				break;
			else
			{
				cin.clear();
				cin.ignore();
			}
		}
		cin.clear();
		cin.ignore();
		return speed;
	}
	else
		return 0;
}











/* =============================================================================================
	hanio�ݹ麯��

	1.������					: hanoi(int n, char src, char tmp, char dst, char mode);
	2.�����⣨������¼��		: hanoi(int n, char src, char tmp, char dst, char mode);
	3.�ڲ�������ʾ������		: hanoi(int n, char src, char tmp, char dst, char mode, int layer);
	4.�ڲ�������ʾ������+����	: hanoi(int n, char src, char tmp, char dst, char mode, int layer, int speed)
	7.ͼ�ν�-Ԥ��-��һ���ƶ�	: hanoi(int n, char src, char tmp, char dst, char mode);
	8.ͼ�ν�-�Զ��ƶ��汾		: hanoi(int n, char src, char tmp, char dst, char mode, int layer, int speed)
================================================================================================ */
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ŵ���ݹ麯��
  ���������int n       ����ŵ������
			char src    ����ʼ��
			char tmp    ���м���
			char dst    ��Ŀ����
			char mode   ��ģʽ
			int layer   ����ŵ��������ȱʡΪ0��
			int speed   ���ƶ��ٶȣ�ȱʡΪ0��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, char mode, int layer, int speed)
{
	int temp = 0;

	if (n == 1)
	{
		switch (mode)
		{
			case '1':// 1.������
				cout << setw(2) << n << '#' << ' ' << src << "---->" << dst << endl;
				break;


			case '2'://2.�����⣨������¼��
				cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << '#' << ' ' << src << "-->" << dst << ')' << endl;
				STEP++;
				break;


			case '3'://3.�ڲ�������ʾ������
				temp = pop(src, layer);
				push(dst, temp, layer);

				cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << '#' << ':' << ' ' << src << "-->" << dst << ')' << ' ';
				showColumn_horizontal();

				STEP++;
				break;


			case '4'://4.�ڲ�������ʾ������+����
				temp = pop(src, layer);
				push(dst, temp, layer);

				if (speed == 0)
				{
					if (_getch() == char(13))
					{
						cct_gotoxy(0, 17);
						cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
						showColumn_horizontal();
						showVerticalChange(src, dst);
					}
				}
				else
				{
					Sleep(TIME / speed);
					cct_gotoxy(0, 17);
					cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
					showColumn_horizontal();

					Sleep(TIME / speed);
					showVerticalChange(src, dst);
				}

				STEP++;
				break;


			case '7'://7.ͼ�ν� - Ԥ�� - ��һ���ƶ�
				temp = pop(src, layer);
				push(dst, temp, layer);

				Sleep(10 * TIME);

				move(src, dst);
				break;

			case '8'://8.ͼ�ν�-�Զ��ƶ��汾
				temp = pop(src, layer);
				push(dst, temp, layer);

				if (speed == 0)
				{
					if (_getch() == char(13))
					{
						cct_gotoxy(0, HORIZONTAL_Y);
						cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
						showColumn_horizontal();
						showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);
						move(src, dst);
					}
				}
				else
				{
					Sleep(TIME/ speed);
					cct_gotoxy(0, HORIZONTAL_Y);
					cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
					showColumn_horizontal();

					Sleep(TIME / speed);
					showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);

					Sleep(TIME / speed);
					move(src, dst);
				}
				STEP++;
				break;
		}
	}
	else
	{
		switch (mode)
		{
			case '1':// 1.������
				hanoi(n - 1, src, dst, tmp, '1');
				cout << setw(2) << n << '#' << ' ' << src << "---->" << dst << endl;
				hanoi(n - 1, tmp, src, dst, '1');
				break;


			case '2': //2.�����⣨������¼��
				hanoi(n - 1, src, dst, tmp, '2');
				cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << '#' << ' ' << src << "-->" << dst << ')' << endl;
				STEP++;
				hanoi(n - 1, tmp, src, dst, '2');
				break;


			case '3'://3.�ڲ�������ʾ������
				hanoi(n - 1, src, dst, tmp, '3', layer);

				temp = pop(src, layer);
				push(dst, temp, layer);

				cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << '#' << ':' << ' ' << src << "-->" << dst << ')' << ' ';
				showColumn_horizontal();
				STEP++;
				hanoi(n - 1, tmp, src, dst, '3', layer);
				break;


			case '4'://4.�ڲ�������ʾ������+����
				hanoi(n - 1, src, dst, tmp, '4', layer, speed);

				temp = pop(src, layer);
				push(dst, temp, layer);

				if (speed == 0)
				{
					if (_getch() == char(13))
					{
						cct_gotoxy(0, 17);
						cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
						showColumn_horizontal();
						showVerticalChange(src, dst);
					}	
				}
				else
				{
					Sleep(TIME / speed);
					cct_gotoxy(0, 17);
					cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
					showColumn_horizontal();

					Sleep(TIME/ speed);
					showVerticalChange(src, dst);
				}

				STEP++;
				hanoi(n - 1, tmp, src, dst, '4', layer, speed);
				break;


			case '7'://7.ͼ�ν� - Ԥ�� - ��һ���ƶ�
				hanoi(n - 1, src, dst, tmp, '7', layer);
				break;


			case'8'://8.ͼ�ν�-�Զ��ƶ��汾
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
						showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);
						move(src, dst);
					}
				}
				else
				{
					Sleep(TIME/ speed);
					cct_gotoxy(0, HORIZONTAL_Y);
					cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << n << "#: " << src << "-->" << dst << ") ";
					showColumn_horizontal();

					Sleep(TIME/ speed);
					showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);

					Sleep(TIME/ speed);
					move(src, dst);
				}

				STEP++;
				hanoi(n - 1, tmp, src, dst, '8', layer, speed);
				break;


		}
	}
}





/* ==================================================================================
		�˹������ƶ�����
====================================================================================== */
void game(int layer, char startColumn, char targetColumn)
{
	int temp = 0;
	int isEND = 0;

	int* SRC;
	SRC = Column_A;
	int* TOP_SRC;
	TOP_SRC = &Top_A;
	int* DST;
	DST = Column_A;
	int* TOP_DST;
	TOP_DST = &Top_A;

	char src = 'A';
	char dst = 'A';
	int x = 0;
	int y = 0;
	int column_x_start = 0;
	int column_x_target = 0;

	int* startColumn_move;
	startColumn_move = Column_A;

	int* targetColumn_move;
	targetColumn_move = Column_A;

	int* top_start;
	top_start = &Top_A;

	int* top_target;
	top_target = &Top_A;

	/*ȷ����ʼ��*/
	switch (startColumn)
	{
		case'A':
			SRC = Column_A;
			TOP_SRC = &Top_A;
			break;
		case'B':
			SRC = Column_B;
			TOP_SRC = &Top_B;
			break;
		case'C':
			SRC =  Column_C;
			TOP_SRC = &Top_C;
			break;
	}
	/*ȷ��Ŀ����*/
	switch (dst)
	{
		case'A':
			DST = Column_A;
			TOP_DST = &Top_A;
			break;
		case'B':
			DST = Column_B;
			TOP_DST = &Top_B;
			break;
		case'C':
			DST = Column_C;
			TOP_DST = &Top_C;
			break;
	}

	/*�����ƶ�ģʽ*/
	while (1)
	{
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

		cct_gotoxy(0, HORIZONTAL_Y + 2);
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";

		/*������ʼ����Ŀ����*/
		while (1)
		{
			cct_gotoxy(60, HORIZONTAL_Y + 2);
			cout << "                                                 ";
			cct_gotoxy(60, HORIZONTAL_Y + 2);


			/*����*/
			src = _getche();
			if (src == 'q' || src == 'Q')
			{
				isEND = 1;
				break;//��������ѭ��
			}

			dst = _getche();
			//while (_getch() != '\r')
			//	;

			/*�ж���ʼ���Ƿ�������ȷ*/
			if (src == 'a' || src == 'b' || src == 'c'
				|| src == 'A' || src == 'B' || src == 'C')
			{
				if (int(src) >= int('a'))
				{
					src = src - 'a' + 'A';
				}
			}
			else
			{
				cout << ' ' << char(8);
				cin.ignore();
				continue;
			}

			/*�ж�Ŀ�����Ƿ�������ȷ*/
			if (dst == 'a' || dst == 'b' || dst == 'c'
				|| dst == 'A' || dst == 'B' || dst == 'C')
			{
				if (int(dst) >= int('a'))
				{
					dst = dst - 'a' + 'A';
				}
			}
			else
			{
				cout << ' ' << char(8);
				cin.ignore();
				continue;
			}

			/*�ж���ʼ����Ŀ�����Ƿ���ͬ*/
			if (src == dst)
			{
				cin.ignore();
				continue;
			}
			else
			{
				cin.putback('\n');
				cin.ignore(10000, '\n');
				break;
			}//����ͬ���������
		}



		if (isEND)
			break;
		else
		{
			/*ȷ����ʼ��*/
			switch (src)
			{
				case'A':
					startColumn_move = Column_A;
					top_start = &Top_A;
					column_x_start = COLUMN_X;//ȷ�����Ƶĺ�����
					break;
				case'B':
					startColumn_move = Column_B;
					top_start = &Top_B;
					column_x_start = COLUMN_X + COLUMN_GAP;//ȷ�����Ƶĺ�����
					break;
				case'C':
					startColumn_move = Column_C;
					top_start = &Top_C;
					column_x_start = COLUMN_X + 2 * COLUMN_GAP;//ȷ�����Ƶĺ�����
					break;
			}
			/*ȷ��Ŀ����*/
			switch (dst)
			{
				case'A':
					targetColumn_move = Column_A;
					top_target = &Top_A;
					column_x_target = COLUMN_X;//ȷ�����Ƶĺ�����
					break;
				case'B':
					targetColumn_move = Column_B;
					top_target = &Top_B;
					column_x_target = COLUMN_X + COLUMN_GAP;//ȷ�����Ƶĺ�����
					break;
				case'C':
					targetColumn_move = Column_C;
					top_target = &Top_C;
					column_x_target = COLUMN_X + 2 * COLUMN_GAP;//ȷ�����Ƶĺ�����
					break;
			}

			if (*top_start == 0)
			{
				cct_setcolor(); //�ָ�ȱʡ��ɫ
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				cct_gotoxy(0, HORIZONTAL_Y + 3);
				cout << "��ԴΪ��!";
				Sleep(10 * TIME);
				cct_gotoxy(0, HORIZONTAL_Y + 3);
				cout << "                                                 ";

				continue;
			}
			else if (*top_target > 0 && startColumn_move[*top_start - 1] > targetColumn_move[*top_target - 1])
			{
				cct_setcolor(); //�ָ�ȱʡ��ɫ
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				cct_gotoxy(0, HORIZONTAL_Y + 3);
				cout << "����ѹС�̣��Ƿ��ƶ�!";
				Sleep(10 * TIME);
				cct_gotoxy(0, HORIZONTAL_Y + 3);
				cout << "                                                 ";

				continue;
			}
			else//�ɽ���
			{
				temp = pop(src, layer);
				push(dst, temp, layer);
			}

			cct_setcolor(); //�ָ�ȱʡ��ɫ
			cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��
			showVerticalChange(src, dst, VERTICAL_X, VERTICAL_Y);
			cct_gotoxy(0, HORIZONTAL_Y);
			cout << "��" << setw(4) << STEP << ' ' << "��" << '(' << setw(2) << targetColumn_move[*top_target - 1] << "#: " << src << "-->" << dst << ") ";
			showColumn_horizontal();
			move(src, dst);

			STEP++;

			if (*top_target == layer)//��������ƶ�
			{
				isEND = 2;
				break;
			}
		}		
	}

	cct_gotoxy(0, HORIZONTAL_Y + 3);
	switch (isEND)
	{
		case 1:
			cct_setcolor(); //�ָ�ȱʡ��ɫ
			cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��
			cout << "��Ϸ��ֹ!!!!!";
			break;
		case 2:
			cct_setcolor(); //�ָ�ȱʡ��ɫ
			cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��
			cout << "��Ϸ����!!!!!";
			break;
	}
}
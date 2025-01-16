/* 1850917 ��ʫ�� ���� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	   /*��λ���غϵ�ʱ��*/
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
char menu()
{
	char chInput_choice;
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,�����ͷʱ�������ƶ�)" << endl;
	cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����,�����ͷʱ�������ƶ�)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0 - 6] ";
	while (1)
	{
		chInput_choice = _getche();
		if (chInput_choice == '0' || chInput_choice == '1' || chInput_choice == '2' || chInput_choice == '3' || chInput_choice == '4' || chInput_choice == '5' || chInput_choice == '6')
			break;
	}
	return chInput_choice;
}

void move_by_ijkl(const HANDLE hout, char chInput_choice)
{
	int X = 35, Y = 8;
	char chInput;

	while (1)
	{
		chInput = _getch();

		/*��i/j/k/l���й���ƶ�*/
		if (chInput_choice == '5' || chInput_choice == '6')//������������ƶ�
		{
			/*�����ǿ������ת���ĵõ���ASCII��Ϊ��-32��75������75�롰K����ASCII��һ��*/
			/*�ж��ַ���ASCII�Ƿ���Ϊ-32�������������K*/
			if (int(chInput) == -32)
			{
				chInput = _getch();
				continue;
			}
		}
		if (chInput == 'i' || chInput == 'I')//��
		{
			Y--;
		}
		if (chInput == 'k' || chInput == 'K')//��
		{
			Y++;
		}
		if (chInput == 'j' || chInput == 'J')//��
		{
			X--;
		}
		if (chInput == 'l' || chInput == 'L')//��
		{
			X++;
		}
		if (chInput == ' ')
		{
			cout << ' ' << char(8);
		}
		if (chInput == 'q' || chInput == 'Q')//��Q/q������Ϸ
		{
			gotoxy(hout, 0, 23);
			cout << "��Ϸ���������س������ز˵�." << endl;
			break;
		}

		/*�߽�ֹͣ*/
		if (chInput_choice == '1' || chInput_choice == '5')
		{
			if (X > 68)
				X = 68;
			if (X < 1)
				X = 1;
			if (Y > 17)
				Y = 17;
			if (Y < 1)
				Y = 1;
			if (X > 0 && X < 69 && Y>0 && Y <= 17)
			{
				gotoxy(hout, X, Y);
			}
		}
		/*�߽����*/
		if (chInput_choice == '2' || chInput_choice == '6')
		{
			if (X > 68)
				X = 1;
			if (X < 1)
				X = 68;
			if (Y > 17)
				Y = 1;
			if (Y < 1)
				Y = 17;
			if (X > 0 && X < 69 && Y>0 && Y <= 17)
			{
				gotoxy(hout, X, Y);
			}
		}
	}
}


void move_by_arrow(const HANDLE hout, char chInput_choice)
{
	int X = 35, Y = 8;
	char chInput;

	while (1)
	{
		chInput = _getch();

		/*�ü�ͷ���й���ƶ�*/
		if (int(chInput) == -32)
		{
			chInput = _getch();
			if (int(chInput) == 72)//��
			{
				Y--;
			}
			else if (int(chInput) == 80)//��
			{
				Y++;
			}
			else if (int(chInput) == 75)//��
			{
				X--;
			}
			else if (int(chInput) == 77)//��
			{
				X++;
			}
			else
			{
				continue;
			}
		}
		if (chInput == ' ')
		{
			cout << ' ' << char(8);
		}
		if (chInput == 'q' || chInput == 'Q')//��Q/q������Ϸ
		{
			gotoxy(hout, 0, 23);
			cout << "��Ϸ���������س������ز˵�." << endl;
			break;
		}

		/*�߽�ֹͣ*/
		if (chInput_choice == '3')
		{
			if (X > 68)
				X = 68;
			if (X < 1)
				X = 1;
			if (Y > 17)
				Y = 17;
			if (Y < 1)
				Y = 1;
			if (X > 0 && X < 69 && Y>0 && Y <= 17)
			{
				gotoxy(hout, X, Y);
			}
		}
		/*�߽����*/
		if (chInput_choice == '4')
		{
			if (X > 68)
				X = 1;
			if (X < 1)
				X = 68;
			if (Y > 17)
				Y = 1;
			if (Y < 1)
				Y = 17;
			if (X > 0 && X < 69 && Y>0 && Y <= 17)
			{
				gotoxy(hout, X, Y);
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	while (1)
	{
		const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

		/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
		srand((unsigned int)(time(0)));

		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		/*��ʾ�˵�����ѡ��˵�*/
		char chInput_choice;
		chInput_choice = menu();
		/*��ѡ���˳���ֱ���˳�*/
		if (chInput_choice == '0')
			break;

		/* ��ʾ��ʼ�ı߿����е�����ַ� */
		init_border(hout);

		/*ʹ���ͣ���ɡ�*����ɵı߿������λ��*/
		gotoxy(hout, 35, 8);

		/*����˵���Ӧģʽ*/
		if (chInput_choice == '1' || chInput_choice == '2'|| chInput_choice == '5' || chInput_choice == '6')
			move_by_ijkl(hout, chInput_choice);
		if (chInput_choice == '3' || chInput_choice == '4')
			move_by_arrow(hout, chInput_choice);

		while (1)
		{
			char enter;
			enter = _getch();
			if (enter == char(13))
				break;
		}
	}

	return 0;
}

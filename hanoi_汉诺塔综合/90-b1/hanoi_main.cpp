/* ���� 1850917 ��ʫ�� */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);

	char mode;
	int layer;
	char startColumn;
	char targetColumn;
	char transitColumn;
	int speed = 0;

	while (1)
	{
		//cct_cls();

		/*�˵�����ʾ��ѡ��*/
		mode = printAndselctMenu();

		/*��ѡ���˳���ֱ���˳�*/
		if (mode == '0')
			break;

		switch (mode)
		{
			case '1':// 1.������
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				hanoi(layer, startColumn, transitColumn, targetColumn, '1');

				cout <<endl<< "���س�������...";
				break;


			case '2'://2.�����⣨������¼��
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				hanoi(layer, startColumn, transitColumn, targetColumn, '2');

				cout << endl << "���س�������...";
				break;


			case '3'://3.�ڲ�������ʾ������
				
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				hanoi(layer, startColumn, transitColumn, targetColumn, '3', layer);

				cout << endl << "���س�������...";
				break;


			case '4'://4.�ڲ�������ʾ������+����
				speed=inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();

				cout << "�� " << startColumn << " �ƶ��� " << targetColumn << "����" << layer << " �㣬��ʱ����Ϊ " << speed;

				cct_gotoxy(0, 17);
				cout << "��ʼ:" << setw(15) << ' ';
				showColumn_horizontal();
				showColumn_vertical();

				hanoi(layer, startColumn, transitColumn, targetColumn, '4', layer, speed);

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				cout << endl << "���س�������...";
				break;


			case '5'://5.ͼ�ν�-Ԥ��-������Բ��
				/*����*/
				cct_cls();

				drawColumn();

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				cout << endl << "���س�������...";
				break;


			case '6'://6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();//����

				drawColumn();
				drawPlate();

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				cout << endl << "���س�������";
				break;


			case '7'://7.ͼ�ν� - Ԥ�� - ��һ���ƶ�
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();//����

				cout << "�� " << startColumn << " �ƶ��� " << targetColumn << "����" << layer << " ��";

				drawColumn();
				drawPlate();

				hanoi(layer, startColumn, transitColumn, targetColumn, '7', layer);

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				cout << endl << "���س�������...";
				break;


			case '8'://8.ͼ�ν�-�Զ��ƶ��汾
				speed = inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();//����

				cout << "�� " << startColumn << " �ƶ��� " << targetColumn << "����" << layer << " �㣬��ʱ����Ϊ " << speed;

				cct_gotoxy(0, HORIZONTAL_Y);
				cout << "��ʼ:" << setw(15) << ' ';
				showColumn_horizontal();

				showColumn_vertical(VERTICAL_X, VERTICAL_Y);

				drawColumn();
				drawPlate();

				hanoi(layer, startColumn, transitColumn, targetColumn, '8', layer, speed);

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				cout << endl << "���س�������...";
				break;


			case '9'://9.ͼ�ν�-��Ϸ��
				inputBaseInfo(mode, &layer, &startColumn, &transitColumn, &targetColumn);
				initStartColumn(startColumn, layer);

				cct_cls();//����

				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				/*��ʼ��ʾ*/
				cout << "�� " << startColumn << " �ƶ��� " << targetColumn << "����" << layer << " ��";
				cct_gotoxy(0, HORIZONTAL_Y);
				cout << "��ʼ:" << setw(15) << ' ';

				showColumn_horizontal();

				showColumn_vertical(VERTICAL_X, VERTICAL_Y);

				drawColumn();
				drawPlate();

				game(layer, startColumn, targetColumn);

				cct_gotoxy(0, END_Y);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//���ù��ΪĬ��

				cout << endl << "���س�������...";
				break;
		}
		

		/*����*/
		resetSTEP();//���ü���
		resetColumn();//��������

		while (_getch() != '\r')
			;

		cct_cls();


	}
	

	return 0;
}

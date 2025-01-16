/* ���� 1850917 ��ʫ�� */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */
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
#define VERTICAL_Y     27  //������ʾ=====������
#define VERTICAL_X     9   //������ʾ=====����ߺ�����

/*������ʾ��Ϣ*/
#define HORIZONTAL_Y   32  //8.������ʾ������
//#define HORIZONTAL_X   9  //8.������ʾ������

#define END_Y          38  //��ʾ������������
#define TIME           100 




/*�˵�����ʾ��ѡ��*/
char printAndselctMenu();



/*���ܺ���*/
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

/*����*/
void resetSTEP();
void resetColumn();



/*������Ϣ����*/
int inputBaseInfo(char mode, int* n, char* src, char* tmp, char* dst);



/* =============================================================================================
    hanio�ݹ麯����ѡ��1-4��

    1.������: hanoi(int n, char src, char tmp, char dst, char mode);
    2.�����⣨������¼��: hanoi(int n, char src, char tmp, char dst, char mode);
    3.�ڲ�������ʾ������: hanoi(int n, char src, char tmp, char dst,char mode,int layer);
    4.�ڲ�������ʾ������+����: hanoi(int n, char src, char tmp, char dst, char mode,int layer,int speed)

    6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������:hanoi(int n, char src, char tmp, char dst, char mode);
    7.ͼ�ν�-Ԥ��-��һ���ƶ�:hanoi(int n, char src, char tmp, char dst, char mode,int layer,int speed)
================================================================================================ */
void hanoi(int n, char src, char tmp, char dst, char mode, int layer = 0, int speed = 0);
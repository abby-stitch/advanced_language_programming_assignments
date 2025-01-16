/* 1850917 ���� ��ʫ�� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 ������ų���
				 ����const�ͱ���
		������ ������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */

char print_letters(char start_ch, char end_ch, int order);
void print_space(int n);
void print_tower_with_space(char start_ch, char end_ch, int order, int numOfspace);

/***************************************************************************
	 �������ƣ�
	 ��    �ܣ���������ӡ������
	 ���������order - 0 ������������
			   order - 1 ������������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* ����ʵ�֣������в������κ���ʽ��ѭ�����������徲̬�ֲ����� */
	int numOfspace = 0;
	print_tower_with_space(start_ch, end_ch, order, numOfspace);
	
}
void print_tower_with_space(char start_ch, char end_ch, int order,int numOfspace)
{
	/* ����ʵ�֣������в������κ���ʽ��ѭ�����������徲̬�ֲ����� */
	char keyLetter = end_ch;
	if (order == 0)
	{
		if (end_ch == start_ch)
		{
			print_space(numOfspace);
			print_letters(start_ch, end_ch, order);
			cout << endl;
		}
		else
		{
			print_tower_with_space(start_ch, char(end_ch - 1), order, numOfspace + 1);
			print_space(numOfspace);
			print_letters(start_ch, end_ch, order);
			cout << endl;
		}
	}
	else if (order == 1)
	{
		if (start_ch == end_ch)
		{
			print_space(numOfspace);
			print_letters(start_ch, end_ch, order);
			cout << endl;
		}
		else
		{
			print_space(numOfspace);
			print_letters(start_ch, end_ch, order);
			cout << endl;
			print_tower_with_space(char(start_ch + 1), end_ch, order,numOfspace+1);
		}
	}
}

/***************************************************************************
	�������ƣ�
	��    �ܣ���ӡÿ����ĸ
	���������order - 0 ������������
			  order - 1 ������������
	�� �� ֵ��
	˵    ����
  ***************************************************************************/
char print_letters(char start_ch, char end_ch, int order)
{
	if (order == 0)
	{
		if (start_ch == end_ch)
		{
			cout << start_ch;
		}
		else
		{

			cout << end_ch;
			print_letters(start_ch, end_ch - 1, order);
			cout << end_ch;
		}
		return end_ch;
	}
	if (order == 1)
	{
		if (start_ch == end_ch)
		{
			cout << end_ch;
		}
		else
		{
			cout << start_ch;
			print_letters(start_ch + 1, end_ch, order);
			cout << start_ch;
		}
		return start_ch;
	}
}


void print_space(int n)
{
	if (n != 0)
	{
		cout << ' ';
		print_space(n - 1);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	while (1) {
		cout << "����������ַ�(A~Z)" << endl;
		end_ch = getchar();			//����������һ���ַ�
		while (getchar() != '\n')	//��ջ�����ʣ���ַ�
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}

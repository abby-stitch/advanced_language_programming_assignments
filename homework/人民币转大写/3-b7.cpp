/* 1850917 ���� ��ʫ�� */
#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
	cout << "������[0-100��)֮������֣�" << endl;
	/*�ֽ�λ��*/
	double num, num1, num2;
	cin >> num;
	num1 = num * 0.1;
	num2 = num1 - (int)num1;
	int decimal = int((num2 + 0.000001) * 1000);

	int bit_2 = decimal % 10;//��
	decimal /= 10;
	int bit_1 = decimal % 10;//��
	decimal /= 10;
	int bit1 = decimal % 10;//Բ

	int bit2 = (int)num1 % 10;//ʮλ
	num1 /= 10;
	int bit3 = (int)num1 % 10;//��λ
	num1 /= 10;
	int bit4 = (int)num1 % 10;//ǧλ
	num1 /= 10;
	int bit5 = (int)num1 % 10;//��λ
	num1 /= 10;
	int bit6 = (int)num1 % 10;//ʮ��λ
	num1 /= 10;
	int bit7 = (int)num1 % 10;//����λ
	num1 /= 10;
	int bit8 = (int)num1 % 10;//ǧ��λ
	num1 /= 10;
	int bit9 = (int)num1 % 10;//��λ
	num1 /= 10;
	int bit10 = (int)num1 % 10;//ʮ��λ
	num1 /= 10;

	/*����ж�*/
	bool level1 = bit10 != 0 || bit9 != 0;//ʮ��~���Ƿ����
	bool level2 = bit8 != 0 || bit7 != 0 || bit6 != 0 || bit5 != 0;//ǧ��~���Ƿ����
	bool level3 = bit4 != 0 || bit3 != 0 || bit2 != 0 || bit1 != 0;//ǧ~Ԫ�Ƿ����
	bool level4 = bit_1 != 0 || bit_2 != 0;//��~���Ƿ����

	cout << "��д����ǣ�" << endl;

	/*ʮ��~�ڷ������*/
	if (level1)
	{
		/*ʮ��λ*/
		switch (bit10)
		{
			case 0:
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
		}
		/*��λ*/
		switch (bit9)
		{
			case 0:
				break;
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
		}
		cout << "��";
	}

	/*ǧ��~��������*/
	if (level2)
	{
		/*ǧ��λ*/
		switch (bit8)
		{
			case 0:
				if (level1)//��ʮ��~��λ����
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
		}
		/*����λ*/
		switch (bit7)
		{
			case 0:
				if (bit8 && (bit5 || bit6))
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
		}
		/*ʮ��λ*/
		switch (bit6)
		{
			case 0:
				if (bit7 && bit5)
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
		}
		/*��λ*/
		switch (bit5)
		{
			case 0:
				break;
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
		}
		cout << "��";
	}

	/*ǧ~Ԫ�������*/
	if (level3)
	{
		/*ǧλ*/
		switch (bit4)
		{
			case 0:
				if (level1 || level2)
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
		}
		/*��λ*/
		switch (bit3)
		{
			case 0:
				if (bit4 && (bit2 || bit1))
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
		}
		/*ʮλ*/
		switch (bit2)
		{
			case 0:
				if (bit3 && bit1)
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
		}
		/*Բ*/
		switch (bit1)
		{
			case 0:
				break;
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
		}
	}
	else if (!(level1 || level2 || level3 || level4))//ʮ��~ԪȫΪ0�ҽ�~��ҲΪ0
	{
		cout << "��Բ��";
	}
	if (level1 || level2 || level3)
	{
		cout << "Բ";
	}
	/*��~�ַ������*/
	if (level4)
	{
		/*��*/
		switch (bit_1)
		{
			case 0:
				if (level3 && bit_2)
				{
					cout << "��";
				}
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ƽ�";
				break;
			case 9:
				cout << "����";
				break;
		}
		/*��*/
		switch (bit_2)
		{
			case 0:
				cout << "��";
				break;
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�Ʒ�";
				break;
			case 9:
				cout << "����";
				break;
		}
	}
	else if (level1 || level2 || level3)
	{
		cout << "��";
	}

	cout << endl;

	return 0;
}
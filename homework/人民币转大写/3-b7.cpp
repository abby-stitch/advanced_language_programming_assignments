/* 1850917 µçĞÅ ÁºÊ«Ñş */
#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö£º" << endl;
	/*·Ö½âÎ»Êı*/
	double num, num1, num2;
	cin >> num;
	num1 = num * 0.1;
	num2 = num1 - (int)num1;
	int decimal = int((num2 + 0.000001) * 1000);

	int bit_2 = decimal % 10;//·Ö
	decimal /= 10;
	int bit_1 = decimal % 10;//½Ç
	decimal /= 10;
	int bit1 = decimal % 10;//Ô²

	int bit2 = (int)num1 % 10;//Ê®Î»
	num1 /= 10;
	int bit3 = (int)num1 % 10;//°ÙÎ»
	num1 /= 10;
	int bit4 = (int)num1 % 10;//Ç§Î»
	num1 /= 10;
	int bit5 = (int)num1 % 10;//ÍòÎ»
	num1 /= 10;
	int bit6 = (int)num1 % 10;//Ê®ÍòÎ»
	num1 /= 10;
	int bit7 = (int)num1 % 10;//°ÙÍòÎ»
	num1 /= 10;
	int bit8 = (int)num1 % 10;//Ç§ÍòÎ»
	num1 /= 10;
	int bit9 = (int)num1 % 10;//ÒÚÎ»
	num1 /= 10;
	int bit10 = (int)num1 % 10;//Ê®ÒÚÎ»
	num1 /= 10;

	/*Êä³öÅĞ¶Ï*/
	bool level1 = bit10 != 0 || bit9 != 0;//Ê®ÒÚ~ÒÚÊÇ·ñ·ÇÁã
	bool level2 = bit8 != 0 || bit7 != 0 || bit6 != 0 || bit5 != 0;//Ç§Íò~ÍòÊÇ·ñ·ÇÁã
	bool level3 = bit4 != 0 || bit3 != 0 || bit2 != 0 || bit1 != 0;//Ç§~ÔªÊÇ·ñ·ÇÁã
	bool level4 = bit_1 != 0 || bit_2 != 0;//½Ç~·ÖÊÇ·ñ·ÇÁã

	cout << "´óĞ´½á¹ûÊÇ£º" << endl;

	/*Ê®ÒÚ~ÒÚ·ÇÁãÊä³ö*/
	if (level1)
	{
		/*Ê®ÒÚÎ»*/
		switch (bit10)
		{
			case 0:
				break;
			case 1:
				cout << "Ò¼Ê°";
				break;
			case 2:
				cout << "·¡Ê°";
				break;
			case 3:
				cout << "ÈşÊ°";
				break;
			case 4:
				cout << "ËÁÊ°";
				break;
			case 5:
				cout << "ÎéÊ°";
				break;
			case 6:
				cout << "Â½Ê°";
				break;
			case 7:
				cout << "ÆâÊ°";
				break;
			case 8:
				cout << "°ÆÊ°";
				break;
			case 9:
				cout << "¾ÁÊ°";
				break;
		}
		/*ÒÚÎ»*/
		switch (bit9)
		{
			case 0:
				break;
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
		}
		cout << "ÒÚ";
	}

	/*Ç§Íò~Íò·ÇÁãÊä³ö*/
	if (level2)
	{
		/*Ç§ÍòÎ»*/
		switch (bit8)
		{
			case 0:
				if (level1)//ÈôÊ®ÒÚ~ÒÚÎ»·ÇÁã
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼Çª";
				break;
			case 2:
				cout << "·¡Çª";
				break;
			case 3:
				cout << "ÈşÇª";
				break;
			case 4:
				cout << "ËÁÇª";
				break;
			case 5:
				cout << "ÎéÇª";
				break;
			case 6:
				cout << "Â½Çª";
				break;
			case 7:
				cout << "ÆâÇª";
				break;
			case 8:
				cout << "°ÆÇª";
				break;
			case 9:
				cout << "¾ÁÇª";
				break;
		}
		/*°ÙÍòÎ»*/
		switch (bit7)
		{
			case 0:
				if (bit8 && (bit5 || bit6))
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼°Û";
				break;
			case 2:
				cout << "·¡°Û";
				break;
			case 3:
				cout << "Èş°Û";
				break;
			case 4:
				cout << "ËÁ°Û";
				break;
			case 5:
				cout << "Îé°Û";
				break;
			case 6:
				cout << "Â½°Û";
				break;
			case 7:
				cout << "Æâ°Û";
				break;
			case 8:
				cout << "°Æ°Û";
				break;
			case 9:
				cout << "¾Á°Û";
				break;
		}
		/*Ê®ÍòÎ»*/
		switch (bit6)
		{
			case 0:
				if (bit7 && bit5)
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼Ê°";
				break;
			case 2:
				cout << "·¡Ê°";
				break;
			case 3:
				cout << "ÈşÊ°";
				break;
			case 4:
				cout << "ËÁÊ°";
				break;
			case 5:
				cout << "ÎéÊ°";
				break;
			case 6:
				cout << "Â½Ê°";
				break;
			case 7:
				cout << "ÆâÊ°";
				break;
			case 8:
				cout << "°ÆÊ°";
				break;
			case 9:
				cout << "¾ÁÊ°";
				break;
		}
		/*ÍòÎ»*/
		switch (bit5)
		{
			case 0:
				break;
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
		}
		cout << "Íò";
	}

	/*Ç§~Ôª·ÇÁãÊä³ö*/
	if (level3)
	{
		/*Ç§Î»*/
		switch (bit4)
		{
			case 0:
				if (level1 || level2)
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼Çª";
				break;
			case 2:
				cout << "·¡Çª";
				break;
			case 3:
				cout << "ÈşÇª";
				break;
			case 4:
				cout << "ËÁÇª";
				break;
			case 5:
				cout << "ÎéÇª";
				break;
			case 6:
				cout << "Â½Çª";
				break;
			case 7:
				cout << "ÆâÇª";
				break;
			case 8:
				cout << "°ÆÇª";
				break;
			case 9:
				cout << "¾ÁÇª";
				break;
		}
		/*°ÙÎ»*/
		switch (bit3)
		{
			case 0:
				if (bit4 && (bit2 || bit1))
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼°Û";
				break;
			case 2:
				cout << "·¡°Û";
				break;
			case 3:
				cout << "Èş°Û";
				break;
			case 4:
				cout << "ËÁ°Û";
				break;
			case 5:
				cout << "Îé°Û";
				break;
			case 6:
				cout << "Â½°Û";
				break;
			case 7:
				cout << "Æâ°Û";
				break;
			case 8:
				cout << "°Æ°Û";
				break;
			case 9:
				cout << "¾Á°Û";
				break;
		}
		/*Ê®Î»*/
		switch (bit2)
		{
			case 0:
				if (bit3 && bit1)
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼Ê°";
				break;
			case 2:
				cout << "·¡Ê°";
				break;
			case 3:
				cout << "ÈşÊ°";
				break;
			case 4:
				cout << "ËÁÊ°";
				break;
			case 5:
				cout << "ÎéÊ°";
				break;
			case 6:
				cout << "Â½Ê°";
				break;
			case 7:
				cout << "ÆâÊ°";
				break;
			case 8:
				cout << "°ÆÊ°";
				break;
			case 9:
				cout << "¾ÁÊ°";
				break;
		}
		/*Ô²*/
		switch (bit1)
		{
			case 0:
				break;
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
		}
	}
	else if (!(level1 || level2 || level3 || level4))//Ê®ÒÚ~ÔªÈ«Îª0ÇÒ½Ç~·ÖÒ²Îª0
	{
		cout << "ÁãÔ²Õû";
	}
	if (level1 || level2 || level3)
	{
		cout << "Ô²";
	}
	/*½Ç~·Ö·ÇÁãÊä³ö*/
	if (level4)
	{
		/*½Ç*/
		switch (bit_1)
		{
			case 0:
				if (level3 && bit_2)
				{
					cout << "Áã";
				}
				break;
			case 1:
				cout << "Ò¼½Ç";
				break;
			case 2:
				cout << "·¡½Ç";
				break;
			case 3:
				cout << "Èş½Ç";
				break;
			case 4:
				cout << "ËÁ½Ç";
				break;
			case 5:
				cout << "Îé½Ç";
				break;
			case 6:
				cout << "Â½½Ç";
				break;
			case 7:
				cout << "Æâ½Ç";
				break;
			case 8:
				cout << "°Æ½Ç";
				break;
			case 9:
				cout << "¾Á½Ç";
				break;
		}
		/*·Ö*/
		switch (bit_2)
		{
			case 0:
				cout << "Õû";
				break;
			case 1:
				cout << "Ò¼·Ö";
				break;
			case 2:
				cout << "·¡·Ö";
				break;
			case 3:
				cout << "Èş·Ö";
				break;
			case 4:
				cout << "ËÁ·Ö";
				break;
			case 5:
				cout << "Îé·Ö";
				break;
			case 6:
				cout << "Â½·Ö";
				break;
			case 7:
				cout << "Æâ·Ö";
				break;
			case 8:
				cout << "°Æ·Ö";
				break;
			case 9:
				cout << "¾Á·Ö";
				break;
		}
	}
	else if (level1 || level2 || level3)
	{
		cout << "Õû";
	}

	cout << endl;

	return 0;
}
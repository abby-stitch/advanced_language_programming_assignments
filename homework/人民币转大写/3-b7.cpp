
#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
	cout << "请输入[0-100亿)之间的数字：" << endl;
	/*分解位数*/
	double num, num1, num2;
	cin >> num;
	num1 = num * 0.1;
	num2 = num1 - (int)num1;
	int decimal = int((num2 + 0.000001) * 1000);

	int bit_2 = decimal % 10;//分
	decimal /= 10;
	int bit_1 = decimal % 10;//角
	decimal /= 10;
	int bit1 = decimal % 10;//圆

	int bit2 = (int)num1 % 10;//十位
	num1 /= 10;
	int bit3 = (int)num1 % 10;//百位
	num1 /= 10;
	int bit4 = (int)num1 % 10;//千位
	num1 /= 10;
	int bit5 = (int)num1 % 10;//万位
	num1 /= 10;
	int bit6 = (int)num1 % 10;//十万位
	num1 /= 10;
	int bit7 = (int)num1 % 10;//百万位
	num1 /= 10;
	int bit8 = (int)num1 % 10;//千万位
	num1 /= 10;
	int bit9 = (int)num1 % 10;//亿位
	num1 /= 10;
	int bit10 = (int)num1 % 10;//十亿位
	num1 /= 10;

	/*输出判断*/
	bool level1 = bit10 != 0 || bit9 != 0;//十亿~亿是否非零
	bool level2 = bit8 != 0 || bit7 != 0 || bit6 != 0 || bit5 != 0;//千万~万是否非零
	bool level3 = bit4 != 0 || bit3 != 0 || bit2 != 0 || bit1 != 0;//千~元是否非零
	bool level4 = bit_1 != 0 || bit_2 != 0;//角~分是否非零

	cout << "大写结果是：" << endl;

	/*十亿~亿非零输出*/
	if (level1)
	{
		/*十亿位*/
		switch (bit10)
		{
			case 0:
				break;
			case 1:
				cout << "壹拾";
				break;
			case 2:
				cout << "贰拾";
				break;
			case 3:
				cout << "叁拾";
				break;
			case 4:
				cout << "肆拾";
				break;
			case 5:
				cout << "伍拾";
				break;
			case 6:
				cout << "陆拾";
				break;
			case 7:
				cout << "柒拾";
				break;
			case 8:
				cout << "捌拾";
				break;
			case 9:
				cout << "玖拾";
				break;
		}
		/*亿位*/
		switch (bit9)
		{
			case 0:
				break;
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
		}
		cout << "亿";
	}

	/*千万~万非零输出*/
	if (level2)
	{
		/*千万位*/
		switch (bit8)
		{
			case 0:
				if (level1)//若十亿~亿位非零
				{
					cout << "零";
				}
				break;
			case 1:
				cout << "壹仟";
				break;
			case 2:
				cout << "贰仟";
				break;
			case 3:
				cout << "叁仟";
				break;
			case 4:
				cout << "肆仟";
				break;
			case 5:
				cout << "伍仟";
				break;
			case 6:
				cout << "陆仟";
				break;
			case 7:
				cout << "柒仟";
				break;
			case 8:
				cout << "捌仟";
				break;
			case 9:
				cout << "玖仟";
				break;
		}
		/*百万位*/
		switch (bit7)
		{
			case 0:
				if (bit8 && (bit5 || bit6))
				{
					cout << "零";
				}
				break;
			case 1:
				cout << "壹佰";
				break;
			case 2:
				cout << "贰佰";
				break;
			case 3:
				cout << "叁佰";
				break;
			case 4:
				cout << "肆佰";
				break;
			case 5:
				cout << "伍佰";
				break;
			case 6:
				cout << "陆佰";
				break;
			case 7:
				cout << "柒佰";
				break;
			case 8:
				cout << "捌佰";
				break;
			case 9:
				cout << "玖佰";
				break;
		}
		/*十万位*/
		switch (bit6)
		{
			case 0:
				if (bit7 && bit5)
				{
					cout << "零";
				}
				break;
			case 1:
				cout << "壹拾";
				break;
			case 2:
				cout << "贰拾";
				break;
			case 3:
				cout << "叁拾";
				break;
			case 4:
				cout << "肆拾";
				break;
			case 5:
				cout << "伍拾";
				break;
			case 6:
				cout << "陆拾";
				break;
			case 7:
				cout << "柒拾";
				break;
			case 8:
				cout << "捌拾";
				break;
			case 9:
				cout << "玖拾";
				break;
		}
		/*万位*/
		switch (bit5)
		{
			case 0:
				break;
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
		}
		cout << "万";
	}

	/*千~元非零输出*/
	if (level3)
	{
		/*千位*/
		switch (bit4)
		{
			case 0:
				if (level1 || level2)
				{
					cout << "零";
				}
				break;
			case 1:
				cout << "壹仟";
				break;
			case 2:
				cout << "贰仟";
				break;
			case 3:
				cout << "叁仟";
				break;
			case 4:
				cout << "肆仟";
				break;
			case 5:
				cout << "伍仟";
				break;
			case 6:
				cout << "陆仟";
				break;
			case 7:
				cout << "柒仟";
				break;
			case 8:
				cout << "捌仟";
				break;
			case 9:
				cout << "玖仟";
				break;
		}
		/*百位*/
		switch (bit3)
		{
			case 0:
				if (bit4 && (bit2 || bit1))
				{
					cout << "零";
				}
				break;
			case 1:
				cout << "壹佰";
				break;
			case 2:
				cout << "贰佰";
				break;
			case 3:
				cout << "叁佰";
				break;
			case 4:
				cout << "肆佰";
				break;
			case 5:
				cout << "伍佰";
				break;
			case 6:
				cout << "陆佰";
				break;
			case 7:
				cout << "柒佰";
				break;
			case 8:
				cout << "捌佰";
				break;
			case 9:
				cout << "玖佰";
				break;
		}
		/*十位*/
		switch (bit2)
		{
			case 0:
				if (bit3 && bit1)
				{
					cout << "零";
				}
				break;
			case 1:
				cout << "壹拾";
				break;
			case 2:
				cout << "贰拾";
				break;
			case 3:
				cout << "叁拾";
				break;
			case 4:
				cout << "肆拾";
				break;
			case 5:
				cout << "伍拾";
				break;
			case 6:
				cout << "陆拾";
				break;
			case 7:
				cout << "柒拾";
				break;
			case 8:
				cout << "捌拾";
				break;
			case 9:
				cout << "玖拾";
				break;
		}
		/*圆*/
		switch (bit1)
		{
			case 0:
				break;
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
		}
	}
	else if (!(level1 || level2 || level3 || level4))//十亿~元全为0且角~分也为0
	{
		cout << "零圆整";
	}
	if (level1 || level2 || level3)
	{
		cout << "圆";
	}
	/*角~分非零输出*/
	if (level4)
	{
		/*角*/
		switch (bit_1)
		{
			case 0:
				if (level3 && bit_2)
				{
					cout << "零";
				}
				break;
			case 1:
				cout << "壹角";
				break;
			case 2:
				cout << "贰角";
				break;
			case 3:
				cout << "叁角";
				break;
			case 4:
				cout << "肆角";
				break;
			case 5:
				cout << "伍角";
				break;
			case 6:
				cout << "陆角";
				break;
			case 7:
				cout << "柒角";
				break;
			case 8:
				cout << "捌角";
				break;
			case 9:
				cout << "玖角";
				break;
		}
		/*分*/
		switch (bit_2)
		{
			case 0:
				cout << "整";
				break;
			case 1:
				cout << "壹分";
				break;
			case 2:
				cout << "贰分";
				break;
			case 3:
				cout << "叁分";
				break;
			case 4:
				cout << "肆分";
				break;
			case 5:
				cout << "伍分";
				break;
			case 6:
				cout << "陆分";
				break;
			case 7:
				cout << "柒分";
				break;
			case 8:
				cout << "捌分";
				break;
			case 9:
				cout << "玖分";
				break;
		}
	}
	else if (level1 || level2 || level3)
	{
		cout << "整";
	}

	cout << endl;

	return 0;

}

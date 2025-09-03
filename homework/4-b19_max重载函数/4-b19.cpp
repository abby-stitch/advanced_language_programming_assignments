
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	int max = a;
	max = max > b ? max : b;
	max = max > c ? max : c;
	return max;
}

int max(int a, int b, int c, int d)
{
	int max = a;
	max = max > b ? max : b;
	max = max > c ? max : c;
	max = max > d ? max : d;
	return max;
}
int main()
{
	int num;
	int a = 0, b = 0, c = 0, d = 0;
	int maxNum = 0;
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();//清除错误标志
			cin.ignore(10000, '\n');//清除缓冲区的当前行
			continue;
		}
		if (num >= 2 && num <= 4 && cin.good())
		{
			//num=2
			if (num == 2)
			{
				cin >> a;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				cin >> b;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				if (a <= 0 || b <= 0)
					continue;
				maxNum = max(a, b);
			}
			//num=3
			else if (num == 3)
			{
				cin >> a;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				cin >> b;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				cin >> c;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				if (a <= 0 || b <= 0 || c <= 0)
					continue;
				maxNum = max(a, b, c);
			}
			//num=4
			else if (num == 4)
			{
				cin >> a;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				cin >> b;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				cin >> c;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				cin >> d;
				if (cin.fail())
				{
					cin.clear();//清除错误标志
					cin.ignore(10000, '\n');//清除缓冲区的当前行
					continue;
				}
				if (a <= 0 || b <= 0 || c <= 0 || d <= 0)
					continue;
				maxNum = max(a, b, c, d);
			}
			cout << "max=" << maxNum << endl;
			break;
		}
		else
		{
			cout << "个数输入错误" << endl;
			break;
		}
	}

		return 0;

}

/* 1850917 ��ʫ�� ���� */
#include <iostream>
using namespace std;

int min(int a, int b, int c = INT_MAX, int d = INT_MAX)
{
	int min = a;
	min = min < b ? min : b;
	min = min < c ? min : c;
	min = min < d ? min : d;
	return min;
}
int main()
{
	int num;
	int a = 0, b = 0, c = 0, d = 0;
	int minNum = 0;
	while (1)
	{
		cout << "���������num��num����������" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();//��������־
			cin.ignore(10000, '\n');//����������ĵ�ǰ��
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
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				cin >> b;
				if (cin.fail())
				{
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				if (a <= 0 || b <= 0)
					continue;
				minNum = min(a, b);
			}
			//num=3
			else if (num == 3)
			{
				cin >> a;
				if (cin.fail())
				{
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				cin >> b;
				if (cin.fail())
				{
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				cin >> c;
				if (cin.fail())
				{
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				if (a <= 0 || b <= 0 || c <= 0)
					continue;
				minNum = min(a, b, c);
			}
			//num=4
			else if (num == 4)
			{
				cin >> a;
				if (cin.fail())
				{
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				cin >> b;
				if (cin.fail())
				{
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				cin >> c;
				if (cin.fail())
				{
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				cin >> d;
				if (cin.fail())
				{
					cin.clear();//��������־
					cin.ignore(10000, '\n');//����������ĵ�ǰ��
					continue;
				}
				if (a <= 0 || b <= 0 || c <= 0 || d <= 0)
					continue;
				minNum = min(a, b, c, d);
			}
			cout << "min=" << minNum << endl;
			break;
		}
		else
		{
			cout << "�����������" << endl;
			break;
		}
	}

	return 0;
}
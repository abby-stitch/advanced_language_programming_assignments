#include <iostream>
#include <math.h>
using namespace std;

void awei0()
{
	cout << "不是一元二次方程" << endl;
}
void liangbudeng(double a, double b, double c)
{
	cout << "有两个不等实根：" << endl;

	double x1, x2;
	x1 = (-b + sqrt(b * b - 4.0 * a * c)) / 2.0 * a;
	x2 = (-b - sqrt(b * b - 4.0 * a * c)) / 2.0 * a;

	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}
void liangxiangdeng(double a, double b, double c)
{
	cout << "有两个相等实根：" << endl;

	double x;
	x = (-b / (2.0 * a));
	cout << "x1=x2=" << x << endl;
}
void liangxugen(double a, double b, double c)
{
	cout << "有两个虚根：" << endl;

	cout << "x1=" << -b / (2.0 * a) << '+' << sqrt(fabs(b * b - 4.0 * a * c)) / (2.0 * a) << 'i' << endl;
	cout << "x2=" << -b / (2.0 * a) << '-' << sqrt(fabs(b * b - 4.0 * a * c)) / (2.0 * a) << 'i' << endl;
}
int panduan(double a, double b, double c)
{
	if (fabs(a - 0) < 1e-6)
		return 1;
	else
	{
		double delta = 0;
		delta = b * b - 4.0 * a * c;
		if (delta > 0)
			return 2;
		else if (fabs(delta) < 1e-6)
			return 3;
		else
			return 4;
	}
}
int main()
{
	double a, b, c;
	int qingkuang;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;

	double delta;
	delta = b * b - 4.0 * a * c;

	if (fabs(a) < 1e-6)
		qingkuang = 1;
	else
	{
		if (delta > 0)
			qingkuang = 2;
		else if (fabs(delta) < 1e-6)
			qingkuang = 3;
		else
			qingkuang = 4;
	}
	switch (qingkuang)
	{
		case 1:
			awei0();
			break;
		case 2:
			liangbudeng(a, b, c);
			break;
		case 3:
			liangxiangdeng(a, b, c);
			break;
		case 4:
			liangxugen(a, b, c);
			break;
	}
	return 0;
}
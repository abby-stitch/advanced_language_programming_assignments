#define _CRT_SECURE_NO_WARNINGS  //VS2019��Ҫ
#include <iostream>
using namespace std;

int main()
{
    char a[10];
    int i;

    for (i = 0; i < 10; i++)
        cout << int(a[i]) << endl;

    scanf("%s", a);

    for (i = 0; i < 10; i++)
        cout << int(a[i]) << endl;

    return 0;
}

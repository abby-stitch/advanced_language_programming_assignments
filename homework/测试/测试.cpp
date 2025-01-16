#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    unsigned char ch;

    while (1)
    {
        ch = cin.get();
        if (ch == '0')
            break;
        else
            cout <<short(ch) << endl;
   }

    return 0;
}

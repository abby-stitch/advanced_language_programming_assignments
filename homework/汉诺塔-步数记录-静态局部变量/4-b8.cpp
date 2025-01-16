/* 1850917 ��ʫ�� ���� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
               3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int count = 1;
    if (n == 1)
    {
        cout << setw(5)  << count << ':' << setw(3) << n << '#' << ' ' << src << "-->" << dst << endl;
        count++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(5)  << count << ':' << setw(3) << n << '#' << ' ' << src << "-->" << dst << endl;
        count++;
        hanoi(n - 1, tmp, src, dst);
    }
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����뺺ŵ���Ĳ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int inputLayer()
{
    int layer = 0;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> layer;
        if (cin.good() && layer > 0 && layer <= 16)
            break;
        else
        {
            cin.clear();
            cin.ignore();
        }
    }
    cin.clear();
    cin.ignore();

    return layer;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����뺺ŵ������ʼ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char inputStartColumn()
{
    char startColumn = 'A';
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> startColumn;
        if (cin.good()&& (startColumn >= 'A' && startColumn <= 'C' || startColumn >= 'a' && startColumn <= 'c'))
            break;
        else
        {
            cin.clear();
            cin.ignore();
        }
    }
    cin.clear();
    cin.ignore();

    if (int(startColumn) >= int('a'))
    {
        startColumn = startColumn - 'a' + 'A';
    }
    return startColumn;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����뺺ŵ����Ŀ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char inputTargetColumn(char startColumn)
{
    char targetColumn = 'A';
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> targetColumn;
        if (cin.good() && (targetColumn >= 'A' && targetColumn <= 'C' || targetColumn >= 'a' && targetColumn <= 'c'))
        {
            if (int(targetColumn) >= ('a'))
            {
                targetColumn = targetColumn - 'a' + 'A';
            }
            if (targetColumn != startColumn)
                break;
        }
        cin.clear();
        cin.ignore();
    }
    cin.clear();
    cin.ignore();

    return targetColumn;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж��м���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char inputTransitColumn(char startColumn, char targetColumn)
{
    char transitColumn = 'A';
    if (startColumn == 'A')
    {
        if (targetColumn == 'B')
            transitColumn = 'C';
        else
            transitColumn = 'B';
    }
    else if (startColumn == 'B')
    {
        if (targetColumn == 'A')
            transitColumn = 'C';
        else
            transitColumn = 'A';
    }
    else
    {
        if (targetColumn == 'A')
            transitColumn = 'B';
        else
            transitColumn = 'A';
    }
    return transitColumn;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
    int layer;
    char startColumn, targetColumn, transitColumn;
    layer = inputLayer();
    startColumn = inputStartColumn();
    targetColumn = inputTargetColumn(startColumn);
    transitColumn = inputTransitColumn(startColumn, targetColumn);

    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(layer, startColumn, transitColumn, targetColumn);

    cout << endl;
    return 0;
}
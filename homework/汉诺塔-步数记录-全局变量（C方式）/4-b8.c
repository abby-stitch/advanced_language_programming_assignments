/* 1850917 ��ʫ�� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 1;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
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
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
        count++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
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
    int ret = 0;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        ret=scanf("%d", &layer);
        if (ret==1&& layer > 0 && layer <= 16)
            break;
        else
        {
            while (getchar() != '\n');
            ret = 0;
        }
    }
    while (getchar() != '\n');
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
    char startColumn;
    int ret = 0;
    while (1)
    {
        printf("��������ʼ��(A-C)\n");
        ret = scanf("%c", &startColumn);
       // printf("startColumn=%c\n",startColumn);

        if (ret == 1 && (startColumn >= 'A' && startColumn <= 'C' || startColumn >= 'a' && startColumn <= 'c'))
            break;
        else
        {
            while (getchar() != '\n');
            ret = 0;
        }
    }
    if (startColumn >= 'a')
    {
        startColumn = startColumn - 'a' + 'A';
    }
    while (getchar() != '\n');
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
    char targetColumn;
    int ret = 0;

    while (1)
    {
        printf("������Ŀ����(A-C)\n");
        ret = scanf("%c", &targetColumn);
       // printf("targetColumn=%c\n", targetColumn);

        if (ret == 1 && (targetColumn >= 'A' && targetColumn <= 'C' || targetColumn >= 'a' && targetColumn <= 'c'))
        {
            if (targetColumn >= 'a')
            {
                targetColumn = targetColumn - 'a' + 'A';
            }
            if (targetColumn != startColumn)
                break;
        }
        while (getchar() != '\n');
        ret = 0;
    }
    while (getchar() != '\n');
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

    printf("�ƶ�����Ϊ:\n");
    hanoi(layer, startColumn, transitColumn, targetColumn);

    return 0;
}

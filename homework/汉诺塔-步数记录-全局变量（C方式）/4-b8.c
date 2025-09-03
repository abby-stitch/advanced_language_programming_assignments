
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 1;
/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
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
  函数名称：
  功    能：输入汉诺塔的层数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int inputLayer()
{
    int layer = 0;
    int ret = 0;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-16)\n");
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
  函数名称：
  功    能：输入汉诺塔的起始柱
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char inputStartColumn()
{
    char startColumn;
    int ret = 0;
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
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
  函数名称：
  功    能：输入汉诺塔的目标柱
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char inputTargetColumn(char startColumn)
{
    char targetColumn;
    int ret = 0;

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
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
  函数名称：
  功    能：判断中间柱
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
    int layer;
    char startColumn, targetColumn, transitColumn;
    layer = inputLayer();
    startColumn = inputStartColumn();
    targetColumn = inputTargetColumn(startColumn);
    transitColumn = inputTransitColumn(startColumn, targetColumn);

    printf("移动步骤为:\n");
    hanoi(layer, startColumn, transitColumn, targetColumn);

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

// 公共函数
// 打印字符串，前导0不打印
void printNum(char *num, int n)
{
    bool startFlag = false;
    for (int i = 0; i < n; i++)
    {
        if (num[i] != '0')
        {
            startFlag = true;
        }
        if (startFlag)
        {
            printf("%c", num[i]);
        }
    }
    printf("\n");
}

// n位数，+1
bool incrementNum(char *num, int n)
{
    bool isOverflow = false;

    // 单独处理最后一位，+1
    int carry = 0; // 进位
    int sum = (num[n - 1] - '0') + 1;
    if (sum == 10)
    {
        carry = 1;
        sum = 0;
    }
    num[n - 1] = sum + '0';

    // 由低到高逐位处理
    for (int i = n - 2; i >= 0 && carry == 1; i--)
    {
        int sum = (num[i] - '0') + carry;
        if (sum == 10)
        { // 第i位溢出
            carry = 1;
            sum = 0;
        }
        else
        {
            carry = 0;
        }
        num[i] = sum + '0';
    }
    // 最终是否有溢出
    if (carry == 1)
    {
        isOverflow = true;
    }

    return isOverflow;
}

// 方法1
void print1ToMaxOfNDigits_1(int n)
{
    if (n <= 0)
    {
        return;
    }
    // 分配 & 初始化内存空间
    char *num = new char[n + 1];
    memset(num, '0', n + 1);
    num[n] = '\0';

    bool isOverflow = false;
    do
    {
        printNum(num, n);
        isOverflow = incrementNum(num, n);
    } while (!isOverflow);

    delete[] num; // 容易忘
}

void f(char *num, int n, int index)
{
    // base case
    if (index == n)
    {
        printNum(num, n);
        return;
    }

    for (char c = '0'; c <= '9'; c++)
    {
        num[index] = c;
        f(num, n, index + 1);
    }
}

// 方法2：全排列
void print1ToMaxOfNDigits_2(int n)
{
    if (n <= 0)
    {
        return;
    }

    // 分配 & 初始化内存空间
    char *num = new char[n + 1];
    memset(num, '0', n + 1);
    num[n] = '\0';

    f(num, n, 0);

    delete[] num;
}

// 测试代码
void test(int n)
{
    printf("Test for %d begins:\n", n);
    print1ToMaxOfNDigits_2(n);
    printf("Test for %d ends:\n", n);
    printf("---------------------\n");
}

int main()
{
    /* 功能测试 */
    // test(1);
    // test(2);
    test(3);

    /* 特殊输入测试 */
    test(0);
    test(-1);

    return 0;
}
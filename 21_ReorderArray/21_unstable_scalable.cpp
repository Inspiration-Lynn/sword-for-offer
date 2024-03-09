#include <iostream>
#include <vector>

using namespace std;

void reorderArr(vector<int> &vec, bool (*func)(int))
{
    if (vec.empty())
        return;

    // l_ptr左边均为奇数 r_ptr右边均为偶数
    int l_ptr = 0, r_ptr = vec.size() - 1;

    while (l_ptr < r_ptr)
    {
        while (l_ptr < r_ptr && !func(l_ptr))
            l_ptr++;

        while (l_ptr < r_ptr && func(r_ptr))
            r_ptr--;

        if (l_ptr < r_ptr)
        {
            swap(vec[l_ptr], vec[r_ptr]);
        }
    }
}

// 可替换的模块
bool isEven(int num)
{
    // 返回是否为偶数
    return (num & 1) == 0;
}

void PrintVec(vector<int> &vec)
{
    for (const auto n : vec)
    {
        cout << n << " ";
    }
    cout << endl;
}

// 测试代码
void Test(string testName, vector<int> numbers, int length)
{
    if (!testName.empty())
        cout << testName << endl;

    printf("Test for solution 1:\n");
    PrintVec(numbers);
    reorderArr(numbers, isEven);
    PrintVec(numbers);
}

void Test1()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2()
{
    vector<int> numbers = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
    vector<int> numbers = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
    vector<int> numbers = {1};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
    vector<int> numbers = {2};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
    Test("Test6", {}, 0);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
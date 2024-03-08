/* 正则表达式匹配：回溯算法经典例子 */
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// 定义模式串单元的字符/字符串的类型
enum Char_type
{
    PURE_LETTER, // 纯字母，后面没有*
    DOT,         // ·
    POST_STAR    // 字母* or .*    // 一开始没有考虑.*
};

struct Char_unit
{
    Char_type type_;
    char content;
};

Char_unit getUnit(string str, int idx)
{
    assert(idx < str.size());
    struct Char_unit unit;
    if (idx + 1 < str.size() && str[idx + 1] == '*')
    {
        unit.content = str[idx];
        unit.type_ = POST_STAR;
    }
    else if (str[idx] == '.')
    {
        unit.content = '.';
        unit.type_ = DOT;
    }
    else
    {
        unit.content = str[idx];
        unit.type_ = PURE_LETTER;
    }
    return unit;
}

// 参数1：模板串 参数2：待匹配的字符串
bool f(string pattern, string str, int p_idx, int idx)
{
    // base case
    if (p_idx >= pattern.size() && idx >= str.size())
        return true;
    if (p_idx >= pattern.size())
    {
        return false;
    }
    if (idx >= str.size())
    {
        struct Char_unit unit = getUnit(pattern, p_idx);
        if (unit.type_ == POST_STAR)
        {
            return f(pattern, str, p_idx + 2, idx);
        }
        else
        {
            return false;
        }
    }

    struct Char_unit unit = getUnit(pattern, p_idx);
    if ((unit.type_ == PURE_LETTER && unit.content == str[idx]) || unit.type_ == DOT)
    {
        return f(pattern, str, p_idx + 1, idx + 1);
    }
    else if (unit.type_ == POST_STAR)
    {
        if (unit.content == str[idx] || unit.content == '.')
        {
            // 情况一开始没考虑全
            return f(pattern, str, p_idx, idx + 1) || f(pattern, str, p_idx + 2, idx + 1) || f(pattern, str, p_idx + 2, idx);
        }
        else
        {
            return f(pattern, str, p_idx + 2, idx);
        }
    }

    return false;
}

bool regular_match(string pattern, string str)
{
    return f(pattern, str, 0, 0);
}

// 测试代码
void Test(string testName, string str, string pattern, bool expected)
{
    if (!testName.empty())
        cout << testName << " begins: " << endl;

    if (regular_match(pattern, str) == expected)
        printf("Passed.\n");
    else
    {
        printf("FAILED.\n");
        exit(0);
    }
}

int main(int argc, char *argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true); //
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true); //
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true); //
    Test("Test16", "ab", ".*", true); //
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true); //
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true); //
    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}
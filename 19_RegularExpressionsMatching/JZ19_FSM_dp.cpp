/* 正则表达式匹配：回溯算法经典例子 */
// 有限状态机思想实现回溯
// 回溯改dp记忆化搜索
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

bool f(vector<vector<int>> &dp, string pattern, string str, int p_idx, int idx)
{
    // base case
    // 模式串指针越界
    if (p_idx >= pattern.size() && idx >= str.size())
        return true;
    if (p_idx >= pattern.size())
        return false;
    // 匹配串指针越界
    if (idx >= str.size())
    {
        if (p_idx + 1 < pattern.size() && pattern[p_idx + 1] == '*')
        {
            return f(dp, pattern, str, p_idx + 2, idx);
        }
        else
        {
            return false;
        }
    }

    assert(p_idx < pattern.size() && idx < str.size());
    if (dp[p_idx][idx] != -1)
    {
        return (dp[p_idx][idx] == 1 ? true : false);
    }

    // 模式串的下一个字符为*
    if (p_idx + 1 < pattern.size() && pattern[p_idx + 1] == '*')
    {
        // 模式串*前字符与待匹配串字符能匹配上
        if ((idx < str.size() && str[idx] == pattern[p_idx]) || (idx < str.size() && pattern[p_idx] == '.'))
        {
            bool isMatch = f(dp, pattern, str, p_idx + 2, idx)        // ignore *
                           || f(dp, pattern, str, p_idx + 2, idx + 1) // move on the next state
                           || f(dp, pattern, str, p_idx, idx + 1);    // stay on the current state
            if (isMatch)
            {
                dp[p_idx][idx] = 1;
                return true;
            }
            else
            {
                dp[p_idx][idx] = 0;
                return false;
            }
        }
        else
        {
            // 字符不能匹配，只能ignore *
            if (f(dp, pattern, str, p_idx + 2, idx))
            {
                dp[p_idx][idx] = 1;
                return true;
            }
            else
            {
                dp[p_idx][idx] = 0;
                return false;
            }
        }
    }

    // 两个字符可以匹配
    if ((idx < str.size() && str[idx] == pattern[p_idx]) || (idx < str.size() && pattern[p_idx] == '.'))
    {
        // 字符不能匹配，只能ignore *
        if (f(dp, pattern, str, p_idx + 1, idx + 1))
        {
            dp[p_idx][idx] = 1;
            return true;
        }
        else
        {
            dp[p_idx][idx] = 0;
            return false;
        }
    }

    return false;
}

bool regular_match(string pattern, string str)
{
    vector<vector<int>> dp(pattern.size(), vector<int>(str.size()));
    for (int i = 0; i < pattern.size(); i++)
    {
        for (int j = 0; j < str.size(); j++)
        {
            dp[i][j] = -1;
        }
    }
    return f(dp, pattern, str, 0, 0);
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
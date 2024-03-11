/* 之字形打印二叉树 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cassert>

#include "../Utilities/BinaryTree.h"

using namespace std;

vector<int> reverse_vec(vector<int> vec);
void printVec2(vector<vector<int>> vec2);

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    bool reversed = false; // false: 正序； true：倒序
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int layer_cnt = q.size();
        vector<int> level_vec;
        while (layer_cnt--)
        {
            assert(!q.empty());
            TreeNode *cur = q.front();
            q.pop();
            level_vec.push_back(cur->val);
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        if (reversed)
            level_vec = reverse_vec(level_vec);
        // toggle reversed
        if (reversed)
            reversed = false;
        else
            reversed = true;

        ans.push_back(level_vec);
    }
    return ans;
}

vector<int> reverse_vec(vector<int> vec)
{
    vector<int> ans;
    stack<int> stk;
    for (auto v : vec)
    {
        stk.push(v);
    }
    while (!stk.empty())
    {
        int cur = stk.top();
        stk.pop();
        ans.push_back(cur);
    }
    return ans;
}

void printVec2(vector<vector<int>> vec2)
{
    for (auto vec : vec2)
    {
        for (auto v : vec)
            cout << v << " ";
        cout << endl;
    }
}

// ====================测试代码====================
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    TreeNode *pNode8 = CreateBinaryTreeNode(8);
    TreeNode *pNode6 = CreateBinaryTreeNode(6);
    TreeNode *pNode10 = CreateBinaryTreeNode(10);
    TreeNode *pNode5 = CreateBinaryTreeNode(5);
    TreeNode *pNode7 = CreateBinaryTreeNode(7);
    TreeNode *pNode9 = CreateBinaryTreeNode(9);
    TreeNode *pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    printf("====Test1 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("10 6 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    vector<vector<int>> ans = zigzagLevelOrder(pNode8);
    printVec2(ans);
    printf("\n");

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    TreeNode *pNode5 = CreateBinaryTreeNode(5);
    TreeNode *pNode4 = CreateBinaryTreeNode(4);
    TreeNode *pNode3 = CreateBinaryTreeNode(3);
    TreeNode *pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    printf("====Test2 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    vector<vector<int>> ans = zigzagLevelOrder(pNode5);
    printVec2(ans);
    printf("\n");

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    TreeNode *pNode5 = CreateBinaryTreeNode(5);
    TreeNode *pNode4 = CreateBinaryTreeNode(4);
    TreeNode *pNode3 = CreateBinaryTreeNode(3);
    TreeNode *pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode2);

    printf("====Test3 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    vector<vector<int>> ans = zigzagLevelOrder(pNode5);
    printVec2(ans);
    printf("\n");

    DestroyTree(pNode5);
}

void Test4()
{
    TreeNode *pNode5 = CreateBinaryTreeNode(5);

    printf("====Test4 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n\n");

    printf("Actual Result is: \n");
    vector<vector<int>> ans = zigzagLevelOrder(pNode5);
    printVec2(ans);
    printf("\n");

    DestroyTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    vector<vector<int>> ans = zigzagLevelOrder(nullptr);
    printVec2(ans);
    printf("\n");
}

//        100
//        /
//       50
//         \
//         150
void Test6()
{
    TreeNode *pNode100 = CreateBinaryTreeNode(100);
    TreeNode *pNode50 = CreateBinaryTreeNode(50);
    TreeNode *pNode150 = CreateBinaryTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, nullptr);
    ConnectTreeNodes(pNode50, nullptr, pNode150);

    printf("====Test6 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("100 \n");
    printf("50 \n");
    printf("150 \n\n");

    printf("Actual Result is: \n");
    vector<vector<int>> ans = zigzagLevelOrder(pNode100);
    printVec2(ans);
    printf("\n");
}

//                8
//        4              12
//     2     6       10      14
//   1  3  5  7     9 11   13  15
void Test7()
{
    TreeNode *pNode8 = CreateBinaryTreeNode(8);
    TreeNode *pNode4 = CreateBinaryTreeNode(4);
    TreeNode *pNode12 = CreateBinaryTreeNode(12);
    TreeNode *pNode2 = CreateBinaryTreeNode(2);
    TreeNode *pNode6 = CreateBinaryTreeNode(6);
    TreeNode *pNode10 = CreateBinaryTreeNode(10);
    TreeNode *pNode14 = CreateBinaryTreeNode(14);
    TreeNode *pNode1 = CreateBinaryTreeNode(1);
    TreeNode *pNode3 = CreateBinaryTreeNode(3);
    TreeNode *pNode5 = CreateBinaryTreeNode(5);
    TreeNode *pNode7 = CreateBinaryTreeNode(7);
    TreeNode *pNode9 = CreateBinaryTreeNode(9);
    TreeNode *pNode11 = CreateBinaryTreeNode(11);
    TreeNode *pNode13 = CreateBinaryTreeNode(13);
    TreeNode *pNode15 = CreateBinaryTreeNode(15);

    ConnectTreeNodes(pNode8, pNode4, pNode12);
    ConnectTreeNodes(pNode4, pNode2, pNode6);
    ConnectTreeNodes(pNode12, pNode10, pNode14);
    ConnectTreeNodes(pNode2, pNode1, pNode3);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    ConnectTreeNodes(pNode14, pNode13, pNode15);

    printf("====Test7 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("12 4 \n");
    printf("2 6 10 14 \n");
    printf("15 13 11 9 7 5 3 1 \n\n");

    printf("Actual Result is: \n");
    vector<vector<int>> ans = zigzagLevelOrder(pNode8);
    printVec2(ans);
    printf("\n");

    DestroyTree(pNode8);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

/* 二叉树的镜像 */
#include <iostream>
#include <cassert>
#include <string>
#include <queue>
#include "../Utilities/BinaryTree.h"

using namespace std;

// 方法1： 递归实现
BinaryTreeNode *getMirror(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return nullptr;

    BinaryTreeNode *r_child = pRoot->m_pRight;
    pRoot->m_pRight = getMirror(pRoot->m_pLeft);
    pRoot->m_pLeft = getMirror(r_child);

    return pRoot;
}

// 方法2：循环实现
// bfs遍历修改版
BinaryTreeNode *getMirror2(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return nullptr;

    queue<BinaryTreeNode *> stk;
    stk.push(pRoot);

    while (!stk.empty())
    {
        BinaryTreeNode *pNode = stk.front();
        stk.pop();

        BinaryTreeNode *left_child = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = left_child;

        if (pNode->m_pLeft)
            stk.push(pNode->m_pLeft);

        if (pNode->m_pRight)
            stk.push(pNode->m_pRight);
    }

    return pRoot;
}

// 测试代码
void Test(string testName, BinaryTreeNode *pRoot)
{
    cout << testName << ":" << endl;
    cout << "[origin tree]:" << endl;
    PrintTree(pRoot);
    cout << "[mirror tree]:" << endl;
    PrintTree(getMirror2(pRoot));
}

// 满二叉树
void test1()
{
    BinaryTreeNode *node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *node4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *node5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *node6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *node7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(node1, node2, node3);
    ConnectTreeNodes(node2, node4, node5);
    ConnectTreeNodes(node3, node6, node7);

    Test("test1", node1);

    DestroyTree(node1);
}

void test2()
{
    BinaryTreeNode *node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *node4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(node1, node2, nullptr);
    ConnectTreeNodes(node2, node3, nullptr);
    ConnectTreeNodes(node3, node4, nullptr);

    Test("test2", node1);

    DestroyTree(node1);
}

void test3()
{
    BinaryTreeNode *node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *node4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(node1, node2, nullptr);
    ConnectTreeNodes(node2, node3, nullptr);
    ConnectTreeNodes(node3, nullptr, node4);

    Test("test3", node1);

    DestroyTree(node1);
}

void test4()
{
    BinaryTreeNode *node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *node4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(node1, nullptr, node2);
    ConnectTreeNodes(node2, nullptr, node3);
    ConnectTreeNodes(node3, nullptr, node4);

    Test("test4", node1);

    DestroyTree(node1);
}

void test5()
{
    Test("test5", nullptr);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
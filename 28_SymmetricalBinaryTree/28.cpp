#include <iostream>
#include <string>
#include <cassert>

#include "../Utilities/BinaryTree.h"

using namespace std;

bool isSymm_recursive(BinaryTreeNode *node1, BinaryTreeNode *node2)
{
    if (node1 == nullptr && node2 == nullptr)
        return true;
    if (node1 == nullptr || node2 == nullptr)
        return false;

    return node1->m_nValue == node2->m_nValue &&
           isSymm_recursive(node1->m_pLeft, node2->m_pRight) &&
           isSymm_recursive(node2->m_pLeft, node1->m_pRight);
}

bool isSymm(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return false;
    return isSymm_recursive(pRoot->m_pLeft, pRoot->m_pRight);
}

// 测试代码
void Test(string testName, BinaryTreeNode *pRoot, bool expected)
{
    if (expected == isSymm(pRoot))
    {
        cout << testName << "passed" << endl;
    }
    else
    {
        cout << testName << "failed" << endl;
        exit(0);
    }
}

void test1()
{
    BinaryTreeNode *n1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *n2 = CreateBinaryTreeNode(7);
    BinaryTreeNode *n3 = CreateBinaryTreeNode(7);
    BinaryTreeNode *n4 = CreateBinaryTreeNode(5);
    BinaryTreeNode *n5 = CreateBinaryTreeNode(6);
    BinaryTreeNode *n6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *n7 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(n1, n2, n3);
    ConnectTreeNodes(n2, n4, n5);
    ConnectTreeNodes(n3, n6, n7);

    Test("test1", n1, true);

    DestroyTree(n1);
}

void test2()
{
    BinaryTreeNode *n1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *n2 = CreateBinaryTreeNode(6);
    BinaryTreeNode *n3 = CreateBinaryTreeNode(7);
    BinaryTreeNode *n4 = CreateBinaryTreeNode(5);
    BinaryTreeNode *n5 = CreateBinaryTreeNode(6);
    BinaryTreeNode *n6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *n7 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(n1, n2, n3);
    ConnectTreeNodes(n2, n4, n5);
    ConnectTreeNodes(n3, n6, n7);

    Test("test2", n1, false);

    DestroyTree(n1);
}

void test3()
{
    BinaryTreeNode *n1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *n2 = CreateBinaryTreeNode(7);
    BinaryTreeNode *n3 = CreateBinaryTreeNode(7);
    BinaryTreeNode *n4 = CreateBinaryTreeNode(5);
    BinaryTreeNode *n5 = CreateBinaryTreeNode(6);
    BinaryTreeNode *n6 = CreateBinaryTreeNode(6);

    ConnectTreeNodes(n1, n2, n3);
    ConnectTreeNodes(n2, n4, n5);
    ConnectTreeNodes(n3, n6, nullptr);

    Test("test3", n1, false);

    DestroyTree(n1);
}

void test4()
{
    BinaryTreeNode *n1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *n2 = CreateBinaryTreeNode(7);
    BinaryTreeNode *n3 = CreateBinaryTreeNode(7);
    BinaryTreeNode *n4 = CreateBinaryTreeNode(5);
    BinaryTreeNode *n5 = CreateBinaryTreeNode(6);
    BinaryTreeNode *n6 = CreateBinaryTreeNode(5);
    BinaryTreeNode *n7 = CreateBinaryTreeNode(6);

    ConnectTreeNodes(n1, n2, n3);
    ConnectTreeNodes(n2, n4, n5);
    ConnectTreeNodes(n3, n6, n7);

    Test("test4", n1, false);

    DestroyTree(n1);
}

void test5()
{
    Test("test5", nullptr, false);
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
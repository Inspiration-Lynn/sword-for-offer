/* 链表中倒数第K个节点 */
#include <iostream>
#include "../Utilities/List.h"

using namespace std;

ListNode *FindKthToTail(ListNode *pHead, int k)
{
    if (k <= 0 || !pHead)
        return nullptr;

    ListNode *dummy = CreateListNode(-1);
    dummy->m_pNext = pHead;
    ListNode *ptr1 = dummy, *ptr2 = dummy;
    for (int i = 0; i < k && ptr1 != nullptr; i++)
    {
        ptr1 = ptr1->m_pNext;
    }
    if (ptr1 == nullptr)
        return nullptr;

    while (ptr1 != nullptr)
    {
        ptr1 = ptr1->m_pNext;
        ptr2 = ptr2->m_pNext;
    }

    return ptr2;
}

// 测试要找的结点在链表中间
void Test1()
{
    printf("=====Test1 starts:=====\n");
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode *pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void Test2()
{
    printf("=====Test2 starts:=====\n");
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode *pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的头结点
void Test3()
{
    printf("=====Test3 starts:=====\n");
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode *pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试空链表
void Test4()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: nullptr.\n");
    ListNode *pNode = FindKthToTail(nullptr, 100);
    PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5()
{
    printf("=====Test5 starts:=====\n");
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode *pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试输入的第二个参数为0
void Test6()
{
    printf("=====Test6 starts:=====\n");
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode *pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);

    DestroyList(pNode1);
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

#include <bits/stdc++.h>
// #include "./Utilities/List.h"
#include "List.h"

using namespace std;

void deleteNode(ListNode **pListHead, ListNode *pNode)
{
    // special case
    if (pListHead == nullptr || pNode == nullptr)
        return;

    if (pNode->m_pNext != nullptr)
    {
        // case 1: 删除中间节点
        ListNode *nxtNode = pNode->m_pNext;
        pNode->m_nValue = nxtNode->m_nValue;
        pNode->m_pNext = nxtNode->m_pNext;

        delete nxtNode;
        nxtNode = nullptr; // 避免悬挂指针
    }
    else if (*pListHead == pNode)
    {
        // case 2: 删除唯一一个节点
        delete pNode;
        *pListHead = nullptr;
        pNode = nullptr;
    }
    else
    {
        // case 3: 删除尾节点
        ListNode *cur = *pListHead;
        while (cur->m_pNext != pNode)
        {
            cur = cur->m_pNext;
        }
        cur->m_pNext = nullptr;

        delete pNode;
        pNode = nullptr;
    }
}

// 测试代码
void test(ListNode *pListHead, ListNode *pNode)
{
    printf("------------------------\n");
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    deleteNode(&pListHead, pNode);

    printf("The result list is: \n");
    PrintList(pListHead);
    printf("------------------------\n");
}

/* 功能测试*/
// 删除中间的节点
void test1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);

    test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 删除尾节点
void test2()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);

    test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 删除头节点
void test3()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);

    test(pNode1, pNode1);

    DestroyList(pNode1);
}

// 删除唯一的一个节点
void test4()
{
    ListNode *pNode1 = CreateListNode(1);

    test(pNode1, pNode1);
}

/* 特殊输入测试 */
void test5()
{
    test(nullptr, nullptr);
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
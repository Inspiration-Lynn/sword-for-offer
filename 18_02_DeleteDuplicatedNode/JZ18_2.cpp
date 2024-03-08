#include <iostream>
#include <unordered_set>
#include "./Utilities/List.h"

using namespace std;

// 功能函数
ListNode *deleteDupNode(ListNode *pHead)
{
    if (!pHead)
        return nullptr;

    ListNode *dummy = CreateListNode(-1);
    dummy->m_pNext = pHead;

    // 遍历找到所有的重复元素
    unordered_set<int> exist_set;
    unordered_set<int> dup_set; // 所有重复数字
    for (ListNode *cur = dummy->m_pNext; cur != nullptr; cur = cur->m_pNext)
    {
        int num = cur->m_nValue;
        if (dup_set.find(num) != dup_set.end())
            continue;
        if (exist_set.find(num) != exist_set.end())
        {
            dup_set.insert(num);
        }
        else
        {
            exist_set.insert(num);
        }
    }

    for (ListNode *cur = dummy; cur->m_pNext != nullptr;)
    {
        if (dup_set.find(cur->m_pNext->m_nValue) != dup_set.end())
        {
            cur->m_pNext = cur->m_pNext->m_pNext;
        }
        else
        {
            cur = cur->m_pNext;
        }
    }

    return dummy->m_pNext;
}

// 测试函数
void test(ListNode *pHead)
{
    cout << "Original linkedlist:" << endl;
    PrintList(pHead);

    ListNode *pHead_new = deleteDupNode(pHead);

    cout << "The result list is:" << endl;
    PrintList(pHead_new);

    cout << "---------------------------" << endl;
}

// 功能测试
// case 1: 中间有重复
void test1()
{
    cout << "test 1:" << endl;

    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(4);
    ListNode *pNode6 = CreateListNode(4);
    ListNode *pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    test(pNode1);

    DestroyList(pNode1);
}

// case 2: 无重复
void test2()
{
    cout << "test 2:" << endl;

    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);

    test(pNode1);

    DestroyList(pNode1);
}

// case 3: 重复节点在链表头
void test3()
{
    cout << "test 3:" << endl;

    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);

    test(pNode1);

    DestroyList(pNode1);
}

// case 4: 全部为重复节点
void test4()
{
    cout << "test 4:" << endl;

    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(2);
    ListNode *pNode4 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);

    test(pNode1);

    DestroyList(pNode1);
}

// case 5: 链表为空
void test5()
{
    cout << "test 5:" << endl;

    test(nullptr);
}

// case 6: 重复节点在链表尾
void test6()
{
    cout << "test 6:" << endl;

    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(3);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);

    test(pNode1);

    DestroyList(pNode1);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}
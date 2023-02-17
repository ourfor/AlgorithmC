//
//  MergeSortedLinkList.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/13.
//

#include "MergeSortedLinkList.hpp"

/// 合并两个排序的链表
/// @link https://www.acwing.com/problem/content/34/
class MergeSortedLinkListSolution {
    
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        
        ListNode *newHead, *newTail;
        ListNode *curr1 = l1, *curr2 = l2;
        if (curr1->val < curr2->val) {
            newHead = curr1;
            curr1 = curr1->next;
        } else {
            newHead = curr2;
            
            curr2 = curr2->next;
        }
        newTail = newHead;
        
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val < curr2->val) {
                newTail->next = curr1;
                curr1 = curr1->next;
            } else {
                newTail->next = curr2;
                curr2 = curr2->next;
            }
            newTail = newTail->next;
        }
        
        if (curr1 != nullptr) {
            newTail->next = curr1;
        } else if (curr2 != nullptr) {
            newTail->next = curr2;
        } else {
            newTail->next = nullptr;
        }
        
        return newHead;
    }
};

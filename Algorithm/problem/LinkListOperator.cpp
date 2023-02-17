//
//  LinkListOperator.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/14.
//

#include "LinkListOperator.hpp"

class LinkListOperatorSolution {
    
struct ListNode {
    int val;
    struct ListNode *next;
};
    
public:
    /// 在O(1)时间删除链表结点
    /// @link https://www.acwing.com/problem/content/description/85/
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

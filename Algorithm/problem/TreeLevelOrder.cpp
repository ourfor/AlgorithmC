//
//  TreeLevelOrder.cpp
//  CTest
//
//  Created by 赫拉 on 2023/2/12.
//

#include "TreeLevelOrder.hpp"
#include <vector>
#include <queue>

/// 不分行从上往下打印二叉树
/// @link https://www.acwing.com/problem/content/41/
class TreeLevelOrderSolution {
    
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
public:
    std::vector<int> printFromTopToBottom(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) return result;
        std::queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            result.push_back(node->val);
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
        return result;
    }
};

/// 分行从上往下打印二叉树
/// @link https://www.acwing.com/problem/content/42/
class TreeLevelOrderWithLevelSolution {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
public:
    std::vector<std::vector<int>> printFromTopToBottom(TreeNode* root) {
        std::vector<std::vector<int>> lines;
        if (root == nullptr) {
            return lines;
        }
        
        std::queue<TreeNode *> queue;
        queue.push(root);
        TreeNode *node = nullptr;
        while (!queue.empty()) {
            int size = (int)queue.size();
            std::vector<int> line;
            for (int i = 0; i < size; i++) {
                node = queue.front();
                queue.pop();
                if (node == nullptr) continue;
                line.push_back(node->val);
                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }
            lines.push_back(line);
        }
        return lines;
    }
};

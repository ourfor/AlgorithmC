//
//  TreeTest.cpp
//  CTest
//
//  Created by 梁甜 on 2023/1/8.
//

#include "TreeTest.hpp"
#include <string>
#include <iostream>
#include <memory>

/// 二叉树构建
/// @link https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef

template <typename T>
using SharedPtr = std::shared_ptr<T>;

typedef struct TreeNode {
    char data;
    SharedPtr<struct TreeNode> left, right;
} TreeNode, *Tree;

/// @params type 0 is left child, 1 is right child
void buildTree(SharedPtr<TreeNode> &root, int type, std::string &chs, int &idx) {
    if (chs[idx] != '#') {
        SharedPtr<TreeNode> node(new TreeNode);
        node->data = chs[idx++];
        if (type == 0) {
            root->left = node;
        } else {
            root->right = node;
        }
        
        buildTree(node, 0, chs, idx);
        buildTree(node, 1, chs, idx);
    } else {
        idx++;
        if (type == 0) {
            root->left = nullptr;
        } else {
            root->right = nullptr;
        }
    }
}

void inOrderTree(std::shared_ptr<TreeNode> tree) {
    if (tree) {
        inOrderTree(tree->left);
        std::cout << tree->data << " ";
        inOrderTree(tree->right);
    }
}

void mainTraverseTree() {
    std::string tmp;
    while (std::cin >> tmp) {
        SharedPtr<TreeNode> tree(new TreeNode);
        tree->data = tmp[0];
        int idx = 1;
        buildTree(tree, 0, tmp, idx);
        buildTree(tree, 1, tmp, idx);
        
        inOrderTree(tree);
    }
}


/// 二叉排序树
/// @link https://www.nowcoder.com/practice/b42cfd38923c4b72bde19b795e78bcb3

typedef struct BSTreeNode {
    int data;
    struct BSTreeNode *left, *right;
} BSTreeNode, *BSTree;

BSTree insertNodeToTree(BSTree tree, int data) {
    if (tree == nullptr) {
        tree = new BSTreeNode;
        tree->data = data;
        tree->left = nullptr;
        tree->right = nullptr;
        return tree;
    }
    
    BSTreeNode *curr = tree;
    while (true) {
        if (curr->data == data) {
            break;
        } else if (curr->data > data) {
            if (curr->left == nullptr) {
                curr->left = new BSTreeNode;
                curr = curr->left;
                curr->data = data;
                curr->left = nullptr;
                curr->right = nullptr;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right == nullptr) {
                curr->right = new BSTreeNode;
                curr = curr->right;
                curr->data = data;
                curr->left = nullptr;
                curr->right = nullptr;
            } else {
                curr = curr->right;
            }
        }
    }
    
    return tree;
}


void preOrder(BSTree tree) {
    if (tree) {
        std::cout << tree->data << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(BSTree tree) {
    if (tree) {
        inOrder(tree->left);
        std::cout << tree->data << " ";
        inOrder(tree->right);
    }
}

void postOrder(BSTree tree) {
    if (tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        std::cout << tree->data << " ";
    }
}

void mainBSTree() {
    int num = 0;
    while (std::cin >> num) {
        int data = 0;
        BSTree tree = nullptr;
        while (num--) {
            std::cin >> data;
            tree = insertNodeToTree(tree, data);
        }
        preOrder(tree);
        std::cout << std::endl;
        inOrder(tree);
        std::cout << std::endl;
        postOrder(tree);
        std::cout << std::endl;
    }
}


/// 完全二叉树公共父节点
/// @link https://www.nowcoder.com/practice/5b80ab166efa4551844657603227caeb
void mainCommonParentNode() {
    int node1 = 0, node2 = 0;
    while (std::cin >> node1 >> node2) {
        while (node1 != node2) {
            if (node1 > node2) {
                node1 /= 2;
            } else {
                node2 /= 2;
            }
        }
        std::cout << node1 << std::endl;
    }
}

// binary_tree.cpp

#include "binary_tree.h"
#include <iostream>

using namespace std;

TreeNode* createNode(double value) {
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void printTree(TreeNode* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

double findMin(TreeNode* root) {
    if (root == nullptr) {
        cerr << "Emoty Tree!" << endl;
        return 0;
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root->data;
}

TreeNode* balanceTree(double arr[], int start, int end) {
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    TreeNode* root = createNode(arr[mid]);

    root->left = balanceTree(arr, start, mid - 1);
    root->right = balanceTree(arr, mid + 1, end);

    return root;
}

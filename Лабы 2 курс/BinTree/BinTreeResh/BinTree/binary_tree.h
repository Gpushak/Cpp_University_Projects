#pragma once
// binary_tree.h

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct TreeNode {
    double data;
    TreeNode* left;
    TreeNode* right;
};

// ������� ��� �������� ������ ���� ������
TreeNode* createNode(double value);

// ������� ��� ������������ ������, ���������� �������
void deleteTree(TreeNode* root);

// ������� ��� ������ ������ (����� � ������ �������)
void printTree(TreeNode* root);

// ������� ��� ������ ������������ �������� � ������
double findMin(TreeNode* root);

// ������� ��� ������������ ������
TreeNode* balanceTree(double arr[], int start, int end);

#endif
#pragma once
// binary_tree.h

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct TreeNode {
    double data;
    TreeNode* left;
    TreeNode* right;
};

// Функция для создания нового узла дерева
TreeNode* createNode(double value);

// Функция для освобождения памяти, занимаемой деревом
void deleteTree(TreeNode* root);

// Функция для печати дерева (обход в прямом порядке)
void printTree(TreeNode* root);

// Функция для поиска минимального элемента в дереве
double findMin(TreeNode* root);

// Функция для балансировки дерева
TreeNode* balanceTree(double arr[], int start, int end);

#endif
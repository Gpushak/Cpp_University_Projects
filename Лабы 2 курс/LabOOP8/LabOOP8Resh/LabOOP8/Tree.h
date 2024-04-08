#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class Tree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // ��������������� ��������� ������
    void insert(Node*& node, int key) {
        if (!node) {
            node = new Node(key);
            return;
        }

        if (key < node->key) {
            insert(node->left, key);
        }
        else if (key > node->key) {
            insert(node->right, key);
        }
    }

    bool search(Node* node, int key) const {
        if (!node) {
            return false;
        }

        if (key == node->key) {
            return true;
        }
        else if (key < node->key) {
            return search(node->left, key);
        }
        else {
            return search(node->right, key);
        }
    }

    void inorderTraversal(Node* node, ostream& os) const {
        if (node) {
            inorderTraversal(node->left, os);
            os << node->key << " ";
            inorderTraversal(node->right, os);
        }
    }

public:
    Tree() : root(nullptr) {}

    // ������ ��� �������� �������������
    void insert(int key) {
        insert(root, key);
    }

    bool search(int key) const {
        return search(root, key);
    }

    // ���������� ��������� <<
    friend ostream& operator<<(ostream& os, const Tree& tree) {
        tree.inorderTraversal(tree.root, os);
        return os;
    }

    // ���������� ��������� >>
    friend istream& operator>>(istream& is, Tree& tree) {
        int key;
        while (is >> key) {
            tree.insert(key);
        }
        return is;
    }

    // ���������� ��� ������������ ������
    ~Tree() {
        destroy(root);
    }

private:
    // ��������������� ����� ��� �������� ������
    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};

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

    // Вспомогательные приватные методы
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

    // Методы для внешнего использования
    void insert(int key) {
        insert(root, key);
    }

    bool search(int key) const {
        return search(root, key);
    }

    // Перегрузка оператора <<
    friend ostream& operator<<(ostream& os, const Tree& tree) {
        tree.inorderTraversal(tree.root, os);
        return os;
    }

    // Перегрузка оператора >>
    friend istream& operator>>(istream& is, Tree& tree) {
        int key;
        while (is >> key) {
            tree.insert(key);
        }
        return is;
    }

    // Деструктор для освобождения памяти
    ~Tree() {
        destroy(root);
    }

private:
    // Вспомогательный метод для удаления дерева
    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};

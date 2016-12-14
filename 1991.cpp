//
// Created by secret on 12/14/16.
//

#include <cstdio>
#include <cstdlib>

int n;

class Node {
private:
    char data;
public:
    Node(char data) : data('') {
        this->data = data;
    }

    char getData() const;

    void setData(char data);

    friend class Tree;
};

class Tree {
private:
    Node *root;
public:
    Tree() : root(NULL) {}

    void insertNode(char data) {
        if (root == NULL) {
            root = new Node(data);
        }
    }

    Node* searchNode(Node* node) {
        Node* cur = root;

        if (root == NULL) {
            return NULL;
        } else if (cur->data == node->data) {
            return cur;
        } else {
            searchNode(node);
        }

        return cur;
    }
};

char Node::getData() const {
    return data;
}

void Node::setData(char data) {
    Node::data = data;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
    }
}
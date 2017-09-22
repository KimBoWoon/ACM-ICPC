//
// Created by secret on 12/14/16.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#pragma warning(disable:4996)

int n;

class Node {
private:
	char data;
	Node *left, *right;
public:
	Node(char data) : left(NULL), right(NULL) {
		this->data = data;
	}

	char getData() const;

	void setData(char data);

	friend class Tree;
};

class Tree {
private:
	Node *root, *temp;
public:
	Tree() : temp(NULL) {
		this->root = new Node('A');
	}

	void insertNode(Node *node, char data, int flag) {
		if (flag == 2) {
			node->left = new Node(data);
		}
		else if (flag == 3) {
			node->right = new Node(data);
		}
	}

	Node* searchNode(Node *node, char data) {
		if (node == NULL) {
			return NULL;
		}
		else if (node->data == data) {
			temp = node;
		}
		else {
			searchNode(node->left, data);
			searchNode(node->right, data);
		}

		return temp;
	}

	void preoder(Node *node) {
		if (node == NULL) {
			return;
		}
		printf("%c", node->data);
		preoder(node->left);
		preoder(node->right);
	}

	void inoder(Node *node) {
		if (node == NULL) {
			return;
		}
		inoder(node->left);
		printf("%c", node->data);
		inoder(node->right);
	}

	void postoder(Node *node) {
		if (node == NULL) {
			return;
		}
		postoder(node->left);
		postoder(node->right);
		printf("%c", node->data);
	}

	Node* getSearchNode() {
		return temp;
	}

	Node* getRootNode() {
		return root;
	}
};

char Node::getData() const {
	return data;
}

void Node::setData(char data) {
	Node::data = data;
}

int main() {
	Tree t;

	cin >> n;
	//scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char a, b, c;

		cin >> a >> b >> c;
		//scanf("%c %c %c", &a, &b, &c);

		Node *cur = t.searchNode(t.getRootNode(), a);
		cur = t.getSearchNode();

		if (b != '.') {
			t.insertNode(cur, b, 2);
		}
		if (c != '.') {
			t.insertNode(cur, c, 3);
		}
	}

	t.preoder(t.getRootNode());
	printf("\n");
	t.inoder(t.getRootNode());
	printf("\n");
	t.postoder(t.getRootNode());
	printf("\n");
}
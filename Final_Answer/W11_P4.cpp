#include<iostream>
using namespace std;
class Node {
public:
	Node* left;
	Node* right;
	Node* par;
	int data;
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
		par = NULL;
	}
};
class BST {
public:
	Node* root;
	BST() {
		root = NULL;
	}
	void insert(int inputData) {
		Node* newnode = new Node(inputData);

		if (root == NULL)
			root = newnode;
		else {
			Node* curNode = root;
			Node* saveNode = NULL;
			while (curNode != NULL) {
				saveNode = curNode;
				if (curNode->data > inputData)
					curNode = curNode->left;
				else
					curNode = curNode->right;
			}
			newnode->par = saveNode;
			if (saveNode->data > inputData)
				saveNode->left = newnode;
			else
				saveNode->right = newnode;
		}
	}
	Node* find(int data) {
		Node* curNode = root;
		while (curNode != NULL) {
			if (curNode->data == data)
				return curNode;
			if (curNode->data > data)
				curNode = curNode->left;
			else
				curNode = curNode->right;
		}
		return NULL;
	}
	Node* min_findNode(Node* node) {
		while (1) {
			if (node->left == NULL)
				return node;
			node = node->left;
		}
	}
	void erase(int data) {
		Node* curNode = find(data);
		int numOfchild = bool(curNode->left) + bool(curNode->right);

		if (numOfchild == 0) {
			if (curNode == root)
				root = NULL;
			else {
				if (curNode->data < curNode->par->data)//부등호 주의!!!
					curNode->par->left = NULL;
				else
					curNode->par->right = NULL;
			}
			delete curNode;
		}
		else if (numOfchild == 2) {
			Node* lastNode = min_findNode(curNode->right);
			int min = lastNode->data;
			erase(lastNode->data);
			curNode->data = min;
		}
		else if (numOfchild == 1) {
			if (curNode == root) {
				if (curNode->left != NULL)
					root = curNode->left;
				else
					root = curNode->right;
			}
			else {
				Node* child = (curNode->left) ? curNode->left : curNode->right;

				child->par = curNode->par;
				if (child->data < curNode->par->data)
					curNode->par->left = child;
				else
					curNode->par->right = child;
			}
			delete curNode;//delete 위치 else if 문 마지막에 확실히 넣기!!!!
		}
		
	}
	void postOrderPrint(Node* node) {
		if (node->left != NULL)
			postOrderPrint(node->left);
		if (node->right != NULL)
			postOrderPrint(node->right);
		cout << node->data << " ";
	}
};
int main() {
	int n;
	cin >> n;

	while (n--) {
		BST s;
		int size;
		cin >> size;

		while (size--) {
			int x;
			cin >> x;
			s.insert(x);
		}
		int eraseNum;
		cin >> eraseNum;

		while (eraseNum--) {
			int x;
			cin >> x;
			s.erase(x);
		}
		if (s.root == NULL)
			cout << "Empty" << endl;
		else {
			s.postOrderPrint(s.root);
			cout << endl;
		}
	}
}
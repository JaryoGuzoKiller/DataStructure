#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	Node() {
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};
class BST {
public:
	Node* root;

	BST() {
		root = NULL;
	}
	void insert(int inputData) {
		Node* newNode = new Node(inputData);
		Node* saveNode = NULL;
		if (root == NULL) {
			root = newNode;
		}
		else {
			Node* curNode = root;
			while (curNode != NULL) {
				saveNode = curNode;
				if (curNode->data == inputData) {
					cout << "ม฿บน" << endl;
					break;
				}
				else if (curNode->data > inputData) {
					curNode = curNode->left;
				}
				else {
					curNode = curNode->right;
				}
			}
			if (saveNode->data > inputData) {
				newNode->parent = saveNode;
				saveNode->left = newNode;

			}
			else {
				newNode->parent = saveNode;
				saveNode->right = newNode;
			}
		}
	}
	Node* find(int inputData) {
		Node* curNode = root;
		while (curNode != NULL) {
			if (curNode->data == inputData)
				return curNode;
			else if (curNode->data > inputData) {
				curNode = curNode->left;
			}
			else {
				curNode = curNode->right;
			}
		}
		return NULL;
	}
	Node* min_findNode(Node* _node) {
		Node* curNode = _node;
		Node* saveNode = NULL;

		while (curNode != NULL) {
			saveNode = curNode;
			curNode = curNode->left;
		}
		return saveNode;
	}
	Node* max_findNode(Node* _node) {
		Node* curNode = _node;
		Node* saveNode = NULL;

		while (curNode != NULL) {
			saveNode = curNode;
			curNode = curNode->right;
		}
		return saveNode;
	}
	void erase(int data) {
		Node* curNode = find(data);
		int numOfchild = bool(curNode->left) + bool(curNode->right);

		if (numOfchild == 0) {
			if (curNode == root)
				root = NULL;
			else {
				if (curNode->parent->data > curNode->data)
					curNode->parent->left = NULL;
				else
					curNode->parent->right= NULL;
			}
			delete curNode;
		}
		else if (numOfchild == 2) {
			Node* minNode = min_findNode(curNode->right);
			int data = minNode->data;
			erase(minNode->data);
			curNode->data = data;
		}
		else if (numOfchild == 1) {
			if (curNode == root) {
				if (curNode->left != NULL)
					root = curNode->left;
				else
					root = curNode->right;
			}
			else {
				Node* curParent = curNode->parent;
				Node* child = (curNode->left) ? curNode->left : curNode->right;

				if (curParent->data > child->data) {
					curParent->left = child;
					child->parent = curParent;
				}
				else {
					curParent->right = child;
					child->parent = curParent;
				}
			}
			delete curNode;
		}
	}
	void inorderPrint(Node* curNode) {
		
		if (curNode != NULL) {
			inorderPrint(curNode->left);
			cout << curNode->data << " ";
			inorderPrint(curNode->right);
		}
	}
};

int main() {
	int n;
	int num;

	cin >> n;
	while (n--) {
		BST s;
		cin >> num;
		for (int i = 0; i < num; i++) {

			int data;
			cin >> data;
			s.insert(data);
		}
		int erasenum;
		cin >> erasenum;
		for (int i = 0; i < erasenum; i++) {
			int x;
			cin >> x;
			s.erase(x);
		}
		cout << endl;
		if (s.root == NULL)
			cout << "Empty" << endl;
		else
			s.inorderPrint(s.root);
	}
}
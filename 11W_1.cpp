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
private:
	Node* root;
public:
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

		saveNode = curNode;
		curNode = curNode->left;

		while (curNode != NULL) {
			saveNode = curNode;
			curNode = curNode->right;
		}
		return saveNode;
	}
	Node* max_findNode(Node* _node) {
		Node* curNode = _node;
		Node* saveNode = NULL;

		saveNode = curNode;
		curNode = curNode->right;


		while (curNode != NULL) {
			saveNode = curNode;
			curNode = curNode->left;
		}
		return saveNode;
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
		int key;
		cin >> key;
		cout << s.min_findNode(s.find(key))->data << " " << s.max_findNode(s.find(key))->data << endl;
	}
}
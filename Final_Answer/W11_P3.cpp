#include<iostream>
using namespace std;
class Node {
public:
	Node* left;
	Node* right;
	Node* par;
	int data;
	Node(int data) {
		left = NULL;
		right = NULL;
		par = NULL;
		this->data = data;
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
		Node* saveNode = NULL;
		if (root == NULL)
			root = newnode;
		else {
			Node* curNode = root;
			while (curNode != NULL) {
				saveNode = curNode;
				if (curNode->data > inputData)
					curNode = curNode -> left;
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
			else if (curNode->data > data)
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
				if (curNode->data < curNode->par->data)
					curNode->par->left = NULL;
				else
					curNode->par->right = NULL;
			}
			delete curNode;
		}
		else if (numOfchild == 2) {
			Node* lastNode = min_findNode(curNode->right);
			int temp = lastNode->data;
			erase(lastNode->data);
			curNode->data = temp;
		}
		else if (numOfchild == 1) {
			if(curNode==root){
				if (curNode->left != NULL)
					root = curNode->left;
				else
					root = curNode->right;
			}
			else {
				Node* child = (curNode->left) ? curNode->left : curNode->right;
				
				if (curNode->par->data > child->data) {
					curNode->par->left = child;
					child->par = curNode->par;
				}
				else {
					curNode->par->right = child;
					child->par = curNode->par;
				}
				
			}
			delete curNode;
		}
	}
	void inOrderPrint(Node* curNode){//중위순회

		if (curNode->left != NULL)
			inOrderPrint(curNode->left);

		cout << curNode->data << " ";

		if (curNode->right != NULL)
			inOrderPrint(curNode->right);

	}
};
int main() {
	int n;
	cin >> n;
	while (n--) {
		int size;
		cin >> size;
		BST s;

		while (size--) {
			int x;
			cin >> x;
			s.insert(x);
		}

		int numOferase;
		cin >> numOferase;
		while (numOferase--) {
			int x;
			cin >> x;
			s.erase(x);
		}
		if (s.root == NULL)
			cout << "Empty" << endl;
		else {
			s.inOrderPrint(s.root);
			cout << endl;
		}
	}
}
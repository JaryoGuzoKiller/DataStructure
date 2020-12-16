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
		Node* newNode = new Node(inputData);
		Node* saveNode = NULL;
		if (root == NULL)
			root = newNode;
		else {
			Node* curNode = root;
			while (curNode != NULL) {
				saveNode = curNode;
				if (curNode->data > inputData)
					curNode = curNode->left;
				else if (curNode->data < inputData)
					curNode = curNode->right;
			}
			newNode->par = saveNode;
			if (saveNode->data > inputData) {
				saveNode->left = newNode;
			}
			else {
				saveNode->right = newNode;
			}
		}
	}
	Node* find(int inputData) {
		Node* cur = root;
		while (cur != NULL) {
			if (cur->data == inputData)
				return cur;
			else if (cur->data > inputData)
				cur = cur->left;
			else
				cur = cur->right;
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
	Node* min_findNodeOfRight(Node* node) {
		if (node->right == NULL)
			return node;
		node = node->right;
		return min_findNode(node);
	}
	Node* max_findNode(Node* node) {
		while (1) {
			if (node->right == NULL)
				return node;
			node = node->right;
		}
	}
	Node* max_findNodeOfLeft(Node* node) {
		if (node->left == NULL)
			return node;
		node = node->left;
		return max_findNode(node);
	}
	void erase(int data) {
		Node* cur = find(data);
		int numOfchild = bool(cur->left) + bool(cur->right);
		if (numOfchild == 0) {
			if (cur == root)
				root = NULL;
			else {
				if (cur->data < cur->par->data)
					cur->par->left = NULL;
				else
					cur->par->right = NULL;
				delete cur;
			}
		}
		else if (numOfchild == 2) {
			Node* minNode = min_findNode(cur->right);
			int temp = minNode->data;
			erase(minNode->data);
			cur->data = temp;
		}
		else if (numOfchild == 1) {
			if (cur == root) {
				if (cur->data > root->data)
					root = cur->left;
				else
					root = cur->right;
			}
			else {
				Node* child = (cur->left) ? cur->left : cur->right;
				child->par = cur->par;
				if (cur->par->data > child->data) {
					cur->left = child;		
				}
				else {
					cur->right = child;		
				}
			}
			delete cur;
		}
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
			int e;
			cin >> e;
			s.insert(e);
		}
		int x;
		cin >> x;
		cout <<s.max_findNodeOfLeft(s.find(x))->data<<" "
			<< s.min_findNodeOfRight(s.find(x))->data << endl;

	}
}
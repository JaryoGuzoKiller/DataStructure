#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
	int data;
	Node* par;
	int depth;
	vector<Node*> chi_v;
public:
	Node(int data) {
		this->data = data;
		par = NULL;
		depth = 0;
	}
	void setParent(Node* par) {
		this->par = par;
	}
	void insertChild(Node* node) {
		this->chi_v.push_back(node);
	}
	void delChild(Node* node) {
		for (int i = 0; this->chi_v.size(); i++) {
			if(chi_v[i]==node)
				this->chi_v.erase(this->chi_v.begin() + i);
		}
	}
	

};
class Tree {
	Node* root;
	Node* par;
	vector<Node*> node_list;
public:
	Tree(int data) {
		Node* node = new Node(data);
		root = node;
		node_list.push_back(node);
	}
	void insertNode(int x, int y) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == x) {
				Node* child = new Node(y);
				child->setParent(node_list[i]);
				node_list[i]->insertChild(child);
				child->depth = node_list[i]->depth + 1;
				node_list.push_back(child);
				return;
			}
		}
	}
	int getDepth(int x) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == x) {
				return node_list[i]->depth;
			}
		}
	}

};
int main() {
	int n, m;
	Tree t(1);
	cin >> n >> m;
	while (n--) {
		int x, y;
		cin >> x>> y;
		t.insertNode(x, y);
	}
	while (m--) {
		int x;
		cin >> x;
		cout << t.getDepth(x) << endl;
	}

}
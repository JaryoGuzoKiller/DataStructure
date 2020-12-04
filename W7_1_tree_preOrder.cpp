#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi_v;

	Node(int data) {
		this->data = data;
		par = NULL;
	}
	void setParent(Node* par) {
		this->par = par;
	}
	void insertChild(Node* child) {
		this->chi_v.push_back(child);
	}
	void delChild(Node* child) {
		for (int i = 0; i < chi_v.size(); i++)
			if (chi_v[i] == child)
				chi_v.erase(chi_v.begin() + i);
	}
};
class Tree {
public:
	Node* root;
	vector<Node*>node_list;
	Tree(int data) {
		Node* node = new Node(data);
		root = node;
		node_list.push_back(node);
	}
	void insertNode(int par_data, int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == par_data) {
				Node* child = new Node(data);
				child->setParent(node_list[i]);
				node_list[i]->insertChild(child);
				node_list.push_back(child);
				return;
			}	
		}
	}
	void preOrder(Node* r) {
		
		cout << r->data << " ";
		
		for (int i = 0; i < r->chi_v.size(); i++) {
			preOrder(r->chi_v[i]);
		}
	}
};
int main() {
	int n;
	cin >> n;
	
	while (n--) {
		Tree t(1);
		int m; 
		cin >> m;
		while (m--) {
			
			int x, y;
			cin >> x >> y;
			t.insertNode(x, y);
		}
		t.preOrder(t.root);
	}
}

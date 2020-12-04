#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
	int data;
	Node* par;
	vector<Node*>chi_v;
	Node(int data) {
		this->data = data;
		par = NULL;
	}
	void insertChild(Node* child) {
		this->chi_v.push_back(child);
	}
	void delChild(Node* child) {
		for (int i = 0; i < this->chi_v.size(); i++) {
			if (chi_v[i] == child)
				this->chi_v.erase(this->chi_v.begin() + i);
		}
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
				Node* node = new Node(data);
				node->par = node_list[i];
				node_list[i]->insertChild(node);
				node_list.push_back(node);
				return;
			}
		}
	}
	void postOrder(Node* r) {
		for (int i = 0; i < r->chi_v.size(); i++)
			postOrder(r->chi_v[i]);
		if(r->chi_v.size()==0)
			cout << r->data << " ";
	}
	void postOrderC(int k) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == k) {
				Node* r = node_list[i];
				postOrder(r);
				return;
			}
		}
	}
};
int main() {
	int n;
	cin >> n;

	while (n--) {
		Tree t(1);
		int m, k;
		cin >> m >> k;
		while (m--) {

			int x, y;
			cin >> x >> y;
			t.insertNode(x, y);
		}
		t.postOrderC(k);
	}
}
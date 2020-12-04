#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
	int data;
	Node* par;
	int depth;
	vector<Node*> chi_v;
	Node(int data) {
		this->data = data;
		par = NULL;
		depth = 0;
	}
	void setParent(Node* par) {
		this->par = par;
	}
	void insertChild(Node* child) {
		this->chi_v.push_back(child);
	}
	void delChild(Node* child) {
		for (int i = 0; i < this->chi_v.size(); i++) {
			if(chi_v[i]==child)
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
				Node* child = new Node(data);
				child->setParent(node_list[i]);
				node_list[i]->chi_v.push_back(child);
				node_list.push_back(child);
				child->depth = node_list[i]->depth + 1;
				return;
			}
		}
	}
	void delNode(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == data) {
				Node* par = node_list[i]->par;
				for (int j = 0; j < node_list[i]->chi_v.size(); j++) {
					par->chi_v.push_back(node_list[i]->chi_v[j]);
					node_list[i]->chi_v[j]->par = par;
				}
				par->delChild(node_list[i]);
				node_list.erase(node_list.begin()+i);
				delete node_list[i];
			}
		}
		return;
	}
	void maxofDepth(int k) {
		int max = 0;
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->depth == k) {
				if (max < node_list[i]->data)
					max = node_list[i]->data;
			}
		}
		cout << max << endl;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	
	Tree t(1);
	while (n--) {
		int x, y;
		cin >> x >> y;
		t.insertNode(x, y);
	}
	while (m--) {
		int x;
		cin >> x;
		t.maxofDepth(x);
	}
}

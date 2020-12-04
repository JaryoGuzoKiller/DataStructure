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
		par=NULL;
	}
	void setParent(Node* par) {
		this->par = par;
	}
	void insertChild(Node* child){
		this->chi_v.push_back(child);
	}
	void delChild(Node* child) {
		for (int i = 0; i < this->chi_v.size(); i++) {
			if (this->chi_v[i] == child)
				this->chi_v.erase(this->chi_v.begin() + i);
		}
	}
};
class Tree {
	int n;
	Node* root;
	vector<Node*> node_list;
public:
	Tree(int data) {
		n = 1;
		Node* node = new Node(data);
		root = node;
		node_list.push_back(node);
	}
	void insertNode(int x, int y) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == x) {
				Node* node = new Node(y);
				node->setParent(node_list[i]);
				node_list[i]->insertChild(node);
				node_list.push_back(node);
				n++;
				return;
			}
		}
	}
	void delNode(int x) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == x) {
				Node* x_par = node_list[i]->par;

				for (int j = 0; j < node_list[i]->chi_v.size(); j++) {
					x_par->insertChild(node_list[i]->chi_v[j]);
					node_list[i]->chi_v[j]->par = x_par;
				}
				x_par->delChild(node_list[i]);
				Node* nownode = node_list[i];
				node_list.erase(node_list.begin() + i);
				delete nownode;
				n--;

			}
		}
		return;
	}
	void printSibling(int x) {
		if (root->data == x) {
			cout << x << endl;
			return;
		}

		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == x) {
				Node* x_par = node_list[i]->par;
				for (int j = 0; j < x_par->chi_v.size(); j++) {
					cout << x_par->chi_v[j]->data << " ";
				}
				cout << endl;
				return;
			}
		}
		cout << 0 << endl;
	}
};
int main() {
	int n;
	cin >> n;
	string input;
	Tree t(1);
	while (n--) {
		cin >> input;
		if (input == "insert") {
			int x, y;
			cin >> x >> y;
			t.insertNode(x, y);
		}
		else if (input == "delete") {
			int x;
			cin >> x;
			t.delNode(x);
		}
		else if (input == "print") {
			int x;
			cin >> x;
			t.printSibling(x);
		}
	}
}

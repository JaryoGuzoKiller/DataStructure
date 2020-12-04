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
		for (int i = 0; i < this->chi_v.size(); i++) {
			if (this->chi_v[i] == child)
				this->chi_v.erase(this->chi_v.begin() + i);
		}
	}
		
};
class Tree {
	Node* root;
	vector<Node*>node_list;
	int n;
public:
	Tree(int i) {
		n = 1;
		Node* node = new Node(i);
		root = node;
		node_list.push_back(node);
	}
	int size() {
		return n;
	}
	void insertNode(int par_data, int data) {
		for (int i = 0; i < n; i++) {
			if (node_list[i]->data == par_data) {
				Node* node = new Node(data);
				node->setParent(node_list[i]);
				node_list[i]->insertChild(node);
				node_list.push_back(node);
				n++;
				return;
			}
		}
	}
	void delNode(int data) {
		Node* nownode;
		Node* par;
		for (int i = 0; i < n; i++) {
			if (node_list[i]->data == data) {
				nownode = node_list[i];
				if (nownode == root) {
					return;
				}
				par = nownode->par;
				for (int i = 0; i < nownode->chi_v.size(); i++) {
					par->insertChild(nownode->chi_v[i]);
				}
				par->delChild(nownode);
				this->node_list.erase(this->node_list.begin() + i);
				n--;
				delete nownode;
			}
		}
		return;
	}
	void printChild(int x) {
		//Node* par;
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == x) {
				if (node_list[i]->chi_v.size() == 0) {
					cout << 0 << endl;
					return;
				}
				else {
					
					for (int j = 0; j < node_list[i]->chi_v.size(); j++) {
						cout << node_list[i]->chi_v[j]->data << " ";
					}
					cout << endl;
					return;
				}	
			}
		}

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
			t.printChild(x);
		}
	}
}

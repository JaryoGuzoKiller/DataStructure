#include<iostream>
using namespace std;

class Node {
public:
	int x;
	Node* next;

	Node(int x) {
		this->x = x;
		next = NULL;
	}
};

class S_list {
	Node* head;
public:
	S_list() {
		head = NULL;
	}
	bool isEmpty() {
		if (head == NULL)return true;
		else
			return false;
	}
	void addFront(int x) {
		Node* node = new Node(x);
		if (head == NULL) {
			head = node;
		}
		else {
			node->next = head;
			head = node;
		}
	}

	void removeFront() {
		if (isEmpty())cout << -1 << endl;
		else {
			Node* node = head;
			cout << node->x << endl;

			head = head->next;
			node->next = NULL;
			delete node;
		}
	}
	void front() {
		if (isEmpty())cout << -1 << endl;
		else {
			//Node* node = head;
			cout << head->x << endl;
		}
	}
	
};

int main() {
	int n, m;
	cin >> n;

	string input;
	S_list s;
	while (n--) {
		cin >> input;

		if (input == "addFront") {
			cin >> m;
			s.addFront(m);
		}
		else if (input == "removeFront") {
			s.removeFront();
		}
		else if (input == "front") {
			s.front();
		}
		else if (input == "empty") {
			if (s.isEmpty())cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
}

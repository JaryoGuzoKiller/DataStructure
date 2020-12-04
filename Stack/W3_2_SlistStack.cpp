#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}
};
class SlistStack {
	Node* head;
	int t;
public:
	SlistStack() {
		t = 0;
		head = NULL;
	}
	bool isEmpty();
	void top();
	void push(int);
	void pop();
	void size();
};
bool SlistStack::isEmpty() {
	if (head == NULL)return true;
	else
		return false;
}
void SlistStack::top() {
	if (isEmpty())cout << -1 << endl;
	else
		cout << head->data << endl;
}
void SlistStack::push(int data) {
	Node* node = new Node(data);
	if (isEmpty())head = node;
	else {
		node->next = head;
		head = node;
	}
	t++;
}
void  SlistStack::pop() {
	if (isEmpty())cout << -1 << endl;
	else {
		Node* node = head;
		head = head->next;

		node->next = NULL;
		cout << node->data << endl;
		
		t--;
	}
}
void  SlistStack::size() {
	cout << t << endl;
}
int main() {
	int n, x;
	string input;
	SlistStack s;
	cin >> n;
	while (n--) {
		cin >> input;
		if (input == "empty") {
			if (s.isEmpty())cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (input == "top")s.top();
		else if (input == "push") {
			cin >> x;
			s.push(x);
		}
		else if (input == "pop")s.pop();
		else if (input == "size")s.size();
	}
}

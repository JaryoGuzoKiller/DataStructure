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
class Qlist {
public:
	
	int n;
	Node* head;
	Node* tail;
	Qlist() {
		n = 0;
		head = NULL;
		tail = NULL;
	}
	void enqueue(int);
	void dequeue();
	int size();
	bool isEmpty();
	void front();
	void rear();
};
bool Qlist::isEmpty() {
	if (head == NULL)return true;
	else
		return false;
}
void Qlist::enqueue(int x) {
	
	Node* node = new Node(x);
	if (head == NULL) {
		head = node;
		tail = node;
	}
	else {
		
		tail->next = node;
		tail = node;
	}
	n++;
}
void Qlist::dequeue() {
	if (isEmpty())cout << "Empty" << endl;
	else {
		Node* temp = head;
		cout << temp->data << endl;

		head = head->next;
		temp->next = NULL;
		delete temp;
		n--;
	}
}
int Qlist::size() {
	return n;
}
void Qlist::front() {
	if (isEmpty())cout << "Empty" << endl;
	else
		cout << head->data << endl;
}
void Qlist::rear() {
	if (isEmpty())cout << "Empty" << endl;
	else
		cout << tail->data << endl;
}
int main() {
	int num, n, x;
	cin >> num;
	cin >> n;
	string input;
	Qlist q;
	while (n--) {
		cin >> input;
		if (input == "isEmpty") {
			if (q.isEmpty())cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (input == "enqueue") {
			cin >> x;
			if (q.size() == num)
				cout << "Full" << endl;
			else
				q.enqueue(x);
		}
		else if (input == "dequeue") q.dequeue();
		else if (input == "size")cout << q.size() << endl;
		else if (input == "front")q.front();
		else if (input == "rear")q.rear();
	}
}

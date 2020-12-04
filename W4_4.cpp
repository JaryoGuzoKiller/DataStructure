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
class Slist {
public:
	Node* head;
	Node* tail;
	Slist() {
		head = NULL;
		tail = NULL;
	}
	void dequeue();
	void enqueue(int);
	int front();
	void addDiffer(int);
};
void Slist::dequeue() {
	Node* node = head;
	head = head -> next;
	node->next = NULL;
	delete node;
}
void Slist::enqueue(int x) {
	Node* node = new Node(x);
	if (head == NULL)
		head = tail = node;
	else {
		tail->next = node;
		tail = node;
	}
}
int Slist::front() {
	return head->data;
}
void Slist::addDiffer(int differ) {
	if (head->next == NULL)
		return;
	dequeue();
	head->data += differ;
}
int main() {
	int game, round;
	cin >> game;

	while (game--) {
		cin >> round;
		Slist p1, p2;
		for (int i = 0; i < round; i++) {
			int x;
			cin >> x;
			p1.enqueue(x);
		}
		for (int i = 0; i < round; i++) {
			int x;
			cin >> x;
			p2.enqueue(x);
		}
		int score1=0, score2=0;
		while (round--) {
			if (p1.front() > p2.front()) {
				p2.addDiffer(p1.front() - p2.front() - 1);
				p1.dequeue();
				score1++;
			}
			else if (p1.front() < p2.front()) {
				p1.addDiffer(p2.front() - p1.front() - 1);
				p2.dequeue();
				score2++;
			}
			else {
				p1.dequeue();
				p2.dequeue();
			}
		}
		if (score1 > score2)
			cout <<  1<< endl;
		else if (score1 < score2)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
}
#include<iostream>
using namespace std;
class arrQueue {
public:
	int f, r, n;
	int* Q;
	int capacity;
	arrQueue(int capacity) {
		this->capacity = capacity;
		Q = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			Q[i] = 0;
		}
		f = 0;
		r = -1;
		n = 0;
	}
	void enqueue(int);
	void dequeue();
	bool isEmpty();
	void front();
	void rear();
	int size() {
		return (r - f + 1 + capacity) % capacity;//nÀº ¿Ö ¾ÈµÉ±î
	}
};
bool arrQueue::isEmpty() {
	if (n == 0)return true;
	else
		return false;
}
void arrQueue::enqueue(int x) {
	if(size() == capacity - 1) cout << "Full" << endl;
	else {
		
		r = (r + 1) % capacity;
		Q[r] = x;
		n++;
	}
}
void arrQueue::dequeue() {
	if (isEmpty())cout << "Empty" << endl;
	else {
		cout << Q[f] << endl;
		Q[f] = 0;
		f = (f + 1) % capacity;
		n--;
	}
}
void arrQueue::front() {
	if (isEmpty())cout << "Empty" << endl;
	else
		cout << Q[f] << endl;
}
void arrQueue::rear() {
	if (isEmpty())cout << "Empty" << endl;
	else {
		//if (r == 0) r = capacity;
		cout << Q[r] << endl;
	}
}
int main() {
	int n, x, size;
	cin >> size;
	cin >> n;
	string input;
	arrQueue q(size + 1);
	while (n--) {
		cin >> input;
		if (input == "enqueue") {
			cin >> x;
			q.enqueue(x);
		}
		else if (input == "dequeue")q.dequeue();
		else if (input == "size")cout << q.size() << endl;
		else if (input == "isEmpty") {
			if (q.isEmpty())cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (input == "front")q.front();
		else if (input == "rear")q.rear();
	}
	return 0;
}

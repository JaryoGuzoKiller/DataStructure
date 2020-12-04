#include<iostream>
using namespace std;

class arrQueue {
public:
	int f, r;

	int* Q;
	arrQueue(int size) {
	
		f = 0;
		r = -1;
		Q = new int[size];
		for (int i = 0; i < size; i++) {
			Q[i] = 0;
		}
	}

	void enqueue(int);
	void dequeue();
	
	int front();
	void addDiffer(int);
};
void arrQueue::enqueue(int x) {
	r = r + 1;
	Q[r] = x;
}
void arrQueue::dequeue() {
	Q[f] = 0;
	f = f + 1 ;
}
int arrQueue::front() {
	return Q[f];
}
void arrQueue::addDiffer(int differ) {
	dequeue();
	Q[f] += differ;
}
int main() {
	int T;
	cin >> T;
	int cardNum;
	
	
	while (T--) {
		cin >> cardNum;

		arrQueue p1(cardNum + 1);
		arrQueue p2(cardNum + 1);
		int score1 = 0, score2 = 0;
		for (int i = 0; i < cardNum; i++) {
			int x;
			cin >> x;
			p1.enqueue(x);
		}
		
		for (int i = 0; i < cardNum; i++) {
			int x;
			cin >> x;
			p2.enqueue(x);
		}
	
		for (int i = 0; i < cardNum; i++) {
			if (p1.front() > p2.front()) {
				score1++;
				
				p1.addDiffer(p1.front()-p2.front()-1);
			
				p2.dequeue();
			}
			else if (p1.front() == p2.front()) {
				p1.dequeue();
				p2.dequeue();
			}
			else {
				score2++;
				
				p2.addDiffer(p2.front()-p1.front()-1);
				
				p1.dequeue();
			}
		}
		if (score1 > score2)
			cout << 1 << endl;
		else if (score1 == score2)
			cout << 0 << endl;
		else
			cout << 2 << endl;
	}
}
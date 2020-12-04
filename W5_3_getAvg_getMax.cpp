#include<iostream>
#include<cmath>
using namespace std;
class Double_list {
	struct Node {
		int data;
		Node* next;
		Node* prev;
	};
public:
	class Iterator {
	public:
		Node* v;
		Iterator(Node* u) {
			v = u;
		}
		Iterator& operator++() {
			v = v->next;
			return *this;
		}
		Iterator& operator--() {
			return *this;
		}
	};
public:
	Node* header;
	Node* trailer;
	int n;
	Double_list() {
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	Iterator begin()const {
		return Iterator(header->next);
	}
	void insert(Iterator& p, int e) {
		Node* w = p.v->prev;
		Node* v = new Node;
		v->data = e;

		v->next = p.v;
		p.v->prev = v;

		w->next = v;
		v->prev = w;
		n++;
	}
	void erase(Iterator& p) {
		Node* temp = p.v;
		Node* w = p.v->next;
		Node* u = p.v->prev;
		u->next = w;
		w->prev = u;
		delete temp;
		n--;
	}
	int size() const {
		return n;
	}
	int getMax() {
		Iterator p = begin();
		int max = 0;
		while (p.v != trailer) {
			if (max < (p.v->data)) {
				max = p.v->data;
			}
			p.operator++();
		}
		return max;
	}
	int getAverage() {
		Iterator p = begin();
		int sum = 0;
		while (p.v != trailer) {
			sum = sum + p.v->data;
			p.operator++();
		}
		return floor(sum / n);
	}
};
int main() {
	int num, n, x;
	cin >> num;

	while (num--) {
		cin >> n;
		Double_list s;
		Double_list::Iterator iter(s.begin());
		for (int i = 0; i < n; i++) {
			cin >> x;
			s.insert(iter, x);
			iter = s.begin();
		}
		cout << s.getAverage() << " " << s.getMax() << endl;
	}
}

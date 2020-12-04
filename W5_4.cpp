#include<iostream>
using namespace std;
class Double_list {
	struct Node {
		int e;
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
			v = v->prev;
			return *this;
		}
	};
public:
	int n;
	Node* header;
	Node* trailer;
	Double_list() {
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	void insert(Iterator& p,const int& e) {
		Node* v = p.v->prev;
		Node* u = new Node;
		u->e = e;
		u->next = p.v;
		p.v->prev = u;
		v->next = u;
		u->prev = v;
		n++;
	}
	Iterator begin() const {
		return Iterator(header->next);
	}
	int getAvg() {
		Iterator p = begin();
		int sum = 0;
		while (p.v != trailer) {
			sum += p.v->e;
			p.operator++();
		}
		return floor(sum / n);
	}
	int getMin() {
		Iterator p = begin();
		int min = p.v->e;
		p.operator++();
		while (p.v != trailer) {
			if (min > p.v->e)
				min = p.v->e;
			p.operator++();
		}
		return min;
	}
};
int main() {
	int n, num, x;
	cin >> n;
	
	while (n--) {
		cin >> num;
		Double_list s;
		Double_list::Iterator iter(s.begin());
		for (int i = 0; i < num; i++) {
			
			cin >> x;
			s.insert(iter, x);
			s.begin();
		}
		cout << s.getAvg() << " " << s.getMin() << endl;
	}
}
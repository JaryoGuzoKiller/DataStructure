#include<iostream>
using namespace std;
class SequenceList {
	struct Node {
		int e;
		Node* prev;
		Node* next;
	};
public:
	class Iterator {
	private:
		Node* v;
	public:
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
		friend class SequenceList;
	};
public:
	int n;
	Node* header;
	Node* trailer;
	SequenceList() {
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	void insert(const Iterator& p,const int& e) {
		Node* u = p.v->prev;
		Node* r = new Node;
		r->e = e;

		r->next = p.v;
		p.v->prev = r;
		r->prev = u;
		u->next = r;
		n++;
	}
	void erase(const Iterator& p) {
		if (n == 0)cout << "Empty" << endl;
		else {
			Node* tmp = p.v;
			Node* w = p.v->prev;
			Node* u = p.v->next;


			u->prev = w;
			w->next = u;
			delete tmp;
			n--;
		}
	}
	Iterator begin()const {
		return Iterator(header->next);
	}
	Iterator end()const {
		return Iterator(trailer);
	}
	int size() const{
		return n;
	}
	void reversePrint(){
		if (n == 0)cout << "Empty" << endl;
		else {
			Node* cur = trailer->prev;
			while (cur != header) {
				cout << cur->e << " ";
				cur = cur->prev;
			}
			cout << endl;
		}
	}
};
int main() {
	int num;
	cin >> num;
	string input;
	SequenceList s;
	SequenceList::Iterator iter = s.begin();
	while (num--) {
		cin >> input;

		if (input == "insert") {
			int x;
			cin >> x;
			s.insert(iter,x);
		}
		else if (input == "erase")s.erase(iter);
		else if (input == "begin")iter = s.begin();
		else if (input == "end")iter = s.end();
		else if (input == "++")iter.operator++();
		else if (input == "--")iter.operator--();
		else if (input == "reversePrint")s.reversePrint();
		else if (input == "size")cout << s.size() << endl;
	}
}
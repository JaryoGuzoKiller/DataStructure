#include<iostream>
using namespace std;
class SequenceList {
private:
	struct Node {
		int e;
		Node* prev;
		Node* next;
	};
public:
	class Iterator {
	private:
		Node* v;
		Iterator(Node* u);
	public:
		Iterator& operator++();
		Iterator& operator--();

		friend class SequenceList;
	};
private:
	int n;
	Node* header;
	Node* trailer;
public:
	SequenceList();
	int size() const;
	bool empty() const;
	Iterator begin()const;
	Iterator end() const;

	void insert(const Iterator& p, const int& e);
	void erase(const Iterator& p);
	void print();

};
SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}
void SequenceList::insert(const Iterator& p, const int& e) {
	Node* w = p.v;
	Node* u = w->prev;
	Node* r = new Node;
	r->e = e;
	r->next = w;
	w->prev = r;
	u->next = r;
	r->prev = u;

	this->n++;
}
void SequenceList::erase(const Iterator& p) {
	if (empty()) cout << "Empty" << "\n";
	else {
		Node* tmp = p.v;
		Node* w = tmp->next;
		Node* u = tmp->prev;
		u->next = w;
		w->prev = u;

		delete tmp;
		this->n--;
	}
}
SequenceList::Iterator::Iterator(Node* u) {
	v = u;
}
SequenceList::Iterator SequenceList::begin()const {
	return Iterator(header->next);
}
SequenceList::Iterator SequenceList::end()const {
	return Iterator(trailer);
}
SequenceList::Iterator& SequenceList::Iterator::operator++() {
	v = v->next;
	return *this;
}
SequenceList::Iterator& SequenceList::Iterator::operator--() {
	v = v->prev;
	return *this;
}
void SequenceList::print() {
	if (empty()) cout << "Empty" << "\n";
	else {
		Node* tmp = header->next;
		while (1) {
			if (tmp == trailer) break;
			else {
				cout << tmp->e << " ";
				tmp = tmp->next;
			}
		}
		cout << endl;
	}
}
int SequenceList::size() const {
	return n;
}
bool SequenceList::empty() const {
	return (n == 0);
}
int main() {
	SequenceList SL;
	SequenceList::Iterator iter = SL.begin();
	int n;
	cin >> n;
	string input;
	int e;
	while (n--) {

		cin >> input;

		if (input == "insert") {
			cin >> e;
			SL.insert(iter, e);
		}
		else if (input == "erase") {
			SL.erase(iter);
		}
		else if (input == "begin") {
			iter = SL.begin();
		}
		else if (input == "end") {
			iter = SL.end();
		}
		else if (input == "++") {
			iter.operator++();
		}
		else if (input == "--") {
			iter.operator--();
		}
		else if (input == "print") {
			SL.print();
		}
		else if (input == "size") {
			cout << SL.size() << "\n";
		}
	}
}

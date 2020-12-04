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
		Iterator(Node* u) {
			v = u;
		}
	public:
		Iterator& operator++() {
			v = v->next;
			return *this;
		};
		Iterator& operator--() {
			v = v->prev;
			return *this;
		};
		friend class SequenceList;
	};
private:
	Node* header;
	Node* trailer;
	int n;
public:
	SequenceList() {
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}

	void insert(const Iterator& p, const int& e) {
		
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
	void erase(const Iterator& p) {
		if (n == 0)cout << "Empty" << endl;
		else {
			Node* tmp = p.v;
			Node* u = tmp->prev;
			Node* w = tmp->next;
			u->next = w;
			w->prev = u;

			delete tmp;
			n--;
		}
	}
	Iterator begin() const {
		return Iterator(header->next);
	}
	Iterator end() const{
		return Iterator(trailer);
	}
	void print() {
		if (n==0) cout << "Empty" << "\n";
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
	int size()const {
		return n;
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
			s.insert(iter, x);
		}
		else if (input == "erase")s.erase(iter);
		else if (input == "begin")iter=s.begin();
		else if (input == "end")iter=s.end();
		else if (input == "++")iter.operator++();
		else if (input == "--")iter.operator--();
		else if (input == "print")s.print();
		else if (input == "size")cout << s.size() << endl;
	}
	return 0;
}

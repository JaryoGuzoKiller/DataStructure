#include<iostream>
#include<vector>
using namespace std;
enum dir{ MIN = 1, MAX = -1 };
class Heap {
	vector<int> v;
	int dir;
	int heapsize;
public:
	Heap(int dir) {
		v.push_back(-1);
		heapsize = 0;
		this->dir = dir;
	}
	bool isEmpty() {
		return(heapsize == 0);
	}
	int size() {
		return heapsize;
	}
	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upHeap(int idx) {
		if (idx == 1)return;

		int par = idx / 2;
		if (v[par] * dir > v[idx]*dir) {
			swap(par, idx);
			upHeap(par);
		}
	}
	void insert(int e) {
		v.push_back(e);
		heapsize++;
		upHeap(heapsize);
	}
	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;

		if (right <= heapsize) {
			if (v[left] * dir <= v[right] * dir) {
				if (v[left] * dir < v[idx] * dir) {
					swap(left, idx);
					downHeap(left);
				}
				else
					return;
			}
			else {
				if (v[right] * dir < v[idx] * dir) {
					swap(right, idx);
					downHeap(right);
				}
				else
					return;
			}
		}
		else if (left <= heapsize) {
			if (v[left]*dir < v[idx]*dir) {
				swap(left, idx);
				downHeap(left);
			}
			else
				return;
		}
		else
			return;
	}
	int pop() {
		if (isEmpty())return -1;

		int top = v[1];
		v[1] = v[heapsize]; heapsize--;
		v.pop_back();
		downHeap(1);
		return top;
	}
	int top() {
		if (isEmpty())return -1;

		return v[1];
	}
	void print() {
		if (isEmpty())cout << -1 << endl;
		else {
			for (int i = 1; i < v.size(); i++)
				cout << v[i] << " ";
			cout << endl;
		}
	}
};
int main() {
	int n;
	cin >> n;
	string input;
	Heap h(MIN);
	while (n--) {
		cin >> input;
		if (input == "isEmpty") cout << h.isEmpty() << endl;
		else if (input == "insert") {
			int e;
			cin >> e;
			h.insert(e);
		}
		else if (input == "size")cout << h.size() << endl;
		else if (input == "pop")cout << h.pop() << endl;
		else if (input == "top")cout << h.top() << endl;
		else if (input == "print")h.print();
	}
}
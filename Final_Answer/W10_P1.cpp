#include<iostream>
#include<vector>
#include<string>
using namespace std;
enum direction  { MIN = 1,MAX = -1 };
class Heap {
	vector<int> v;
	int root_index;
	int heap_size;
	int direction;
public:
	Heap(int direction) {
		this->direction = direction;
		this-> root_index = 1;
		v.push_back(-1);
		this->heap_size = 0;
	}
	bool isEmpty() {
		return(heap_size == 0);
	}
	int size() {
		return heap_size;
	}
	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upHeap(int idx) {
		if (root_index == idx)return;
		int par = idx / 2;
		if (v[par] * direction > v[idx] * direction) {
			swap(par,idx);
			upHeap(par);
		}
	}
	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}
	void downHeap(int idx) {
		if (idx == heap_size)return;
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heap_size) {
			if (v[left] * direction >= v[right] * direction){
				if (v[right] * direction < v[idx] * direction) {
					swap(idx, right);
					downHeap(right);
				}
				else
					return;
			}
			else {
				if (v[left] * direction < v[right] * direction) {
					if (v[left] * direction < v[idx] * direction) {
						swap(idx, left);
						downHeap(left);
					}
					else
						return;
				}
			}
		}
		else if (left <= heap_size) {
			if (v[left]*direction < v[idx] * direction) {
				swap(idx, left);
				downHeap(left);
			}
			else
				return;
		}
	}
	int pop() {
		if (isEmpty())return -1;
		int top = v[root_index];
		v[root_index] = v[heap_size];
		heap_size--;
		v.pop_back();
		downHeap(root_index);
		return top;
	}
	int top() {
		if (isEmpty())return -1;
		return v[root_index];
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
	Heap h(MAX);
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
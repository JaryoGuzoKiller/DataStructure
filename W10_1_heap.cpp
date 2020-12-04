#include<iostream>
#include<vector>
using namespace std;
enum direction{MIN=1,MAX=-1};

class Heap {
private:
	vector<int> v;
	int heap_size;
	int root_index;
	int direction;
public:
	Heap(int direction) {
		v.push_back(-1);
		this->root_index = 1;
		this->direction = direction;
		this->heap_size = 0;
	}
	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upHeap(int idx) {
		if (idx == root_index) return;
		else {
			int parent = idx / 2;
			if (v[parent] * direction > v[idx] * direction) {
				swap(parent, idx);
				upHeap(parent);
			}
		}
	}
	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heap_size) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction) {
					swap(left, idx);
					downHeap(left);
				}
				else return;
			}
			else {
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
					downHeap(right);
				}
				else return;
			}
		}
		else if (left <= heap_size) {
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else return;
	}
	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}
	int pop() {
		int top = v[root_index];
		v[root_index] = v[heap_size];
		heap_size--;
		v.pop_back();
		downHeap(root_index);
		return top;
	}
	int top() {
		return v[root_index];
	}
	int size() {
		return heap_size;
	}
	bool isEmpty() {
		if (heap_size == 0)return true;
		else return false;
	}
	void print() {
		if (isEmpty())cout << -1 << endl;
		else {
			for (int i = root_index; i <= heap_size; i++)
				cout << v[i] << " ";
			cout << endl;
		}
	}
};
int main() {
	int n;
	cin >> n;
	Heap h(MAX);
	string input;
	while (n--) {
		cin >> input;
		if (input == "insert") {
			int x;
			cin >> x;
			h.insert(x);
		}
		else if (input == "size") {
			cout << h.size() << endl;
		}
		else if (input == "isEmpty") {
			if (h.isEmpty())cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (input == "pop") {
			if (h.isEmpty())cout << -1 << endl;
			else
				cout << h.pop() << endl;
		}
		else if (input == "top") {
			if (h.isEmpty())cout << -1 << endl;
			else
				cout << h.top() << endl;
		}
		else if (input == "print") {
			h.print();
		}
	}
}

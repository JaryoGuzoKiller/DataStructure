#include<iostream>
#include<vector>
using namespace std;

enum dir { MIN = 1, MAX = -1 };
class Heap {
public:
	vector<int> v;
	int dir;
	int heapsize;
	int upHeapCount;

	Heap(int dir) {
		v.push_back(-1);
		this->dir = dir;
		this->heapsize = 0;
		this->upHeapCount = 0;
	}
	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upHeap(int idx) {
		upHeapCount++;
		if (idx == 1)return;

		int par = idx / 2;
		if (v[par] * dir > v[idx] * dir) {
			swap(idx, par);
			upHeap(par);
		}
	}
	void insert(int e) {
		v.push_back(e);
		heapsize++;
		upHeap(heapsize);//매개변수 e가 아닌 heapsize(가장 마지막 인덱스)!!!!!
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
			if (v[left] * dir < v[idx] * dir) {
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
		int top = v[1];

		v[1] = v[heapsize]; heapsize--;
		v.pop_back();
		downHeap(1);
		return top;
	}
	int top() {
		return v[1];
	}
	void print() {
		for (int i = 1; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	int n, count = 0;
	cin >> n;

	while (n--) {
		int size, p;
		Heap h(MAX);
		cin >> size >> p;
		while (size--) {
			int e;
			cin >> e;
			h.insert(e);
		}
		h.print();
		cout << h.v[p] << endl;
		for (int i = 0; i < p-1; i++) {
			h.pop();
		}
		cout << h.top() << endl;
		count += h.upHeapCount;
		cout << count << endl;
	}
}
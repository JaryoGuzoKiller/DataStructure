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
		heapsize = 0;
		upHeapCount = 0;
	}
	bool isEmpty() {
		return (heapsize == 0);
	}
	int size() {
		return heapsize;
	}
	void swap(int a, int b) {
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}
	void upHeap(int idx) {
		upHeapCount++;
		if (idx == 1)return;

		int par = idx / 2;
		if (v[par] * dir > v[idx] * dir) {
			
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
		v[1] = v[heapsize];
		heapsize--;
		v.pop_back();
		downHeap(1);
		return top;
	}
	int top(){
		return v[1];
	}
	void print() {
		for (int i = 1; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	void minSort() {
		int temp;
		int copyj;
		
		for (int i = 1; i < v.size(); i++) {
			int min = 2000000;// ÀÌ°Å ¶§¹®¿¡ ·Õ¾Ø¼­ ¶ä!!!!!!!!!!!!!!!!!!ÁÖÀÇ
			
			for (int j = i; j < v.size(); j++) {
				if (v[j] < min) {
					min = v[j];
					copyj = j;
				}
			}
			v[copyj] = v[i];
			v[i] = min;
		}
	}
	
};
int main() {
	int n;
	int count = 0;
	cin >> n;

	while (n--) {
		Heap h(MIN);
		int size, p;
		
		cin >> size >> p;
		
		for (int i = 0; i < size; i++) {
			int e;
			cin >> e;
			h.insert(e);
		}

		h.print();
		cout << h.v[p] << endl;

		h.minSort();
		//h.print();
		cout << h.v[p] << endl;

		count += h.upHeapCount;
		cout << count << endl;
	}
}
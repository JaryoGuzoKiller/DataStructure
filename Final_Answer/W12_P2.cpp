#include<iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;
class cell {
public:
	int flag;
	int value;
	int key;

	cell() {
		flag = NOITEM;
		value = -1;
		key = -1;
	}
};
class DoubleHashing {
	int cursize;
	int arrsize;
	cell* hasharr;
public:
	DoubleHashing(int arrsize) {
		this->arrsize = arrsize;
		hasharr = new cell[arrsize];
		cursize = 0;
	}
	int hashfunc(int key) {
		return key % arrsize;
	}
	int hashfunc2(int key) {
		return(17 - (key % 17));
	}
	void put(int key) {
		int probing = 1;
		int initial_idx = hashfunc(key);
		int curidx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrsize;

		while (hasharr[curidx].flag==ISITEM) {
			probing += 1;
			curidx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrsize;
		}
		hasharr[curidx].key = key;
		hasharr[curidx].value =key;
		hasharr[curidx].flag = ISITEM;
	}
	void print() {
		for (int i = 0; i < arrsize; i++) {
			cout << hasharr[i].key << " ";
		}
		cout << endl;
	}
};
int main() {
	int n;
	cin >> n;
	while (n--) {
		int arrsize;
		cin >> arrsize;

		DoubleHashing h(arrsize);

		int cursize;
		cin >> cursize;
		while (cursize--) {
			int x;
			cin >> x;
			h.put(x);
		}
		h.print();
	}
}

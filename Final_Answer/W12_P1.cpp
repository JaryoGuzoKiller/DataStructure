#include<iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

class cell {
public:
	int key;
	int value;
	int flag;
	cell() {
		key = -1;
		value = -1;
		flag = NOITEM;
	}

};
class LinearHashTable {
	cell* hashArr;
	int arrsize;//해시 테이블의 크기
	int cursize;//현재까지 삽입됨 entry 갯수
public:
	LinearHashTable(int arrsize) {
		this->arrsize = arrsize;
		hashArr = new cell[arrsize];
		cursize = 0;
	}
	int hashfunc(int key) {
		return key % arrsize;
	}
	void find(int key) {
		int probing = 1;
		int initial_idx = hashfunc(key);
		int curidx = hashfunc(key);
		bool firstOpr = true;
		//빈공간을 찾아 이동
		while (hashArr[curidx].flag == ISITEM || hashArr[curidx].flag == AVAILABLE) {
			if (hashArr[curidx].key == key)
			{
				cout << "find " << key << endl;
				return;
			}
			else if (curidx == initial_idx && !firstOpr) {
				cout << "loop" << endl;
				return;
			}
			probing += 1;
			firstOpr = false;
			curidx = (hashfunc(key) + probing - 1) % arrsize;
		}
		cout << "don't find " << key << endl;
	}
	void put(int key, int value) {
		int probing = 1;
		int initial_idx = hashfunc(key)%arrsize;
		int curidx = hashfunc(key)%arrsize;
		bool firstOpr = true;

		if (isFull()) { cout << " Full" << endl; }
		else {
			while (hashArr[curidx].flag== ISITEM){
				if (curidx == initial_idx && !firstOpr)
				{
					cout << "loop" << endl;
					break;
				}
				probing += 1;
				firstOpr = false;
				curidx = (hashfunc(key) + probing - 1) % arrsize;
			}
			hashArr[curidx].key = key;
			hashArr[curidx].value = value;
			hashArr[curidx].flag = ISITEM;
			cursize++;
		}
	}
	bool isFull() {
		return (cursize == arrsize);
	}
	void erase(int key) {
		int probing = 1;
		int initial_idx = hashfunc(key);
		int curidx = hashfunc(key);
		bool first = true;
		if (isEmpty()) { cout << "Empty" << endl; }
		else {
			while (hashArr[cursize].flag == ISITEM || hashArr[cursize].flag == AVAILABLE) {
				if (hashArr[curidx].key == key) {
					hashArr[curidx].flag = AVAILABLE;
					hashArr[curidx].value = -1;
					hashArr[curidx].key = -1;
					break;
				}
				else if (curidx == initial_idx && !first) {
					cout << "loop" << endl;
					break;
				}
				probing += 1;
				first = false;
				curidx = (hashfunc(key) + probing - 1) % arrsize;
				
			}
			cursize--;
		}
	}
	bool isEmpty() {
		return (cursize == 0);
	}
	void print() {
		for (int i = 0; i < arrsize; i++) {
			cout << hashArr[i].value << " ";
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

		LinearHashTable h(arrsize);

		int cursize;
		cin >> cursize;
		while (cursize--) {
			int x;
			cin >> x;
			h.put(x,x);
		}
		h.print();
	}

}
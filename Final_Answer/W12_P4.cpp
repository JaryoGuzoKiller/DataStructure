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
class LinearHashing {
public:
	cell* hashArr;
	int cursize;
	int arrsize;
	LinearHashing(int arrsize) {
		this->arrsize = arrsize;
		cursize = 0;
		hashArr = new cell[arrsize];
	}
	int hashfunc(int key) {
		return key % arrsize;
	}
	void put(int key) {
		int initial_key = hashfunc(key);
		int curidx = hashfunc(key);
		int probing = 1;

		while (hashArr[curidx].flag == ISITEM) {
			probing += 1;
			curidx = (hashfunc(key) + probing - 1)%arrsize;
		}
		hashArr[curidx].key = key;
		hashArr[curidx].value = key;
		hashArr[curidx].flag = ISITEM;
		cursize++;
	}
	void find(int key) {
		int initial_key = hashfunc(key);
		int curidx = hashfunc(key);
		int probing = 1;

		while (hashArr[curidx].flag == ISITEM
			||hashArr[curidx].flag==AVAILABLE) {
			if (hashArr[curidx].key == key) {
				cout << "True " << probing << endl;
				return;
			}
			probing += 1;
			curidx = (hashfunc(key) + probing - 1) % arrsize;
		}
		cout << "False " << probing << endl;
	}
};
int main() {
	int n;
	cin >> n;

	while (n--) {
		int arrsize;
		cin >> arrsize;

		LinearHashing d(arrsize);

		int cursize;
		cin >> cursize;
		while (cursize--) {
			int x;
			cin >> x;
			d.put(x);
		}
		int num;
		cin >> num;
		while (num--) {
			int x;
			cin >> x;
			d.find(x);
		}

	}
}
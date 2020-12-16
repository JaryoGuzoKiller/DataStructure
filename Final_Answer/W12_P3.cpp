#include<iostream>
using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

class cell {
public:
	int flag;
	int key;
	int value;
	cell() {
		flag = NOITEM;
		key = -1;
		value = -1;
	}
};
class DoubleHashing {
public:
	cell* hashArr;
	int cursize;
	int arrsize;

	DoubleHashing(int arrsize) {
		this->arrsize = arrsize;
		hashArr = new cell[arrsize];
		cursize = 0;
	}
	int hashfunc(int key) {
		return key % arrsize;
	}
	int hashfunc2(int key) {
		return(17 - (key % 17));
	}
	void put(int key, int value) {
		int probing = 1;
		int initial_idx = hashfunc(key);
		int curidx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrsize;

		while (hashArr[curidx].flag == ISITEM) {
			probing += 1;
			curidx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrsize;
		}
		hashArr[curidx].key = key;
		hashArr[curidx].value = value;
		hashArr[curidx].flag = ISITEM;
		cursize++;
	}
	void find(int key){
		int probing = 1;
		int initial_idx = hashfunc(key);
		int curidx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrsize;
		
		while (hashArr[curidx].flag == ISITEM||hashArr[curidx].flag==AVAILABLE) {
			if (hashArr[curidx].key == key) {
				cout << "True " << probing << endl;
				return;
			}	
			probing += 1;
			curidx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrsize;
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

		DoubleHashing d(arrsize);
		
		int cursize;
		cin >> cursize;
		while (cursize--) {
			int x;
			cin >> x;
			d.put(x, x);
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
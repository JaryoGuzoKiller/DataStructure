#include<iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

class cell
{
public:
	int key, value, flag;
	cell() {
		key = -1;
		value = -1;
		flag = NOITEM;
	}
};

class DoubleHashing {
private:
	cell* hashArr;
	int arrSize;
	int curSize;
public:
	DoubleHashing(int size) {
		this->arrSize = size;
		hashArr = new cell[arrSize];
		//curSize = 0;
	}
	int hashfunc(int key) {
		return key % arrSize;
	}
	int hashfunc2(int key) {
		return(17 - (key % 17));
	}
	void put(int key, int value) {
		int probing = 1;
		int initial_idx = hashfunc(key) % arrSize;
		int curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;


		while (hashArr[curIdx].flag == ISITEM) {
			probing += 1;
			curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
		}
		hashArr[curIdx].key = key;
		hashArr[curIdx].value = value;
		hashArr[curIdx].flag = ISITEM;
		//curSize++;
	}
	void find(int key) {
		int probing = 1;
		int initial_idx = hashfunc(key) % arrSize;
		int curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
		int count = 1;
		while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE)
		{
			if (hashArr[curIdx].key == key) {
				cout << "True " << count << endl;
				return;
			}
			probing += 1;
			curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
			count++;
		}
		cout << "False " << count << endl;
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << hashArr[i].value << " ";
		}
	}
};

int main() {
	int n;
	cin >> n;

	while (n--) {
		int size;
		cin >> size;

		int arrSize;
		cin >> arrSize;
		DoubleHashing t(size);
		while (arrSize--) {
			int x;
			cin >> x;
			t.put(x, x);
		}
		int findNum;
		cin >> findNum;
		while (findNum--) {
			int x;
			cin >> x;
			t.find(x);
		}
	}
}

#include<iostream>
using namespace std;

class Array {
	int arr[10000] = { 0, };

public:
	void at(int i) {
		if (arr[i] == 0) {
			cout << 0 << endl;
		}
		else
			cout << arr[i] << endl;
	}
	void set(int i, int x) {
		if (arr[i] == 0) {
			cout << 0 << endl;
		}
		else {
			arr[i] = x;
		}
	}
	void add(int i, int x) {
		if (arr[i]==0) {
			for (int k = 0; k < 10000; k++) {
				if (arr[k] == 0) {
					arr[k] = x;
					break;
				}
			}
		}
		else {
			for (int j = 9999; j >= i; j--) {
				arr[j + 1] = arr[j];
			}
			arr[i] = x;
		}
	}

};

int main() {
	Array a;

	int n;
	cin >> n;
	string input;
	int x, i;
	while(n--){
		cin >> input;
		if (input == "at") {
			cin >> i;
			a.at(i);
		}
		else if (input == "add"){
			cin >> i >> x;
			a.add(i, x);
		}
		else if (input == "set") {
			cin >> i>> x;
			a.set(i, x);
		}
	}
}

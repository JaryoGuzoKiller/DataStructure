#include<iostream>
using namespace std;

class ArrayStack {
public:
	int c;
	int t;
	int* S;
	
	ArrayStack(int c) {
		this->c = c;
		this->S = new int[c];
		t = -1;
	}
	bool isEmpty() {
		if (t == -1)return true;
		else
			return false;
	}
	void top() {
		cout << S[t] << endl;
	}
	void push(int data) {
		t = t + 1;
		S[t] = data;
	}
	void pop() {
		if (isEmpty())cout << -1 << endl;
		else
		{
			cout << S[t] << endl;
			t = t - 1;
		}
	}
	void size() {
		cout << t + 1 << endl;
	}
};

int main() {
	int n, x;
	cin >> n;
	ArrayStack a(100);
	string input;
	while (n--) {
		cin >> input;
		if (input == "empty") {
			if (a.isEmpty())cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (input == "top")
			a.top();
		else if (input == "push") {
			cin >> x;
			a.push(x);
		}
		else if (input == "pop")a.pop();
		else if (input == "size")a.size();
	}
}

#include<iostream>
using namespace std;
class Stack {
public:
	int t;
	int capacity;
	char* S;
	Stack(int capacity) {
		this->capacity = capacity;
		this->S = new char[capacity];
		t = -1;
	}
	bool isEmpty();
	void push(char);
	char pop();
	char top();
};
bool Stack::isEmpty() {
	if (t == -1)return true;
	else
		return false;
}
void Stack::push(char x) {
	t = t + 1;
	S[t] = x;
}
char Stack::pop() {
	t = t - 1;
	return S[t + 1];
}
char Stack::top() {
	return S[t];
}
int getOrder(char op) {
	switch (op) {
	case'*':
		return 3;
	case'+':
		return 2;
	case'-':
		return 2;
	case'(':
		return 1;
	default:
		return -1;
	}
}
int main() {
	int n;
	cin >> n;

	string input;
	Stack s(1000);
	while (n--) {
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input.at(i) != '(' && input.at(i) != ')' && input.at(i) != '+' &&
				input.at(i) != '-' && input.at(i) != '*')
				cout << input.at(i);

			else if (input.at(i) == '(' || input.at(i) == ')') {
				if (input.at(i) == '(') s.push(input.at(i));
				else {
					while (1) {
						if (s.top() == '(') {
							s.pop();
							break;
						}
						cout << s.pop();
					}
				}
			}
			else {//operator case
				while (!s.isEmpty() && getOrder(s.top()) >= getOrder(input.at(i)))
					cout<<s.pop();
				s.push(input.at(i));
			}

		}
		while (!s.isEmpty()) {
			cout << s.pop();
		}
		cout << endl;
	}
}
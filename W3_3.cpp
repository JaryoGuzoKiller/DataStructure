#include<iostream>
using namespace std;
class ArrayStack {
public:
	int t;
	int capacity;
	int* Stack;
	ArrayStack(int capacity) {
		this->Stack = new int[capacity];
		this->capacity = capacity;
		t = -1;
	}
	void push(int);
	int pop();
	int top();
	bool isEmpty();
};
void ArrayStack::push(int x) {
	t = t + 1;
	Stack[t] = x;
}
int ArrayStack::pop() {
	t = t - 1;
	return Stack[t+1];
}
int ArrayStack::top() {
	return Stack[t];
}

int main() {
	int n;
	cin >> n;
	string input;
	ArrayStack a(100);
	while (n--) {
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input.at(i) != '+' && input.at(i) != '-' && input.at(i) != '*' && input.at(i) != '/') {
				a.push(input.at(i) - '0');
			}
			else {

				int num1, num2;
				int result = 0;
				num1 = a.pop();
				num2 = a.pop();


				switch (input.at(i)) {
				case '+':
					result = num2 + num1;
					break;
				case '-':
					result = num2 - num1;
					break;
				case'*':
					result = num2 * num1;
					break;
				case'/':
					result = num2 / num1;
					break;
				}
				a.push(result);
			}
		}
		cout << a.pop() << endl;
	}
}
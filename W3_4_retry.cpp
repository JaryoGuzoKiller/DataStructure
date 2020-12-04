#include<iostream>
using namespace std;
class Node {
public:
	char data;
	Node* next;
	Node(char data) {
		this->data = data;
		next = NULL;
	}
};
class LinkedStack {
public:
	Node* head;
	LinkedStack() {
		head = NULL;
	}
	void push(char x) {
		Node* node = new Node(x);
		if (head == NULL)
			head = node;
		else {
			node->next = head;
			head = node;
		}
	}
	void pop() {
		Node* node = head;
		head = head->next;
		node->next = NULL;
	}
	char top() {
		return head->data;
	}
	bool isEmpty() {
		if (head == NULL)return true;
		else
			return false;
	}
};
int getOrder(char op) {
	switch (op) {
	case '*':
		return 3;
	case '+':
		return 2;
	case '-':
		return 2;
	case'(':
		return 1;
	}
}
//1.숫자를 만나면 무조건 출력
//2.왼괄호를 만나면 무조건 push
//3.오른괄호를 만나면 왼괄호를 만날때까지 pop
//4.연산자를 만나면 비어있거나 자신보다 연산자우선순위 같거나 높은 연산자를 모두 pop,
//그리고 자신은 push
int main() {
	int n;
	cin >> n;
	string input;
	LinkedStack l;
	while (n--) {
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input.at(i) != '*' && input.at(i) != '+' && input.at(i) != '-' &&
				input.at(i) != '(' && input.at(i) != ')')
				cout << input.at(i);

			else if (input.at(i) == '(')
				l.push(input.at(i));

			else if (input.at(i) == ')') {
				while (1) {
					if (l.top() == '(') {
						l.pop();
						break;
					}
					else {
						cout << l.top();
						l.pop();
					}
				}
			}
			else {
				while (!l.isEmpty() && getOrder(input.at(i)) <= getOrder(l.top())) {
					cout << l.top();
					l.pop();
				}
				l.push(input.at(i));
			}
		}
		while (!l.isEmpty()) {
			cout << l.top();
			l.pop();
		}
		cout << endl;
	}
}
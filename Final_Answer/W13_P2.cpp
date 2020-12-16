#include<iostream>
#include<vector>
using namespace std;
int vertex[2001] = { 0, };
bool edge_exist[2001][2001] = { false, };

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int temp = n;
	while (n--) {
		int x;
		cin >> x;
		vertex[x] = 1;
	}
	int count = 0;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (vertex[x] == 0 || vertex[y] == 0) {
			cout << -1 << endl;
		}
		else if (edge_exist[x][y] == true || edge_exist[y][x] == true) {
			cout << -1 << endl;
		}
		else {
			edge_exist[x][y] = true;
			edge_exist[y][x] = true;
			count++;
		}
	}
	cout << temp << " " << count << endl;
	while (k--) {
		int x, y;
		cin >> x >> y;
		if (vertex[x] == 0 || vertex[y] == 0)
			cout << -1 << endl;
		else if (edge_exist[x][y] != 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}
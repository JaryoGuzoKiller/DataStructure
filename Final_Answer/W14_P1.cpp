#include<iostream>
#include<vector>
using namespace std;
bool matrix[501][501] = { false, };
char info[501] = { NULL, };
bool visited[501] = { false, };
void DFS(int k) {
	cout << info[k];
	visited[k] = true;

	for (int i = 0; i < 501; i++) {
		if (matrix[k][i] == true&&visited[i]==false) {
			DFS(i);
		}
	}

}
int main() {
	int n, m, k;
	cin >> n >> m >> k;

	while (n--) {
		int x;
		char c;
		cin >> x >> c;
		info[x] = c;
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		matrix[x][y] = true;
		matrix[y][x] = true;
	}
	DFS(k);
	cout << endl;
}
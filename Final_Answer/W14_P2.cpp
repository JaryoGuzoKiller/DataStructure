#include<iostream>
#include<vector>
using namespace std;
vector<int> v[20001];
bool visited[20001] = { false, };

void DFS(int k) {
	cout << k << " ";
	visited[k] = true;
	for (int i = 0;i< v[k].size(); i++) {
		if (visited[v[k][i]] == false)
			DFS(v[k][i]);
	}
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	while (n--) {
		int vertex;
		cin >> vertex;
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		bool exist = false;
		for (int i = 0; i < v[x].size(); i++) {
			if (v[x][i] == y) {
				cout << -1 << endl;
				exist = true;
				break;
			}
		}
		if (!exist) {
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	DFS(k);
}
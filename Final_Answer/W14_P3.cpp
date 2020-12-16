#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[20001];
bool visited[20001] = { false, };
queue<int> q;

void BFS(int k) {
	cout << k << " ";
	visited[k] = true;
	q.push(k);
	while (!q.empty()) {
		int nownode = q.front();
		q.pop();
		for (int i = 0; i < v[nownode].size(); i++) {
			if (visited[v[nownode][i]] == false) {
				q.push(v[nownode][i]);
				visited[v[nownode][i]] = true;
				cout << v[nownode][i] << " ";
			}
		}
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
	BFS(k);
}
#include<iostream>
#include<vector>
using namespace std;
bool vertex[2001] = { false, };               //정점존재유무
bool edge_exist[2001][2001] = { false, };    //간선 존재 유무     
class edge {
public:
	int src;
	int dst;
	string str;
	edge(int src, int dst, string str) {
		this->src = src;
		this->dst = dst;
		this->str = str;
	}
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int temp = n;
	while (n--) {
		int x;
		cin >> x;
		vertex[x] = true;
	}
	int count = 0;       //간선의 개수
	vector<edge*> edgelist;
	while (m--) {
		int x, y;
		string word;
		cin >> x >> y >> word;
		if (vertex[x] == 0 || vertex[y] == 0) {   //정점이 없으면
			cout << -1 << endl;
		}
		else if (edge_exist[x][y] == true || edge_exist[y][x] == true) {
			cout << -1 << endl;         //간선이 이미 있으면
		}
		else {
			edge_exist[x][y] = true;
			edge_exist[y][x] = true;
			edge* e=new edge(x, y,word);
			edgelist.push_back(e);
			count++;
		}
	}
	cout << temp << " " << count << endl;    

	int cnt = count;//남은 간선의 개수
	while (k--) {        //삭제
		int x;
		cin >> x;
		
		if (vertex[x] == NULL)
			cout << -1 << endl;
		else {
			vertex[x] = NULL;
			for (int i = 0; i < 2001; i++) {
				if (edge_exist[x][i] == true) {
					cnt--;//간선의 개수 하나 감소
					edge_exist[x][i] = false;
					edge_exist[i][x] = false;
				}
			}
			for (int i = 0; i < edgelist.size(); i++) {
				if (edgelist[i]->src == x || edgelist[i]->dst == x) {
					edgelist[i]->str = "";   //지우면 벡터 사이즈가 줄어서 안됨
				}
			}
			cout << cnt << " ";
			for (auto& e : edgelist) {
				if(e->str!="")                //삭제된거 제외하고 출력
					cout << e->str << " ";
			}
			cout << endl;
		}	
	}
}
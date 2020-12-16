#include<iostream>
#include<vector>
using namespace std;
bool vertex[2001] = { false, };               //������������
bool edge_exist[2001][2001] = { false, };    //���� ���� ����     
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
	int count = 0;       //������ ����
	vector<edge*> edgelist;
	while (m--) {
		int x, y;
		string word;
		cin >> x >> y >> word;
		if (vertex[x] == 0 || vertex[y] == 0) {   //������ ������
			cout << -1 << endl;
		}
		else if (edge_exist[x][y] == true || edge_exist[y][x] == true) {
			cout << -1 << endl;         //������ �̹� ������
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

	int cnt = count;//���� ������ ����
	while (k--) {        //����
		int x;
		cin >> x;
		
		if (vertex[x] == NULL)
			cout << -1 << endl;
		else {
			vertex[x] = NULL;
			for (int i = 0; i < 2001; i++) {
				if (edge_exist[x][i] == true) {
					cnt--;//������ ���� �ϳ� ����
					edge_exist[x][i] = false;
					edge_exist[i][x] = false;
				}
			}
			for (int i = 0; i < edgelist.size(); i++) {
				if (edgelist[i]->src == x || edgelist[i]->dst == x) {
					edgelist[i]->str = "";   //����� ���� ����� �پ �ȵ�
				}
			}
			cout << cnt << " ";
			for (auto& e : edgelist) {
				if(e->str!="")                //�����Ȱ� �����ϰ� ���
					cout << e->str << " ";
			}
			cout << endl;
		}	
	}
}
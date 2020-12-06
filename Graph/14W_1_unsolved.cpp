#include<iostream>
#include<string>
#include<vector>
#include<queue>
//#inlcude<stack>
using namespace std;


#define NOT_EXPLORED 0
#define DISCOVERY 1
#define BACK 2
class vertex {
public:
	int data;
	string info;
	int degree;
	bool visited;
	vector <vertex*> adj_list;
	
	vertex(int data,string info) {
		this->info = info;
		this->data = data;
		this->degree = 0;
		this->visited = false;
	}
};

class edge {
public:
	vertex* src;
	vertex* dst;
	
	int edge_stat;
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		this->edge_stat = NOT_EXPLORED;
	}
};

#define vertexRange 1000
class graph {
public:
	edge*** edgeMatrix;
	vector<vertex*> vertex_list;
	vector<edge*> edge_list;
	graph() {
		edgeMatrix = new edge * *[vertexRange];
		for (int i = 0; i < vertexRange; i++) {
			edgeMatrix[i] = new edge * [vertexRange];
			for (int j = 0; j < vertexRange; j++) {
				edgeMatrix[i][j] = NULL;
			}
		}
	}
	
	vertex* findvertex(int data) {
		vertex* v = NULL;
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == data) {
				v = vertex_list[i];
				break;
			}
		}
		return v;
	}
	edge* findedge(int src, int dst) {
		int _src = NULL, _dst = NULL;
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == src) {
				_src = i;
			}
			if (vertex_list[i]->data == dst) {
				_dst = i;
			}
		}
		if (edgeMatrix[_src][_dst] == NULL) {
			return NULL;
		}
		else {
			return edgeMatrix[_src][_dst];
		}
	}

	void insert_vertex(int n, string info) {
		if (findvertex(n) != NULL) {
			return;
		}

		else {
			vertex* newVertex = new vertex(n, info);
			vertex_list.push_back(newVertex);
		}
	}

	void insert_edge(int source, int destination) {
		vertex* src = findvertex(source);
		vertex* dst = findvertex(destination);
		int _src = NULL, _dst = NULL;
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == source) {
				_src = i;
			}
			if (vertex_list[i]->data == destination) {
				_dst = i;
			}
		}
		if (findedge(source, destination) == NULL) {
			edge* new_e = new edge(src, dst);
			edge_list.push_back(new_e);
			edgeMatrix[_src][_dst] = new_e;
			edgeMatrix[_dst][_src] = new_e;
			src->adj_list.push_back(dst);
			dst->adj_list.push_back(src);

		}
		else {
			cout << -1 << endl;
			return;
		}
		src->degree++;
		dst->degree++;
	}
	int getXY(int source) {
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == source) {
				return i;
			}
		}
	}

	void DFS(vertex* curV) {
		cout << curV->info;//bacde
		curV->visited = true;

		queue<vertex*>sorted_queue;
		vector<vertex*>newlist = curV->adj_list;
		
		int min = 500;
		int temp = 0;
		int size = newlist.size();
		vertex* u = NULL;
		for (int i = 0; i < size; i++) {
			int min = 500;
			for (int j = 0; j < newlist.size(); j++) {
				if (min > newlist[j]->data) {
					min = newlist[j]->data;
					u = newlist[j];
					temp = j;
				}
			}
			sorted_queue.push(u);
			newlist.erase(newlist.begin()+temp);
		}
		while (!sorted_queue.empty()) {

			edge* e=edgeMatrix[getXY(curV->data)][getXY(sorted_queue.front()->data)];
			if (e->edge_stat == NOT_EXPLORED) {
				vertex* w = sorted_queue.front();
				if (w->visited == false) {
					e->edge_stat = DISCOVERY;
					DFS(w);
				}
				else
					e->edge_stat = BACK;
			}
			sorted_queue.pop();
		}
	}
	
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	graph g;
	while (n--) {
		int x;
		string info;
		cin >> x >> info;
		g.insert_vertex(x,info);
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		g.insert_edge(x, y);
	}
	g.DFS(g.findvertex(k));
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define MappingSize 501

class vertex {
public:
	vertex* prev;
	vertex* next;
	int degree;
	int data;
	
	vertex(int data) {
		this->degree = 0;
		this->data = data;
	}
	void increase_degree() {
		this->degree++;
	}
	void decrease_degree() {
		this->degree--;
	}
};

class edge {
public:
	edge* prev;
	edge* next;
	vertex* source;
	vertex* destination;
	string data;
	
	edge(vertex* a, vertex* b, string data) {
		this->source = a;
		this->destination = b;
		this->data = data;
	}
};

class DoublyVertexLinkedList {	//vertex로 이루어진 이중연결리스트
public:
	vertex* head;
	vertex* tail;
	DoublyVertexLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}
	void insert(vertex* insertVertex) {
		if (this->head == NULL) {
			head = insertVertex;
			tail = insertVertex;
		}
		else {
			tail->next = insertVertex;
			insertVertex->prev = tail;
			tail = insertVertex;
		}
	}
	void remove(vertex* delVertex) {
		if (delVertex == head || delVertex == tail) {
			if (delVertex == head && delVertex != tail) {
				vertex* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (delVertex == tail && delVertex != head) {
				vertex* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
			else { head = tail = NULL; }
		}
		else {
			delVertex->prev->next = delVertex->next;
			delVertex->next->prev = delVertex->prev;
			delete delVertex;
		}
	}
};

class DoublyEdgeLinkedList {		//edge로 이루어진 이중연결리스트
public:
	edge* head;
	edge* tail;
	DoublyEdgeLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}
	void insert(edge* insertEdge) {
		if (this->head == NULL) {
			head = insertEdge;
			tail = insertEdge;
		}
		else {
			tail->next = insertEdge;
			insertEdge->prev = tail;
			tail = insertEdge;
		}
	}
	void remove(edge* delEdge) {
		if (delEdge == head || delEdge == tail) {
			if (delEdge == head && delEdge != tail) {
				edge* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (delEdge == tail && delEdge != head) {
				edge* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
			else { head = tail = NULL; }
		}
		else {
			delEdge->prev->next = delEdge->next;
			delEdge->next->prev = delEdge->prev;
			delete delEdge;
		}
	}
};

class Graph {
public:
	edge*** edgeMatrix;						//edge정보를 관리하는 matrix
	DoublyVertexLinkedList* VertexList;		//전체 vertex정보를 관리하는 이중연결리스트
	DoublyEdgeLinkedList* EdgeList;			//전체 edge정보를 관리하는 이중연결리스트
	int vertexSize;
	int edgeSize;
	//그래프에 존재하는 vertex의 개수
	int mappingTable[MappingSize];			// vertex의 고유한 번호와 
											// 해당 veretx의 matrix에서 index로 매핑

	Graph() {
		this->VertexList = new DoublyVertexLinkedList();
		this->EdgeList = new DoublyEdgeLinkedList();
		this->vertexSize = 0;
		for (int i = 0; i < MappingSize; i++)mappingTable[i] = -1;
		this->edgeMatrix = new edge * *[1];
		this->edgeMatrix[0] = new edge * [1];
		this->edgeMatrix[0][0] = NULL;
		int edgeSize = 0;
	}
	bool isfindVertex(int n) {		// VertexList에서 고유한 번호가 n인 vertex의 존재 유무 검사
		bool flag = false;
		vertex* temp = VertexList->head;
		while (temp != NULL) {
			if (temp->data == n) {
				flag = true;
				break;
			}
			temp = temp->next;
		}
		return flag;
	}
	vertex* findVertex(int n) {				// VertexList에서 고유한 번호가 n인 
		vertex* temp = VertexList->head;    //vertex의 주소 반환
		while (temp != NULL) {
			if (temp->data == n) {
				break;
			}
			temp = temp->next;
		}
		return temp;
	}

	void insert_vertex(int n) {			// 그래프에 고유한 번호가 n인 vertex 삽입
		if (isfindVertex(n) == true) {
			return;
		}

		else {
			edge*** tempMatrix = new edge * *[vertexSize + 1];  //정점이 1개 추가될 때마다 
			for (int i = 0; i < vertexSize + 1; i++) {        //기존 matrix보다 가로, 세로 길이가 1만큼 
				tempMatrix[i] = new edge * [vertexSize + 1];	  //더 큰 tempmatrix 생성
				for (int j = 0; j < vertexSize + 1; j++) {
					tempMatrix[i][j] = NULL;
				}
			}

			for (int i = 0; i < vertexSize; i++) {
				for (int j = 0; j < vertexSize; j++) {
					tempMatrix[i][j] = this->edgeMatrix[i][j];	 //element들  copy
				}
			}

			//for (int i = 0; i < vertexSize; i++) {
			//	
			//		delete this->edgeMatrix[i];	 //element들  copy
			//	
			//}
			//delete this->edgeMatrix;

			this->edgeMatrix = tempMatrix;

			vertex* newVertex = new vertex(n);
			VertexList->insert(newVertex);						//VertexList에 고유번호가 n인 vertex 추가
			this->vertexSize++;
			mappingTable[vertexSize - 1] = n;					// mappingtable에 vertex 자신이 
		}														//matrix의 어느 index인지 저장
	}


	void erase_vertex(int n) {                          // 그래프에 고유한 번호가 n인 vertex 제거
		if (isfindVertex(n) == false || vertexSize == 0) {
			return;
		}
		else {
			edge*** tempMatrix = new edge * *[vertexSize - 1]; //정점이 1개 삭제될 때마다
			for (int i = 0; i < vertexSize - 1; i++) {       //기존 matrix보다 가로, 세로 길이가 1만큼
				tempMatrix[i] = new edge * [vertexSize - 1];   //더 작은 tempmatrix 생성
				for (int j = 0; j < vertexSize - 1; j++) {
					tempMatrix[i][j] = NULL;
				}
			}

			int middleIdx = 0;
			for (int i = 0; i < vertexSize; i++) {
				if (mappingTable[i] == n)middleIdx = i;		//middleidx: 삭제할 vertex의 matrix에서의 인덱스
			}
			for (int i = middleIdx; i < vertexSize; i++) {	// mappingtable update
				mappingTable[i] = mappingTable[i + 1];
			}


			for (int i = 0; i < vertexSize; i++) {			//EdgeList에서 고유번호가 n인 vertex와 연결된 모든 edge들 제거
				if (this->edgeMatrix[middleIdx][i] != NULL) {
					EdgeList->remove(this->edgeMatrix[middleIdx][i]);
				}
			}

			for (int i = 0; i < vertexSize; i++) {			//middleidx를 기점으로 element들을 적절히 copy
				for (int j = 0; j < vertexSize; j++) {
					if (i < middleIdx && j < middleIdx) {
						tempMatrix[i][j] = this->edgeMatrix[i][j];
					}
					else if (i > middleIdx && j > middleIdx) {
						tempMatrix[i - 1][j - 1] = this->edgeMatrix[i][j];
					}
					else if (j > middleIdx) {
						tempMatrix[i][j - 1] = this->edgeMatrix[i][j];
					}
					else if (i > middleIdx) {
						tempMatrix[i - 1][j] = this->edgeMatrix[i][j];
					}
				}
			}
			this->edgeMatrix = tempMatrix;
			VertexList->remove(findVertex(n));			//VertexList에 고유번호가 n인 vertex 제거
			this->vertexSize--;

		}
	}

	void insert_edge(int indirectSource, int IndirectDestination, string data) {
		if (isfindVertex(indirectSource) == false || isfindVertex(IndirectDestination) == false) {
			cout << -1 << endl;
			return;
		}

		int destination = -1;
		int source = -1;
		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == IndirectDestination)destination = i;
			if (mappingTable[i] == indirectSource)source = i;
			if (source != -1 && destination != -1)break;
		}

		if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL) {
			cout << -1 << endl;
			return;
		}

		edge* newEdge = new edge(findVertex(indirectSource), findVertex(IndirectDestination), data);
		edgeMatrix[source][destination] = newEdge;
		edgeMatrix[destination][source] = newEdge;

		findVertex(indirectSource)->increase_degree();
		findVertex(IndirectDestination)->increase_degree();

	}

	void erase_edge(int indirectSource, int IndirectDestination) {
		int destination = -1;
		int source = -1;
		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == IndirectDestination)destination = i;
			if (mappingTable[i] == indirectSource)source = i;
			if (source != -1 && destination != -1)break;
		}

		if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL)return;
		findVertex(indirectSource)->decrease_degree();
		findVertex(IndirectDestination)->decrease_degree();

		edge* delEdge = edgeMatrix[source][destination];
		EdgeList->remove(delEdge);

		edgeMatrix[source][destination] = NULL;
		edgeMatrix[destination][source] = NULL;
	}
	void isAdjacent(int ver1, int ver2)
	{
		int findidx1 = -1;
		int findidx2 = -1;

		for (int i = 0; i < vertexSize; i++)
		{
			if (ver1 == mappingTable[i])
			{
				findidx1 = i;
			}

			if (ver2 == mappingTable[i])
			{
				findidx2 = i;
			}
		}

		if (findidx1 == -1 || findidx2 == -1)
		{
			cout<<-1<<endl;
		}
		else if (edgeMatrix[findidx1][findidx2] != NULL || edgeMatrix[findidx2][findidx1] != NULL)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<< 0<<endl;
		}
	}
};
	int main() {
		int n, m, k;
		cin >> n >> m>>k;

		Graph g;

		for (int i = 0; i < n; i++) {
			int vertex;
			cin >> vertex;
			g.insert_vertex(vertex);
		}
		while (m--) {
			int start, dest;
			cin >> start >> dest;
			g.insert_edge(start, dest, "기모찌");
		}
		int edgeSize = 0;
		for (int i = 0; i < g.vertexSize; i++) {
			for (int j = 0; j < g.vertexSize; j++) {
				if (g.edgeMatrix[i][j] != NULL)
					edgeSize++;
			}
		}
		cout << g.vertexSize << " " << edgeSize / 2 << endl;
		while (k--) {
			int v1, v2;
			cin >> v1 >> v2;
			g.isAdjacent(v1, v2);
		}
	}

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

class DoublyVertexLinkedList {	//vertex�� �̷���� ���߿��Ḯ��Ʈ
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

class DoublyEdgeLinkedList {		//edge�� �̷���� ���߿��Ḯ��Ʈ
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
	edge*** edgeMatrix;						//edge������ �����ϴ� matrix
	DoublyVertexLinkedList* VertexList;		//��ü vertex������ �����ϴ� ���߿��Ḯ��Ʈ
	DoublyEdgeLinkedList* EdgeList;			//��ü edge������ �����ϴ� ���߿��Ḯ��Ʈ
	int vertexSize;
	int edgeSize;
	//�׷����� �����ϴ� vertex�� ����
	int mappingTable[MappingSize];			// vertex�� ������ ��ȣ�� 
											// �ش� veretx�� matrix���� index�� ����

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
	bool isfindVertex(int n) {		// VertexList���� ������ ��ȣ�� n�� vertex�� ���� ���� �˻�
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
	vertex* findVertex(int n) {				// VertexList���� ������ ��ȣ�� n�� 
		vertex* temp = VertexList->head;    //vertex�� �ּ� ��ȯ
		while (temp != NULL) {
			if (temp->data == n) {
				break;
			}
			temp = temp->next;
		}
		return temp;
	}

	void insert_vertex(int n) {			// �׷����� ������ ��ȣ�� n�� vertex ����
		if (isfindVertex(n) == true) {
			return;
		}

		else {
			edge*** tempMatrix = new edge * *[vertexSize + 1];  //������ 1�� �߰��� ������ 
			for (int i = 0; i < vertexSize + 1; i++) {        //���� matrix���� ����, ���� ���̰� 1��ŭ 
				tempMatrix[i] = new edge * [vertexSize + 1];	  //�� ū tempmatrix ����
				for (int j = 0; j < vertexSize + 1; j++) {
					tempMatrix[i][j] = NULL;
				}
			}

			for (int i = 0; i < vertexSize; i++) {
				for (int j = 0; j < vertexSize; j++) {
					tempMatrix[i][j] = this->edgeMatrix[i][j];	 //element��  copy
				}
			}

			//for (int i = 0; i < vertexSize; i++) {
			//	
			//		delete this->edgeMatrix[i];	 //element��  copy
			//	
			//}
			//delete this->edgeMatrix;

			this->edgeMatrix = tempMatrix;

			vertex* newVertex = new vertex(n);
			VertexList->insert(newVertex);						//VertexList�� ������ȣ�� n�� vertex �߰�
			this->vertexSize++;
			mappingTable[vertexSize - 1] = n;					// mappingtable�� vertex �ڽ��� 
		}														//matrix�� ��� index���� ����
	}


	void erase_vertex(int n) {                          // �׷����� ������ ��ȣ�� n�� vertex ����
		if (isfindVertex(n) == false || vertexSize == 0) {
			return;
		}
		else {
			edge*** tempMatrix = new edge * *[vertexSize - 1]; //������ 1�� ������ ������
			for (int i = 0; i < vertexSize - 1; i++) {       //���� matrix���� ����, ���� ���̰� 1��ŭ
				tempMatrix[i] = new edge * [vertexSize - 1];   //�� ���� tempmatrix ����
				for (int j = 0; j < vertexSize - 1; j++) {
					tempMatrix[i][j] = NULL;
				}
			}

			int middleIdx = 0;
			for (int i = 0; i < vertexSize; i++) {
				if (mappingTable[i] == n)middleIdx = i;		//middleidx: ������ vertex�� matrix������ �ε���
			}
			for (int i = middleIdx; i < vertexSize; i++) {	// mappingtable update
				mappingTable[i] = mappingTable[i + 1];
			}


			for (int i = 0; i < vertexSize; i++) {			//EdgeList���� ������ȣ�� n�� vertex�� ����� ��� edge�� ����
				if (this->edgeMatrix[middleIdx][i] != NULL) {
					EdgeList->remove(this->edgeMatrix[middleIdx][i]);
				}
			}

			for (int i = 0; i < vertexSize; i++) {			//middleidx�� �������� element���� ������ copy
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
			VertexList->remove(findVertex(n));			//VertexList�� ������ȣ�� n�� vertex ����
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
			g.insert_edge(start, dest, "�����");
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

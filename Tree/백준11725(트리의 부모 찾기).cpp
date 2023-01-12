#include<iostream>
#include<vector>

using namespace std;


class Graph {
public:
	int Nodes;
	//인접 노드들 저장
	vector<vector<int>> adj;
	//방문했는지 여부 저장
	vector<bool> visited;
	//노드들의 부모 노드 저장하는 벡터
	vector<int> parent;
	
	Graph() :Nodes(0) {	}
	Graph(int N) :Nodes(N) {
		//1부터 N까지 값이 정점으로 들어오므로 0부터 N까지 잡아줘야함
		adj.resize(N+1);
		visited.resize(N+1,false);
		parent.resize(N + 1);
	}
	//u,v 노드 연결
	void ConnectNodes(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//adj에 연결된 노드들 dfs방식으로 부모 정점 parent벡터에 할당
	void SetPrevNodeInAllNode(int Node) {
		if (visited[Node]) return;
		visited[Node] = true;
		for (auto i : adj[Node]) {
			if (visited[i]) continue;
			parent[i] = Node;
			SetPrevNodeInAllNode(i);
		}
	}
	//index정점의 부모 정점 출력용
	int GetParent(int index) {
		return parent[index];
	}
};
Graph* g;
void Input() {
	int N=0,tmpNode1=0,tmpNode2=0;
	cin >> N;
	g = new Graph(N);
	//그래프에서 두개 정점 이어주고 
	for (int i = 0; i < N-1; i++) {
		cin >> tmpNode1 >> tmpNode2;
		g->ConnectNodes(tmpNode1, tmpNode2);
	}
	//1부터 시작해서 dfs방식으로 parent배열에 부모값 다 저장
	g->SetPrevNodeInAllNode(1);
	for (int i = 2; i <= N; i++) {
		//각 2~ N값의 부모값 출력
		cout << g->GetParent(i) << '\n';
	}
	
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}


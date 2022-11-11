#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Graph {
private:
	int Nodes;
	vector<vector<int>> adj;
	vector<int> visited;
public:
	//생성자
	Graph(int N) :Nodes(N) {
		adj.resize(N+1);
		visited.resize(N+1);
	}

	//양방향으로 짰으므로 u와 v노드 서로 연결
	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//각 노드와 연결된 노드들을 오름차순으로 정렬
	void sortAdj(){
		for (int i = 1; i <= Nodes; i++) {
			sort(adj[i].begin(), adj[i].end());
		}
	}
	/// <summary>
	/// 각 정점마다 dfs 실행
	/// </summary>
	/// <returns>그래프 내의 컴퍼넌트 갯수</returns>
	int returnComponents(){
		int components = 0;
		for (int i = 1; i <= Nodes; i++) {
			if (!visited[i]) {
				components++;
				dfs(i);
			}
		}
		return components;
	}
	/// <summary>
	/// 매개변수로 들어온 Node정점에서 dfs로 연결요소들 탐색
	/// </summary>
	/// <param name="Node"></param>
	void dfs(int Node) {
		if (visited[Node]) return;
		visited[Node] = true;
		for (int k : adj[Node]) {
			if (!visited[k]) {
				dfs(k);
			}
		}
	}
};

void input() {
	int inputNodes = 0, inputEdges = 0,edge1=0,edge2=0;
	cin >> inputNodes >> inputEdges;
	//그래프 선언
	Graph g(inputNodes);
	g.sortAdj();
	for (int i = 0; i < inputEdges; i++) {
		cin >> edge1 >> edge2;
		g.addEdge(edge1, edge2);
	}
	cout << g.returnComponents();
}

int main() {
	input();
}
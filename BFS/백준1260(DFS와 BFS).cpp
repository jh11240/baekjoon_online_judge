#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int nodes = 0, edges = 0, initNode = 0;

/// <summary>
/// bfs, dfs 함수 정의한 그래프 객체
/// </summary>
class Graph {
public:
	//각 노드의 인접 노드 담은 2차원 벡터
	vector<vector<int>> adj;
	//각 노드의 방문 여부 저장한 벡터
	vector<int> visited;
	//bfs에서 사용될 큐
	queue<int> q;

	//생성자
	Graph() {
		//2차원 벡터 1001만큼 메모리 미리 할당해주기
		adj.resize(1000 + 1);
		//방문 벡터 1001만큼 메모리 미리 할당해주기
		visited.resize(1000 + 1);
	}

	//간선 이어주는 함수(양방향 그래프)
	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	//각 노드의 인접노드 sort해야함
	void sortVertex() {
		for (int i = 1; i <= nodes; i++) {
			sort(adj[i].begin(), adj[i].end());
		}
	}
	//dfs함수
	void dfs(int Node) {
		if (visited[Node]) return;
		visited[Node] = true;
		cout << Node<<" ";
		for (int elem : adj[Node]) {
			if (!visited[elem]) {
				dfs(elem);
			}
		}
	}
	//bfs함수
	void bfs(int Node) {
		q.push(Node);
		visited[Node] = true;
		while (!q.empty()) {
			int cur = q.front();
			cout << cur << ' ';
			q.pop();
			for (int elem : adj[cur]) {
				if (!visited[elem]) {
					visited[elem] = true;
					q.push(elem);
				}
			}
		}
	}
};
//전역 변수로 선언
Graph* g;

void input() {
	int node1=0,node2=0;
	cin >> nodes >> edges >> initNode;
	g = new Graph();
	for (int i = 0; i < edges; i++) {
		cin >> node1 >> node2;
		g->addEdge(node1,node2);
	}
	g->sortVertex();

}
void solution() {
	g->dfs(initNode);
	cout << '\n';
	//visited 1001까지 false해줘서 통과
	fill(&g->visited[1], &g->visited[1001], false);
	g->bfs(initNode);
}

int main() {
	input();
	solution();
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int nodes = 0, edges = 0, initNode = 0;

class Graph {
public:
	int Nodes;
	vector<vector<int>> adj;
	vector<int> visited;
	queue<int> q;

	Graph() :Nodes(1000) {
		adj.resize(1000 + 1);
		visited.resize(1000 + 1);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(int Node) {
		if (visited[Node]) return;
		visited[Node] = true;
		cout << Node<<" ";
		for (int elem : adj[Node]) {
			if (!visited[elem]) {
				visited[elem] = true;
				dfs(elem);
			}
		}
	}

	void bfs(int Node) {
		q.push(Node);
		visited[Node] = true;
		int qSize = q.size();
		cout << Node << ' ';
		for (int i = 0; i < qSize; i++) {
			int cur = q.front();
			cout << cur<<' ';
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
Graph* g;

void input() {
	int node1=0,node2=0;
	cin >> nodes >> edges >> initNode;
	g = new Graph();
	for (int i = 0; i < edges; i++) {
		cin >> node1 >> node2;
		g->addEdge(node1,node2);
	}

}
void solution() {
	g->dfs(initNode);
	cout << '\n';
	fill(&g->visited[0], &g->visited[nodes], false);
	g->bfs(initNode);
}

int main() {
	input();
	solution();
}
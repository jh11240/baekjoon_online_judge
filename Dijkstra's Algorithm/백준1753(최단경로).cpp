#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int V, E, startNode;
const int Max_V = 20'000;
const int INF = 1'000'000'000;

//index는 출발노드, value.first는 도착노드, value.second는 간선의가중치
vector<pair<int, int>> adj[Max_V];

//시작점에서 index까지의 최단거리
int dist[Max_V];

//index노드를 방문했는지 여부
bool visited[Max_V];

// {dist[node],node} 노드를 저장해서 dist값이 제일 작은값부터 반환
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//다익스트라 알고리즘 
void Solution() {

	while (!pq.empty()) {

		//방문안한 노드이면서 dist가 제일 작은 값부터 주위노드로 뻗어나가기를 반복함
		int curNode = pq.top().second;
		pq.pop();
		while (!pq.empty() && visited[curNode]) {
			curNode = pq.top().second;
			pq.pop();
		}
		//visited[curNode]==false일때가 아니라 pq가 empty일때 탈출한 상황이라면 체크해서 탈출 
		if (visited[curNode]) break;
		
		visited[curNode] = true;

		//curNode에서 연결된 노드로 이동하는 거리 갱신
		for (auto& p : adj[curNode]) {
			//cur
			if (dist[p.first] > p.second + dist[curNode]) {
				dist[p.first] = p.second + dist[curNode];
				//갱신될때마다 우선순위큐에 푸시해도 상관없다. 어차피 방문여부체크해서 제일 적은 값일때만 값을 체크해본다.
				pq.push({dist[p.first],p.first });
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i]<<'\n';
	}
}

void Input()
{
	fill(dist, dist + Max_V, INF);
	fill(visited, visited + Max_V, false);

	cin >> V >> E >> startNode;
	startNode--;
	//시작노드의 거리값 0으로 설정
	dist[startNode] = 0;
	//우선순위큐에 시작노드에 해당하는 값 넣어줌
	pq.push({ 0,startNode });
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back(make_pair(v - 1, w));
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solution();
}
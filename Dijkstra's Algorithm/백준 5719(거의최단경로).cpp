#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, M, S, D;
struct Edge{
	int U;
	int V;
	int dist;
	bool isShortest;
};
//간선 벡터
vector<Edge> v;
//도착점으로 부터 역방향 벡터
vector<vector<int>> pre;
//시작지점으로부터 순방향 벡터
vector<vector<int>> su;
queue<int> queueForFindingShortestPath;
int minDist[501];
bool visited[501];
int INF = 1'000'000'000;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;

void Deijkstra();
void DeleteShortestPath();

void Input() {
	int tmp1, tmp2,dist;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) return;
	

		cin >> S >> D;
		v.clear();
		pre.clear();
		pre.resize(N);
		su.clear();
		su.resize(N);
		while (!queueForFindingShortestPath.empty()) queueForFindingShortestPath.pop();
		
		for (int i = 0; i < M; i++) {
			cin >> tmp1 >> tmp2 >> dist;
			//v에 간선정보 저장
			v.push_back({ tmp1,tmp2,dist,false });
			//v의 인덱스값을 저장하므로 su는 tmp1과 연결된 간선 전체 정보를 v에서 꺼내쓴다.
			su[tmp1].push_back(i);
			//마찬가지로 pre는 인덱스 i로 tmp2와 연결된 간선 전체 정보를 저장함
			pre[tmp2].push_back(i);

		}
		Deijkstra();
		if (minDist[D]==INF) {
			cout << -1 << '\n';
			continue;
		}
		DeleteShortestPath();
		Deijkstra();
		if (minDist[D] == INF) {
			cout << -1 << '\n';
			continue;
		}
		cout << minDist[D]<<'\n';
	}
}

void Deijkstra() {
	fill(minDist, minDist + 500, INF);
	fill(visited, visited + 500, false);
	minDist[S] = 0;
	pq.push({ minDist[S],S });

	while (!pq.empty()) {
		int curNode = 0;
		do {
			curNode = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curNode]);

		if (visited[curNode]) {
			break;
		}
		visited[curNode] = true;
		//curNode와 연결된 간선들의 정보는 v[p]에 들어있음
		for (int p : su[curNode]) {
			//curNode에서 p로가는 루트가 최단거리 루트라면 진행하지않고 continue
			if (v[p].isShortest) continue;
			
			int nextNode = v[p].V, nextDist = v[p].dist;
			if (minDist[nextNode] > minDist[curNode] + nextDist) {
				minDist[nextNode] = minDist[curNode] + nextDist;
				pq.push({minDist[nextNode],nextNode});
			}
		}
	}
}

void DeleteShortestPath() {
	//시작지점D를 큐에 푸시
	queueForFindingShortestPath.push(D);
	fill(visited, visited + 500, false);
	//BFS시작
	while (!queueForFindingShortestPath.empty()) {
		int curNode = 0;
		do {
			curNode = queueForFindingShortestPath.front();
			queueForFindingShortestPath.pop();
		} while (!queueForFindingShortestPath.empty() && visited[curNode]);

		//큐가 비었는데 curNode가 방문한 노드라면 break;
		if (visited[curNode]) break;
		visited[curNode] = true;

		for (int elem: pre[curNode]) {
			int preNode = v[elem].U, preDist = v[elem].dist;
			//만약 curNode까지의 최단거리가 preNode를 거친 루트라면 해당 루트까지의 최단거리가 맞다.
			if (minDist[curNode] == minDist[preNode] + preDist) {
				queueForFindingShortestPath.push(preNode);
				//최단거리 경로라고 체크해줌으로써 다음 다익스트라에서 이 간선무시함
				v[elem].isShortest = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
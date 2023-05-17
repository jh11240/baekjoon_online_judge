#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;
int N, M;
int INF = 100'000'000;
//네트워크끼리 연결된 가중치
vector<vector<pair<int, int>>> adj;
//최단거리로 연결된 노드 저장용 map
map<int,int> prevNode;
//방문 여부 배열
bool visited[1001];
//최단거리 저장용 배열
int minDist[1001];
//다익스트라 용 우선순위큐 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Input() {
	int tmpNode1, tmpNode2, tmpTime;
	cin >> N >> M;
	adj.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> tmpNode1 >> tmpNode2 >> tmpTime;
		//양 방향이므로 두개 다 push back 
		adj[--tmpNode1].push_back({ --tmpNode2,tmpTime });
		adj[tmpNode2].push_back({tmpNode1,tmpTime });
	}
	
	fill(minDist, minDist + 1000, INF);
	fill(visited, visited + 1000, false);
	minDist[0] = 0;
	pq.push({minDist[0],0});
}
void Solution() {
	int curNode=0;
	while (!pq.empty()) {
		do {
			curNode = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curNode]);

		visited[curNode] = true;
		
		for (pair<int, int>& p : adj[curNode]) {
			int nextNode = p.first, nextDist = p.second;
			if (minDist[nextNode] > minDist[curNode] + nextDist) {
				minDist[nextNode] = minDist[curNode] + nextDist;
				pq.push({ minDist[nextNode],nextNode });
				//새로운 최단거리를 발견해서 갱신할때 두 노드를 map에 저장해줌
				prevNode[nextNode]=curNode;
			}
		}
	}
	//반복문이 끝나고 map에 남은 간선들이 슈퍼컴퓨터에서 다른 노드들과 연결된 최소 간선들이다.

	cout << prevNode.size() << '\n';
	for (auto p : prevNode) {
		cout << p.first+1 << " " << p.second+1<<'\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solution();
}
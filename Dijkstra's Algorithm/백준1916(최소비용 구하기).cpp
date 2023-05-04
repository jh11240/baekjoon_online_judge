#include<iostream>
#include<vector>
#include<queue>


using namespace std;
//index는 시작점, pair.first는 도착점, pair.second는 비용
vector<vector<pair<int, int>>> adj;
//방문여부
bool visited[1001];
//시작도시로부터의 최단 비용
int minCost[1001];
//비용최대값 10만, 도시 최대갯수 1000개라서 나올수 있는 최대거리는 9990만 이다
int N, M,startCity,endCity,MaxInt=100'000'000;
//정렬기준인 fisrt값은 해당 노드까지의 거리, second값은 해당 노드
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


void Solution() {
	while (!pq.empty()) {
		int curNode = pq.top().second;
		pq.pop();
		while (!pq.empty() && visited[curNode]) {
			curNode = pq.top().second;
			pq.pop();
		}

		//pq가 비어있고 curNode가 방문한 노드라면 탈출
		if (visited[curNode]) break;

		//방문처리해주기.
		visited[curNode] = true;

		//curNode주변 노드들의 최단거리값을 비교,갱신해주며 갱신되었다면 pq에 넣어줌
		for (pair<int, int>& p : adj[curNode]) {
			int nextNode = p.first, nextCost = p.second;
			if (minCost[nextNode] > minCost[curNode] + nextCost) {
				minCost[nextNode] = minCost[curNode] + nextCost;
				pq.push({ minCost[nextNode],nextNode });
			}
		}
	}
	//목적지까지 가는 거리 출력
	cout << minCost[endCity];
}

void Input() {
	int tmpStart, tmpEnd, cost;
	cin >> N >> M;
	adj.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> tmpStart >> tmpEnd >> cost;
		adj[tmpStart-1].push_back({ tmpEnd - 1, cost });
	}
	cin >> startCity >> endCity;
	//index는 0부터 시작하므로 1빼주기
	startCity--;
	endCity--;
	//방문 여부 다 false로 초기화
	fill(visited, visited + 1001, false);
	//최단 거리 전부 제일 큰값으로 초기화
	fill(minCost, minCost + 1001, MaxInt);
	//시작노드는 최단거리 0으로 
	minCost[startCity] = 0;
	//시작 노드 pq에 넣어주기
	pq.push(make_pair(minCost[startCity],startCity));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solution();
}
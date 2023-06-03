#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, f, s, t;
//비행기를 안 타고 차로만 갔을때의 최소 비용 저장용 배열
long long originMinCost[150'001];
//비행기를 탔을때의 최소비용 저장용 배열
long long flightEndMinCost[150'001];
bool visited[150'001];
long long INF = 8'000'000'000;
vector<vector<pair<int,int>>> edge;
vector<pair<int,int>> flight;
priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
void Input() {
	int u, v, c;
	cin >> n >> m >> f >> s >> t;
	edge.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		edge[u].push_back({ v,c });
		edge[v].push_back({ u,c });
	}
	for (int i = 0; i < f; i++) {
		cin >> u >> v;
		flight.push_back({u,v});
	}
}
void FirstDeijkstra() {
	fill(visited, visited + 150'000, false);
	fill(originMinCost, originMinCost + 150'000, INF);

	originMinCost[s] = 0;
	pq.push({ originMinCost[s],s });
	while (!pq.empty()) {
		int curNode = 0;
		do {
			curNode = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curNode]);
		if (visited[curNode]) break;
		visited[curNode] = true;

		for (auto& elem : edge[curNode]) {
			int nextNode = elem.first, nextDist = elem.second;
			if (originMinCost[nextNode] > originMinCost[curNode] + nextDist) {
				originMinCost[nextNode] = originMinCost[curNode] + nextDist;
				pq.push({originMinCost[nextNode],nextNode});
			}
		}
	}
}

void DetermineFlight() {
	//모든 flight를 한번씩 탔을때 거리중의 제일 최소비용
	long long Ans = originMinCost[t];
	//각 flight의 루트에서 다익스트라를 실행해서 최소거리 찾기
	for (auto& elem : flight) {
		fill(flightEndMinCost, flightEndMinCost + 150'000, INF);
		fill(visited, visited + 150'000, false);
		//비행 도착점까지의 비용은 비행 출발점까지의 비용과 같다.
		flightEndMinCost[elem.second] = originMinCost[elem.first];
		//비행 도착점에서 목적지까지 다익스트라 
		pq.push({ flightEndMinCost[elem.second],elem.second });
		while (!pq.empty()) {
			int curNode = 0;
			do {
				curNode = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visited[curNode]);

			if (visited[curNode]) break;
			visited[curNode] = true;

			for (auto& elem : edge[curNode]) {
				int nextNode = elem.first, nextDist = elem.second;
				if (flightEndMinCost[nextNode] > flightEndMinCost[curNode] + nextDist) {
					flightEndMinCost[nextNode] = flightEndMinCost[curNode] + nextDist;
					pq.push({ flightEndMinCost[nextNode],nextNode });
				}
			}
		}
		Ans = min(Ans, flightEndMinCost[t]);
	}
	cout << Ans;	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	FirstDeijkstra();
	DetermineFlight();
}
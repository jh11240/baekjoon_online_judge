#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N, M, K;
const int MAX = 10'000;
long long INF = 1e12;
vector<vector<pair<int, int>>> adj;
priority_queue < pair<long long, long long>, vector<pair<long long , long long>>, greater<pair<long long, long long>>> pq;
long long minDist[21][MAX];
bool visited[21][MAX]={0,};
void Input() {
	int u, v, cost;
	cin >> N >> M >> K;
	adj.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> cost;
		adj[--u].push_back({ --v,cost });
		adj[v].push_back({ u,cost });
	}
}

void Solution() {
	for (int i = 0; i <= 20; i++) {
		fill(minDist[i], minDist[i] + MAX, INF);
	}
	//이렇게 초기화시 오류남 why? 찾아보자 -> 멍청아 minDist열값 최대가 1만인데 10001까지 초기화시키면 어떡하냐 멍청아
	//fill(&minDist[0][0], &minDist[20][10'001], INF);
	//fill(&visited[0][0], &visited[20][10'001], false);
	minDist[K][0] = 0;
	pq.push({ 0, K*MAX});
	while (!pq.empty()) {
		int curNode=0, curK=0;
		do {
			curK = pq.top().second / MAX;
			curNode = pq.top().second%MAX;
			pq.pop();
		} while (!pq.empty()&&visited[curK][curNode]);

		if (visited[curK][curNode]) break;
		visited[curK][curNode] = true;

		for (auto& elem : adj[curNode]) {
			int nextNode = elem.first;
			long long dist = elem.second;

			if (minDist[curK][nextNode] > minDist[curK][curNode] + dist) {
				minDist[curK][nextNode] = minDist[curK][curNode] + dist;
				pq.push({minDist[curK][nextNode], curK*MAX+ nextNode});
			}

			if (curK-1 >= 0 && minDist[curK - 1][nextNode] > minDist[curK][curNode]) {
				minDist[curK - 1][nextNode] = minDist[curK][curNode];
				pq.push({ minDist[curK - 1][nextNode], (curK-1) * MAX + nextNode });
			}
		}
	}
	long long Ans = INF;
	for (int i = 0; i < 20; i++) {
		Ans = Ans > minDist[i][N - 1] ? minDist[i][N - 1] : Ans;
	}
	cout << Ans;
}

int main() {
	Input();
	Solution();
}
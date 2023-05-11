#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int minDist[1001];
int minDistX[1001];
bool visited[1001];
int N, M, X, INF=1'000'000;
vector<vector<pair<int, int>>> v;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Solution() {
	int Ans = 0;

	fill(minDistX, minDistX + 1001, INF);
	fill(visited, visited + 1001, false);

	minDistX[X] = 0;
	pq.push({ minDistX[X],X });
	//X에서 각 마을로의 다익스트라 알고리즘
	while (!pq.empty()) {
		int curNode = pq.top().second;
		pq.pop();
		while (!pq.empty() && visited[curNode]) {
			curNode = pq.top().second;
			pq.pop();
		}
		//curNode가 방문한 상태인데, pq가 비었다면 위 반복문 탈출함
		if (visited[curNode]) break;

		//방문 처리해주고
		visited[curNode] = true;

		//curnode에 인접한 노드들에 대해 curNode를 거쳐서 가는 거리가 더 짧은지 비교하고 갱신
		for (pair<int, int>& p : v[curNode]) {
			int nextNode = p.first, nextDist = p.second;
			if (minDistX[nextNode] > minDistX[curNode] + nextDist) {
				minDistX[nextNode] = minDistX[curNode] + nextDist;
				pq.push({ minDistX[nextNode],nextNode });
			}
		}
	}

	//각마을에서 x로의 다익스트라 알고리즘
	for (int i = 0; i < N; i++) {
		fill(minDist, minDist + 1001, INF);
		fill(visited, visited + 1001, false);
		minDist[i] = 0;
		pq.push({minDist[i],i});
		while (!pq.empty()) {
			int curNode = pq.top().second;
			pq.pop();
			while (!pq.empty() && visited[curNode]) {
				curNode = pq.top().second;
				pq.pop();
			}

			if (visited[curNode])break;

			visited[curNode] = true;

			for (pair<int, int>& p : v[curNode]) {
				int nextNode = p.first, nextDist = p.second;
				if (minDist[nextNode] > minDist[curNode] + nextDist) {
					minDist[nextNode] = minDist[curNode] + nextDist;
					pq.push({ minDist[nextNode],nextNode });
				}
			}
		}
		//각마을에서 다익스트라가 끝나면 해당 마을에서 X로의 최소값+ X에서 해당 마을로의 최소값 더해준 후, Ans와 비교 후 갱신
		Ans = minDist[X] + minDistX[i] > Ans?minDist[X] + minDistX[i] : Ans;	
	}
	cout << Ans;
}

void Input() {
	int tmpStart, tmpEnd, tmpDist;
	cin >> N >> M >> X;
	X--;
	v.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> tmpStart >> tmpEnd >> tmpDist;
		v[--tmpStart].push_back({ --tmpEnd,tmpDist });
	}

}

int main() {
	Input();
	Solution();
}
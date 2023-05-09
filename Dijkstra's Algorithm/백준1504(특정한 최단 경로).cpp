#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int, int>>> adj;

bool visited[801];
//시작노드부터 나머지 노드
int minDistFirst[801];
//들려야할 노드 중 첫번째 노드부터 나머지 노드
int minDistSecond[801];
//들려야할 노드 중 두번째 노드부터 나머지 노드
int minDistThird[801];

int INF = 100'000'000;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

int N, E, firstLoc,SecondLoc;

void Init() {
	fill(visited, visited + 801, false);
	while(!pq.empty())
	pq.pop();
}

void Input() {
	int tmpStart, tmpEnd, Dist;
	cin >> N >> E;
	adj.resize(N);
	for (int i = 0; i < E; i++) {
		cin >> tmpStart >> tmpEnd >> Dist;
		adj[--tmpStart].push_back({ --tmpEnd,Dist });
		adj[tmpEnd].push_back({ tmpStart,Dist });
	}
	cin >> firstLoc >> SecondLoc;
	firstLoc--;
	SecondLoc--;
	fill(minDistFirst, minDistFirst + 801, INF);
	fill(minDistSecond, minDistSecond + 801, INF);
	fill(minDistThird, minDistThird + 801, INF);
	Init();
}
void Solution() {
	//1번 노드에서 각 노드로의 다익스트라 알고리즘 적용하기
	minDistFirst[0] = 0;
	pq.push({ minDistFirst[0],0 });
	while (!pq.empty()) {
		int curNode = pq.top().second;
		pq.pop();

		while (!pq.empty() && visited[curNode]) {
			curNode = pq.top().second;
			pq.pop();
		}
		if (visited[curNode]) break;

		visited[curNode] = true;

		for (pair<int, int>& p : adj[curNode]) {
			int nextNode = p.first, nextDist = p.second;
			if (minDistFirst[nextNode] > minDistFirst[curNode] + nextDist) {
				minDistFirst[nextNode] = minDistFirst[curNode] + nextDist;
				pq.push({ minDistFirst[nextNode],nextNode });
			}
		}

	}
	Init();

	//firstLoc노드에서 나머지 노드로의 다익스트라 알고리즘 적용
	minDistSecond[firstLoc] = 0;
	pq.push({minDistSecond[firstLoc],firstLoc});

	while (!pq.empty()) {
		int curNode = pq.top().second;
		pq.pop();
		while (!pq.empty() && visited[curNode]) {
			curNode = pq.top().second;
			pq.pop();
		}

		if (visited[curNode]) break;

		visited[curNode] = true;
		for (pair<int, int>& p : adj[curNode]) {
			int nextNode = p.first, nextDist = p.second;
			if (minDistSecond[nextNode] > minDistSecond[curNode] + nextDist) {
				minDistSecond[nextNode] = minDistSecond[curNode] + nextDist;
				pq.push({ minDistSecond[nextNode],nextNode });
			}
		}
	}
	Init();
	//secondLoc에서 나머지 노드로의 다익스트라 알고리즘 적용
	minDistThird[SecondLoc] = 0;
	pq.push({minDistThird[SecondLoc],SecondLoc});

	while (!pq.empty()) {
		int curNode = pq.top().second;
		pq.pop();
		while (!pq.empty() && visited[curNode]) {
			curNode = pq.top().second;
			pq.pop();
		}

		if (visited[curNode]) break;

		visited[curNode] = true;

		for (pair<int, int>& p : adj[curNode]) {
			int nextNode = p.first, nextDist = p.second;
			if (minDistThird[nextNode] > minDistThird[curNode] + nextDist) {
				minDistThird[nextNode] = minDistThird[curNode] + nextDist;
				pq.push({minDistThird[nextNode],nextNode});
			}
		}
	}
	//firstLoc을 먼저 들리는 경우
	int tmpFirstWay = minDistFirst[firstLoc] + minDistSecond[SecondLoc] + minDistThird[N - 1];
	//secondLoc을 먼저 들리는 경우
	int tmpSecondWay = minDistFirst[SecondLoc] + minDistThird[firstLoc] + minDistSecond[N - 1];

	//두가지 경우의 길이 둘다 N번째 노드에 도달할 수 없다면
	if (tmpFirstWay >= INF && tmpSecondWay >= INF) {
		cout << -1;
		return;
	}
	//도달할 수 있다면 둘 중에 짧은 경로로 출력
	cout << min(tmpFirstWay,tmpSecondWay);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solution();
}

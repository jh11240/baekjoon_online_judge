#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<functional>

//일단 문제 이해 잘못이해 각 움직임마다 해당 높이*E- 거리*d연산이 아니라 마지막에 해당 목표의 높이*E- 이동한 전체거리*D이다.
//두번째는 높이를 기준으로 다익스트라를 사용하기 위해, pq의 first값을 높이값으로 잡아서 높이가 작은값을 기준으로 이동했는데, 값이 엄청 컸다 
//높이를 높은쪽으로만 움직이는 방식은, adj벡터에 저장을 할때 높이를 낮은쪽에서 높은쪽으로 저장을 하면 끝이다.
using namespace std;
int N, M, D, E;
const long long INF = 1e18;
const int MAX = 100'000;
vector<vector<pair<long long, long long>>> adj;
int Height[100'001];
bool visited[100'001];
long long minDistFromStart[100'001];
long long minDistFromEnd[100'001];

//first는 각 정점의 높이, second는 정점의 인덱스
priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

void Input() {
	int tmpBeginNode=0, tmpEndNode=0, tmpDist=0;
	cin >> N >> M >> D >> E;
	for (int i = 0; i < N; i++) {
		cin >> Height[i];
	}
	fill(minDistFromEnd, minDistFromEnd + 100'000, INF);
	fill(minDistFromStart, minDistFromStart + 100'000, INF);
	adj.resize(MAX);
	//양방향 간선이므로 간선 정보를 받을 때, 무조건 낮은곳에서 높은곳으로 저장
	for (int i = 0; i < M; i++) {
		cin >> tmpBeginNode >> tmpEndNode >> tmpDist;
		--tmpBeginNode;
		--tmpEndNode;
		if (Height[tmpBeginNode] < Height[tmpEndNode]) adj[tmpBeginNode].push_back({tmpEndNode,tmpDist});
		if (Height[tmpBeginNode] > Height[tmpEndNode]) adj[tmpEndNode].push_back({ tmpBeginNode,tmpDist });
	}

}

void Solution() {
	//출발점정보 우선순위큐에 저장
	minDistFromStart[0] = 0;
	pq.push({ 0,0 });
	fill(visited, visited + MAX, false);
	//출발점에서 모든 점들까지 다익스트라를 이용해 minDistFromStart채우기
	while (!pq.empty()) {
		int curNode = 0;
		do {
			curNode = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curNode]);

		if (visited[curNode]) break;
		visited[curNode] = true;

		for (auto& p : adj[curNode]) {
			int nextNode = p.first, nextDist = p.second;
			if (minDistFromStart[nextNode] > minDistFromStart[curNode] + nextDist) {
				minDistFromStart[nextNode] = minDistFromStart[curNode] + nextDist;
				pq.push({ minDistFromStart[nextNode],nextNode });
			}
		}
	}
	//방문배열 초기화하고 고려대학교정보 우선순위큐에 저장
	fill(visited, visited + MAX, false);
	minDistFromEnd[N - 1] = 0;
	pq.push({0,N-1});
	//고려대학교에서 모든 점들까지 다익스트라를 이용해 minDistFromEnd채우기
	while (!pq.empty()) {
		int curNode = 0;
		do {
			curNode = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curNode]);

		if (visited[curNode]) break;
		visited[curNode] = true;

		for (auto& p : adj[curNode]) {
			int nextNode = p.first, nextDist = p.second;
			if ( minDistFromEnd[nextNode] > minDistFromEnd[curNode] + nextDist) {
				minDistFromEnd[nextNode] = minDistFromEnd[curNode] + nextDist;
				pq.push({ minDistFromEnd[nextNode],nextNode });
			}
		}
	}
	//기본적으로 나올수없는 값인 -INF값을 Ans에 저장
	long long Ans = -INF;
	//모든 노드를 순회하면서 출발점에서 해당노드 까지의 가치+ 고려대학교에서 해당 노드까지의 가치값중에 제일 큰 값을 저장 
	for (int i = 0; i < N; i++) {
		//목표노드까지의 최단거리가 INF 보단 작아야 한다!
		if (minDistFromEnd[i] < INF && minDistFromStart[i] < INF)
			Ans = max(Ans, (1LL * Height[i] * E - (minDistFromEnd[i] + minDistFromStart[i]) * D)); 
	}
	//만약 Ans가 갱신이 안되었다면조건을 만족하는 길이 없다는 뜻이므로 IMpossible 출력
	if (Ans == -INF) cout << "Impossible";
	else
	cout << Ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solution();
}
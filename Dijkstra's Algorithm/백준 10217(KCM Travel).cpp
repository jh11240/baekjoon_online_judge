#pragma region using Dijkstra's Algorithm
// #include<iostream>
// #include<vector>
// #include<queue>

// using namespace std;
// struct ticket {
// 	int v;
// 	int c;
// 	int d;
// };

// vector<vector<ticket>> ticketInfo;
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// int T, N, M, K,u,v,c,d;
// const int MAX = 10'001;
// const int INF = 1'000'000'000;
// //행은 지원 비용, 열은 노드 
// int minDist[MAX][100];
// bool visited[MAX][100];

// void Solution();

// void Input() {
// 	cin >> T;
// 	for (int i = 0; i < T; i++) {
// 		cin >> N >> M >> K;
// 		ticketInfo.clear();
// 		ticketInfo.resize(N);
// 		while (!pq.empty()) pq.pop();
// 		for (int j = 0; j < K; j++) {
// 			cin >> u >> v >> c >> d;
// 			ticketInfo[--u].push_back({ --v,c,d });
// 		}
// 		Solution();
// 	}
// }

// void Solution() {
// 	fill(&minDist[0][0], &minDist[MAX-1][100], INF);
// 	fill(&visited[0][0], &visited[MAX-1][100], 0);

// 	minDist[M][0] = 0;
// 	pq.push({ minDist[M][0],M * MAX });

// 	while (!pq.empty()) {
// 		int curM = 0, curNode = 0;
// 		do {
// 			curM = pq.top().second / MAX;
// 			curNode = pq.top().second % MAX;
// 			pq.pop();
// 		} while (!pq.empty() && visited[curM][curNode]);
// 		if (visited[curM][curNode]) break;
// 		visited[curM][curNode] = true;

// 		for (auto& elem : ticketInfo[curNode]) {
// 			int nextNode = elem.v, nextDist = elem.d, nextCost = elem.c;

// 			//무조건 M원이하로 써야하기 때문에 어디로 가든 비용은 감소된다.
// 			//if (minDist[curM][nextNode] > minDist[curM][curNode] + nextDist) {
// 			//	minDist[curM][nextNode] = minDist[curM][curNode] + nextDist;
// 			//	pq.push({ minDist[curM][nextNode],curM * MAX + nextNode });
// 			//}

// 			//다음 간선으로 갈 비용이 존재하고, 다음간선으로 갔을때 minDist가 갱신이 된다면
// 			if ((curM >= nextCost) && (minDist[curM - nextCost][nextNode] > minDist[curM][curNode] + nextDist)) {
// 				minDist[curM - nextCost][nextNode] = minDist[curM][curNode] + nextDist;
// 				pq.push({ minDist[curM - nextCost][nextNode],(curM - nextCost) * MAX + nextNode });
// 			}

// 		}
// 	}
// 	int Ans = INF;
// 	for (int i = 0; i < M; i++) {
// 		Ans = Ans > minDist[i][N - 1] ? minDist[i][N - 1] : Ans;
// 	}
// 	if (Ans == INF) cout << "Poor KCM" << '\n';
// 	else cout << Ans << '\n';
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	Input();
// }
#pragma endregion

#pragma region using Dynamic Programming
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct ticket {
	int v;
	int c;
	int d;
};

vector<vector<ticket>> ticketInfo;
int T, N, M, K,u,v,c,d;
const int MAX = 10'001;
const int INF = 1'000'000'000;
//행은 지원 비용, 열은 노드 
int minDist[MAX][100];

void Solution();

void Input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M >> K;
		ticketInfo.clear();
		ticketInfo.resize(N);
		for (int j = 0; j < K; j++) {
			cin >> u >> v >> c >> d;
			ticketInfo[--u].push_back({ --v,c,d });
		}
		Solution();
	}
}
//매 방문마다 현재 비용이 줄어들기 때문에, 다이나믹프로그래밍도 가능하다(knap-sack문제와 유사).
int KCM(int curMoney,int node) {
	int& ret = minDist[curMoney][node];
	if (ret != -1) return ret;
	if (node == N-1) return ret=0;

	ret = INF;
	for (auto& elem : ticketInfo[node]) {
		if (curMoney >= elem.c) ret = min(ret, KCM(curMoney -	 elem.c, elem.v)+elem.d);
	}	
	return ret;
}

void Solution() {
	fill(&minDist[0][0], &minDist[MAX-1][100], -1);

	int Ans = KCM(M, 0);
	if (Ans == INF) cout << "Poor KCM" << '\n';
	else cout << Ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
#pragma endregion
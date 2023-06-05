#pragma region  using M dijkstra algorithm

// #include<iostream>
// #include<vector>
// #include<queue>
// #include<algorithm>
// using namespace std;
// int n, m, f, s, t;
// //비행기를 안 타고 차로만 갔을때의 최소 비용 저장용 배열
// long long originMinCost[150'001];
// //비행기를 탔을때의 최소비용 저장용 배열
// long long flightEndMinCost[150'001];
// bool visited[150'001];
// long long INF = 8'000'000'000;
// vector<vector<pair<int,int>>> edge;
// vector<pair<int,int>> flight;
// priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
// void Input() {
// 	int u, v, c;
// 	cin >> n >> m >> f >> s >> t;
// 	edge.resize(n);
// 	for (int i = 0; i < m; i++) {
// 		cin >> u >> v >> c;
// 		edge[u].push_back({ v,c });
// 		edge[v].push_back({ u,c });
// 	}
// 	for (int i = 0; i < f; i++) {
// 		cin >> u >> v;
// 		flight.push_back({u,v});
// 	}
// }
// void FirstDijkstra() {
// 	fill(visited, visited + 150'000, false);
// 	fill(originMinCost, originMinCost + 150'000, INF);

// 	originMinCost[s] = 0;
// 	pq.push({ originMinCost[s],s });
// 	while (!pq.empty()) {
// 		int curNode = 0;
// 		do {
// 			curNode = pq.top().second;
// 			pq.pop();
// 		} while (!pq.empty() && visited[curNode]);
// 		if (visited[curNode]) break;
// 		visited[curNode] = true;

// 		for (auto& elem : edge[curNode]) {
// 			int nextNode = elem.first, nextDist = elem.second;
// 			if (originMinCost[nextNode] > originMinCost[curNode] + nextDist) {
// 				originMinCost[nextNode] = originMinCost[curNode] + nextDist;
// 				pq.push({originMinCost[nextNode],nextNode});
// 			}
// 		}
// 	}
// }

// void DetermineFlight() {
// 	//모든 flight를 한번씩 탔을때 거리중의 제일 최소비용
// 	long long Ans = originMinCost[t];
// 	//각 flight의 루트에서 다익스트라를 실행해서 최소거리 찾기
// 	for (auto& elem : flight) {
// 		fill(flightEndMinCost, flightEndMinCost + 150'000, INF);
// 		fill(visited, visited + 150'000, false);
// 		//비행 도착점까지의 비용은 비행 출발점까지의 비용과 같다.
// 		flightEndMinCost[elem.second] = originMinCost[elem.first];
// 		//비행 도착점에서 목적지까지 다익스트라 
// 		pq.push({ flightEndMinCost[elem.second],elem.second });
// 		while (!pq.empty()) {
// 			int curNode = 0;
// 			do {
// 				curNode = pq.top().second;
// 				pq.pop();
// 			} while (!pq.empty() && visited[curNode]);

// 			if (visited[curNode]) break;
// 			visited[curNode] = true;

// 			for (auto& elem : edge[curNode]) {
// 				int nextNode = elem.first, nextDist = elem.second;
// 				if (flightEndMinCost[nextNode] > flightEndMinCost[curNode] + nextDist) {
// 					flightEndMinCost[nextNode] = flightEndMinCost[curNode] + nextDist;
// 					pq.push({ flightEndMinCost[nextNode],nextNode });
// 				}
// 			}
// 		}
// 		Ans = min(Ans, flightEndMinCost[t]);
// 	}
// 	cout << Ans;	
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	Input();
// 	FirstDijkstra();
// 	DetermineFlight();
// }


#pragma endregion

#pragma region using 2D Array

	#include<iostream>
	#include<queue>
	#include<algorithm>
	using namespace std;

	const int MAX = 50000;
	const long long INF = 1e18;
	vector<pair<long long, long long>> adj[2][MAX];
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;
	int n, m, f, s, e;
	long long dist[2][MAX];
	bool visited[2][MAX]={false,};

	void Input() {
		cin >> n >> m >> f >> s >> e;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v>>w;
			adj[0][u].push_back({ v,w });
			adj[0][v].push_back({ u,w });
			adj[1][u].push_back({ MAX + v,w });
			adj[1][v].push_back({ MAX + u ,w});
		}
		for (int i = 0; i < f; i++) {
			int u, v;
			cin >> u >> v;
			//비행기를 탄다면 이제 도착지점을 MAX더해줘서 1로 올리기
			adj[0][u].push_back({ MAX + v, 0});
		}
	}
	void Solution() {
		fill(dist[0], dist[0] + n, INF);
		fill(dist[1], dist[1] + n, INF);
		dist[0][s] = 0;
		//first는 거리, second는 노드
		pq.push({ 0,s });

		while (!pq.empty()) {
			//k값은 dist의 행에 해당하고, curNode는 dist의 열에 해당한다.
			int curNode=0, k=0;

			do {
				curNode = pq.top().second % MAX;
				k = pq.top().second / MAX;
				pq.pop();
			} while (!pq.empty() && visited[k][curNode]);

			if (visited[k][curNode]) break;
			visited[k][curNode] = true;

			//adj[k][curNode]과 연결된 간선들에 대해서 
			for (auto& elem : adj[k][curNode]) {
				//nextK는 연결된 지점의 행값, nextNode는 연결된 지점의 열값, nextDist는 curNode와 nextNode사이 거리
				long long nextNode = elem.first % MAX, nextK = elem.first / MAX, nextDist = elem.second;

				if ( dist[nextK][nextNode] > dist[k][curNode] + nextDist) {
					dist[nextK][nextNode] = dist[k][curNode] + nextDist;
					//노드값을 저장할 때,max값을 곱해준후 저장한다.
					pq.push({dist[nextK][nextNode],nextK * MAX + nextNode});
				}
			}
		}
		//그냥 차타고갔을때( dist[0][e]), 비행기 탔을때 최소비용(dist[1][e])둘을 비교해서 최소값 출력
		cout << min(dist[0][e], dist[1][e]);
	}
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		Input();
		Solution();
	}
	
#pragma endregion
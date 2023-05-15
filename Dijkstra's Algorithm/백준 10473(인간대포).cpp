	#include<iostream>
	#include<math.h>
	#include<vector>
	#include<queue>
	using namespace std;

	double startX, startY, targetX,targetY;
	int cannonAmount;
	const double walkSpeed = 5.0;
	//index번째 대포의 위치 pair형태로
	vector<pair<double, double>> adj;
	//pair의 first는 second에 대항하는 좌표로 걸리는 시간, second는 adj의 인덱스(0번은 원래 위치, 1~N은 대포순서 , N+1이 목적지.)
	priority_queue<pair<double, double>, vector<pair<double, double>>, greater<pair<double, double>>> pq;

	//0번은 원래 위치, 1~N은 대포순서 , N+1이 목적지.
	double minTime[102];
	//다익스트라에서 사용될 방문여부 저장용 bool형 배열
	bool visited[102];

	double GetDistance(pair<double,double>a, pair<double,double> b) {
		return sqrt((a.first - b.first)*(a.first - b.first) +( a.second - b.second)* (a.second - b.second));
	}

	double GetRunningTime(pair<double, double> startLoc, pair<double, double> targetLoc) {
		double dist = GetDistance(startLoc, targetLoc);
		return dist /walkSpeed;
	}

	double GetCannonLaunchTime(pair<double, double> startLoc, pair<double, double> targetLoc) {
		double retTime = 2;
		double dist = GetDistance(startLoc, targetLoc);
		retTime += fabs(dist - 50) / walkSpeed;
		//걸어가는 시간과 대포타는 시간 비교
		retTime = retTime> dist / walkSpeed? dist/walkSpeed : retTime;
		return retTime;
	}

	void Input() {
		double tmpCannonX = 0, tmpCannonY = 0;
		cin >> startX >> startY;
		cin >> targetX >> targetY;
		cin >> cannonAmount;
		//1번부터 대포사용하기 위해 0번에 시작좌표 푸시
		adj.push_back({ startX,startY });
		//1번부터 cannonAmount번 index까지 대포의 좌표 저장
		for (int i = 0; i < cannonAmount; i++) {
			cin >> tmpCannonX >> tmpCannonY;
			adj.push_back({ tmpCannonX, tmpCannonY });
		}
		//마지막에 목적지 좌표 저장
		adj.push_back({ targetX, targetY });
		fill(visited, visited + 100, false);
		minTime[0]=0;
		for (int i = 1; i <= cannonAmount+1; i++) {
			minTime[i] = GetRunningTime(adj[0], adj[i]);
			pq.push({ minTime[i],i });
		}
	}

	void Solution() {

		//시작점에서 제일 가까운 대포부터 다익스트라 시작
		while (!pq.empty()) {
			int curNode = 0;
			do {
				curNode = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visited[curNode]);

			visited[curNode] = true;

			//curnode위치에서 나머지 모든 대포의 위치로 진행 
			for (int i = 1; i <= cannonAmount; i++) {
				//자기 자신이라면 continue
				if (i == curNode) continue;
				//갱신해줘야 한다면 갱신
				else if (minTime[i] > minTime[curNode] + GetCannonLaunchTime(adj[curNode], adj[i])) {
					minTime[i] = minTime[curNode] + GetCannonLaunchTime(adj[curNode], adj[i]);
					pq.push({ minTime[i], i });
				}
			}
			//도착지점에서는 다른곳으로 갈 이유가 없으므로 우선순위큐에 푸시를 안해줌
			if (minTime[cannonAmount + 1] > minTime[curNode] + GetCannonLaunchTime(adj[curNode], { targetX,targetY })) {
				minTime[cannonAmount + 1] = minTime[curNode] + GetCannonLaunchTime(adj[curNode], { targetX,targetY });
			}
		}
		cout.precision(6);
		cout<<fixed << minTime[cannonAmount + 1];
	}

	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		Input();
		Solution();

	}
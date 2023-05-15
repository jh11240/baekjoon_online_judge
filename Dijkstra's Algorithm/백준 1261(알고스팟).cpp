#include<iostream>
#include<vector>
#include<queue>

using namespace std;	
int Maze[101][101];
int minWallsToBreak[101][101];
bool visited[101][101];

//vector<vector<pair<int, int>>> v;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, M, INF = 10'000;
int dirX[4] = {-1,1,0,0};
int dirY[4] = {0,0,-1,1};

void Solution() {
	int curNodeX=0, curNodeY = 0;
	while (!pq.empty()) {
		curNodeX = pq.top().second / M;
		curNodeY = pq.top().second % M;
		pq.pop();
		while (visited[curNodeX][curNodeY]) {
			curNodeX = pq.top().second / M;
			curNodeY = pq.top().second % M;
			pq.pop();
		}

		visited[curNodeX][curNodeY] = true;

		//상하좌우로 움직여야하므로 상하좌우를 반복문으로 처리
		for (int i = 0; i < 4; i++) {
			int nextNodeX = curNodeX + dirX[i];
			int nextNodeY = curNodeY + dirY[i];

			//범위를 벗어나면 continue처리
			if (nextNodeX < 0 || nextNodeY < 0 || nextNodeX >= N || nextNodeY >= M) continue;
			//이미 방문했다면 continue처리
			if (visited[nextNodeX][nextNodeY])continue;

			//curNodeX,curNodeY를 거쳐서 도달했을때의 부숴야 할 벽갯수가 더 작다면 갱신후 우선순위큐에 넣어줌.
			if (minWallsToBreak[nextNodeX][nextNodeY] > minWallsToBreak[curNodeX][curNodeY] + Maze[nextNodeX][nextNodeY]) {
				minWallsToBreak[nextNodeX][nextNodeY] = minWallsToBreak[curNodeX][curNodeY] + Maze[nextNodeX][nextNodeY];
				pq.push({ minWallsToBreak[nextNodeX][nextNodeY],nextNodeX * M + nextNodeY });
			}
		}
	}
	 cout << minWallsToBreak[N - 1][M - 1];
}

void Input() {
	char tmpInput;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmpInput;
			Maze[i][j] = tmpInput - '0';
		}
	}
	fill(&visited[0][0], &visited[100][100], false);
	fill(&minWallsToBreak[0][0], &minWallsToBreak[100][100], INF);
	minWallsToBreak[0][0] = Maze[0][0];
	pq.push({minWallsToBreak[0][0],0});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solution();
}
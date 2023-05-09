#include<iostream>
#include<queue>

using namespace std;
int N,INF=10'000;
//처음 입력값 배열
int Cave[126][126];
//0,0에서 최저로 잃는 코인
int Loss[126][126];
//방문 여부 처리
bool visited[126][126];

//Loss, 좌표는 x*N+y로 저장
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dirX[4] = {-1,1,0,0};
int dirY[4] = {0,0,-1,1};

//Loss배열에 각 칸까지의 최저 손실 저장하는 함수
void SetLoss() {

	while (!pq.empty()) {
		//priority Queue. second값에는 각 칸의 정보를 N*행+열로 저장해서 썼다.
		int curNodeX = pq.top().second / N;
		int curNodeY = pq.top().second % N;
		pq.pop();
		//top값이 방문한 칸이라면 방문안한 칸 나올때까지 반복
		while (!pq.empty() && visited[curNodeX][curNodeY]) {
			int curNodeX = pq.top().second / N;
			int curNodeY = pq.top().second % N;
			pq.pop();
		}

		//방문안한 칸이므로 방문 처리
		visited[curNodeX][curNodeY] = true;

		//상하좌우 체크용
		for (int i = 0; i < 4; i++) {
			//좌표 x,y값 상하좌우에 맞게 변형
			int nextX = curNodeX + dirX[i];
			int nextY = curNodeY + dirY[i];

			//0~N-1을 벗어난다면 continue
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
			//이미 방문한 칸이라면 continue
			if (visited[nextX][nextY]) continue;

			//[nextX,nextY]칸의 최저 손실보다 [curNodeX, curNodeY]칸을 거쳐 [nextX,nextY]에 도달하는 손실이 더 작다면 갱신
			if (Loss[nextX][nextY] > Loss[curNodeX][curNodeY] + Cave[nextX][nextY]) {
				Loss[nextX][nextY] = Loss[curNodeX][curNodeY] + Cave[nextX][nextY];
				pq.push({ Loss[nextX][nextY], nextX * N + nextY });
			}
		}
	}
}

void Input() {
	int testCase = 1;
	while (1) {
		//매 테케마다 초기화
		fill(&Loss[0][0], &Loss[125][125], INF);
		fill(&Cave[0][0], &Cave[125][125], 0);
		fill(&visited[0][0], &visited[125][125], false);
		cin >> N;
		if (N == 0) return;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Cave[i][j];
			}
		}
        //각 칸의 손실값을 그래프의 가중치로 생각했으므로 \
        0,0 칸의 손실값을 미리 저장하고 진행해야함
		Loss[0][0] = Cave[0][0];
		pq.push({ Cave[0][0],0 });
		SetLoss();
		cout << "Problem "<<testCase++<<": " << Loss[N - 1][N - 1]<<'\n';
	}
}

int main() {
	Input();
}
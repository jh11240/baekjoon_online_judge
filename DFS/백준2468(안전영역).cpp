#include<iostream>
#include<algorithm>

using namespace std;
int N,maxHeight;
int hills[101][101];
int Flooded[101][101];
int visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> hills[i][j];
			//입력값중 최대 높이 미리 저장. line 55에 사용하기 위함
			maxHeight = maxHeight > hills[i][j] ? maxHeight : hills[i][j];
		}
	}
}

/// <summary>
/// Flooded 배열에서 홍수로 잠긴 부분 0, 안 잠긴 부분 1로 채워주기
/// </summary>
/// <param name="홍수로 잠긴 물의 높이"></param>
void fillFlooded(int floodHeight) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//비 온 높이보다 언덕 높이가 더 크다면 1로 채우고 나머진 0
			if (hills[i][j] > floodHeight) Flooded[i][j] = 1;
			else Flooded[i][j] = 0;
		}
	}
}

//flooded의 x,y좌표에서 dfs시행
void dfs(int x,int y) {
	if (visited[x][y]) return;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextA = x + dx[i];
		int nextB = y + dy[i];
		//범위를 벗어나지 않으며, 물에 안잠긴 곳이면
		if (nextA >= 0 && nextB >= 0 && nextA < N && nextB < N && Flooded[nextA][nextB]) {
			if (!visited[nextA][nextB]) {
				dfs(nextA,nextB);
			}
		}
	}
}

void solution() {
	//최대 컴퍼넌트 수
	int maxComponent = 0;
	//홍수 난 물의 높이 0부터 maxHeight까지 .
	for (int i = 0; i <= maxHeight; i++) {
		int component = 0;
		//flooded배열 채운 후
		fillFlooded(i);
		//방문 배열 false로 지정 후
		fill(&visited[0][0], &visited[100][100],false);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//방문 안했고, 물에 안잠긴 곳이라면 dfs 시작
				if (!visited[i][j] && Flooded[i][j]) {
					component++;
					//dfs시행
					dfs(i,j);
				}
			}
		}
		//최대 컴퍼넌트 수 갱신
		maxComponent = maxComponent > component ? maxComponent : component;
	}
	cout << maxComponent;
}

int main() {
	input();
	solution();
}
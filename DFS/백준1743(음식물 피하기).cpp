#include<iostream>
#include<algorithm>

using namespace std;
int height = 0, width = 0, garbage = 0;
int field[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void input() {
	int r=0, c = 0;
	cin >> height >> width >> garbage;
	for (int i = 0; i < garbage; i++) {
		cin >> r >> c;
		field[r][c] = 1;
	}
	fill(&visit[1][1],&visit[100][100],false);
}
/// <summary>
/// (x,y)좌표와 이어진 노드들을 dfs로 탐색한 후, 노드갯수를 더한 후 반환.
/// </summary>
/// <param name="좌표 x"></param>
/// <param name="좌표 y"></param>
/// <returns>노드갯수를 리턴</returns>
int dfs(int x, int y) {
	//각 컴퍼넌트의 노드갯수
	int Nodes = 1;
	//방문 했다면 return
	if (visit[x][y] == true) return 0;
	//방문 했으므로 true로 표기
	visit[x][y] = true;
	int nextA = 0, nextB = 0;
	for (int i = 0; i < 4; i++) {
		nextA = x + dx[i];
		nextB = y + dy[i];
		//x,y의 상하좌우 값이 각각 범위 안에 있고, 해당 값에 쓰레기가 존재할 경우  field안에 x,y로 넣어놨누;
		if (nextA >= 1 && nextB >= 1 && nextA <= height && nextB <= width && field[nextA][nextB])
		{
			//방문한 곳이면 패스 
			if (!visit[nextA][nextB]) {
				//해당 dfs에서의 노드 리턴값을 노드에 더해준 후
				Nodes += dfs(nextA, nextB);
			}
		}
	}
	//노드 갯수 리턴
	return Nodes;
}

void solution() {
	//최대컴퍼넌트의 노드갯수
	int maxComponent = 0;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			//(i,j)좌표에 방문 안 했고, 쓰레기가 있다면
			if (!visit[i][j] && field[i][j] == 1) {
				//해당 좌표가 포함한 컴퍼넌트의 노드갯수를 maxComponent와 비교해서 더 큰값 저장
				maxComponent = max(dfs(i, j), maxComponent);
			}
		}
	}
	cout << maxComponent;
}
int main() {
	input();

	solution();
}
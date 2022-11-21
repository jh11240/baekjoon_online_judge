#include<iostream>
#include<queue>

using namespace std;
int maze[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void BFS(int y, int x);


void input() {
	int targetY=0, targetX = 0;
	string row = "";
	//타겟 좌표 입력
	cin >> targetY >> targetX;
	//행 갯수만큼 
	for (int i = 0; i < targetY; i++) {
		//string형으로 받고
		cin >> row;
		//string형의 각 char형 변수를 int값으로 변환하여 maze배열에 넣어줌
		for (int j = 0; j < targetX; j++) {
			maze[i][j] = row[j] - '0';
		}
	}
	//visited배열을 0으로 초기화
	fill(&visited[0][0], &visited[100][100], 0);
	//BFS함수 실행
	BFS(targetY, targetX);
}
void BFS(int y, int x) {
	//큐 선언
	queue<pair<int,int>> q;
	//기본값인 0,0 넣어줌.
	q.push({ 0, 0 });
	//0,0에서 방문했다고 표시
	visited[0][0] = 1;
	//뻗어나갈 레벨 1부터 시작 (바로 주위 탐색후 값 찾으면 ans출력하므로 )
	int Ans = 1;
	while (!q.empty()) {
		//큐 사이즈 변동되므로 임시변수에 저장 후 종결조건으로 사용
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			//pair객체를 이용해 front값 저장
			pair<int, int> tmp = q.front();
			//queue를 pop해준다.
			q.pop();
			//상하좌우 검색해야하므로 미리선언한 dx,dy배열을 이용한다.
			for (int j = 0; j < 4; j++) {
				int nextY = tmp.first + dy[j];
				int nextX = tmp.second + dx[j];
				//탐색후 타겟값이 발견되면 바로 Ans+1값 출력 (+1하는 이유는 조건에 시작 노드도 포함하라고해서)
				if (nextY == y-1 && nextX == x-1) {
					cout << Ans+1;
					return;
				}
				//다음으로 탐색할 좌표가 범위를 벗어나지않으며 1이라면
				if (nextX >= 0 && nextY >= 0 && nextY < y && nextX < x && maze[nextY][nextX]==1) {
					//방문하지 않은 곳이면 
					if (!visited[nextY][nextX]) {
						//방무했따고 표기하고 
						visited[nextY][nextX] = true;
						//큐에 넣어준다.
						q.push({ nextY,nextX });
					}
				}
			}
		}
		//큐사이즈만큼 반복문이 돌았다면 한 레벨이 끝났다는 뜻이므로 레벨++
		Ans++;

	}
}

int main() {
	input();
}
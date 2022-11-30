#include<iostream>
#include<queue>

using namespace std;
int height=0, width = 0;
//전역변수라 0초기화
int tomatoFarm[1001][1001];
//false로 초기화
bool visited[1001][1001];
queue<pair<int, int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void solution();

void input() {
	//토마토가 모두 익었는지 조사하는 변수
	bool isAllRotten = true;
	cin >> width >> height;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> tomatoFarm[i][j];
			//농장에 익은 토마토라면
			if (tomatoFarm[i][j] == 1) {
				//푸시
				q.push({ i,j });
				visited[i][j] = true;
			}
			//토마토가 하나라도 안 익은 게 있다면
			else if (tomatoFarm[i][j] == 0) {
				isAllRotten = false;

			}
		}
	}
	//토마토가 시작부터 다 익었다면
	if (isAllRotten) {
		cout << 0;
		return;
	}
	else {
		//익은 토마토가 0개라면 불가능하므로
		if (q.empty()) {
			cout << -1;
			return;
		}
		//bfs진행
		solution();
	}
	
}
void solution() {
	//시작은 0일차지만 이미 푸시되어있는 상태로 진행 되므로 level++가 실행된다 마지막에 1빼야됨
	int level=0;
	while (!q.empty()) {
		//큐 사이즈는 가변적이므로 변수 할당
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			pair<int, int> p = q.front();
			q.pop();
			//상하좌우 칸 조사하기 용이하게 반복문 사용
			for (int j = 0; j < 4; j++) {
				int nextH = p.first + dx[j];
				int nextW = p.second + dy[j];
				//범위 넘어가면 바로 continue
				if (nextH < 0 || nextW < 0 || nextH >= height || nextW >= width) continue;
				//이미 방문한 곳이면 continue;
				if (visited[nextH][nextW]) continue;
				//방문했다고 처리
				visited[nextH][nextW] = true;
				//다음칸이 비어있는칸이면 continue
				if (tomatoFarm[nextH][nextW] == -1) continue;
				//비어있지않다면 해당 칸 큐에 푸시해주기
				else {
					q.push({ nextH,nextW });
				}
			}
		}
		//한 큐의 사이즈만큼 끝날때마다 레벨이 증가
		level++;
	}
	//방문을 못한 곳이 있고,"해당 지역이 익지 않은 토마토라면" -1출력
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (visited[i][j] == false && tomatoFarm[i][j]==0) {
				cout << -1;
				return;
			}
		}
	}
	//반복문끝났다면 더이상 큐에 아무것도 없는 상황이므로 진행 끝
	cout << level-1;
}

int main() {
	input();

}
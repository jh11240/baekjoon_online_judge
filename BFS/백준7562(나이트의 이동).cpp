#include<iostream>
#include<queue>

using namespace std;
int testCases = 0, chessFieldLen = 0;
int dx[8] = {1,-1,2,2,-2,-2,1,-1};
int dy[8] = {2,2,1,-1,1,-1,-2,-2};
int visited[301][301];

void BFS(pair<int, int>sPoint, pair<int, int>ePoint) {
	//시작좌표와 끝좌표 같다면 0출력
	if (sPoint == ePoint) {
		cout << 0 << '\n';
		return;
	}

	//bfs에 쓰일 큐 선언
	queue<pair<int,int>> q;
	//시작 포인트는 방문했으므로 방문 체크
	visited[sPoint.first][sPoint.second] = 1;
	//큐에 시작 포인트 집어넣기
	q.push(sPoint);
	//시작 레벨은 1로 설정
	int level = 1;
	while (!q.empty()) {
		//큐의 사이즈는 가변적이므로 미리 변수에 할당
		int qSize = q.size();
		//큐사이즈만큼 반복하면 레벨 하나 끝난것
		for (int i = 0; i < qSize; i++) {
			//큐의 front값 저장
			pair<int, int> cur = q.front();
			//큐 pop
			q.pop();
			//현재좌표가 0,0일때 (2,-1)(2,1)(-2,-1)(-2,1)(1,2)(1,-2)(-1,-2)(-1,2)총 8군데 갈 수 있으므로 8곳 다 체크
			for (int i = 0; i < 8; i++) {
				int NextX = cur.first + dx[i];
				int NextY = cur.second + dy[i];
				//종결 좌표값과 같아지면 해당 레벨 출력
				if (NextX == ePoint.first && NextY == ePoint.second) {
					cout << level << '\n';
					return;
				}
				// 특정 위치로 가야하는 조건이 없으므로 범위 내에 있기만 하면됨
				if (NextX >= 0 && NextY >= 0 && NextX < chessFieldLen && NextY < chessFieldLen) {
					//방문한적 없다면 
					if (!visited[NextX][NextY]) {
						//방문 체크한 후
						visited[NextX][NextY] = 1;
						//큐에 집어넣음
						q.push({ NextX,NextY });
					}
				}

			}
		}
		level++;
	}
}


void input() {
	pair<int, int> startPoint, endPoint;
	int tmp1=0, tmp2=0;
	//테스트케이스 수 받아옴
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		// 체스판 길이
		cin >> chessFieldLen;
		//시작좌표
		cin >> tmp1 >> tmp2;
		startPoint = { tmp1,tmp2 };
		//타겟좌표
		cin >> tmp1 >> tmp2;
		endPoint = { tmp1,tmp2 };
		//방문 배열 false로 채우기
		fill(&visited[0][0], &visited[chessFieldLen][chessFieldLen], false);
		BFS(startPoint, endPoint);
	}
}

int main() {
	input();
}
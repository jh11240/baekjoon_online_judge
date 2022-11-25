#include<iostream>
#include<queue>

using namespace std;

//#,@,.,*입력받는 배열
char building[1001][1001];
//상근이가 갈수있는 좌표 담는 큐(bfs에서)
queue<pair<int,int>> person;
//상근이가 움직인 좌표의 방문여부
int visitedP[1001][1001];
//불이 옮겨붙는 좌표 담는 큐(bfs에서 사용)
queue<pair<int,int>> fire;
//불이 옮겨붙는 좌표 방문 여부
int visitedF[1001][1001];

//상하좌우 좌표 반복문처리하기위한 배열
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

//열, 행
int width = 0, height = 0;

void solution();

/// <summary>
/// 방문 배열, 큐 초기화
/// </summary>
void init() {
	fill(&visitedF[0][0], &visitedF[height][width], 0);
	fill(&visitedP[0][0], &visitedP[height][width], 0);
	while (!fire.empty()) {
		fire.pop();
	}
	while (!person.empty()) {
		person.pop();
	}
}

/// <summary>
/// 입력값 받는 함수
/// </summary>
void input() {
	
	int tc = 0;
	cin >> tc;
	for (int index = 0; index < tc; index++) {
		cin >> width >> height;
		init();
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin>>building[i][j];
				//시작지점이면 상근 큐에 푸시
				if (building[i][j] == '@') {
					person.push({ i,j });
					//방문 했다고 체크
					visitedP[i][j] = 1;
				}
				//산불지점이면 불 큐에 푸시
				else if (building[i][j] == '*') {
					fire.push({i,j});
					//방문 했다고 체크
					visitedF[i][j] = 1;
				}
			}
		}
		solution();
	}
}
//1. 불 한번 bfs, 사람 한번 bfs 하는 방법, 
//2. 각 불 bfs해서 탈출로까지 제일 최단거리, 사람 bfs해서 최단거리 서로 비교 
//-> 여기서 신경쓸부분은 인간이 제일 가까운 탈출로 지점을 저장해서 불도 다 그지점으로 돌려야함 왜냐면 단순히 불이 반대쪽 탈출로로 1칸 만에 갈수있다면 오답나옴

void solution() {
	//움직인 거리 
	int level = 1;
	while (!person.empty()) {
		//각 레벨에서 큐 사이즈만큼만 반복하기 위한 변수
		int qSize = person.size();
		int fSize = fire.size();
		//불 먼저 레벨 1만큼 진행
		for (int k = 0; k < fSize; k++) {
			pair<int, int> tmp = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int nextA = tmp.first + dx[i];
				int nextB = tmp.second + dy[i];
				//다음 좌표가 범위 내에 있으면서, '.'이어야 이동 가능('*'이나 '@'는 신경안써도됨)
				if (nextA >= 0 && nextB >= 0 && nextA < height && nextB < width && (building[nextA][nextB] == '.')) {
					//방문안했다면
					if (!visitedF[nextA][nextB]) {
						//방문 체크
						visitedF[nextA][nextB] = 1;
						//큐에 해당 좌표 푸시
						fire.push({ nextA,nextB });
					}
				}
			}
		}
		//상근이 진행
		for (int i = 0; i < qSize; i++) {
			pair<int, int> tmp = person.front();
			person.pop();
			for (int i = 0; i < 4; i++) {
				int nextA = tmp.first + dx[i];
				int nextB = tmp.second + dy[i];
				//탈출할수 있다면
				if (nextA<0 || nextA==height|| nextB<0 ||nextB==width) {
					cout << level<<'\n';
					return;
				}
				//범위내에 있으면서, 다음 칸이 빈 공간이면서, 불길이 안닿은 곳이면
				if (nextA >= 0 && nextB >= 0 && nextA < height && nextB < width && building[nextA][nextB] == '.' && visitedF[nextA][nextB] != 1) {
					if (!visitedP[nextA][nextB]) {
						visitedP[nextA][nextB] = 1;
						person.push({ nextA,nextB });
					}
				}
			}
		}
		level++;
	}
	cout << "IMPOSSIBLE" << '\n';
}

int main() {
	input();
}
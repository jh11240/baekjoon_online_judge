#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int height = 0, width = 0;
int map[1001][1001];
bool visited[2][1001][1001];

//큐에 넣을 칸 정보들
struct space {
	//행
	int height;
	//열
	int width;
	//벽을 한번 부쉈는지(1) 안 부쉈는지(0)
	bool crushed;
};

void input() {
	char tmp = 0;
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> tmp;
			//char형으로 받아온 후 하나하나 int값에 넣어줌 
			map[i][j] = tmp - '0';
		}
	}
}


void solution() {
	//같은 지점일때는 그냥 1출력
	if (height == 1 && width == 1) {
		cout << 1;
		return;
	}
	//칸 정보 구조체를 담은 bfs용 큐 선언
	queue<space> q;
	//시작 값인 0,0,false를 넣어준다
	q.push({ 0,0,0 });
	//시작값 방문 처리
	visited[0][0][0] = true;
	//bfs의 각 레벨
	int level = 1;
	//큐가 비어있지 않을 때
	while (!q.empty()) {
		//큐사이즈는 가변적이므로 변수에 할당
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			//큐의 front값
			int r = q.front().height;
			int c = q.front().width;
			bool crush=q.front().crushed;
			//큐 pop()
			q.pop();
			//큐의 front값의 상하좌우칸 반복문을 이용해 표현
			for (int j = 0; j < 4; j++) {
				int nextR = r + dx[j];
				int nextC = c + dy[j];
				//만약 범위 바깥이면 바로 continue
				if (nextR < 0 || nextC < 0 || nextR >= height || nextC >= width) continue;
				//이미 방문한 지역이면 continue
				if (visited[crush][nextR][nextC]) continue;
				//목표지점이면 시작지점도 포함이므로 level+1값 출력
				if (nextR == height - 1 && nextC == width - 1) {
					cout << level + 1;
					return;
				}
				//(nextR,nextC)칸에 벽이 있다면
				if (map[nextR][nextC]) {
					//벽을 이미 부신상태면 이제 벽통과 못하므로 continue
					if (crush) continue;
					//벽을 안 부셨다면 1층 visited배열에 방문 체크
					visited[1][nextR][nextC] = true;
					//이 칸은 1층 배열에서 방문체크하며 bfs하면서 놀것
					q.push({ nextR,nextC,1 });
				}
				//(nextR,nextC)칸에 벽이 없다면
				else {
					//벽을 한번 부셨다면 1층 visited배열, 안부셨다면 0층 visited배열에서 체크
					visited[crush][nextR][nextC] = true;
					//조건에 맞는 crush값으로 큐에 들어감
					q.push({nextR, nextC, crush});
				}
			}
		}
		level++;
	}
	//반복문 빠져나왔다면 
	cout << -1;

}

int main() {
	input();
	solution();
}
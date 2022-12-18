#include<iostream>
#include<vector>

using namespace std;
char Road[6][6];
int height=0,width=0,targetDistance = 0,ans=0;
bool visited[6][6];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void Input() {
	cin >> height >> width>> targetDistance;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> Road[i][j];
		}
	}

}

void Backtracking(int h, int w,int length) {
	//시작칸 방문처리해줘야함.
	visited[h][w] = true;
	//다음칸만 T인지 탐색하면 안 되고 시작칸이 T일수도 있다. return
	if (Road[h][w]== 'T') {
		return;
	}
	//만약 목적지 도착시
	if (h == 0 && w == width-1) {
		//길이가 K랑 같다면 ans증가시키기
		if (length == targetDistance) ans++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		//다음 가로값
		int nextH = h + dx[i];
		//다음 세로값
		int nextW = w + dy[i];

		//범위 바깥이면 continue
		if (nextH<0||nextW<0||nextH >= height || nextW >= width) continue;
		//다음칸 T라면 continue
		if (Road[nextH][nextW] == 'T') continue;
		//방문이미 했다면 continue
		if (visited[nextH][nextW]) continue;
		//조건 다 지나왔다면 방문처리해준 후
		visited[nextH][nextW] = true;
		//다음 백트래킹 실행
		Backtracking(nextH, nextW, length + 1);
		//백트래킹 하고 전단계로 돌아오면 방문처리 초기화해줌
		visited[nextH][nextW] = false;
	}

}

void Solution() {
	Backtracking(height - 1, 0, 1);
	cout << ans;
}

int main() {
	Input();
	Solution();

}
#include<iostream>

using namespace std;
//N, 동쪽 확률, 서쪽 확률, 북쪽 확률, 남쪽 확률
int N = 0, eastPer = 0, westPer = 0, northPer = 0, southPer = 0;
//답
double ans = 0;
//중앙 14,14에서 출발해서 동서남북 어느쪽으로든 14칸 갈 수 있도록 2차원 배열 생성
int field[29][29];
bool visited[29][29];
//좌표 반복문 처리용 0=north, 1=south, 2=west, 3=east
int dh[4] = { -1,1,0,0 };
int dw[4] = { 0,0,-1,1 };
//percentage저장용 배열
double directionPer[4];

void Input() {
	cin >> N >> eastPer >> westPer >> southPer >> northPer;
	directionPer[0] = (double)northPer/100;
	directionPer[1] = (double)southPer/100;
	directionPer[2] = (double)westPer/100;
	directionPer[3] = (double)eastPer/100;
}

/// @brief 각 좌표에 대해서 확률을 계산해서 N만큼 이동했을 때 해당 확률 ans에 더하는 함수
/// @param height 행좌표
/// @param width 열좌표
/// @param length 이동한 횟수
/// @param percentage 해당 좌표에 올 확률
void Backtracking(int height,int width,int length,double percentage) {
	//조건에 도달했을 때,
	if (length == N+1) {
		ans += percentage;
		return;
	}
	//시작점 방문처리
	visited[height][width] = true;

	for (int i = 0; i < 4; i++) {
		//다음 조사할 행값
		int nextH = height + dh[i];
		//다음 조사할 열값
		int nextW = width + dw[i];
		//다음 칸으로 갈 확률이 0이면 continue
		if (!directionPer[i]) continue;
		//방문했다면 continue;
		if (visited[nextH][nextW]) continue;
		//예외문 다 뚫었으면 방문 처리해주고
		visited[nextH][nextW] = true;
		//percentage곱해줌
		percentage *= directionPer[i];
		//그다음 단계 백트래킹 실행
		Backtracking(nextH, nextW, length + 1, percentage);
		//모든곳을 다 방문해봐야하니 return해서 이번 정점 방문여부와 방문한 확률 초기화
		percentage /= directionPer[i];
		visited[nextH][nextW] = false;
	}
}

void Solution() {
	Backtracking(14, 14, 1,1.0f);
	//소숫점뒤 유효숫자 9까지 오차 허용이므로
	cout.precision(9);
	cout << ans;
}

int main() {
	Input();
	Solution();

}
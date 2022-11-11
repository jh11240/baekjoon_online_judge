#include<iostream>

using namespace std;

int Tot=0, width=0,height=0,X=0,Y=0, K=0;
//전체 필드
int field[51][51];
//방문한 필드
bool visited[51][51];
//(x-1,y),(x+1,y),(x,y-1),(x,y+1)로 나누기위함
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//(a,b) 점에 대해 dfs수행
void dfs(int a, int b) {
	//a,b방문했다면 return
	if (visited[a][b]) return;
	//방문 안했다면 방문했다고 체크해주기
	visited[a][b] = true;
	for (int i = 0; i < 4; i++) {
		//x-1,x+1,x
		int nextA = a + dx[i];
		//y,y-1,y+1
		int nextB = b + dy[i];
		//나눴을때 행과 열이 범위 안에 있으면서 배추가 있는 칸일때 dfs 다시 시행 
		if (nextA >= 0 && nextB >= 0 && nextA < height && nextB < width && field[nextA][nextB]) {
			dfs(nextA, nextB);
		}
	}
	return;
}


void solution() {
	int Ans = 0;
	//방문 배열 false로 초기화
	fill(&visited[0][0], &visited[50][50],false);
	
	//행
	for (int i = 0; i < height; i++) {
		//열
		for (int j = 0; j < width; j++) {
			//배추가 있고, 방문하지 않았다면
			if (field[i][j] == 1 && !visited[i][j]) {
				//컴퍼넌트 갯수 추가하고 dfs시작
				Ans++;
				//dfs함수 호출
				dfs(i, j);
			}
		}
	}
	cout << Ans<<'\n';

}

void input() {
	cin >> Tot;
	for (int i = 0; i < Tot; i++) {
		cin >> width>> height>>K;
		//field 0으로 초기화
		fill(&field[0][0], &field[50][50], 0);
		for (int i = 0; i < K; i++) {
				cin >> X >> Y;
				field[Y][X] = 1;
		}
		solution();
	}
}


int main() {
	input();
}
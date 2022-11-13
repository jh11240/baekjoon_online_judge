#include<iostream>

using namespace std;
int N=0;
char RGB[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> RGB[i][j];
		}
	}
}

//적녹색약일때
void dfsRB(int x, int y,char RB) {
	//방문했다면 return
	if (visited[x][y]) return;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextA = x + dx[i];
		int nextB = y + dy[i];
		//타겟 색이 G나 R이면 동일하게 인식
		if (RB == 'G' || RB == 'R') {
			//범위 바깥이 아니면서 nextA,nextB좌표의 색이 R이나 G라면
			if (nextA >= 0 && nextB >= 0 && nextA < N && nextB < N && (RGB[nextA][nextB] == 'R' ||RGB[nextA][nextB]=='G') ) {
				//방문하지 않았따면
				if (!visited[nextA][nextB])
					//DFSRB를 실행
				dfsRB(nextA, nextB, RB);
			}
		}
		//파란색이라면
		else 
			//범위 바깥이 아니면서 nextA,nextB좌표의색이 파랑이라면
			if (nextA >= 0 && nextB >= 0 && nextA < N && nextB < N && RGB[nextA][nextB] == 'B' ) {
				//방문 안했다면
				if(!visited[nextA][nextB])
					//dfs함수 실행
				dfsRB(nextA, nextB, RB);
			}

	}
}
//색약 아닐때
void dfsRGB(int x, int y,char R) {
	//방문했다면 return
	if (visited[x][y]) return;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextA = x + dx[i];
		int nextB = y + dy[i];
		//범위 바깥이 아니면서, 다음 색이 이번에 매개변수로 들어온 색과 같다면
		if (nextA >= 0 && nextB >= 0 && nextA < N && nextB < N && RGB[nextA][nextB]==R) {
			//방문 안했다면
			if (!visited[nextA][nextB])
				dfsRGB(nextA, nextB, R);
		}

	}
}


void solution() {
	//정상인의 컴퍼넌트 수와, 적녹색약 컴퍼넌트 수
	int RGBcomponent = 0,RBcomponent=0;
	// 방문배열 초기화
	fill(&visited[0][0], &visited[100][100], false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				RGBcomponent++;
				dfsRGB(i, j, RGB[i][j]);
			}
		}
	}
	//방문배열 다시 초기화
	fill(&visited[0][0], &visited[100][100], false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {

				RBcomponent++;
				dfsRB(i, j, RGB[i][j]);
			}
		}
	}
	cout << RGBcomponent <<" "<<RBcomponent;
}

int main() {
	input();
	solution();
}
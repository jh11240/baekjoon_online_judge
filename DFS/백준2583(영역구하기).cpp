#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int M=0, N=0, K=0;
int Area[101][101];
int visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> Ans;

void input() {
	int leftBottomX = 0, rightTopX = 0,leftBottomY = 0, rightTopY = 0;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		//왼쪽아래 좌표와 오른쪽 위 좌표
		cin >> leftBottomX >> leftBottomY>>rightTopX >> rightTopY;
		//상자가 있는 구역은 1로 넣어줌
		for (int i = leftBottomY; i < rightTopY; i++) {
			for (int j = leftBottomX; j < rightTopX; j++) {
				//0,0이 왼쪽 밑이므로 
				Area[M-i-1][j] = 1;
			}
		}
			
	}
}

int dfs(int x, int y) {
	//방문한 곳이면 return 0
	if (visited[x][y]) return 0;
	//방문했다고 표시
	visited[x][y] = true;
	//각 컴퍼넌트의 노드 몇개인지 리턴용
	int Node = 1;
	for (int i = 0; i < 4; i++) {
		int nextA = x + dx[i];
		int nextB = y + dy[i];
		//nextA. nextB가 범위안에 있는지와 상자의 유무 체크
		if (nextA >= 0 && nextB >= 0 && nextA < M && nextB < N && !Area[nextA][nextB]) {
			if(!visited[nextA][nextB])
			Node+=dfs(nextA, nextB);
		}

	}
	return Node;
}

void solution() {
	//사각형으로 나눠질 컴퍼넌트갯수
	int component = 0;
	//방문 배열 다 false 채워주기.
	fill(&visited[0][0], &visited[100][100], false);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//방문 한적없고, 상자가 없는 구역이라면 
			if(!visited[i][j]&& !Area[i][j]){
				component++;
				//dfs함수 실행하여 컴퍼넌트 크기 답벡터에 푸시
				Ans.push_back(dfs(i, j));
			}
		}
	}
	sort(Ans.begin(), Ans.end());
	cout << component<<'\n';
	for (auto iter = Ans.begin(); iter != Ans.end(); ++iter) {
		cout << *iter << " ";
	}
}

int main() {
	input();
	solution();
}
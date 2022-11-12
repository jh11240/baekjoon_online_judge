#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N = 0;
int realEstate[26][26];
bool visited[26][26];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<int> Ans;

void input() {
	string row = "";
	cin >> N;
	//숫자로 한줄 입력해온후 나머지연산으로 하나씩 일일이 넣어주기
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		cin >> row;
		for (int j = 0; j < N; j++) {
			realEstate[i][j] = row[j]-'0';
		}
	}
}

int dfs(int x, int y) {
	//이미 방문한 곳이라면 return 0
	if (visited[x][y]) return 0;
	//방문했다,
	visited[x][y] = true;
	//return할 노드. 기본적으로 x,y가 있으므로 1 
	int Node=1;
	for (int i = 0; i < 4; i++) {
		int nextA = x+ dx[i];
		int nextB = y+ dy[i];
		//만약 x,y좌표의 상하좌우 각각의 값이 범위를 넘지않으면서 집이 있는 곳이라면
		if (nextA >= 0 && nextB >= 0 && nextA < N && nextB < N && realEstate[nextA][nextB]) {
			//방문도 안했던곳이면
			if (!visited[nextA][nextB]) {
				//dfs재귀를 돌려서 해당칸으로 갔을때의 노드 수 반환하여 합침
				Node += dfs(nextA, nextB);
			}
		}
	}
	return Node;
}

void solution() {
	//컴퍼넌트 갯수 
	int components=0;
	//방문한곳 false로 처리
	fill(&visited[0][0], & visited[25][25], false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//방문하지 않았고, 단지가 존재한다면
			if (!visited[i][j] && realEstate[i][j]) {
				//새로운 단지 있는것이므로 compoenent 추가
				components++;
				//컴퍼넌트가 몇개있을지 모르므로 벡터에 push
				Ans.push_back(dfs(i, j));
			}
		}
	}
	//컴퍼넌트 갯수 출력
	cout << components<<'\n';
	//오름차순으로 출력하라했으므로 정렬
	sort(Ans.begin(),Ans.end());
	//벡터 iterator로 원소들 다 출력
	for (auto iter = Ans.begin(); iter != Ans.end(); ++iter) {
		cout << *iter << '\n';
	}
}

int main() {
	input();
	solution();
}
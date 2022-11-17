#include<iostream>
#include<vector>
using namespace std;

void solution(int students);

int cycleCnt=0;
vector<int> adj;
vector<int>visited;
vector<int>finished;

void init(int students) {
	cycleCnt = 0;
	adj.clear();
	adj.push_back(-1);
	finished.resize(students+1);
	visited.resize(students+1);
	fill(finished.begin(), finished.end(),false);
	fill(visited.begin(),visited.end(),false);
}

void dfs(int Nodes) {
		//해당 노드를 방문 안했고
		if (!visited[Nodes]) {
			visited[Nodes] = true;
			//완결난 컴퍼넌트가 아니라면
			if (!finished[Nodes]) {
				dfs(adj[Nodes]);
			}
		}
		//해당 노드를 방문 했지만
		else {
			//완결난 컴퍼넌트 아니라면 싸이클 이므로
			if (!finished[Nodes]) {
				//싸이클인 지점부터 자신까지 올때까지 cycleCNt증가시킴
				for (int tmp = Nodes; adj[tmp] != Nodes; tmp = adj[tmp])
					cycleCnt++;
				//자기 자신 지점도 포함해줌
				cycleCnt++;
				return;
			}
			//방문했고 완결났다면 return
			return;
		}
		finished[Nodes] = true;
	}

void input() {
	int T, amountStudents = 0,studentsNum=0;
	cin >> T;
	for (int i = 0; i < T; i++) 
	{
		cin >> amountStudents;
		init(amountStudents);
		for (int j = 1; j <= amountStudents; j++) {
			cin >> studentsNum;
			adj.push_back(studentsNum);
		}
		solution(amountStudents);
	}
}

void solution(int students) {
	for (int i = 1; i <=students; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	cout << students -  cycleCnt<< '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
}
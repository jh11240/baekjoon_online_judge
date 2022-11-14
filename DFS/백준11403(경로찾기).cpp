#include<iostream>
#include<vector>

using namespace std;
int N = 0;
class graph {
public:
	int Nodes;
	//인접리스트
	vector<vector<int>> adj;
	//방문했는지 여부
	vector<bool> visited;

	graph(int n) :Nodes(n) {
		adj.resize(n);
		visited.resize(n);
	}


	/// <summary>
	/// 방향그래프의 간선추가 하는 함수. 한 방향만 추가한다.
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v"></param>
	void AddEdge(int u, int v) {
		adj[u].push_back(v);
	}

	//매개변수는 각각 u부터 dfs시작, 맨처음 인덱스가 뭔지, 맨처음 재귀함수인지
	void dfs(int u,int firstIndex,bool first) {
		//방문했다면 return
		if (visited[u]) return;
		//만약 첫번째 인덱스이고, 맨처음이면
		if (u == firstIndex && first) {
			//visited[u]를 false로 해놔야한다.
			visited[u] = false;
		}
		//첫밴째 인덱스지만, 맨처음이 아니라면
		else if (u == firstIndex && !first) {
			//true로 바꿔야한다.
			visited[u] = true;
		}
		//첫번째인덱스가 아니라면 true로 설정
		else visited[u] = true;
		//노드u와 인접한 모든 노드에 대해
		for (int elem : adj[u]) {
			//방문 안한 노드라면
			if (!visited[elem]) {
				//해당 노드, 맨처음 인덱스값, 맨처음이아니라는 의미로 false
				dfs(elem,firstIndex,false);
			}	
		}
	}

};
graph* g;
void input() {

	cin >> N;
	g=new graph(N);
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 1) {
				g->AddEdge(i, j);
			}
		}
	}

}
void solution() {
	for (int i = 0; i < N; i++) {
			//매 반복문마다 방문 배열을 false로 초기화
			fill(g->visited.begin(), g->visited.end(), false);
			g->dfs(i,i,true);
			//i번째일때 방문배열을 다 출력
			for (int j = 0; j < N; j++) {
				cout << g->visited[j]<<' ';
			}
			//endl
			cout << '\n';
	}
}

int main() {
	input();
	solution();
}
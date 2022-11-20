#include<iostream>
#include<queue>
using namespace std;

int people = 0, targetPersonA = 0, targetPersonB = 0, relationsAmount= 0;

class Graph {
public:
	int Nodes;
	vector<vector<int>> adj;

	Graph(int N) :Nodes(N) {
		adj.resize(N+1);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	/// <summary>
	/// Node값에서 다른 값 까지 몇 개의레벨이 존재하는지 계산하는 함수
	/// </summary>
	/// <param name="시작 노드"></param>
	void bfs(int Node,int target) {
		//bfs에서 사용될 큐
		queue<int> q;
		//방문 벡터 false로 초기화
		vector<int> visited(Nodes+1, false);
		//q에 임시로 0값 푸시해줌(시작에서 pop해줄것)
		q.push(Node);
		//visited에 true넣어줌
		visited[0]=true;
		//해당 값과 어느정도 떨어져있는지 체크
		int size = 1;
		
		while (!q.empty()) {
			//큐 사이즈 임시변수에 저장(반복문에서 종결조건 변하면 안되므로)
			int qSize = q.size();

			//각 큐에 사이즈가 한 레벨에 들어있는 노드들의 갯수이므로 반복문이 끝나면 레벨하나가 증가해서 탐색하게된다.
			for (int i = 0; i < qSize; i++) {
				//큐의 front값 cur에 저장
				int cur = q.front();
				//큐 pop
				q.pop();
				//큐의 front값의 인접노드(다음 레벨)들에 대해 반복
				for (int elem : adj[cur]) {
					//elem노드를 방문하지 않았다면
					if (!visited[elem]) {
						//해당 노드가 타겟이라면 지금까지 size 출력
						if (elem == target) {
							cout << size;
							return;
						}
						//방문했다고 체크
						visited[elem] = true;
						//큐에 해당 노드 push
						q.push(elem);
					}
				}
			}
			//level 증가
			size ++ ;
		}
		//반복문을 다 돌았는데 타겟노드를 발견못하면 다른 컴퍼넌트이므로 -1 출력
		cout << -1;
	}
};

Graph* graph;

void input() {
	int tmp1=0, tmp2 = 0;
	cin >> people >> targetPersonA >> targetPersonB >> relationsAmount;
	graph = new Graph(people);
	for (int i = 0; i < relationsAmount; i++) {
		cin >> tmp1 >> tmp2;
		graph->addEdge(tmp1, tmp2);

	}
}
void solution() {
	graph->bfs(targetPersonA, targetPersonB);
}


int main() {

	input();
	solution();
}

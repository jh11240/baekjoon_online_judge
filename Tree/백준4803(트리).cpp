#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
bool visited[501];
int N=0, M = 0,tmpNode1=0,tmpNode2=0,edgeCnt=0;

void Solution(int testCases);

void Input() {
	//테스트케이스 번호 출력용
	int testCases = 1;
	while (1) {
		//각 반복마다 clear초기화
		adj.clear();
		//visited배열 초기화
		fill(visited, visited + 501, false);

		//N,M 입력받음
		cin >> N >> M;

		if (N == 0 && M == 0)
			return;
		else {
			//adj 크기 할당해줌
			adj.resize(N + 1);
			//M만큼 반복
			for (int i = 0; i < M; i++) {
				cin >> tmpNode1 >> tmpNode2;
				//node1에 node2연결
				adj[tmpNode1].push_back(tmpNode2);
				//node2에 node1연결
				adj[tmpNode2].push_back(tmpNode1);
			}
		}

		Solution(testCases++);
	}
}
//각 컴퍼넌트의 노드 갯수 반환
int DFS(int Node) {
	//노드 갯수
	int Sum = 1;
	//해당 노드 방문했다면 0을 return해서 0 더해줌
	if (visited[Node]) return 0;
	//방문안했다면 방문 처리
	visited[Node] = true;
	for (int elem : adj[Node]) {
		//각 연결된 점마다 edgeCnt++해줌 
		//양방향그래프로 설정해놔서 간선갯수 2배니까 마지막에 /2해줘야함
		edgeCnt++;
		//node갯수 더해줌
		Sum+=DFS(elem);
	}
	//Sum 리턴해줌
	return Sum;
	
}

void Solution(int testCases) {
	//testCases번호의 테케에서 트리 갯수
	int trees = 0;
	//노드 갯수만큼 dfs로 컴퍼넌트 체크 
	for (int i = 1; i <= N; i++) {
		//i 노드 방문했다면 continue
		if (visited[i]) continue;
		//노드갯수 0으로 설정
		int Nodes = 0;
		//간선 갯수인 cnt0으로 초기화
		edgeCnt = 0;
		//노드갯수 재귀통해 구함
		Nodes+=DFS(i);
		//그래프를 양방향그래프로 선언해서 간선이 두개씩 체크되서 cnt가 두배가 되므로 2로 나눠줘야함.
		//노드갯수-간선갯수가 1이여야 트리가 성립함
		if (Nodes - edgeCnt / 2 == 1 ) trees++;
	}
    //trees갯수에 따라 출력
	if (trees == 0) cout << "Case " << testCases << ": No trees."<<'\n';
	else if (trees == 1) cout << "Case " << testCases << ": There is one tree."<<'\n';
	else cout << "Case " << testCases << ": A forest of " << trees << " trees."<<'\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
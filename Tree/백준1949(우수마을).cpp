#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//adj는 그래프, tree는 adj를 트리로 구현한 구조이다
vector<vector<int>> tree, adj;
//노드의 총 갯수
int N;
//각 마을의 인원수
vector<int> villageInfo;
//트리 만들때 사용되는 각 마을을 방문했는지 여부
vector<bool> visited;
//각 노드가 우수마을일 때/ 우수마을이 아닐때의 최댓 dp값
int dp[10'001][2];

void MakeTree(int Node);
int MaxGoodVillagePeople(int Node, bool isGood);

void Input() {
	int tmp = 0, tmpNode1=0, tmpNode2 = 0;
	cin >> N;
	// 각 벡터들 사이즈 할당해줌, []연산자 이용하기 위함
	adj.resize(N + 1);
	tree.resize(N + 1);
	visited.resize(N + 1);
	villageInfo.resize(N + 1);
	//각 마을의 인원수 저장
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		villageInfo[i]=(tmp);
	}
	//인접 노드 받아와서 양방향그래프 adj에 저장
	for (int i = 0; i < N - 1; i++) {
		cin >> tmpNode1 >> tmpNode2;
		adj[tmpNode1].push_back(tmpNode2);
		adj[tmpNode2].push_back(tmpNode1);
	}
	//아무노드인 tmpNode1을 루느노드로 하는 트리 구조 생성
	MakeTree(tmpNode1);
	//루트노드인 tmpNode1이 우수마을일때의 최대 인원수와 tmpNode1이 우수마을이 아닐때의 최대인원수중 더 큰값이 답
	int Ans = max(MaxGoodVillagePeople(tmpNode1, true), MaxGoodVillagePeople(tmpNode1, false));
	cout << Ans;
}

/// <summary>
/// tree만드는 함수
/// </summary>
/// <param name="Node"></param>
void MakeTree(int Node) {
	visited[Node] = true;

	for (int elem : adj[Node]) {
		if (visited[elem]) continue;
		//트리 구조의 부모값에 자식값 대응시키고 재귀
		tree[Node].push_back(elem);
		MakeTree(elem);
	}
}
/// <summary>
/// 각 서브트리의 루트노드가 Node이고 Node마을이 우수한 마을이거나 아닐 때 
/// 해당 서브트리의 최대 우수마을인원값 재귀 통해 구하는 함수 
/// </summary>
/// <param name="Node(각 서브트리의 루트노드)"></param>
/// <param name="isGood(우수한 마을인지 bool형 변수)"></param>
/// <returns> 해당 서브트리에서의 최대 우수마을인원값 </returns>
int MaxGoodVillagePeople(int Node,bool isGood) {
	//이미 구한값이면 바로 return한다
	if (dp[Node][isGood]) return dp[Node][isGood];
	//참조자 &을 사용해 값을 바로 변경해줄수있도록 함
	int& ret = dp[Node][isGood];
	for (int elem : tree[Node]) {
		//기본적으로 elem노드가 우수마을이 아닐때 최대값을 불러오고
		int tmp = MaxGoodVillagePeople(elem, false);
		//만약 isGood이 false라면 elem노드가 우수마을일때 최대값과 비교해본다.
		if (!isGood) tmp = max(tmp, MaxGoodVillagePeople(elem, true));
		//각 자식마다 서브트리가 있을 것이므로 최대 인원값은 모든자식들의 최대값을 더한값이 나와야한다.
		ret += tmp;
	}
	//마지막에 isGood인지 체크하여 우수한마을이면 Node노드에 해당하는 인원수도 더하고 return해준다.
	if (isGood) ret += villageInfo[Node];
	return ret;
}

int main() {
	Input();
}
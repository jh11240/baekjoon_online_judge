#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> adj,tree;
vector<bool> visited;
int Nodes;
int dp[1'000'001][2];

void MakeTree(int Node) {
	visited[Node] = true;
	for (int elem : adj[Node]) {
		if (visited[elem]) continue;
		tree[Node].push_back(elem);
		MakeTree(elem);
	}
}

//해당 노드가 어댑터인지 아닌지로 분기를 나눠 재귀를 하는 함수
int SetLessEarlyAdapter(int node, bool isAdapter) {
	//이미 구한값이면 바로 return
	if (dp[node][isAdapter]) return dp[node][isAdapter];
	//참조자 이용해 값을 바로 변경가능하게 함
	int& ret = dp[node][isAdapter];
	//자식 노드중에
	for (int elem : tree[node]) {
		int tmp = SetLessEarlyAdapter(elem, !isAdapter);
		//어댑터아닌사람이 둘이 있을 순없음
		if (isAdapter) tmp = min(tmp, SetLessEarlyAdapter(elem, isAdapter));
		//자식값들의최소값 다 더해줌
		ret += tmp;
	}
	//자신이 어댑터라면 1 더해줌
	if (isAdapter) ret += 1;
	return ret;
}

void Input() {
	int tmpNode1=0, tmpNode2=0;
	cin >> Nodes;
	adj.resize(Nodes + 1);
	tree.resize(Nodes + 1);
	visited.resize(Nodes + 1);
	for (int i = 0; i < Nodes-1; i++) {
		cin >> tmpNode1 >> tmpNode2;
		adj[tmpNode1].push_back(tmpNode2);
		adj[tmpNode2].push_back(tmpNode1);
	}
	MakeTree(tmpNode1);
	cout << min(SetLessEarlyAdapter(tmpNode1, false), SetLessEarlyAdapter(tmpNode1, true));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
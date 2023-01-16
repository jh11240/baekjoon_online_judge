#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
int rootNode=0,deleteNode=0;
void Solution();

void Input() {
	int Nodes = 0, parentNodeInput = 0;
	cin >> Nodes;
	adj.resize(Nodes+1);
	visited.resize(Nodes+1,false);
	for (int i = 0; i < Nodes; i++) {
		cin >> parentNodeInput;
		//루트값이 아니고
		if (parentNodeInput != -1) {
			adj[i].push_back(parentNodeInput);
			adj[parentNodeInput].push_back(i);
		}
		else rootNode = i;
	}
	//삭제할 노드값 
	cin >> deleteNode;
	if (deleteNode == rootNode){
		cout << 0;
		return;
	}
	Solution();
}

int SearchTree(int Node) {
	int leafNodes = 0,childrenCnt=0;
	//각 노드마다 방문 체크
	visited[Node] = true;
	//해당 노드에 연결된 노드들에 대해
	for (int elem : adj[Node]) {
		//방문 했다면 패스
		if (visited[elem]) continue;
		//해당 값이 지운노드라면 패스
		if (elem == deleteNode) continue;
		//자식 몇개인지 체크용
		childrenCnt++;
		//위의 조건을 통과했다면 해당 값으로 재귀 
		leafNodes += SearchTree(elem);
	}
	//자식 값이 0개면 리프노드이므로 1 리턴
	if (childrenCnt==0) return 1;

	return leafNodes;
}

void Solution() {
	cout<<SearchTree(rootNode);
}

int main() {
	Input();
}
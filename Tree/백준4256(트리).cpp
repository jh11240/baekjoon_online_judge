#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
vector<int> inOrder;
vector<int> preOrder;
//전위순회 원소들의 인덱스 저장용
map<int, int> preOrderIndex;

//값들은 1부터들어오므로 0으로 초기화해도 됨
int parent[1001];
int leftChildren[1001];
int rightChildren[1001];

void init() {
	inOrder.clear();
	preOrder.clear();
	preOrderIndex.clear();
	fill(parent, parent + 1001, 0);
	fill(leftChildren, leftChildren + 1001, 0);
	fill(rightChildren, rightChildren+ 1001, 0);
}
void Solution();

void Input() {
	int N=0,Nodes=0,tmptreeNodes=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Nodes;
		init();
		for (int j = 0; j < Nodes; j++) {
			cin >> tmptreeNodes;
			preOrder.push_back(tmptreeNodes);
			preOrderIndex[tmptreeNodes] = j;
		}
		for (int j = 0; j < Nodes; j++) {
			cin >> tmptreeNodes;
			inOrder.push_back(tmptreeNodes);
		}
		Solution();
		cout << '\n';
	}
}

//rootNode기준으로 왼쪽 서브트리의 루트, 오른쪽 서브트리의 루트를 구해서 rootNode와 관계정립시켜주고 각 서브트리의 루트노드로 다시 재귀
//서브트리의 루트와 inorder벡터에서의 해당 서브트리의 위치를 iterator로 넣어줌  
void MakeTree(int rootNode,vector<int>::iterator inOrderBegin,vector<int>::iterator inOrderEnd) {
	//루트 노드가 0이면 return
	if (inOrderBegin >= inOrderEnd-1) return;

	//오른쪽 서브트리 노드 루트값, 왼쪽 서브트리 노드 루트값, 오른쪽 서브트리중에 인덱스 제일 작은 값 저장용 변수
	int rightSubTreeRootNode = 1002, leftSubTreeRootNode = 1002, rightSubTreeRootNodeIdx = 1002;
	vector<int>::iterator preOrderIter, inOrderIter;
	for (auto iter = inOrderBegin; iter != inOrderEnd; ++iter) {
		if (*iter == rootNode) {
				inOrderIter = iter;
				break;
		}
		if (iter == inOrderEnd - 1) {
			inOrderIter = inOrderEnd - 1;
		}
	}

	for (auto iter1 = preOrder.begin(); iter1 != preOrder.end(); ++iter1) {
		if (*iter1 == rootNode) {
				preOrderIter = iter1;
				break;
		}
		if (iter1 == preOrder.end() - 1) {
			preOrderIter = preOrder.end() - 1;
		}
	}
	//무조건 자식 두개 다있따고 가정하고 품;

	//오른쪽 서브트리
	for (auto iter=inOrderIter+1; iter != inOrderEnd; ++iter) {
		//min노드에 오른쪽서브트리의 루트노드 찾아줌-> 오른쪽서브트리의 노드값들중에 전위순회에서 제일먼저 나온 노드가 루트노드
		if (rightSubTreeRootNodeIdx > preOrderIndex[*iter]) {
			rightSubTreeRootNodeIdx = preOrderIndex[*iter];
			rightSubTreeRootNode = *iter;
		}
	}
	//왼쪽 자식노드가 있다면
	if(preOrderIter!=preOrder.end()-1)
	//왼쪽 서브트리의 루트노드는 전위순회벡터에서 바로 다음 값임
	leftSubTreeRootNode = *(preOrderIter + 1);

	//왼쪽자식이없고 오른쪽자식만 있을 경우 전위순회에서 다음값과 중위순회 다음값이 일치함
	if (leftSubTreeRootNode == rightSubTreeRootNode) {
		leftSubTreeRootNode = 0;
	}
	//왼쪽 자식 노드 있을때만
	if (preOrderIter != preOrder.end() - 1)
	leftChildren[rootNode] = leftSubTreeRootNode;
	//오른쪽 자식 노드 있을 때만
	if(inOrderIter!=inOrderEnd-1)
	rightChildren[rootNode] = rightSubTreeRootNode;
	//왼쪽 자식노드 있을때만
	if (preOrderIter != preOrder.end() - 1)
	parent[leftSubTreeRootNode] = rootNode;
	//오른쪽 자식노드 잇을때만
	if (inOrderIter != inOrderEnd - 1)
	parent[rightSubTreeRootNode] = rootNode;

	//왼쪽 자식노드 있다면 해당 노드를 루트로 왼쪽 서브트리 완성
	if (preOrderIter != preOrder.end() - 1)
	MakeTree(leftSubTreeRootNode,inOrderBegin,inOrderIter);
	//오른쪽 자식노드 있다면 해당 노드를 루트로 오른쪽 서브트리 완성한다.
	if (inOrderIter != inOrderEnd - 1)
	MakeTree(rightSubTreeRootNode,inOrderIter+1,inOrderEnd);
}

//후위 순회 방식으로 답 출력
void PrintInOrder(int Node) {
	if (Node == 0) return;
	PrintInOrder(leftChildren[Node]);
	PrintInOrder(rightChildren[Node]);
	cout << Node<<" ";
}

void Solution() {
	int rootNode = preOrder[0];
	MakeTree(rootNode,inOrder.begin(),inOrder.end());
	PrintInOrder(rootNode);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();

}
/////////////////////////////////////////////////////////////높이 N완전이진트리 크기의 배열을 선언하고 구현 
// #include<iostream>
// #include<vector>
// #include<queue>

// using namespace std;

// class Tree {
// public:
// 	int Node;
// 	vector<char> treeArr;

// 	Tree():Node(0) {}
// 	Tree(int N) :Node(N) {
// 		treeArr.resize((N+1)*(N+2)/2,'.');
// 	}
// 	//부모랑 자식값을 서로 p, l ,r값으로 설정해주는 함수
// 	void SetParentChildren(char p, char l, char r) {
// 		//맨처음 세팅이면 루트값과 루트의 자식값 대입해줌.
// 		if (treeArr[1] == '.') {
// 			treeArr[1] = p;
// 			treeArr[2] = l;
// 			treeArr[3] = r;
// 		}
// 		//처음이아니라면 p값을 iterator로 찾아서 해당값의 자식에 넣어줌 
// 		else {
// 			for (int i = 1; i <Node*(Node+1)/2;i++) {
// 				if (treeArr[i] == p) {
// 					treeArr[i * 2] = l;
// 					treeArr[i * 2 + 1] = r;
// 					break;
// 				}
// 			}
// 		}
// 	}
// 	// 왼쪽 자식 방문, 자기자신 방문, 오른쪽 자식 방문하는 중위 순위
// 	void InOrder(int root) {
//     	//범위 안넘어가는지 체크 및 .인지 체크
// 		if (root*2<treeArr.size()&& treeArr[root * 2] != '.') InOrder(root * 2);
// 		cout << treeArr[root];
// 		if (root * 2+1 < treeArr.size() && treeArr[root * 2 + 1] != '.') InOrder(root * 2 + 1);
// 	}
// 	//자기 자신부터 방문하는 전위순회
// 	void PreOrder(int root) {
// 		cout << treeArr[root];
//         //범위 안넘어가는지 체크 및 .인지 체크
// 		if (root * 2 < treeArr.size() && treeArr[root * 2] != '.') PreOrder(root * 2);
// 		if (root * 2+1 < treeArr.size() && treeArr[root * 2 + 1] != '.') PreOrder(root * 2 + 1);

// 	}
// 	//무조건 자식부터 방문하는 후위 순회
// 	void PostOrder(int root) {
//    	 	//범위 안넘어가는지 체크 및 .인지 체크
// 		if (root * 2 < treeArr.size() && treeArr[root * 2] != '.') PostOrder(root * 2);
// 		if (root * 2+1 < treeArr.size() && treeArr[root * 2 + 1] != '.') PostOrder(root * 2 + 1);
// 		cout << treeArr[root];
// 	}
// };
// Tree* tree;

// void Input() {
// 	int Nodes = 0;
// 	char parentNode = 0, leftNode = 0, rightNode = 0;
// 	cin >> Nodes;
// 	tree=new Tree(Nodes);
// 	for (int i = 0; i < Nodes; i++) {
// 		cin >> parentNode >> leftNode >> rightNode;
// 		tree->SetParentChildren(parentNode, leftNode, rightNode);
// 	}
// }

// void Solution() {
// 	tree->PreOrder(1);
// 	cout << '\n';
// 	tree->InOrder(1);
// 	cout << '\n';
// 	tree-> PostOrder(1);
// }

// int main() {
// 	Input();
// 	Solution();
// }

//////////////////////////////////////////////////////////////배열의 크기가 알파벳 갯수 26으로 줄여서 푸는 방법

#include<iostream>

using namespace std;

//i번째 인덱스의 부모 노드값
int parent[26];
//i번째 인덱스의 왼쪽 자식 노드값
int leftChildren[26];
//i번째 이덱스의 오른쪽 자식 노드값
int rightChildren[26];

//p번째 알파벳의 자식 노드로 lc,rc번째 알파벳 설정하고, 
//lc,rc번째 알파벳의 부모노드로 p번째 알파벳으로 설정하는 함수
void SetPAndC(int p, int lc, int rc) {
	//p번째 알파벳의 왼쪽 자식 노드는 lc번째 알파벳, 
	leftChildren[p] = lc;
	//오른쪽 자식노드는 rc 번째 알파벳 값이 들어간다
	rightChildren[p] = rc;
	//lc,rc가 -1이면 저장할 의미도 없을 뿐더러 인덱스가 -1이 되면 안되기때문에 예외로 조사한다.
	//lc번째 알파벳의 부모노드는 p번째 알파벳으로 설정
	if(lc!=-1)parent[lc] = p;
	//rc번째 알파벳의 부모노드는 p번째 알파벳으로 설정
	if(rc!=-1)parent[rc] = p;
}
void Input() {
	//미리 부모, 자식 배열들 -1로 초기화
	fill(parent,parent+26,-1);
	fill(leftChildren,leftChildren+26,-1);
	fill(rightChildren,rightChildren+26,-1);
	int N=0;
	char parent=' ', leftChild = ' ', rightChild = ' ';
	cin >> N;
	//N만큼 반복해서 받음
	for (int i = 0; i < N; i++) {
		cin >> parent >> leftChild >> rightChild;
		//만약 왼쪽 자식만 .이라면
		if (leftChild == '.'&&rightChild!='.') {
			//해당 char값에 'A'를 빼주면 해당 알파벳의 인덱스가 나옴.
			//왼쪽자식에 -1값을 저장
			SetPAndC(parent-'A', -1, rightChild - 'A');
			continue;
		}
		//오른쪽만 .이라면
		else if (leftChild != '.' && rightChild == '.') {
			//오른쪽값에 -1을 저장
			SetPAndC(parent-'A', leftChild-'A', -1);
			continue;
		}
		//둘다 .이라면
		else if (leftChild == '.' && rightChild == '.') {
			//왼쪽 오른쪽 자식 다 -1 대입
			SetPAndC(parent-'A', -1, -1);
			continue;
		}
		//.이 없다면 해당 알파벳에 해당하는 인덱스값으로 설정 
		SetPAndC(parent-'A', leftChild-'A', rightChild-'A');
	}
}
//전위 순회
void PreOrder(int root) {

	cout << (char)(root+'A');

	if (leftChildren[root] != -1) PreOrder(leftChildren[root]);

	if (rightChildren[root] != -1) PreOrder(rightChildren[root]);
}
//중위 순회
void InOrder(int root) {
	if (leftChildren[root] != -1) InOrder(leftChildren[root]);
	cout << (char)(root+'A');
	if (rightChildren[root] != -1) InOrder(rightChildren[root]);
}
//후위 순회
void PostOrder(int root) {
	if (leftChildren[root] != -1) PostOrder(leftChildren[root]);
	if (rightChildren[root] != -1) PostOrder(rightChildren[root]);
	cout << (char)(root+'A');
}


void Solution() {
	PreOrder(0);
	cout << '\n';
	InOrder(0);
	cout << '\n';
	PostOrder(0);
}

int main() {
	Input();
	Solution();
}

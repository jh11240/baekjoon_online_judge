#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
//부모 자식연결
vector<vector<int>> tree;

struct parentAndChild {
	int parent;
	int child;
	//맵에서 키비교용으로 필요함
	bool operator<(const parentAndChild& other) const{
		if (parent == other.parent) return child < other.child;
		return parent<other.parent;
	}
};
//parent, child값의 가중치저장용 맵
map<parentAndChild, int> distInfo;

//답 출력용
int maxRadius=0;

void Input() {
	//N, 부모값, 자식값, 가중치
	int N = 0,parent=0,child=0,dist=0;
	cin >> N;
	//노드는 1부터 들어옴
	tree.resize(N+1);
	for (int i = 0; i < N-1; i++) {
		cin >> parent >> child >> dist;
		//부모값에 자식값 푸시해줌
		tree[parent].push_back(child);
		distInfo[{parent, child}] = dist;
	}
}

//루트인 node 노드에서 제일 멀리떨어진 노드와의 거리 반환(각 자식들에서 재귀함수를 통해 제일 먼 거리와 두 번째로 먼 거리 찾아놓음.)
int SearchTree(int node) {
	//node 노드의 자식노드가 없다면 0리턴
	if (tree[node].size() == 0) return 0;

	//자식 중에 제일 긴 길이
	int longest=0,
		//자식중 두번째로 긴 길이
		secondLongest=0,
		// node의 자식 중 하나로 파고들어갔을때의 나온 리프노드부터 node노드까지의 거리
		lengthOfEachChildRoute=0,
		//node노드의 각 자식에서 node노드까지의 길이
		tmpLengthNodeToElem=0;

	//node 노드의 각 자식마다 재귀를 통해 
	for (int elem : tree[node]) {
		//노드에서 각자식까지의 길이 초기화후, 값 넣어줌
		tmpLengthNodeToElem= 0;
		tmpLengthNodeToElem = distInfo[{node, elem}];
		//elem자식으로 내려갔을 때의 총 길이
		lengthOfEachChildRoute = tmpLengthNodeToElem;
		lengthOfEachChildRoute += SearchTree(elem);
		//제일 길다면 longest에 저장 
		//갱신될때 지금 longest를 second로 넘겨줘야함!!!!
		if (longest < lengthOfEachChildRoute) {
			secondLongest = longest;
			longest = lengthOfEachChildRoute;
		}
		//두번째로 길다면 secondLongest에 저장 lengthOfChildRoute< longest로 했더니 같을때 체크를 못함
		else if (lengthOfEachChildRoute<=longest && lengthOfEachChildRoute>secondLongest)
			secondLongest = lengthOfEachChildRoute;
	}
	//모든 자식노드에 대해 DFS가 끝나면 최대거리와 두번째로 긴 거리가 저장됨 
	//최대 지름값 갱신
	maxRadius = max(maxRadius, longest + secondLongest);
	//node에서 출발해서 자식값중 제일 먼 거리를 리턴 
	return longest;
}


void Solution() {
	//루트노드는 1로 정해줌
	SearchTree(1);
	cout << maxRadius;
}

int main() {
	Input();
	Solution();
}
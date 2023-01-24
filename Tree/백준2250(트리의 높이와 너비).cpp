#include<iostream>
#include<vector>

using namespace std;

int parents[10'001];
int leftChildren[10'001];
int rightChildren[10'001];
int N,order=1;
vector<vector<int>> levelAndWidth;

//입려값 받아서 트리 구조 형성
void Input() {
	int parent = 0, leftChild = 0, rightChild = 0;
	fill(parents, parents + 10001, -1);
	fill(leftChildren, leftChildren + 10001, -1);
	fill(rightChildren, rightChildren + 10001, -1);
	levelAndWidth.resize(10001);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parent >> leftChild >> rightChild;
		leftChildren[parent] = leftChild;
		rightChildren[parent] = rightChild;
		parents[leftChild] = parent;
		parents[rightChild] = parent;
	}
}
//중위 순회 방식으로 레벨과 순서저장하는 벡터인 levelAndWidth에 푸시해준다.
void InOrder(int Node,int level) {
	//노드가 -1이면 끝이므로  retunr
	if (Node == -1) return;
	//왼쪽 자식으로 재귀
	InOrder(leftChildren[Node],level+1);
	// 노드에 도달했다면 level에 order값을 증가시켜서 push해줌
	levelAndWidth[level].push_back(order++);
	//오른쪽 자식으로 재귀
	InOrder(rightChildren[Node],level+1);
}
//1값을 기준으로 부모값을거슬러 올라가다 parent가 -1인 최초의 값이 루트임
int findRoot() {
	int cur = 1;
	while (1) {
		//부모값 저장
		cur = parents[cur];
		//부모값이 -1이라면 cur이 루트이므로
		if (parents[cur] == -1) {
			//반복문 빠져나옴
			break;
		}
	}
	//cur리턴
	return cur;
}
void Solution() {
	//최대 거리
	int maxDist = 0;
	//최대 거리가 저장된 레벨
	int maxDistLevel = 0;
	//루트값 저장
	int root = findRoot();
	//중위순회 시작
	InOrder(root,1);
	//levelAndWidth 탐색하면서
	for (int i = 1; i < levelAndWidth.size(); i++) {
		//levelAndWidth[i]가 비어있다면 패스
		if (!levelAndWidth[i].size()) continue;
		else {
			//최대 거리가 i레벨의 최대 너비보다 크거나 같다면 continue
			//같을때도 continue인건 최대너비 같으면 제일 작은 레벨 반환해야하므로
			if (maxDist >= levelAndWidth[i].back() - levelAndWidth[i].front() + 1) {
				continue;
			}
			//최대 거리가 더 작으면 갱신
			maxDist = levelAndWidth[i].back() - levelAndWidth[i].front() + 1;
			//레벨도 갱신
			maxDistLevel = i;
		}
	}
	//답 출력
	cout << maxDistLevel<<" "<<maxDist;
}

int main() {
	Input();
	Solution();
}
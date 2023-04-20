#include<iostream>

using namespace std;

//사이즈는 2^19 *2로 해서 
int segTree[524'288*2];
//인덱스 값 잡아주는 배열
int index[100'000];
int firstLeafNodeIdx = 524288;


int findHowManyDvdsInTargetRange(int targetL, int targetR, int nodeNum, int curL, int curR) {
	if (targetR < curL || curR < targetL) return 0;
	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];
	int mid = (curL + curR) / 2;
	return findHowManyDvdsInTargetRange(targetL, targetR, nodeNum * 2, curL, mid) +
		findHowManyDvdsInTargetRange(targetL, targetR, nodeNum * 2 + 1, mid + 1, curR);
}

void SetAncestorNode(int idx, int val) {
	int tmpIdx = idx + firstLeafNodeIdx;
	while (tmpIdx > 0) {
		segTree[tmpIdx] += val;
		tmpIdx /= 2;
	}

}

void Input() {
	int testCases=0,n=0,m=0,tmpInput=0;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
	fill(segTree, segTree + 524288 * 2, 0);
	fill(index, index + 100'000, 0);
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			//책을  쌓을 공간이 인덱스 증가하는 방향으로 생기므로 
			//인덱스값들을 반대로 쌓아야한다.
			index[j] = n-j-1;
			SetAncestorNode(j, 1);
		}
		for (int j = 0; j < m; j++) {
			cin >> tmpInput;
			//tmpInput위치에 해당하는 인덱스를 index배열에서 조회한 뒤, 해당 인덱스+1 부터 끝까지의 구간합 출력 
			cout << findHowManyDvdsInTargetRange(index[--tmpInput]+1, firstLeafNodeIdx * 2, 1, 0, firstLeafNodeIdx - 1) << " ";
			//해당 노드를 -1로 변경하고 조상노드도 -1씩 빼는식으로 갱신하면서 책을 뺐다는걸 구현
			SetAncestorNode(index[tmpInput], -1);
			//tmpInput의 인덱스는 이제 맨위인 n+j
			index[tmpInput] =n+j;
			//n+j인덱스의 노드를 1을 더하면서 책을 맨위에 둔것으로 구현
			SetAncestorNode(index[tmpInput], 1);

		}
		cout << '\n';

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
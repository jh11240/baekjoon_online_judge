#include<iostream>

using namespace std;
//수의 범위가 int 범위 이므로 두 수를 연산하게 되면 int를 넘어갈 수 있음
long long segmentTree[262144];
int N = 0, Q = 0,firstLeafNode=1;


long long Sum(int targetL, int targetR, int nodeNum, int curL, int curR) {
	if (targetR < curL || curR < targetL) return 0;
	if (targetL <= curL && curR <= targetR) return segmentTree[nodeNum];

	int mid = (curL + curR) / 2;
	return Sum(targetL, targetR, 2*nodeNum, curL, mid) + Sum(targetL, targetR, 2*nodeNum+1, mid + 1, curR);
}

//리프노드에서 a번째 인덱스의 수를 b로 바꿔주는 함수
void ChangeElemAndReadjustTree(int a, int b) {
	//리프노드의 a번째 인덱스
	int firstElemIdx = a + firstLeafNode;
	//리프노드의 a번째 인덱스의 변화량, 리프노드의 b번째 인덱스의 변화량
	long long Change = b- segmentTree[firstElemIdx];

	while (firstElemIdx > 0) {
		segmentTree[firstElemIdx] += Change;
		firstElemIdx /= 2;
	}
}

//x부터 y까지의 합 구하기
void SumBetweenTwoIdx(int x, int y) {
	//노트에서 적혀있듯이 x,y순서 바뀌어 있다면 다시 바꿔주자.
	if (x > y) swap(x, y);

	long long Ans = Sum(x, y, 1, 0, firstLeafNode-1);
	cout << Ans<<'\n';
}

void Input() {
	int x=0, y=0, a=0, b=0;
	cin >> N >> Q;
	//리프노드 시작 인덱스 찾기
	while (firstLeafNode < N) {
		firstLeafNode *= 2;
	}
	//리프노드 입력받기
	for (int i = 0; i < N; i++) {
		cin >> segmentTree[firstLeafNode + i];
	}
	//리프노드로부터 부모노드들 갱신하기
	for (int i = firstLeafNode - 1; i > 0; i--) {
		segmentTree[i] = segmentTree[i * 2] + segmentTree[i * 2 + 1];
	}
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		SumBetweenTwoIdx(x-1, y-1);
		ChangeElemAndReadjustTree(a - 1, b);
	}


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
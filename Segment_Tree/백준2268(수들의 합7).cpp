#include<iostream>

using namespace std;
long long segmentTree[2'097'152];
int N, M, firstLeafIdx = 1;

//목표 구간 [targetL, targetR]에서의 합 리턴하는 함수, 현재 탐색 노드 nodeNum, 현재 구간 [curL, curR] 
long long ReturnSum(int targetL, int targetR, int nodeNum, int curL, int curR) {
	if (curR<targetL || curL>targetR) return 0;
	if (targetL <= curL && curR <= targetR) return segmentTree[nodeNum];

	int mid = (curL + curR) / 2;
	return ReturnSum(targetL, targetR, nodeNum * 2, curL, mid) + ReturnSum(targetL, targetR, nodeNum * 2 + 1, mid + 1, curR);
}
//리프노드에서 i번째 인덱스값을 k로 바꾸는 함수
 void Mod(int i, int k) {
	int tmpIdx = firstLeafIdx + i;
	int change = k-segmentTree[tmpIdx];
	while (tmpIdx > 0) {
		segmentTree[tmpIdx] +=change;
		tmpIdx /= 2;
	}
}
 //i번째 인덱스부터 j번째 인덱스까지의 합을 구해 리턴하는 함수
void Sum(int i, int j) {
	if (i > j) swap(i, j);

	cout << ReturnSum(i, j, 1, 0, firstLeafIdx - 1)<<'\n';
}

void Input() {
	int a = 0,b=0,c=0;
	cin >> N >> M;
	//리프노드의 시작 인덱스 구하기
	while (firstLeafIdx < N)
		firstLeafIdx *= 2;

	for (int i = 0; i < M; i++) {
		cin >> a>>b>>c;
		if (a) {
			Mod(b - 1, c);
		}
		else {
			Sum(b - 1, c - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();

}
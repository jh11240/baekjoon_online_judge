#include<iostream>


using namespace std;

//2^20이 1048576
long long segTree[2'097'152];

int N,Q, firstLeafNodeIdx=1;

void ReadjustTree(int b, int c) {
	int tmp = firstLeafNodeIdx + b;
	while (tmp > 0) {
		//구간합같은 문제는 값이 다른값으로 변경되서 변화량을 더해야 함.
		//이문제는 수입과 지출이 추가되는 형태로 c값을 그냥 더해도 무방
		segTree[tmp] += c;
		tmp /= 2;
	}
}

long long FindChanges(int targetL, int targetR, int nodeNum, int curL, int curR) {
	if (targetR < curL || curR < targetL) return 0;
	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];
	int mid = (curL + curR) / 2;
	return FindChanges(targetL, targetR, nodeNum * 2, curL, mid) + FindChanges(targetL, targetR, nodeNum * 2 + 1, mid + 1, curR);
}

void PrintAnswer(int b, int c) {
	cout << FindChanges(b, c, 1, 0, firstLeafNodeIdx - 1)<<'\n';
}

void Input() {
	int a=0, b=0, c=0;
	cin >> N >> Q;
	while (firstLeafNodeIdx < N) {
		firstLeafNodeIdx *= 2;
	}
	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			ReadjustTree(b - 1, c );
		}
		else {
			PrintAnswer(b - 1, c - 1);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
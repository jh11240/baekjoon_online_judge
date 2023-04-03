#include<iostream>

using namespace std;

//사이즈 2^21 의 트리
long long Arr[2097152];
//나머지
const int Modular = 1'000'000'007;
//수의 갯수, 변경 횟수, 구간의 곱 구하는 횟수 , 첫번째 리프노드의 인덱스
int N,M,K,FirstLeafNodeIndex=1;

//목표구간 [targetL,targetR] 현재 탐색구간 [curL, curR] 현재 보고있는 노드 nodeNum
long long Mul(int targetL, int targetR, int nodeNum, int curL, int curR) {
	if (targetL > curR || targetR < curL) return 1;
	else if (targetL <= curL && targetR >= curR) return Arr[nodeNum]%Modular;

	int mid = (curL + curR) / 2;
	return Mul(targetL, targetR, nodeNum * 2, curL, mid) * Mul(targetL, targetR, nodeNum * 2 + 1, mid + 1, curR) % Modular;

}

//변화량으로 double change =(double) c / Arr[idx];을 사용하면 안되는게 arr[idx]값이 0이나오면 division by 0되버림
void ChangeAndAdjustTree(int a, int b, int c) {
	if (a == 1) {
		int idx = b + FirstLeafNodeIndex;
		Arr[idx] = c;
		//부모 노드값 다시 세팅
		for (int i = idx / 2; i > 0; i /= 2) {
			Arr[i] = Arr[i * 2] * Arr[i * 2 + 1] % Modular;
		}

	}
	else {
		cout << Mul(b, c-1, 1, 0, FirstLeafNodeIndex - 1)<<'\n';

	}
}

void Input() {
	int a=0, b=0, c = 0;
	cin >> N >> M >> K;
	//곱이므로 1로 초기화해줌
	fill(Arr, Arr + 2097152, 1);
	//2를 계속 곱해주며 첫번째 리프노드 위치를 정함.
	while (FirstLeafNodeIndex < N) {
		FirstLeafNodeIndex *= 2;
	}
	//리프노드들 입력받음
	for (int i = 0; i < N; i++) {
		cin >> Arr[FirstLeafNodeIndex + i];
	}
	//세그먼트 트리 전체 노드 갱신해줌
	for (int i = FirstLeafNodeIndex - 1; i > 0; i--) {
		Arr[i] = Arr[i * 2]  * Arr[i * 2 + 1] % Modular;
	}
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		ChangeAndAdjustTree(a, b-1, c);
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
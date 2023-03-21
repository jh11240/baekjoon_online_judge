#include<iostream>

using namespace std;

//2^21값이다. 2^20이 100만을 넘어가는 수라서 트리는 높이가 20이 되고, 높이 20의 트리의 총 갯수는 2^21보다 작으므로 최대사이즈를 2^21로 설정
long long Arr[2097152];

int N=0,M=0,K=0,FirstLeafNodeIdx=1;

//LTaget과 RTarget은 우리가 구하려는 타겟 범위,nodeNum은 현재 LCur~RCur구간의 합을 담당하는 노드인덱스 ,LCur, RCur은 현재 범위 
long long Sum(int LTarget, int RTarget, int nodeNum, int LCur, int RCur) {
	//현재 Sum함수가 계산하는 범위가 타겟범위를 벗어나면 바로 리턴 0
	if (LTarget > RCur || RTarget < LCur) return 0;
	//현재 Sum함수가 계산하는 범위가 타겟범위 안에 존재하면 LCur부터 RCur값을 담당하는 해당 노드의 값(nodeNum인덱스의 값)을 반환 
	if (LTarget <= LCur && RCur <= RTarget) return Arr[nodeNum];
	//현재 범위가 타겟 범위보다 넓다면 현재범위를 반으로 줄여서 재귀 
	int mid = (LCur+RCur) / 2;
	return Sum(LTarget, RTarget, nodeNum * 2, LCur, mid) + Sum(LTarget, RTarget, nodeNum * 2 + 1, mid+1, RCur);

}

void ChangeLeafAndReAdjustTree(int a, int b, long long c) {
	if (a == 1) {
		//b번째는 리프노드 인덱스이므로 리프노드 시작 인덱스 더해야댐
		b += FirstLeafNodeIdx;
		//바꾸려는 값 c에 원래 있던 원소 Arr[b]를 빼줌으로써 두 값의 차이(b번째 원소의 변화량)를 저장
		c -= Arr[b];
		while (b > 0) {
			//부모로 거슬러 올라가며 두값의 차이만큼 다 더해줌
			Arr[b] += c;
			b /= 2;
		}
	}
	else {
		cout << Sum(b,c-1,1,0,FirstLeafNodeIdx-1)<<'\n';
	}
}

void Input() {
	cin >> N>>M>>K;
	int tmp = 1, a = 0, b = 0;
	long long c = 0;
	while (tmp<N) {
		tmp *= 2;
	}
	FirstLeafNodeIdx = tmp;
	//처음 리프노드 위치부터 리프노드들 입력받고
	for (int i = 0; i < N; i++) {
		cin >> Arr[FirstLeafNodeIdx + i];
	}
	//처음 리프노드 바로전 노드(tmp-1번째 노드)부터 부모노드들 채워나감
	for (int i = tmp-1; i > 0; i--) {
		Arr[i] = Arr[i*2] + Arr[i*2 + 1];
		//Arr[i/2] = Arr[i]+Arr[i+1] 을 하면 안됨 \
		리프 두개당 하나가 올라가야되는데(4 5의 부모 2, 6 7 의 부모 3 이런식 )\
		이렇게 짜면 (4 5의 부모 2, 5 6의 부모 2 이런식으로 됨)
	}
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		//리프노드 index는 0번째부터 시작하지만 문제에선 1번째부터 라고 표현하므로 b-1번째부터 c번째
		ChangeLeafAndReAdjustTree(a, b-1, c);
	}

	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
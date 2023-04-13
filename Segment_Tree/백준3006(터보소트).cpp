#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int SegTree[262144];

vector<pair<int, int>> GreaterVec;

int N,tmp=0,firstLeafNodeIdx=1;

bool Greater(pair<int, int> a,pair<int,int> b) {
	return a.first < b.first;
}

int HowManyNumsInTargetRange(int targetL, int targetR, int nodeNum, int curL, int curR) {
	if (curL > targetR || curR < targetL) return 0;
	if (targetL <= curL && curR <= targetR) return SegTree[nodeNum];
	int mid = (curL + curR) / 2;
	return HowManyNumsInTargetRange(targetL, targetR, nodeNum * 2, curL, mid)+
		HowManyNumsInTargetRange(targetL, targetR, nodeNum * 2+1, mid+1, curR);
}
void SetAncestorNode(int n) {
	int tmp = n + firstLeafNodeIdx;

	while (tmp > 1) {
		SegTree[tmp]++;
		tmp /= 2;
	}
}

void Solution() {
	for (int i = 0; i < N; i++) {
		int pos;
		//홀수일 때 제일 큰수 고르기(0부터 시작이라 반대임)
		if (i % 2) {
			//홀수값 다음 홀수값일때 이 조건문 안으로 들어온다 \
			 따라서 조건문 안으로 들어오는 i값이 2씩 차이나므로 우리가 원하는 인덱스 가져오려면 2로 나눠서 1씩 차이나게 변형해야함 
			pos = GreaterVec[N-1-i/2].second;
			//끝값 인덱스 N-1에서 현재 인덱스값과 이미 자기자리 찾아간 숫자갯수 빼줘서 이동해야하는 숫자 구함
			cout << N - 1 - pos - HowManyNumsInTargetRange( pos,N-1, 1, 0, firstLeafNodeIdx - 1)<<'\n';
		}
		//짝수일 때 제일 작은 수 고르기
		else {
			//위의 주석과 같이 짝수일때 이 조건문 안으로 들어오므로 i값이 2씩 차이난다. \
			2로 나눠서 원하는 인덱스로 변형
			pos = GreaterVec[i/2].second;
			//해당 인덱스에서 자기자리 찾아간 숫자갯수 빼줌
			cout << pos-HowManyNumsInTargetRange(0,pos,1,0,firstLeafNodeIdx-1)<<'\n';
		}
		//자기자리 찾아간 상태이므로 구간합트리의 조상노드들 전부 1씩더하며 갱신해줌
		SetAncestorNode(pos);
	}

}

void Input() {
	cin >> N;
	while (N > firstLeafNodeIdx) firstLeafNodeIdx *= 2;
	fill(SegTree, SegTree + 262144, 0);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		GreaterVec.push_back({ tmp, i });
	}
	sort(GreaterVec.begin(), GreaterVec.end(), Greater);
	Solution();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}


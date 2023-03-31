#include<iostream>
#include<vector>

using namespace std;
//2^17이 최초로 10만을 넘어가는 수이므로 트리의 최대 노드 갯수는 2^18을 넘지 않는다
//각 노드는 최솟값, 최댓값을 가진 pair로 구성되고, 리프노드들은 최소 최대값을 같은 값을 가진다.
vector<pair<int, int>> segTree;

int N = 0, M = 0, firstLeafNodeIdx = 1;
pair<int, int> zeroPair = { 0,0 };

//두 pair 비교해서 새로운 pair 만들기
pair<int, int> MakeNewPairByComparing(pair<int,int> a, pair<int,int> b) {
	//초기값으로 설정한 (0,0)이 있을때  (설정안하면 모든 노드 최솟값은 전부 0으로 됨) 
	if (a ==zeroPair) {
		if (b == zeroPair) {
			return zeroPair;
		}
		else
			return b;
	}
	else if(b==zeroPair) {
		return a;
	}

	pair<int, int> retPair;
	retPair.first = a.first > b.first ? b.first : a.first;
	retPair.second = a.second > b.second ? a.second : b.second;
	return retPair;
}

//타겟 구간의 왼쪽값, 타겟구간의 오른쪽값, 노드인덱스, 현재 탐색하는 구간의 왼쪽값, 오른쪽값
pair<int,int> FindMinAndMax(int targetL,int targetR,int nodeNum,int curL,int curR) {
	//탐색하는 구간이 목표구간을 벗어난경우 0,0을 반환 
	if (curR < targetL || targetR < curL) return zeroPair;
	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];

	//평균값 mid
	int mid = (curL + curR) / 2;
	//curL값부터 mid값 까지의 최솟값과 최댓값 pair로 
	pair<int, int> firstVal = FindMinAndMax(targetL, targetR, nodeNum * 2, curL, mid);
	//mid+1값부터 curR값까지의 최소,최대값 pair로 저장
	pair<int, int> secondVal = FindMinAndMax(targetL, targetR, nodeNum * 2 + 1, mid + 1, curR);
	return MakeNewPairByComparing(firstVal,secondVal);
}

//a,b사이의 최솟값과 최댓값 pair로 저장해서 출력하는 함수
void query(int a, int b) {
	
	pair<int, int> Ans = FindMinAndMax(a-1, b-1,1,0,firstLeafNodeIdx-1);
	cout<<Ans.first<<" " << Ans.second<<'\n';
}

void Input() {
	int tmp1,tmp2;
	//세그먼트 트리를 0,0으로 초기화해줌 
	segTree.resize(262144,zeroPair);
	cin >> N>>M;
	//N개보다 큰 2의 배수될때까지 2곱해줌
	while (firstLeafNodeIdx<N) {
		firstLeafNodeIdx *= 2;
	}
	
	for (int i = 0; i < N; i++) {
		cin >> tmp1;
		segTree[firstLeafNodeIdx + i]=make_pair(tmp1,tmp1);
	}
	for (int i = firstLeafNodeIdx - 1; i > 0; i--) {
		segTree[i] = MakeNewPairByComparing(segTree[i * 2], segTree[i * 2 + 1]);
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		query(tmp1, tmp2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();

 }
#include<iostream>
#include<vector>

//세그트리의 i번째 리프노드에는 현재 i번째 어떤 디스크 들어있냐가 아니라 i번째 디스크가 몇번 인덱스에 있는지를 조사해야됨.

using namespace std;
int N=0,K=0,firstLeafNodeIdx=1;
vector<pair<int, int>> segTree;
//이번문제는 0번쨰 인덱스를 포함하므로 빈 노드는 -1로 설정해야함
pair<int, int> BasePair = { -1, - 1 };

pair<int, int> CalculateMinAndMAx(pair<int, int> left, pair<int, int>right) {
	pair<int, int> ret;
	//left나 right가 비어있을 때 처리
	if (left == BasePair) {
		if (right == BasePair) return BasePair;
		else return right;
	}
	else if(right==BasePair) {
		return left;
	}
	//ret에는 left,right의 최소 최대를 가져와서 저장 
	ret.first = left.first > right.first ? right.first : left.first;
	ret.second = left.second > right.second ? left.second : right.second;

	return ret;
}

//[targetL, targetR]구간의 최소 최대값을 pair<int,int>형으로 반환
pair<int,int> IsDvdsExistInARow(int targetL,int targetR,int nodeNum,int curL,int curR) {
	if (curL > targetR || curR < targetL) return BasePair;
	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];
	int mid = (curL + curR) / 2;
	return CalculateMinAndMAx(IsDvdsExistInARow(targetL, targetR, nodeNum*2,curL,mid),
		IsDvdsExistInARow(targetL,targetR,nodeNum*2+1,mid+1,curR));
}
//idx+firstLeafNodeIdx 인덱스 리포노드의 조상노드들을 갱신 
void SetAncestorNode(int idx) {
	int tmpIdx = idx + firstLeafNodeIdx;
	while (tmpIdx > 1) {
		tmpIdx /= 2;
		pair<int, int> left = segTree[tmpIdx * 2];
		pair<int, int> right = segTree[tmpIdx * 2+1];
		segTree[tmpIdx] = CalculateMinAndMAx(left, right);
	}
}

void Swap(int indexA, int indexB) {
	//같은 인덱스일때 오버헤드 제거
	if (indexA == indexB) return;
	swap(segTree[firstLeafNodeIdx + indexA],segTree[firstLeafNodeIdx+indexB]);
	SetAncestorNode(indexA);
	SetAncestorNode(indexB);
}

//Q에 따라 A,B 처리
void Solution(int Q,int A,int B) {
	if (Q == 0) {
		
		Swap(A, B);
	}
	else if (Q == 1) {
		pair<int, int> Ans = IsDvdsExistInARow(A, B, 1, 0, firstLeafNodeIdx - 1);
		if (Ans.first == A && Ans.second == B) {
			cout << "YES" << '\n';
			return;
		}
		else
			cout << "NO"<<'\n';
	}
}

void Input() {
	int testCase=0,Q=0,A=0,B=0;
	segTree.resize(524288);
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> N >> K;
		while (firstLeafNodeIdx < N) firstLeafNodeIdx *= 2;
		//초기 세그먼트 트리 {-1,-1}로 세팅 
		fill(segTree.begin(), segTree.begin() + firstLeafNodeIdx * 2, BasePair);
		//초기에 i번째 dvd는 i번째 dvd가 꽂혀있으므로 초깃값 세팅 
		for (int j = 0; j < firstLeafNodeIdx; j++) {
			segTree[j + firstLeafNodeIdx] ={ j, j };

		}
		//조상노드들 세팅
		for (int j = 0; j < firstLeafNodeIdx; j++) {
			SetAncestorNode(j);
		}
		//쿼리값 받아서 처리 
		for (int j = 0; j < K; j++) {
			cin >> Q >> A >> B;
			Solution(Q, A, B);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
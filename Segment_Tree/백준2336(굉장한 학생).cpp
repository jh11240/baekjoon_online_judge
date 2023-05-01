#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//리프노드 구성은 한 학생의 두번째 시험등수가 index, 세번째 시험등수가 value 
int segTree[1'048'576];
int N,firstLeafNodeIdx=1,MAXINT = 1'000'000'000;
//학생마다 성적용 크기 3짜리 벡터 할당해줌 
vector<vector<int>> v;

void SetAncestorNode(int idx,int val) {
	int tmpIdx = idx + firstLeafNodeIdx;
	segTree[tmpIdx] = val;
	while (tmpIdx > 1) {
		tmpIdx /= 2;
		segTree[tmpIdx] = min(segTree[tmpIdx * 2], segTree[tmpIdx * 2 + 1]);
	}
}

int FindMin(int targetL, int targetR, int nodeNum, int curL, int curR) {
	if (targetL > curR || curL > targetR) return MAXINT;
	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];
	int mid = (curL + curR) / 2;
	return min(FindMin(targetL, targetR, nodeNum * 2, curL, mid), FindMin(targetL, targetR, nodeNum * 2 + 1, mid + 1, curR));
}

void Solution() {
	int result=0;

	//sort가 되어있는 상태이므로 v는 첫번째 시험의 등수로 정렬되어있다.
	for (int i = 0; i < N; i++) {
		//첫번째 시험등수로 정렬되어있으므로 이미 i번째학생이 첫번째 시험으로 이겨서\
		i번째 학생 뒤의 학생들은 i번째 학생보다 대단할수 없음.\
		따라서 i번째학생은 자신의 앞 순서의 학생들과 2번째 3번째를 비교해야함.\

		//따라서 자신의 두번째 시험 성적 보다 작은 index구간의 최소 등수값이 자신의 세번째 등수보다 크다면 자신은 굉장하다. 
		if (FindMin(0, v[i][1], 1, 0, firstLeafNodeIdx - 1) > v[i][2]) result++;
		//자신의 두번째 시험성수 index에 자신의 세번째 시험등수 value로 세그트리 업데이트해줌
		SetAncestorNode(v[i][1], v[i][2]);
	}
	cout << result;
}

void Input() {
	int tmpInput=0;
	cin >> N;
	//구간 최소합 트리이므로 제일 큰 숫자로(여기선 10억) 채워준다.
	fill(segTree, segTree + 1'048'576, MAXINT);
	//크기3의 벡터를 학생 수만큼 할당해준다.
	v.resize(N, vector<int>(3));
	//세그먼트 트리의 리프노드의 시작점을 구해준다.
	while (firstLeafNodeIdx < N) firstLeafNodeIdx *= 2;

	//시험 번호 0~2
	for (int i = 0; i < 3; i++) {
		//등수
		for (int j = 0; j < N; j++) {
			//학생 번호
			cin >> tmpInput;

			//학생번호(index라서 -1), 몇번째 시험, 등수
			v[tmpInput-1][i]=j;

		}
	}

	//첫번째 등수 기준으로 정렬 (어떤학생이 몇점맞았냐는 안중요하고 
	//성적이 굉장한 학생수만 중요하므로 학생순서가 섞여도 상관없다)
	sort(v.begin(), v.end());
	Solution();

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
// ///////////////////////////////////////////////////////// using segmentTree

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;
// int N,firstLeafNodeIdx=1;
// int segTree[262144];

// vector<pair<int, int>> v;

// //목표구간 [targetL,targetR]의 제일 긴 증가하는 부분수열값 찾는 재귀함수. 현재구간 [curL,curR]을 기준으로 찾아간다
// int FindLongestIncreasingSubsequence(int targetL, int targetR, int nodeNum, int curL, int curR) {
// 	if (targetR < curL || curR < targetL) return 0;
// 	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];

// 	int mid = (curL + curR) / 2;
// 	return max(FindLongestIncreasingSubsequence(targetL, targetR, nodeNum * 2, curL, mid), 
// 		FindLongestIncreasingSubsequence(targetL, targetR, nodeNum * 2 + 1, mid + 1, curR));
// }
// //idx의 조상노드들 전부 갱신해주는 함수
// void SetAncestorNode(int idx) {
// 	while (idx > 1) {
// 		idx /= 2;
// 		segTree[idx] = max(segTree[idx * 2], segTree[idx * 2 + 1]);
// 	}
// }

// void Solution() {
// 	int tmp = 0,result=0;
// 	//이미 값으로 정렬된 벡터를 순회
// 	for (auto iter : v) {
// 		//0부터 현재 값의 인덱스까지의 구간의 제일 긴 증가하는 부분수열에 +1을 해준다. 
// 		tmp = FindLongestIncreasingSubsequence(0, iter.second, 1, 0, firstLeafNodeIdx - 1)+1;
// 		//현재값의 인덱스값에 저장
// 		segTree[firstLeafNodeIdx + iter.second] = tmp;
// 		//지금까지 구한 제일 긴 증가하는 부분수열의 최대값을 result에 저장해줌.
// 		result = max(tmp, result);
// 		//현재 값의 인덱스의 조상노드들도 갱신해준다.
// 		SetAncestorNode(firstLeafNodeIdx + iter.second);
// 	}
// 	cout << N-result;
// }

// void Input() {
// 	int tmp = 0;
// 	cin >> N;
// 	while (firstLeafNodeIdx < N) firstLeafNodeIdx *= 2;
// 	for (int i = 0; i < N; i++) {
// 		cin >> tmp;
// 		v.push_back({ tmp,i });
// 	}
// 	//이문제에선 각 값이 겹치진 않으므로 따로 comp함수 안 짜도 됨.
// 	sort(v.begin(), v.end());
// 	Solution();
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	Input();
// }

// ///////////////////////////////////////////////////////// using BinarySearch

#include<iostream>
#include<vector>

using namespace std;
vector<int> v;

int BinarySearch(int elem) {
	int low = 0, high = v.size() - 1, mid = 0;
	//벡터내의 제일 작은값보다 작으면 바로 작은값 리턴
	if (v[low] >= elem)
		return low;

	//elem값보다 크거나 같은 값이 high,  elem값보다 작은 값이 low에 저장됨
	while (low+1 < high) {
		mid = (low + high) / 2;
		if (v[mid] < elem) low = mid;
		else high = mid;
	}

	return high;
}

void Input() {
	int N=0,tmp=0,tmpIdx=0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (i == 0 || v.back() < tmp) v.push_back(tmp);
		else {
			tmpIdx = BinarySearch(tmp);
			v[tmpIdx] = tmp;
		}
	}
	cout << N - v.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}

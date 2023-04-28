#pragma region using BinarySearch

// #include<iostream>

// using namespace std;
// //2^21
// //index는 맛의 순위, value는 갯수
// int segTree[2097152];
// int N, firstLeafNodeIdx=2097152/2;

// //[targetL, targetR]맛 구간의 사탕갯수의 합을 반환하는 함수
// int HowManyCandiesInTargetRange(int targetL, int targetR, int nodeNum, int curL, int curR) {
// 	if (targetL > curR || curL > targetR) return 0;
// 	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];
// 	int mid = (curL + curR) / 2;
// 	return HowManyCandiesInTargetRange(targetL, targetR, nodeNum * 2, curL, mid) +
// 		HowManyCandiesInTargetRange(targetL, targetR, nodeNum*2+1,mid+1,curR);
// }

// //세그트리의 idx+firstLeafNodeIdx 인덱스의 값을 변경 후 조상노드들도 변경 
// void SetAncestorNode(int idx,int val) {
// 	int tmpIdx = idx + firstLeafNodeIdx;
// 	while (tmpIdx > 0) {
// 		segTree[tmpIdx] += val;
// 		tmpIdx /= 2;
// 	}
// }

// //targetAmount 원하는 사탕 순위보다 구간합이 처음으로 커지는 index를 찾아서 반환
// int binarySearch(int targetAmount) {
// 	int low=0,high=1'000'000,mid = 0;
// 	//low 랑 high랑 1차이 나게 하려고 하다보니 index 0이 답일때 0을 반환못한다.
// 	if (segTree[firstLeafNodeIdx] >= targetAmount) return 0;
// 	while (low + 1 < high) {
// 		mid = (low + high) / 2;
// 		if (HowManyCandiesInTargetRange(0, mid, 1, 0, firstLeafNodeIdx - 1) < targetAmount) low = mid;
// 		else high = mid;
// 	}
// 	return high;
// }

// void Solution(int A, int B, int C=0) {

// 	if (A == 1) {
// 		int tmpIdx = binarySearch(B);
// 		//index는 0부터지만 사탕의 맛은 1부터
// 		cout << tmpIdx+1<<'\n';
// 		SetAncestorNode(tmpIdx,-1);
// 	}
// 	else {
// 		SetAncestorNode(B,C);
// 	}
// }
// void Input() {
// 	int A=0, B=0, C = 0;
// 	cin >> N;
// 	for (int i = 0; i < N; i++) {
// 		cin >> A;
// 		if (A == 1) {
// 			cin >> B;
// 			Solution(A, B);
// 		}
// 		else {
// 			cin >> B >> C;
// 			Solution(A, B - 1, C);
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	Input();
// }

#pragma endregion

#pragma region RecursiveSearch in Tree
 
#include<iostream>

using namespace std;
//2^21
//index는 맛의 순위, value는 갯수
int segTree[2097152];
int N, firstLeafNodeIdx=2097152/2;

//세그트리의 idx+firstLeafNodeIdx 인덱스의 값을 변경 후 조상노드들도 변경 
void SetAncestorNode(int idx,int val) {
	int tmpIdx = idx + firstLeafNodeIdx;
	while (tmpIdx > 0) {
		segTree[tmpIdx] += val;
		tmpIdx /= 2;
	}
}

//targetAmount 원하는 사탕 순위보다 구간합이 처음으로 커지는 index를 찾아서 반환
int SearchTasteIndex(int idx,int targetAmount) {
	if (idx >= firstLeafNodeIdx) return idx - firstLeafNodeIdx;
	int tmp = segTree[idx*2];
	//왼쪽자식의 노드값이 원하는 타겟보다 작거나 같으면 왼쪽자식으로 진행
	if (targetAmount <= tmp) return SearchTasteIndex(idx * 2, targetAmount);
	//오른쪽 자식 노드값이 원하는 타겟보다 크면 오른쪽 자식으로 진행
	//오른쪽으로 꺾으니 targetAmount 에서 왼쪽자식구간합인 tmp값을 빼줘야 원하는 구간합 탐색이 가능하다.
	else return SearchTasteIndex(idx * 2 + 1, targetAmount-tmp);
}

void Solution(int A, int B, int C=0) {

	if (A == 1) {
		//B개의 인덱스 찾기 
		int tmpIdx = SearchTasteIndex(1,B);
		//index는 0부터지만 사탕의 맛은 1부터
		cout << tmpIdx+1<<'\n';
		SetAncestorNode(tmpIdx, -1);
	}
	else {
		SetAncestorNode(B,C);
	}
}
void Input() {
	int A=0, B=0, C = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A == 1) {
			cin >> B;
			Solution(A, B);
		}
		else {
			cin >> B >> C;
			Solution(A, B - 1, C);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}

#pragma endregion
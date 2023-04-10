// ///////////////////////////////////////////////////////////////////////////using segmentTree 

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;
// //2^18
// int segTree[262144];
// vector<pair<int,int>> v;

// int N=0,firstLeafNodeIdx=1,tmp=0;

// bool comp(pair<int, int> a, pair<int, int> b) {
// 	if (a.first != b.first) return a.first < b.first;
// 	else
// 		//수가 같을땐 카운트 되지않게 인덱스 큰걸 앞으로 보냄. \
// 		lis는 수가 정렬되있을때 인덱스가 작은것에서 큰것으로 갈때 커지므로
// 		return a.second > b.second;
// }

// int FindLIS(int targetL, int targetR, int nodeNum, int curL, int curR) {
// 	if (targetR < curL || curR < targetL) return 0;
// 	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];
// 	int mid = (curL + curR) / 2;
// 	return max(FindLIS(targetL, targetR, nodeNum*2, curL, mid) , FindLIS(targetL, targetR, nodeNum*2+1, mid + 1, curR));
// }
// void setAncestorNode(int n) {
// 	while (n > 0) {
// 		segTree[n] = max(segTree[n * 2], segTree[n * 2 + 1]);
// 		n /= 2;
// 	}
// }

// void Solution() {
// 	int result=0;
// 	sort(v.begin(), v.end(), comp);
// 	// 값순으로 정렬된 벡터에서 해당 값들의 원래 인덱스를 순회하며, 
// 	//해당 인덱스까지의 최대 LIS값을 불러와 1을 더하는 방식
// 	for (auto iter : v) {
// 		tmp = FindLIS(0, iter.second, 1, 0, firstLeafNodeIdx - 1)+1;
// 		result = max(tmp, result);
// 		//segtree에서 주의할점 리프노드에 값넣을때 firstLeafNodeIdx를 꼭 더해야함 자꾸 빼먹음, 분할정복통해 트리 순회하는 함수에서 
// 		//두개 나눌때 nodeNum값을 2곱해주는걸 빼먹음 자꾸
// 		segTree[firstLeafNodeIdx+ iter.second] = tmp;
// 		setAncestorNode((firstLeafNodeIdx+iter.second)/2);
// 	}
// 	cout << result<<'\n';
// }

// void Input() {
// 	while (!cin.eof() ) {
// 		v.clear();
// 		fill(segTree, segTree + 262144, 0);
// 		if (!(cin >> N)) break;
// 		while (firstLeafNodeIdx < N) firstLeafNodeIdx *= 2;

// 		for (int i = 0; i < N; i++) {
// 			//segTree 리프노드 채워넣기
// 			cin >> tmp;	
// 			v.push_back({ tmp,i });
// 		}
// 		Solution();
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	Input();
// }


/////////////////////////////////////////////////////////////////////////// using binarySearch 
#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

//elem값보다 크거나 같은 v의 값중 인덱스 제일 작은값 반환 
int BinarySearch(int elem) {
	int low = 0, high = v.size() - 1, mid = 0;
	//만약 v에 원소 두개라면 밑의 while문을 통과를 못해서 따로빼기
	if (v.size() == 2) {
		if (elem <= v[low]) return low;
	}
	while (low + 1 < high) {
		mid = (low + high) / 2;
		if (v[mid] < elem) low = mid;
		//같거나 클때 high값에 mid를 넣는 식으로 high는 elem보다 크고 low는 elem보다 작게 형성
		else high = mid;
	}

	return high;
}

void Input() {
	int N=0,tmp=0,tmpIdx=0;
	while (cin >> N) {
		v.clear();
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			//처음 값이거나 v의 마지막값보다 tmp가 크면 push_back
			if (v.empty() || v.back() < tmp) v.push_back(tmp);
			else {
				//tmp보다 큰 인덱스값 tmpIdx에 저장
				tmpIdx = BinarySearch(tmp);
				//v[tmpIdx]에 tmp저장
				v[tmpIdx] = tmp;
			}
		}
		cout << v.size() << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
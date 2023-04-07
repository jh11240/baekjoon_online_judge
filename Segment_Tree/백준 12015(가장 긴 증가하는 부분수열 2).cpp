
// //////////////////////////////////////////////// using Binary Search
// #include<iostream>
// #include<vector>

// using namespace std;

// vector<int> v;

// int binarySearch(int elem) {
// 	int low = 0, high = v.size()-1,mid=0;
// 	while (low+1 < high) {
// 		mid = (low + high) / 2;
// 		if (v[mid] < elem) low = mid;
// 		else high = mid;
// 	}
// 	//v.size()가 2일경우 index 1의 원소를 바로 반환하는걸 방지하기 위함
// 	if (v[low] >= elem) {
// 		return low;
// 	}

// 	return high;
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	int N=0,tmp=0,idxToChange;
// 	cin >> N;
// 	for (int i = 0; i < N; i++) {
// 		cin >> tmp;
// 		//비어있거나 벡터의 끝값보다 이번 tmp값이 더 크다면 push_back
// 		if (i == 0 || v.back()<tmp)
// 			v.push_back(tmp);
// 		//아니라면 tmp값보다 크거나 같은 원소중 제일 인덱스 큰 원소를 tmp로 교체한다.
// 		else {
// 			idxToChange = binarySearch(tmp);
// 			v[idxToChange] = tmp;
// 		}
// 	}
// 	cout << v.size();
// }

//////////////////////////////////////////////// using Segment Tree 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//2^21
int segTree[2097152];
int N,firstLeafNodeIdx=1,largestIdx=0,lis=0;

//값, 인덱스
vector<pair<int,int>> v;

//벡터 v 정렬시 비교용 함수. 
bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.first != b.first) return a.first < b.first;
	//만약 중복값이면 인덱스 큰값을 앞으로 보내서 중복값일때 길이 증가하지 않도록 처리
	else return a.second > b.second;
}

//n번째 리프노드 값 k로 설정 후 , 조상 노드로 거슬러 올라가며 더큰값으로 갱신해주는 함수
void SetAncestorNode(int n,int k) {
	n += firstLeafNodeIdx;
	segTree[n] = k;
	while (n > 1) {
		n /= 2;
		segTree[n] = max(segTree[2 * n], segTree[2 * n + 1]);
	}
}

//[targetL,targetR]의 최대값을 구하는 함수 
long long Largest(int targetL, int targetR, int nodeNum, int curL, int curR) {
	if (curR < targetL || targetR < curL) return 0;
	if (targetL <= curL && curR <= targetR) return segTree[nodeNum];
	long long mid = (curL + curR) / 2;
	return max(Largest(targetL, targetR, nodeNum*2, curL, mid) , Largest(targetL, targetR, nodeNum*2+1, mid + 1, curR));
}

void ReadjustTree() {
	int tmp = 0,result=0;
	//정렬된 벡터에서 순회하며
	for (auto iter : v) {
		//tmp= 정렬된 벡터에서 순회하는 값의 현재 인덱스 
		tmp = Largest(0, iter.second, 1, 0, firstLeafNodeIdx - 1) + 1;
		result = max(result, tmp);
		//작은값부터 해당 인덱스 값에서 조상노드로 올라가며 갱신 
		SetAncestorNode(iter.second, tmp);

	}
	cout << result;
}

void Input() {
	int tmp;
	cin >> N;
	
	//firstLeafNodeIdx 구하기
	while (firstLeafNodeIdx < N) {
		firstLeafNodeIdx *= 2;
	}

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back({ tmp,i });
	}
	sort(v.begin(), v.end(), cmp);
	ReadjustTree();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();

}

#include<iostream>
#include<algorithm>

using namespace std;
//나무의 수, 가져가려하는 타겟 길이
int N, M;
//들어오는 나무 길이
int inputArr[1'000'000];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
	}
	//들어온값 정렬
	sort(inputArr, inputArr + N);
}

//middle길이로 잘랐을때 얼마나 가져갈수있는지 
long long cut(long long middle) {
	long long  sum = 0;
	for (int i = 0; i < N; i++) {
		if(inputArr[i] - middle>=0)
			sum += inputArr[i] - middle;
	}
	return sum;
}

//이분탐색 코드
void solution() {
	//조건을 만족하는 최대값 low, 조건을 불만족하는 최소값 high로 설정
	long long low = 0, high = inputArr[N-1];

	//1번 방법

	////low와 high가 1차이 날 때까지
	//while (low+1 < high) {
	//	//mid값은 low와 high더한값이 int값 넘어갈 수도 있으므로 long long으로 선언
	//	long long mid = (low + high) / 2;

	//	//mid값으로 잘랐을 때 타깃 길이인 M보다 같거나 크다면 low값을 mid로 변경해줌
	//	if (cut(mid) >= M) low = mid;
	//	//작다면 high값을 mid로 변경해주어 범위를 바꿔준다.
	//	else
	//		high = mid;
	//}
	//cout<<low;

	//2번 방법

	long long mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;

		if (cut(mid) >= M) low = mid+1;

		else
			high = mid-1;
	}

	cout << (low + high)/2;
	//cout<<high; 둘 다됨 어차피 cut(mid)=M다음 단계에선 cut(mid)<M이 되므로 high =mid-1이 실행되고 high값이 답이나옴.

}

int main() {
	input();
	solution();
}
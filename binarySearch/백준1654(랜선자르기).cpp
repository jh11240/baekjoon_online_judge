#include<iostream>

using namespace std;
int K, N, Max=0;
int inputArr[10001];

void input() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> inputArr[i];
		//제일 큰 입력값 얻기 -> high값에 쓸 것
		Max = Max > inputArr[i] ? Max : inputArr[i];
	}
}

void solution() {
	//high를 입력값의 최대값으로 정하면 안됨 low를 답으로 배출할텐데 high가 처음에 답이들어있으면 답을 못구함
	long long low = 0, high = 2'200'000'000, mid=0, tmpSum=0;
	while (low + 1 < high) {
		mid = (low + high) / 2;
		for (int i = 0; i < K; i++) {
			tmpSum += inputArr[i] / mid;
		}
		//자른 갯수가 N개보다 많다면 범위를 높여야하므로 
		if (tmpSum >= N) low = mid;
		else high = mid;
		tmpSum = 0;
	}
	cout << low;

}

int main() {
	input();
	solution();
}
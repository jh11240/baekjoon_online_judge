#include<iostream>
#include<algorithm>

using namespace std;

int N, C;
int inputArr[200'001];
int inputDiffer[200'001];

void input() {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
	}
	sort(inputArr, inputArr + N);
	for (int i = 0; i < N-1; i++) {
		inputDiffer[i]= inputArr[i+1] - inputArr[i];

	}
}

/// <summary>
/// mid값을 최대 인접거리로 정했을 때 설치한 공유기 갯수가 C개보다 많다면 true 반환, C개보다 적다면 false반환 
/// </summary>
/// <param name="mid"></param>
/// <returns></returns>
bool possible(int mid){
	//설치한 갯수, 부분합
	int amount=1,tmpSum=0;
	for (int i = 0; i < N; i++) {
		//tmpSum에 각 좌표차이값들 하나씩 더해준 후
		tmpSum += inputDiffer[i];
		//tmpSum이 mid값보다 커지면 공유기를 하나 설치해야함.
		if (tmpSum >= mid) {
			//공유기 하나 설치
			amount++;
			//설치갯수가 원하는 갯수보다 같거나 많다면 true반환-> low값 조정해서 mid값 올림
			if (amount >= C) {
				return true;
			}
			//부분합 초기화
			tmpSum = 0;
		}


	}
	//N개에 다 설치해도 C개보다 적다면 mid값 낮춰야하므로 false 반환해 high값 조정
	return false;
}

void solution() {
	int low = 0, high = 1'000'000'001,mid=0;
	while (low + 1 < high) {
		mid = (low + high) / 2;
		//최대값 맞춰야하므로 low값에 최대값이들어감 
		((possible(mid)) ? low : high) = mid;
	}
	cout << low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solution();
}
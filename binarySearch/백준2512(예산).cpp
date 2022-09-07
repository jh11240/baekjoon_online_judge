#include<iostream>
#include<algorithm>

using namespace std;
int N,target;
int dp[10'001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dp[i];
	}
	sort(dp, dp + N);
	cin >> target;
}

int cut(int middle) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (dp[i] >= middle) {
			sum += middle;
		}
		else {
			sum += dp[i];
		}
	}
	return sum;
}

void solution() {
	//low = 0, high = dp[N-1] 이런식으로 high값을 해당범위의 끝으로 잡으면 해당범위 끝이 답일때 그답-1이 답으로나옴
	int low = 0, high = 100'001,mid=0;
	//이렇게 구현하면 high가 엄청 큰값이 들어가도 cut에선 dp배열에 들어온 값들을 다 더해버리기만하므로 
	//high값이 그대로 답으로 나옴 low가 범위를 만족하는지 체크해야함 
	while (low + 1 < high ) 
	{
		if (cut(dp[N - 1]) <= target) {
			cout << dp[N - 1];
			return;
		}
		mid = (low + high) / 2;
		if (cut(mid) <= target) 
			low = mid;
		else
			high = mid;
		
	}
	cout << low;
}

int main() {
	input();
	solution();
}
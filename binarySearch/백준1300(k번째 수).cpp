#include<iostream>
#include<algorithm>

using namespace std;
long long N, K;

void input() {
	cin >> N >> K;
}
/// <summary>
/// mid값이 k번째보다 크면 mid줄여야하므로 high값 조절, k번째 보다 작으면 low값 조절
/// </summary>
/// <param name="mid"></param>
/// <returns></returns>
bool IsKthNum(long long mid) {
	if (mid > N * N) return false;
	long long tmpSum = 0,tmp=0;
	for (int i = 1; i <= N; i++) {
		//각 행 숫자로 mid값을 나누면 mid보다 작은 값이 몇개 있는지 알 수 있음
		//but, 만약 N이 4인데 mid가 10인경우에 2로 나눴을 땐 2x4에서 끝나는게 아니라 2x5까지 취급하게 되므로 비교해야함
		tmp = min((long long)N*i, mid);
		tmpSum += tmp / i;
		if (tmpSum >= K) return false;
	}
	return true;
}

void solution() {
	long long low = 0, high = 1'000'000'001, mid = 0;
	while (low + 1 < high) {
		mid = (low + high) / 2;
		(IsKthNum(mid) ? low : high) = mid;
	}
	//low출력으로 해버리면 i*j값을 안만족해도 그냥 ㅈ건에 맞으면 출력해버림
	//따라서 만족하는값중에 최소값을 찾아야하므로 high출력으로 변경
	cout << high;
}

int main() {
	input();
	solution();
}
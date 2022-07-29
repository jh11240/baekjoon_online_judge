//#include<iostream>								//3
//												// 동전 2와 같은 방법으로  dp를 시작위치와 타겟값 잡았는데
//												// dp[400][100'000]으로 하려다가 1억 6천만 바이트라서 그냥 포기했다.
//#include<algorithm>
//
////n번째 값에서 k^2
//int dp[100'000], amount = 0;
//using namespace std;
//
//void input() {
//	cin >> amount;
//}
//
////바텀업 방식
//void solution() {
//	for (int i = 1; i <= amount; i++) {
//	//각 dp[i]값엔 최대값인 i를 넣어준다.(1^2 i번 더했을때가 최대값 )
//		dp[i] = i;
//		//1부터 j*j<i를 만족하는 j값까지 dp[i]값과, dp[i-j*j]+1 값을 비교해서 저장(여기서 동전 2의 방식이 나옴 해당 값을 빼고 +1을 하는 방식)
//		for (int j = 1; j*j <= i; j++) {
//			dp[i] = min(dp[i], dp[i - j * j] + 1);
//		}
//	}
//	cout << dp[amount];
//}
//
//int main() {
//	input();
//	solution();
//}


//출처 https://github.com/kks227/BOJ/blob/master/1600/1699.cpp
//제곱수들을 다 만든 후 동전2 의 방식과 같은 탑다운 방식 

#include<iostream>
#include<algorithm>

using namespace std;
const int MAX = 317;
int square[MAX], dp[100'001][MAX],amount=0;

void input() {
	cin >> amount;
	for (int i = 0; i < MAX; i++) {
		square[i] = i * i;
	}
}

//탑다운 방식, n번째 제곱수를 이용해 target값을 만들기
int solution(int target, int n) {
	//만약 입력받은 값을 계속 줄여나가다가 0이나오면 0
	if (target == 0) return 0;
	//만약 위치값이 끝까지 가면 n을 return
	if (n == MAX - 1) return n;
	//ret값에 해당 dp값 참조시켜준다.
	int& ret = dp[target][n];
	//ret값이 이미 있을 경우 바로 return
	if (ret) {
		return ret;
	}
	ret = solution(target, n + 1);
	//ret값은  n+1에 해당하는 제곱수부터 target값을 만드는 경우의수와
	//n번째 제곱수를 하나 사용한 후 target-square[n]의 값을 만드는 경우의 수와 비교
	if(square[n]<=target) ret = min(ret, solution(target - square[n], n) + 1);
	return ret;

}

int main() {
	input();
	cout<<solution(amount, 0);
}
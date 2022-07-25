	#include<iostream>
	#include<vector>
	using namespace std;
	const int MAX = 10'000'000;

	vector<int> dp(MAX,MAX);

	//입력받는 함수
	void input(int& amount) {
		cin >> amount;
	}
	//////바텀 업 방식으로 배열을 채워넣기(O(N)의 시간복잡도/ 범위가 최대 10^6이라서 가능)
	////void solution(int& amount) {
	////	dp[0] = 0;
	////	dp[1] = 0;
	////	for (int i = 2; i <= amount; i++) {
	////		dp[i] = min(dp[i], dp[i - 1] + 1);
	////		//3으로 나눠 떨어질 시
	////		if (i % 3 == 0) dp[i] =min( dp[i / 3] + 1, dp[i]);
	////		//2로 나눠 떨어질 시
	////		if (i % 2 == 0) dp[i] =min( dp[i / 2] + 1,dp[i]);
	////	}
	////}


		////바텀 업 방식으로 배열을 채워넣기 2 (2나 3으로 나눠떨어질시 추가하는 방식이아니라 2랑 3을 곱해버린후 저장하고 나중에 비교)
		//void solution(int& amount) {
		//	dp[0] = 0;
		//	dp[1] = 0;
		//	for (int i = 1; i <= amount; i++) {
		//		//2나 3을 곱하고 저장하므로 1부터 시작, i+1값을 다룰수있는 이유는 2,3을 곱해서 저장했으므로 i+1값이 있을 수도 있음
		//		dp[i+1] = min(dp[i+1], dp[i] + 1);			
		//		//i값에 2를 곱한값이 범위를 넘지 않는다면 2곱한값이 저장된 값과 지금값+1값 비교
		//		if (i*2 <MAX) dp[i*2] =min( dp[i*2], dp[i]+1);
		//		//i값에 3를 곱한값이 범위를 넘지 않는다면 3곱한값이 저장된 값과 지금값+1값 비교
		//		if (i* 3<MAX) dp[i*3] =min( dp[i*3],dp[i]+1);
		//	}
		//}

	//탑다운 방식으로 구현 큰문제부터 쪼개나감
	int solution(int amount) {
		if (amount == 1) return 0;
		if (dp[amount] != MAX) return dp[amount];

		int Ans = solution(amount - 1) + 1;


		if (amount % 3 == 0) Ans = min(Ans, solution(amount / 3) + 1);
		if (amount % 2 == 0) Ans = min(Ans, solution(amount / 2) + 1);
		dp[amount] = Ans;
		return Ans;

	}

	int main() {
		int amount = 0;
		input(amount);

		//바텀업 방식 사용시
		//solution(amount);	
		//cout << dp[amount];

		//탑다운 방식 사용시
		int Ans = solution(amount);
		cout << Ans;
	}
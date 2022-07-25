#include<iostream>

using namespace std;
int dp[1001];
const int devideBy = 10'007;
void input(int& amount) {
	cin >> amount;
	dp[1] = 1;
	dp[2] = 2;
}
//2xn을 채우는 경우의수 F(n)이라하면 마지막 부분을 채울수있는 경우의 수는 1x2 하나채우는 경우인 F(n-1), 2x1두개로  채우는 경우 F(n-2)
//즉, 피보나치 수열이다.
void solution(int amount) {				
	for (int i = 3; i <= amount; i++)
		dp[i] = (dp[i - 1]%devideBy + dp[i - 2]%devideBy)%devideBy;
	cout << dp[amount];
}

int main() {
	int amount = 0;
	input(amount);
	solution(amount);

}
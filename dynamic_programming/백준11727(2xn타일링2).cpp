#include<iostream>

using namespace std;
int dp[1001];
const int devideBy = 10007;

void input(int& amount) {
	cin >> amount;
	dp[1] = 1;
	dp[2] = 3;

}
//F(n)을 2xn에 넣을수 있는 경우의수라고 했을때, 2x2하나 넣었을때 F(n-2), 2x1두개 넣었을때 F(n-2), 1x2하나 넣었을 때 F(n-1)
void solution(int& amount) {
	for (int i = 3; i <= amount; i++) {
		dp[i] = (dp[i - 1]%devideBy + 2*dp[i - 2]%devideBy)%devideBy;
	}
	cout << dp[amount];
}

int main() {
	int amount=0;
	input(amount);
	solution(amount);
}
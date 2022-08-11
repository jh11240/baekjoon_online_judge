#include<iostream>

using namespace std;
const int N = 1001;
const int K = 1001;
const int MOD = 10'007;
int dp[N][K],inputN=0,inputK=0;

void input() {
	cin >> inputN>>inputK;
}
void solution() {

	dp[1][1] = 1;
	dp[1][0] = 1;

	//n은 2부터 inputN까지
	for (int i = 2; i <= inputN; i++) {
		//k는 0부터 n까지
		for (int j = 0; j <= i; j++) {
			//k==0이거나 n==k이면 1 넣어줌
			if (j == 0 || j==i) {
				dp[i][j] = 1;
				continue;
			}
			//아니라면 nCr= n-1Cr + n-1Cr-1 공식에 따라 넣어줌,
			dp[i][j] = (dp[i-1][j]%MOD + dp[i-1][j-1]%MOD) % MOD;
		}
	}
	cout << dp[inputN][inputK];
}

int main() {
	input();
	solution();
}
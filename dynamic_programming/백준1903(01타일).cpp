#include<iostream>
#include<memory.h>

using namespace std;
const int MAX = 1'000'001;
const int devideBy = 15746;
long long dp[MAX];
void input(int& amount) {
	cin >> amount;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
}

void solution(int amount) {	//답이 피보나치 수열로 나온다. 1/  00 11/ 100 001 111/ 1100 0011 1001 1111 0000 / https://www.acmicpc.net/board/view/84734 
									//틀렸습니다가 떠서 찾아보니 재귀를 너무 깊게해버려서 1만 부근부터는 답도 안나온다.  
									//너무 깊은 재귀일때는 바텀업을 고려!
	
	for (int i = 3; i <= amount; i++) {
		dp[i] = (dp[i - 1]%devideBy + dp[i - 2]%devideBy)%devideBy;
	}
	cout << dp[amount];
}


int main() {
	
	int amount = 0;
	input(amount);
	solution(amount);
}	
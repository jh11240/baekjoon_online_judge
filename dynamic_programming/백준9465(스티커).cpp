#include<iostream>
//dp배열
int inputArr[2][100'000],dp[100'00][3],Ans=0;
using namespace std;

void solution(int& amountArr);

void initDp(int& amountArr) {
	for (int i = 0; i < amountArr; i++) {
		inputArr[0][i] = inputArr[1][i] = 0;
	}
	for (int i = 0; i < amountArr; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = 0;
	}
}

void input() {
	int amount = 0,amountArr=0;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> amountArr;
		for (int j = 0; j < amountArr; j++) {
			cin>>inputArr[0][j];
		}
		for (int j = 0; j < amountArr; j++) {
			cin >> inputArr[1][j];
		}
		solution(amountArr);
		initDp(amountArr);
	}

}

//before은 전에 넣은 값이 0이면 안뜯은거/ 1이면 위에 뜯은거/ 2면 아래 뜯은거
void solution(int& amountArr) {
	//첫번째에서 아무것도 안골랐을때
	dp[0][0] = 0;
	dp[0][1]=inputArr[0][0];
	dp[0][2]=inputArr[1][0];
	for (int i = 1; i < amountArr; i++) {
		dp[i][0] += dp[i - 1][0] + max(inputArr[0][i], inputArr[1][i]);
		dp[i][1] += dp[i-1][2]+inputArr[0][i];
		dp[i][2] += dp[i-1][1]+inputArr[1][i];
	}
	 int ans=max(dp[amountArr-1][0],max(dp[amountArr-1][1],dp[amountArr-1][2]));
	 cout << ans<<'\n';
}

int main() {
	input();
}
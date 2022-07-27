//#include<iostream>										//3
////dp배열
//int inputArr[2][100'001], dp[100'001][3], Ans = 0;
//using namespace std;
//
//void solution(int& amountArr);
//
//void initDp(int& amountArr) {
//	for (int i = 0; i < amountArr; i++) {
//		inputArr[0][i] = inputArr[1][i] = 0;
//	}
//	for (int i = 0; i < amountArr; i++) {
//		dp[i][0] = dp[i][1] = dp[i][2] = 0;
//	}
//}
//
//void input() {
//	int amount = 0, amountArr = 0;
//	cin >> amount;
//	for (int i = 0; i < amount; i++) {
//		cin >> amountArr;
//		for (int j = 0; j < amountArr; j++) {
//			cin >> inputArr[0][j];
//		}
//		for (int j = 0; j < amountArr; j++) {
//			cin >> inputArr[1][j];
//		}
//		solution(amountArr);
//		initDp(amountArr);
//	}
//
//}
//
////before은 전에 넣은 값이 0이면 안뜯은거/ 1이면 위에 뜯은거/ 2면 아래 뜯은거
////처음엔 이런식으로 짜서 그냥 값이 지그재그 모양 더한 값 하나만 나옴
//// dp[i+1][1] += dp[i][2] + inputArr[0][i];
////dp[i + 1][2] += dp[i][1] + inputArr[1][i];
//
//void solution(int& amountArr) {
//
//	for (int i = 0; i < amountArr; i++) {
//		dp[i+1][0] = max(dp[i][0],max(dp[i][2],dp[i][1]) );
//		dp[i+1][1] = max(dp[i][2],dp[i][0]) + inputArr[0][i];
//		dp[i+1][2] = max(dp[i][1],dp[i][0]) + inputArr[1][i];
//	}
//	int ans = max(dp[amountArr ][0], max(dp[amountArr ][1], dp[amountArr][2]));
//	cout << ans << '\n';
//}
//
//int main() {
//	input();
//}

#include<iostream>

using namespace std;

int inputArr[2][100'001], dp[100'001][3], Ans = 0;

int solution(int current, int before,int amountArr);

void initDp(int& amountArr) {
	for (int i = 0; i < amountArr; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = -1;
	}
}

void input() {
	int amount = 0, amountArr = 0;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> amountArr;
		for (int j = 0; j < amountArr; j++) {
			cin >> inputArr[0][j];
		}
		for (int j = 0; j < amountArr; j++) {
			cin >> inputArr[1][j];
		}
		//dp 초기화
		initDp(amountArr);
		cout<<solution(0,0,amountArr)<<'\n';
	}
}
//current열부터 땠을 때 최대값, before이 0이면 current-1열에서 아무것도 안 뗀 것, 1이면 윗값 뗀 것, 2이면 아랫값 뗀 것 
int solution(int current, int before, int amountArr) {
	//current열이 최종값에 다다르면 return 0 해주기
	if (current == amountArr) return 0;
	//배열에 저장해놔서 다시 계산 안하도록
	if (dp[current][before] != -1) return dp[current][before];
	//ans는 before이 0일 때로 초기화
	int ans = solution(current + 1, 0, amountArr);

	//만약 before이 0이나 2라면
	if (before != 1) {
		//c+1열에서 before이 0일 때와, before이 2일 때 비교 해서 더 큰 값 저장
		ans = max(ans, solution(current + 1, 1, amountArr) + inputArr[0][current]);
	}
	//만약 before이 0이나 1이라면
	if (before != 2) {
		//c+1열에서 before이 0이거나 1일때 비교해서 더 큰 값 저장
		ans = max(ans, solution(current + 1, 2, amountArr) + inputArr[1][current]);
	}
	//dp배열에 저장해놓기
	dp[current][before] = ans;
	//ans return
	return ans;
}


int main() {
	input();
}
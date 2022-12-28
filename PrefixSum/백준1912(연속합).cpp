////////////////// dp방식 이용
// #include<iostream>
// #include<algorithm>

// using namespace std;
// int inputArr[100'001];
// bool isAllElemNeg = true;

// void Input() {
// 	int N = 0, maxSum = -1'000'000,tmpSum=0,maxInt=-1001;
	
// 	cin >> N;
//     //입력을 받으면서 동시에 모든 원소가 음수인지 체크 및 제일 큰 원소 저장하기
// 	for (int i = 0; i < N; i++) {
// 		cin >> inputArr[i];
// 		if (inputArr[i] > 0) isAllElemNeg = false;
// 		maxInt = maxInt > inputArr[i] ? maxInt : inputArr[i];
// 	}
    
//     //모든 원소가 음수값일 시
// 	if (isAllElemNeg) {
// 		//제일큰값이 답
// 		maxSum = maxInt;
// 	}
//     //음수값이 아닐 시
// 	else
// 		for (int i = 0; i < N; i++) {
// 			tmpSum += inputArr[i];
// 			//음수가되면 0으로 초기화 
// 			if (tmpSum < 0) tmpSum = 0;
// 			//각 반복마다 maxSum 갱신해주기
// 			maxSum = max(tmpSum, maxSum);
// 		}
// 	cout << maxSum;
// }



// int main() {
// 	Input();
// }

///////////////////////////////////////// dp방식 이용
#include<iostream>
#include<algorithm>

using namespace std;
int dp[100'002];
int N = 0, maxSum = -1'000'001;

void Input() {
	int inputInt=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inputInt;
		//dp[i+1]에는 (i번째 dp값인 dp[i]+ i번째 입력값 )과 i번째 입력값을 비교해 더 큰값이 들어감,
		dp[i + 1] = max(dp[i] + inputInt, inputInt);
		//최대값 갱신
		maxSum = maxSum > dp[i + 1] ? maxSum : dp[i + 1];
	}
	cout << maxSum;
}



int main() {
	Input();
}

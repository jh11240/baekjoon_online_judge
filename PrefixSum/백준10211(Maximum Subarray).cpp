/////////////////////////////////////////////////////////////// brute-force방식
// #include<iostream>

// using namespace std;
// int inputArr[1001];
// int Sum[1002];
// int T = 0, N = 0;

// //0부터 N까지의 index내에서 최대 부분배열 찾는 함수
// int Solution() {
// 	if (N == 1) return Sum[1];
// 	//싹다 음수일수도있으므로 최소값 0으로 잡으면 안 될듯
// 	int maxSum= -1'000'001;
// 	// 첫번째 원소를 포함헤야하므로 0부터 시작해서 인덱스N까지 포함해야함 
// 	for (int i = 0; i < N; i++) {
// 		for (int j = i+1; j < N+1; j++) {
// 			maxSum = maxSum> Sum[j] - Sum[i]? maxSum: Sum[j]-Sum[i];
// 		}
// 	}
// 	return maxSum;
// }

// void Input() {
// 	cin >> T;
// 	for (int i = 0; i < T; i++) {
// 		cin >> N;
// 		for (int j = 0; j < N; j++) {
// 			cin >> inputArr[j];
// 			//Sum[i+1]배열은 i번째 까지의 합 
// 			Sum[j + 1] = Sum[j] + inputArr[j];
// 		}
// 		cout<<Solution()<<'\n';
// 	}
// }



// int main() {
// 	Input();
// }

////////////////////////////////////////////////////////////// 테케당 O(N)의 시간복잡도로 가능한

// #include<iostream>

// using namespace std;
// int inputArr[1001];
// int T = 0, N = 0;
// //모든 원소 음수인지
// bool isAllElemNeg = true;

// //0부터 N까지의 index내에서 최대 부분배열 찾는 함수
// int Solution() {
// 	//싹다 음수일수도있으므로 최소값 0으로 잡으면 안 될듯
// 	int maxSum= -1'000'001, tmpSum=0;
// 	if (isAllElemNeg) {
// 		for (int i = 0; i < N; i++) {
// 			maxSum = maxSum > inputArr[i] ? maxSum : inputArr[i];
// 		}
// 	}
// 	else {
// 		// 어차피 연속된 합이 음수가 아닌이상 최대값임 
// 		for (int i = 0; i < N; i++) {
// 			tmpSum += inputArr[i];
// 			//만약 더했는데 음수가나오면 최대값이 될수없으므로 0으로 초기화
// 			if (tmpSum < 0) tmpSum = 0;
// 			//매번 비교해서 최대값 갱신 
// 			maxSum = maxSum > tmpSum ? maxSum : tmpSum;
// 		}
// 	}
// 	return maxSum;
// }

// void Input() {
// 	cin >> T;
// 	for (int i = 0; i < T; i++) {
// 		isAllElemNeg = true;
// 		cin >> N;
// 		for (int j = 0; j < N; j++) {
// 			cin >> inputArr[j];
// 			if (inputArr[j] > 0) isAllElemNeg = false;
// 		}
// 		cout<<Solution()<<'\n';
// 	}
// }



// int main() {
// 	Input();
// }

////////////////////////////////////////////////////////////////////dp 방식을 통한
#include<iostream>
#include<algorithm>

using namespace std;
int dp[1002];
int T = 0, N = 0, maxSum = -1'000'001,inputInt=0;

void Input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		maxSum = -1'000'001;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> inputInt;
			//이전값까지의 최대값+ 이번 원소와 이번원소를 비교해서 더 큰 값 저장
			dp[j + 1] = max(dp[j] + inputInt, inputInt);
			//최대값 비교 
			maxSum = max(maxSum, dp[j + 1]);
		}
		cout<<maxSum<<'\n';
	}
}



int main() {
	Input();
}
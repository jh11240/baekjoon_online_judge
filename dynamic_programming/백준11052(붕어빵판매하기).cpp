//#include<iostream>							//3 동전2 방식을 고집해서 dp배열을 2차원으로 만들려고 억지를 부리다 보니 dp[n번째 ][ 지금까지 산 카드 갯수]이렇게
//											// 짜다보니 n이 amount이상일때 지금까지 산 카드갯수가 0일때 뭘 return해야하는지 정확히몰라서 해메다가 인터넷 찾아봄
//#include<algorithm>
//
//using namespace std;
//
//const int MAX = 1001;
////i번째, amount
//int dp[MAX]	,arr[MAX], amount = 0;
//
//void input() {
//	int temp = 0;
//	cin >> amount;
//	for (int i = 1; i <= amount; i++) {
//		cin >> arr[i];
//	}
//	for (int i = 0; i < MAX; i++) {
//		dp[i] = -1;
//	}
//}
//
//
////n번째갯수일 때 지불해야할 최댓값
//int solution(int n) {
//	//0개일땐 지불값이 0
//	if (n == 0) return 0 ;
//	//ret변수에 dp배열참조
//	int& ret = dp[n];
//	//이미 구했따면 바로 return
//	if (ret != -1) return ret;
//
//	//ret 초기화
//	ret = 0;
//	//ret값은 각 i개에 대해 카드i개의 가격+ n-i+1개의 카드를 사용했을때 최댓값을 다 비교해서 넣어준다.
//	for (int i = 1; i <= n; i++) {
//		//i는 몇개의 갯수 인지. n-i+1은 i개의 갯수를 뺐을때의 
//		ret = max(ret, arr[i] + solution(n - i));
//	}
//	return ret;
//}
//
//
//int main() {
//	input();
//	int Ans = solution(amount);
//	cout << Ans;
//}

#include<iostream>							
#include<algorithm>

using namespace std;

const int MAX = 1001;
//i번째, amount
int dp[MAX]	,arr[MAX], amount = 0;

//입력받는 함수
void input() {
	int temp = 0;
	cin >> amount;
	for (int i = 1; i <= amount; i++) {
		cin >> arr[i];
	}
}

//dp배열 바텀업 방식으로 쌓고 답 출력하는 함수
void solution() {
	
	for (int i = 1; i <= amount; i++) {
		//각 dp[i]에는 i개들어있는 카드팩 샀을 때의 값어치로 초기화해줌
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			//그후 dp[i]와 
			//1개 들어있는 카드팩을 샀을 때의 최대값부터 i-1개 카드팩을 샀을 때의 최댓값을 구해 비교한다.
			dp[i] = max(dp[i], arr[j]+dp[i-j]);
		}
	}
	//답 출력
	cout << dp[amount];
}

int main() {
	input();
	solution();
}
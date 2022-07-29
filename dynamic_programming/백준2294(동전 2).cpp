////동전의 금액이 배수관계가아니면 그리디로 불가능 dp로 해야함 //3
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
// //당연한 소리지만 impossible값은 제일 큰값을 해야 조건에 부합하지 않는 값들은 line42 min함수에서 걸러진다. 
// //작게 만들면 min값에서 답이 impossilble로 고정되어서 return되서 무조건 임파서블만 뜬다
//const int impossible = +9'999'999;
//
////입력받을 배열, 최소값 저장 할 배열
////dp[n][k]
//int inputArr[101],dp[101][10'001];
//int amount = 0, target = 0;
//void input() {
//	cin >> amount >> target;
//	for (int i = 0; i < amount; i++) {
//		cin >> inputArr[i];
//	}
//
//	//dp값 -1로 초기화
//	for (int i = 0; i <= amount; i++) {
//		for (int j = 0; j <= target; j++) {
//			dp[i][j] = -1;
//		}
//	}
//}
////dp 배열의 열값으로 이값을 넣었을때 안넣었을 때, 
////바텀업으로 할시 궁금한점은 dp배열의 열값이 0이면 이값을 안쓸때 최소값, 1이면 이 값을 쓸때 최소값인데 
////target처리를 어떻게 하는지 궁금하다. 썼을때 target이랑 안썼을때 target을 어떻게 나누는지 모르겠다.
//
////탑-다운, current부터 끝까지, target을 만드는 경우의 수 
//int solution(int current,int target) {
//	//정상적으로 출력할 수 있다면 0 return
//	if (current == amount && target==0) return 0;
//	//정상적으로 출력할 수 없다면 impossible return
//	if (current == amount && target != 0) {
//		return impossible;
//	}
// //이미 구한 값이면 바로 return
//	if (dp[current][target] != -1) return dp[current][target];
//	 
//	int ans = solution(current+1,target);
//	//만약 current번째의 동전을 넣을 수있다면, ans값은 current번째의 동전을 제외한 나머지 동전으로 target값 만든 경우의 수와, current번째 동전을 사용했을 때의 경우의 수를 비교한다.
// //solution(current, target-inputArr[current])+1의 의미는 current번째 동전을 하나 사용한 경우로 
// //(current번째 동전부터  target - inputArr[current]의 값어치를 만드는 경우의수 + 이미 하나 사용했으므로 +1)의 의미다.
//	if (target >= inputArr[current]) ans = min(ans, solution(current, target - inputArr[current]) + 1);
//
//	dp[current][target] = ans;
//	return ans;
//	
//}
//
//int main() {
//	input();
//	
//	int ans=solution(0, target);
//	if (ans == impossible) cout << -1;
//	else cout << ans;
//}

//바텀업 방식
#include<iostream>
#include<algorithm>

using namespace std;

const int impossible = +9'999'999;

//입력받을 배열, 최소값 저장 할 배열
//dp[n][k]
int inputArr[101],dp[101][10'001];
int amount = 0, target = 0;
void input() {
	cin >> amount >> target;
	for (int i = 0; i < amount; i++) {
		cin >> inputArr[i];
	}

	//dp값 impossible로 초기화
	for (int i = 0; i <= amount; i++) {
		for (int j = 0; j <= target; j++) {
			dp[i][j] = impossible;
		}
	}
}

//바텀업 방식은 탑다운과는 다르게 n까지의 갯수에서 k를 만드는 경우의 수
void solution() {
	dp[0][0] = 0;

	//각 i번째 동전에서
	for (int i = 0; i < amount; i++) {
		dp[i][0] = 0;
		//j는 타겟
		for (int j = 0; j <= target; j++) {
			//i+1번째 동전 썼을때 j를 만들 경우의 수는 i번째 동전 써서 j만들 경우의 수와 비교해서 더 작은 값 넣어줌
			dp[i + 1][j] = min(dp[i+1][j],dp[i][j]);
			//tempTarget에 j+ i번째 동전 값 
			int tempTarget = j + inputArr[i];
			//만약 i번쨰 동전을 더할수 있는 경우라면, i번째 동전썼을때 temptarget값 만들 경우의 수는 i번째 동전 써서 j값 만들 경우의수 +1값과 비교해서 넣어준다.
			//min(dp[i][tempTarget], dp[i][j] + 1)는 
			//i개의 동전으로 temptarget을 만들때의 경우의 수와 
			//i개의 동전으로 j를 만들때의 경우의수 에서 inputarr[i]의 동전을 하나 사용했을때의 경우의수를 비교해서 더 작은값을 넣어준다.
			if (tempTarget <= target) dp[i][tempTarget] = min(dp[i][tempTarget], dp[i][j] + 1);
		}
	}
}
int main() {
	input();
	solution();
	if (dp[amount - 1][target] == impossible) cout << -1;
	else cout << dp[amount - 1][target];
}
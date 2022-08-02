#include<iostream>
#include<vector>

using namespace std;
vector<int> v(91,0);
long long dp[91][2];

void input(int& amount) {
	cin >> amount;

	//초기화 
	for (int i = 1; i <= 90; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
}

////전의값이 1인지 0인질 알아야해서 탑다운이 더 간편할듯
////총 amount, 지금 인덱스, 전에 끝이 0인지 1인지
////!!! 시간 초과 버전
//void solution(int amount,int current,int before) {;
//	if (current > amount) return;
//
//	if (before == 0) {
//
//		v[current] += 2;
//		solution(amount, current + 1, 0);
//		solution(amount, current + 1, 1);
//	}
//	else if (before == 1) {
//
//		v[current] += 1;
//		solution(amount, current + 1, 0);
//	}
//
//}

//->위의 함수 바텀업으로 구현, 2차원 배열쓰기

//void solution(int amount) {
//	dp[1][0] = dp[1][1] = 1;
//	for (int i = 2; i <= amount; i++) {
//		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
//		dp[i][1] = dp[i - 1][0];
//	}
//}


////총 길이, 맨 처음 값 - > 어차피 시간초과
//int solution(int length, int first) {
//	if (length == 2) return 1;
//
//	int zero = solution(length - 1, 0);
//	int one = solution(length - 1, 1);
//
//	if (first == 0) return zero + one;
//	else return zero;
//}

//->위의 함수 탑다운으로 구현,
long long solution(int length, int first) {	// 출처 https://www.acmicpc.net/board/view/7686
	//ret에 참조자를 안쓰면 시간 초과가 난다. ->참조자나 포인터를 안쓰면 당연히 dp배열에 값이 저장이 안되므로 dp의 개념이아니라 단순재귀라서 시간초과
	/*그리고 사실 int형 변수 하나의 메모리할당과 값복사는 시간이 거의 들지 않습니다.

		제 생각에 저 차이로 인해 시간차이가 발생한 이유는 캐시 hit에 의한것으로 생각됩니다.

		위에 언급한대로 O2 최적화를 통해 레퍼런스 변수는 b로 치환이 되어 사용됩니다.따라서 b의 주소가 CPU의 캐시에 등록되어있다면

		b를 접근할 때마다 계속 hit가 발생하여 성능이 향상될 것입니다.

		하지만 레퍼런스가 아닌 일반 변수를 통해 값을 복사했다면, b를 접근할 경우와 a를 접근할 경우 두 변수의 메모리 공간이 다르기 때문에 캐시 hit fail이 발생할 수 있습니다.

		이 차이가 성능에 영향을 미치고 있다고 생각됩니다.*/
	//-> dp배열이 전역변수로 할당되었으므로 저글의 cache 언급처럼 접근할때마다 hit가 발생해 빨라짐
	long long& ret = dp[length][first];			
	if (ret != -1) return ret;
	if (length == 1) return 1;
	if (first == 0) ret= solution(length - 1, 0) + solution(length - 1, 1);
	else ret=solution(length - 1, 0);

	return ret;

}

int main() {
	int amount=0,Ans=0;
	input(amount);
	//solution(amount);
  //1로 계산하는 이유는 맨처음은 무조건 1로시작하무로
	//cout << dp[amount][1];

	//마찬가지로 1로 계산하는 이유는 1로 시작하므로 
	long long ans = solution(amount, 1);
	cout << ans;
}

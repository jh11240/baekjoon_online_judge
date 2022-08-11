#include<iostream>

//배열 최대값
const int MAX = 100;
//나눌 값
const int MOD = 1'000'000'000;
using namespace std;
int dp[10][MAX],amount=0;

void input() {
	cin >> amount;
}


//앞자리 first일때, n번째부터 끝자리까지의 최댓값 
int solution(int first, int n)
{
	//만약 n이 끝 값이면 끝값부터 끝값의 계단수는 first값 하나이므로 1을 return
	if (n==amount-1) return 1;

	//ret값에 dp값 참조
	int& ret = dp[first][n];
	//이미 ret값 존재시 return ret
	if (ret != 0) return ret;

	//만약 first값이 0보다 클때 first-1으로 시작하고 n+1부터 끝까지의 최댓값 ret값에 더해줌
	if (first > 0) {
		ret += solution(first-1,n+1);
		ret %= MOD;
	}
	//first값이 9보다 작을때 first+1로 시작하고 n+1부터 끝까지의 최대값을 ret에 더해줌
	//if문을 두 번 씀으로써 자연스럽게 0과 9가 아닌값은 두번 통과하게되고, 0과 9는 한번씩 연산이 되게끔 한다.
	if (first < 9) {
		ret += solution(first + 1, n + 1);
		ret %= MOD;
	}
	return ret;
}

int main() {
	int sum = 0;
	input();
	for (int i = 1; i < 10; i++) {
		sum += solution(i,0);
		sum %= MOD;
	}
	cout << sum;

}
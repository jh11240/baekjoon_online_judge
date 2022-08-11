#include<iostream>

//배열 최대값
const int MAX = 1000;
//나눌 값
const int MOD = 10'007;
using namespace std;
int dp[10][MAX],amount=0;

void input() {
	cin >> amount;
}


//앞자리 first일때, n번째부터 끝자리까지의 최댓값 
int solution(int first, int n)
{
	//만약 n이 끝 값이면 끝값부터 끝값의 오르막 수는 first값 하나이므로 1을 return
	if (n==amount-1) return 1;

	//ret값에 dp값 참조
	int& ret = dp[first][n];
	//이미 ret값 존재시 return ret
	if (ret != 0) return ret;

	//9보다 작은 값은  n+1부터 끝까지 범위면서 맨 앞 수가 first+1인 오르막수를 ret값에  추가로 더해준다,
	if (first < 9) {
		int temp = first;
		//하지만 오르막 수는 해당 first값부터 9까지 조사해야하므로 반복문을 이용해 추가로 더 조사한다.
		while (temp < 9) {
			ret += solution(temp + 1, n + 1);
			ret %= MOD;
			temp++;
		}
	}
	//first값과 같아도 오르막 수가 가능하므로  n+1부터 끝까지 범위면서 맨 앞 수가 first인 오르막 수를 ret값에 더해준다
	ret += solution(first, n + 1);
	ret %= MOD;

	return ret;
}

int main() {
	int sum = 0;
	input();
	for (int i = 0; i < 10; i++) {
		sum += solution(i,0);
		sum %= MOD;
	}
	cout << sum;

}
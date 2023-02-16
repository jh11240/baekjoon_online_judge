#include<iostream>
#include<map>
#include<math.h>
using namespace std;
long long int N;
int P, Q;
//일반 배열로 dp처럼 풀기엔 10^12* 8 바이트 크기를 못 감당함 
//하지만 map을 사용해 값을 넣어주는 식으로하면 실제 저장할 값이 몇 안되어서 풀기 가능하다
map<long long, long long> dp;
void Input() {
	cin >> N >> P >> Q;
	dp[0] = 1;
}

long long returnValueA(long long n) {
	if (dp[n]) return dp[n];	
	long long devidedByP = returnValueA(n / P);
	long long devidedByN = returnValueA(n / Q);
	dp[n] = devidedByP + devidedByN;
	return dp[n];
}

int main() {	
	ios_base::sync_with_stdio(0);
	Input();
	cout << returnValueA(N);
}
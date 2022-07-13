#include<iostream>									//

using namespace std;

void input(int& A,int& B,int& C) {					//입력받는 함수
	cin >> A >> B >> C;
}
long long Solution(int A,int B,int C) {				//재귀를 통해 계산해서 return 하는 함수

	if (B == 1) return A % C;						//제곱수가 1이면 A return

	long long temp = Solution(A, B / 2, C) % C;		//미리 temp로 Solution(A,B/2,C)%C를 정의해야 빠르다. return Solution(A,B/2,C)%C*Solution(A,B/2,C)%C
													//이런식으로 return하면 함수를 계속 호출하게되서 시간 초과난다.

	if (B % 2 == 0)									//제곱수가 짝수일땐 A^(B/2)의 제곱 연산을 재귀를 통해 하면되고
		return temp * temp % C;
	else
		return  temp * temp % C* (A % C);			//제곱수가 홀수라면 A^(B/2)의 제곱연산을 한후 A를 하나 더 곱해야한다.
													//A%C를 앞에 계산 시 A%C *temp*temp를 먼저 계산하게 된후 %C연산을 하므로
													//%C연산을 하기전에 long long범위를 넘어갈수 있다. 
}

int main() {
	int A, B, C;
	input(A,B,C);
	int ans = Solution(A,B,C)%C;
	cout << ans;
}
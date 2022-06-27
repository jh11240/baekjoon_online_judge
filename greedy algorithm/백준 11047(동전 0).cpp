#include<iostream>
#include<vector>
using namespace std;

vector<int> coins;						//동전 가치 입력받는 벡터
	
void input(int& N,int& K) {				//입력받는 함수
	int tempInput = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin>>tempInput;
		coins.push_back(tempInput);
	}
}
void solution(int& N, int& K) {			//값 도출하는 함수
	int ans = 0;						//답
	for (int i = N - 1; i >= 0;i--) {	//오름차순으로 입력값이 들어왔으므로 제일 큰값부터
		if (K / coins[i] != 0) {		//제일 큰값과 나눳을때 0이아니라면
			ans += K / coins[i];		//나눈값을 답에 더해주고
			K %= coins[i];				//나머지값을 K에 저장
			if (K == 0) {				//나머지값이 0이란것은 동전으로 다 채운것이므로
				cout << ans;			//답 출력후 return
				return;
			}
		}
	}
}

int main() {
	int N= 0, K = 0;
	input(N, K);
	solution(N, K);
}

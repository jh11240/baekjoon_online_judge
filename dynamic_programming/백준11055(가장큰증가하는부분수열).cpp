#include<iostream>
#include<memory.h>

using namespace std;
int amount = 0, dp[1001], inputArr[1001];

void input() {
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> inputArr[i];
	}
	memset(dp, -1, sizeof(dp));
}

//pos위치부터 끝까지의 값중 최대 길이 수열의 합 return
int solution(int pos) {
	//끝에 다다르면 1 return
	if (pos == amount) return 1;
	//dp배열값 참조
	int& ret = dp[pos];
	//이미 구해놓은 값이면 그 값 반환
	if (ret != -1) return ret;
	
	//0으로 초기화
	ret = 0;
	//pos부터 끝까지의 원소를 다 비교해 더 큰값이 있다면 
	//해당 값에서 다시 solution함수 호출해서 제일 큰값을 ret에 넣음
	for (int i = pos; i < amount; i++) {
		if (inputArr[pos] < inputArr[i]) ret = max(ret, solution(i));
	}

	//여기서 sum을 어떻게 반환할까 고민하다가 그냥 ret자체를 return햇는데 그냥 각 값을 더하면 되는거군
	return ret+=inputArr[pos];
}

int main() {
	input();
	//solution함수에서 비교하는 값을 들여다보면 해당 pos값부터 무조건 시작하게 짜여있어서 모든 pos값에 대해 해봐야함
	int ans=0;
	for(int i=0;i<amount;i++)
	ans = max(ans,solution(i));
	cout << ans;
}
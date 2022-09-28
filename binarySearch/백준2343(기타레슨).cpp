#include<iostream>

using namespace std;
int N, M,Sum=0;
int inputArr[100'001];

//입력값 구하는 함수
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
		Sum += inputArr[i];
	}
	
}

//그냥 단순히 들어온값보다 작을때까지 더해서 해당 합의 최댓값을 return하려했는데 들어온값보다 작은 범위까지 다 더하는 과정에서 ret이 m개 생기는지 체크해야함.
/// <summary>
/// medium값으로 넘어온 값을 기준으로 범위를 나누고 범위가 M개로 나눠지지 않으면 false, 나뉘면 true return하는 함수
/// </summary>
/// <param name="medium"></param>
/// <returns></returns>
bool maxPartialSize(int medium) {
	//각 부분들의 합 , 몇군데로 나눠야할지 
	int partialSum=0,partiallimit=M;
	//0부터 N까지
	for (int i = 0; i < N; i++) {
		//만약 medium보다 큰 원소있다면 불가능
		if (inputArr[i] > medium) return false;
		//각 부분합 구하기
		partialSum += inputArr[i];
		//i번째 원소 더했을때 medium값 넘겼을 때
		if (partialSum > medium) {
			//partiallimit하나 지우고 한 부분 완성
			partiallimit--;
			//지웠을 때 0인 된다면 M번보다 더 많이 나누게 되는것이므로 불가능 
			if (partiallimit <= 0) return false;
			//partialSum은 i번째 반복을 이미 한 값이므로 i번째 원소값만 냅둠
			partialSum = inputArr[i];
		}
	}
	return true;

}

//그냥 다더하고 3으로 나누면 15가되어서 왜 17일까하다가 문제 다시보니 연속된거로 끊어야하네
void solution() {
	//Sum을 M개로 나눈 게 최소
	int mid = 0, low = 0, high = Sum;
	//low와 high가 1차이 날때까지
	while (low + 1 < high) {
		mid = (low + high) / 2;
		((maxPartialSize(mid)) ? high : low) = (low + high) / 2;
	}
	cout << high;
}

int main() {
	input();
	solution();
}

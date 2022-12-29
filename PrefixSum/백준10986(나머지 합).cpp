#include<iostream>

using namespace std;

//index까지의 원소의 총합 % M값 저장한 배열
int Sum[1'000'002];
//각 index는 M으로 나눈 나머지가 같은 구간의 총 갯수
int rem[1001];

int N = 0, M = 0;
void Input() {
	int inputInt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inputInt;
		//i번째값까지 나머지 더한 총합= Sum[i+1]
		Sum[i + 1] = (Sum[i] + (inputInt % M)) % M;
		//나머지값 다 저장 
		rem[Sum[i + 1]]++;
	}
}

void Solution() {
	long long Ans = 0;
	for (int i = 0; i < M; i++) {
		//0~rem[i]-1값까지 더한 값이 Sum[i]값과 같은 값을 가진 인덱스와의 쌍의 개수다 
		Ans +=(long long) rem[i]*(rem[i]-1) /2;
	}
	//마지막에 쌍을 안이뤄도 이미 0으로 나눠떨어지는 구간인 rem[0]의 갯수를 더해줘야함
	cout << Ans+rem[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solution();
}
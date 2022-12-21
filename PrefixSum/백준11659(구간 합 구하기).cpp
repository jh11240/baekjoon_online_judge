#include<iostream>

using namespace std;
int inputArr[100'001];
//입력값받으면서 그대로 합 값 저장
int	pSum[100'001];

int N, M;
void Input() {
	int tmp1 = 0, tmp2 = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
		//입력받자마자 바로 더해서 저장 pSum[i+1]은 i번째까지의 수를 다 더한 것
		pSum[i + 1] = pSum[i] + inputArr[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		//인덱스 tmp1-1부터 tmp2-1까지의 합이므로 
		cout << pSum[tmp2] - pSum[tmp1-1]<<'\n';
	}
}

int main() {
	//입출력관련해서 시간 더 줄이기
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}
#include<iostream>

using namespace std;
int N = 0, M = 0,tmp1=0,tmp2=0;
int inputArr[100'001];
//index-1까지 더한 합배열
int Sum[100'001];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> inputArr[i];
		//i까지의 합은 i-1까지의 합 + i번째 원소
		Sum[i + 1] = Sum[i] + inputArr[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		cout<<Sum[tmp2 + 1] - Sum[tmp1]<<'\n';
	}
}



int main() {
	//입출력 관련해서 시간 감소
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

}
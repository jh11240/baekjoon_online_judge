#include<iostream>

using namespace std;

int N = 0, Q = 0;
int inputArr[1001];
int differSum[1001];

//합 배열선언해서 수가 커져도 처리 가능하도록 구현한 함수
void Input() {
	int tmp1 = 0, tmp2 = 0;
	cin >> N >> Q;
	cin >> inputArr[0];
	for (int i = 1; i < N; i++) {
		cin >> inputArr[i];
		//i번째까지의 구간합의 총합
		differSum[i + 1] =differSum[i]+ abs(inputArr[i] - inputArr[i - 1]);
	}
	for (int i = 0; i < Q; i++) {
		cin >> tmp1 >> tmp2;
		//인덱스는 1부터 들어오므로 tmp1-1 부터 tmp2-1까지의 합 출력
		cout << differSum[tmp2] - differSum[tmp1] << '\n';
	}
}
//하나하나 다구현해도 어차피 총 연산 100만이라 가능한 함수
void Input1() {
	int tmp1 = 0, tmp2 = 0;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
	}
	for (int i = 0; i < Q; i++) {
		int Sum = 0;
		cin >> tmp1 >> tmp2;
		//tmp-1과 tmp1까지의 합부터 tmp2-2부터 tmp2-1까지 더해서 출력
		for (int j = tmp1 - 1; j < tmp2-1; j++) {
			Sum += abs(inputArr[j + 1] - inputArr[j]);
		}
		cout << Sum<<'\n';
	}
}
int main() {
	//이 문제조건은 최대치가 작아서 Input1이나 Input이나 다 답이 나옴
	//Input();
	Input1();
}
#include<iostream>

using namespace std;
int arr[1001] = { 0, };						//미리 배열에 선언

void solution(int& input);

void init(){								//미리 배열에 삼각수 값 넣어주기
	for (int i = 1; i < 1001; i++) {
		arr[i] = (i * (i + 1)) / 2;
	}
}

void input() {								//입력 담당 함수
	int amount=0,in=0;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> in;
		solution(in);
	}
}

void solution(int& in) {
	int idx = 0;						//입력값보다 작은 삼각수의 인덱스
	for (int i = 1; i < 1000; i++) {	
		if (arr[i] > in) {				//처음으로 in보다 큰 값 나오면
			idx = i - 1;				//idx값 정해줌(필요이상으로 3중 for문에서 시간 안쓰기 위해)
			break;						
		}
	}

	for (int i = 1; i <= idx; i++) {	//3중 for문으로 3값 더했을때 값나오면 1 출력
		for (int j = 1; j <= idx; j++) {
			for (int k = 1; k <= idx; k++) {
				if (arr[i] + arr[j] + arr[k] == in) {
					cout << 1 << '\n';
					return;
				}
			}
		}
	}
	cout << 0 << '\n';					//못 찾으면 0 출력
	return;
}

int main() {
	init();
	input();
}
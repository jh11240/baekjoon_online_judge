#include<iostream>
#include<vector>

using namespace std;

char** arr;									//int로 하면 111을 다먹어서 char형으로 해야함
void input(int& amount) {					
	cin >> amount;
	arr = new char* [amount];				//1780 번이랑 다르게 동적 할당으로 2차원 배열 구성
	for (int i = 0; i < amount; i++) {
		arr[i] = new char[amount];
	}
	for (int i = 0; i < amount; i++) {		//입력값받아서 저장
		for (int j = 0; j < amount; j++) {
			cin >> arr[i][j];
		}
	}
}
void solution(int x,int y, int length) {	//1780이랑 원리는 유사
	if (length == 0) return;				// length가 1일때 마지막이여야하므로 0들어올땐 return

	char temp = arr[x][y];					//배열의 첫값 저장
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			if (arr[i][j] != temp) {		//첫값과 다르면 다른 값으로 이뤄진 사각형이므로 재귀 시작
				cout << "(";				//네개로 나눠질 시, ( 출력
				solution(x, y, length / 2);
				solution(x, y+length/2, length / 2);
				solution(x+length/2, y, length / 2);
				solution(x+length/2, y+length/2, length / 2);
				cout << ")";				//나눠진값들이 다시 병합되면 )출력
				return;
			}
		}
	}
	if (temp-'0' == 0) {					//temp값이 char형이므로 int형과 비교하려면 '0'빼야함
		cout << 0;
		return;
	}
	else
	{
		cout << 1;
		return;
	}



}

int main() {
	int amount = 0;
	input(amount);
	solution(0, 0, amount);

}

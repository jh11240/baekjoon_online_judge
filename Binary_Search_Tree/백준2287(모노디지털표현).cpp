#include<iostream>
#include<string>
#include<set>

using namespace std;
int K, N;
//1개부터 8개의 K로 만들 수 있는 모든 수 저장용 set
set<int> Cal[9];

//kAmount개의 K로 만들 수 있는 모든 수를 Cal[kAMount]에 저장
void MakeSet(int kAmount) {
	//kAmount개의 K를 이어붙여서 저장할 변수
	int tmp = 0;
	for (int i = 0; i < kAmount; i++) {
		tmp = tmp * 10 + K;
	}
	//tmp저장하고
	Cal[kAmount].insert(tmp);
	//-tmp도 저장한다
	Cal[kAmount].insert(-tmp);
	//kAMount까지
	for (int i = 1; i < kAmount; i++) {
		//Cal[i]에 저장된 모든 값과
		for (int A : Cal[i]) {
			//Cal[kAMount-i]에 저장된 모든값을 연산해서 저장
			for (int B : Cal[kAmount - i]) {
				if (i <= kAmount / 2) {
					Cal[kAmount].insert(A + B);
					Cal[kAmount].insert(A - B);
					Cal[kAmount].insert(A * B);
				}
				//DivisionByZero오류 범하지 않기위해 B가 0이 아닐때만
				if (B) Cal[kAmount].insert(A / B);

			}
		}

	}
}
//Cal[1]부터 Cal[8]내에 input이 있는지 찾아서 있다면 i값 없다면 NO출력
void Solution(int input) {
	int i = 1;
	for (i; i<9&&Cal[i].find(input) == Cal[i].end(); i++) { }
	if(i==9)cout << "NO" << '\n';
	else cout << i << '\n';
}

void Input() {
	int input = 0;
	cin >> K >> N;
	//1개의 K부터 8개의 K로 만들 수 있는 모든 수 다 Cal에 저장
	for (int i = 1; i <= 8; i++) {
		MakeSet(i);
	}
	//그 후 값 받을때마다 찾아서 출력
	for (int i = 0; i < N; i++) {
		cin >> input;
		Solution(input);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();

}
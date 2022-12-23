#include<iostream>

using namespace std;
int N = 0, M = 0;
int Sum[1026][1026];
int inputArr[1025][1025];

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> inputArr[i][j];
			//(i,j까지의 합은 i,j-1까지의 합+ i-1,j까지의 합 -  중복된 부분 + i,j좌표의 값)
			Sum[i + 1][j + 1] = Sum[i + 1][j] + Sum[i][j + 1] - Sum[i][j] + inputArr[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1=0, y1=0, x2=0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
                //x2,y2까지의 합- x2,y1-1까지의합 - x1-1,y2까지의 합 + x1,y1까지의합(중복된 부분)
		cout<<Sum[x2+1][y2+1] - Sum[x2+1][y1]-Sum[x1][y2+1]+Sum[x1][y1] << '\n';
	}
}

int main() {
	//c랑 c++입출력 분리
	ios_base::sync_with_stdio(0);
	//입력 출력 연결 분리
	cin.tie(0);

	Input();
}
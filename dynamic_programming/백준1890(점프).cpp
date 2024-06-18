#include<iostream>

using namespace std;
int N;
//[0]에 원래 타일값 [1]에 방문횟수
long long Tile[101][101][2];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Tile[i][j][0];
		}
	}
	//만약 처음에 0이면 아무곳도 갈수없으므로 0 출력
	if (Tile[0][0][0] == 0) {
		cout << 0;
		return 0;
	}
	Tile[0][0][1] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Tile[i][j][1] == 0 || Tile[i][j][0] == 0) continue;
			int tileNum = Tile[i][j][0];
			if (i + tileNum < N)
				Tile[i + tileNum][j][1]+=Tile[i][j][1];
			if (j + tileNum < N)
				Tile[i][j + tileNum][1]+=Tile[i][j][1];
		}
	}
	cout << Tile[N - 1][N - 1][1];
}
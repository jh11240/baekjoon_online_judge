#include <iostream>
using namespace std;

char map[51][51];

// 왼쪽 위가 B로 시작할 경우
char ans_B[8][8] = { {'B','W','B','W','B','W','B','W'},
					 {'W','B','W','B','W','B','W','B'},
					 {'B','W','B','W','B','W','B','W'},
					 {'W','B','W','B','W','B','W','B'},
					 {'B','W','B','W','B','W','B','W'},
					 {'W','B','W','B','W','B','W','B'},
					 {'B','W','B','W','B','W','B','W'},
					 {'W','B','W','B','W','B','W','B'},
};

// 왼쪽 위가 W로 시작할 경우
char ans_W[8][8] = { {'W','B','W','B','W','B','W','B'},
					 {'B','W','B','W','B','W','B','W'},
					 {'W','B','W','B','W','B','W','B'},
					 {'B','W','B','W','B','W','B','W'},
					 {'W','B','W','B','W','B','W','B'},
					 {'B','W','B','W','B','W','B','W'},
					 {'W','B','W','B','W','B','W','B'},
					 {'B','W','B','W','B','W','B','W'},
};

int N, M;
int min_n = 999;
int cnt_B, cnt_W;
int ans;

void find_mini(int x, int y) {
	
	cnt_B = 0, cnt_W = 0;
    
	int y_i = 0;
	for (int i = y; i < y + 8; i++) {
		int x_i = 0;
		for (int j = x; j < x + 8; j++, x_i++) {
			
			if (map[i][j] != ans_B[y_i][x_i]) cnt_B++;	// map이 왼쪽위가 B인 체스판의 i,j위치와 같지않다면 cnt_B를 ++ 시킨다.
			if (map[i][j] != ans_W[y_i][x_i]) cnt_W++;  // map이 왼쪽위가 W인 체스판의 i,j위치와 같지않다면 cnt_W를 ++ 시킨다.
		}
		y_i++;
	}
    
    // 왼쪽위가 B일 case가 W일때보다 바꿀값이 적다면 B
	if (cnt_B < cnt_W) ans = cnt_B;
	else ans = cnt_W; // 아니라면 W
    
	if (ans < min_n) min_n = ans;  

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
    
    // 맵 넣기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
    // 각 위치에 대하여 체스판 만들기
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			find_mini(j,i);
		}
	}

    // min 값 출력
	cout << min_n << endl;

	return 0;
}
#include<iostream>

using namespace std;
int N=0,Ans=0;
//몇번째행에 퀸이 어디있는지 checkQueenCanPos에서 사용될 것
int queen[15];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void Input() {
	cin >> N;
}

//h행 w열에 퀸이 들어갈 수 있는지 보는 것.
bool checkQueenCanPos(int h,int w) {

	for (int i = 0; i < h; i++) {
		//같은 열에 존재하면 false
		if (queen[i]==w) return false;
		//대각선에 존재하면 false
		if (abs(h - i) == abs(w - queen[i]))
		return false;
	}
	return true;
}

/// <summary>
/// 열마다 하나 행마다 하나씩 배치해야하므로 각 열의 행에 넣었을 때 백트래킹
/// </summary>
/// <param name="h"></param>
/// <param name="w"></param>
/// <param name="amount"></param>
void Backtracking(int h,int w,int amount) {
	if (h == N) return;

	for (int i = 0; i < N; i++) {
		if (!checkQueenCanPos(h, i)) continue;
		if (amount == N - 1) Ans++;
		queen[h] = i;
		Backtracking(h+1,w, amount+1);
		queen[h] = 0;
	}
}

void Solution() {
	Backtracking( 0,0, 0);
	cout << Ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	Input();
	Solution();
}
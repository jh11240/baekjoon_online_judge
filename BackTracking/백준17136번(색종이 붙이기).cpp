#include<iostream>
#include<vector>

using namespace std;
int paper[11][11];

struct oneInfo {
	int height;
	int width;
};

vector<oneInfo> ones;
bool covered[11][11];
int paperAmount[5] = { 5,5,5,5,5 };

void Input() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
			if (paper[i][j] == 1) ones.push_back({ i,j});
		}
	}
}

void returnCoveredToFalse(int num, int height, int width) {
	for (int i = height; i < num; i++) {
		for (int j = width; j < num; j++) {
			if (covered[i][j] == true)
				covered[i][j] = false;
			else
				continue;
		}
	}
}

/// <summary>
/// height,width좌표에 numxnum 크기의 종이 붙였을 때 0이 덮히는지 체크하는 함수
/// </summary>
/// <param name="종이 한 변사이즈(num)"></param>
/// <param name="좌표 행(height)"></param>
/// <param name="좌표 열(width)"></param>
/// <returns></returns>
bool checkIfZeroCovered(int num,int height,int width) {
	for (int i = height; i < num; i++) {
		for (int j = width; j < num; j++) {
			if (paper[i][j] == 0) {
				returnCoveredToFalse(num,height,width);
				return true;
			}
			else {
				covered[height][width] = true;
			}
		}
	}
	return false;
}

void Bactracking(vector<oneInfo>::iterator oneOffset) {
	if (oneOffset == ones.end()) return;
	//만약 다음 1의 자리가 색종이 덮여있다면 다음 1의자리로 패스
	if (covered[oneOffset->height][oneOffset->width]) {
		Bactracking(oneOffset+1);
		//1의 자리가 덮여있다면 밑의 과정 처리 안해도되므로 백트래킹 끝나고 바로 return
		return;
	}
	for (int i = 5; i > 0; i--) {
		//0이 색종이로 커버가 된다면 continue
		if (checkIfZeroCovered(i, oneOffset->height, oneOffset->width)) 
			continue;
		//0이 안된다면 이미 해당 구역의 1들은 다 covered가 true 체크되었을 것.
		else {
			//갯수 -1 해줌
			paperAmount[i-1]--;
			//갯수가 음수가 나온다면 이번 재귀에서 바꾼 covered값들 초기화 해주고
			if (paperAmount[i - 1] < 0) {
				returnCoveredToFalse(i, oneOffset->height, oneOffset->width);
				paperAmount[i - 1] ++;
				return;
			}
			Bactracking(oneOffset + 1);
			//백트래킹끝나고 초기화
			returnCoveredToFalse(i, oneOffset->height, oneOffset->width);
			paperAmount[i - 1]++;
		}
	}
}

void Solution() {
	int Ans = 0;
	Bactracking(ones.begin());
	for (int i = 0; i < 4; i++) {
		Ans += 5 - paperAmount[i];
	}
	cout << Ans;
}

int main() {
	Input();
	Solution();
}
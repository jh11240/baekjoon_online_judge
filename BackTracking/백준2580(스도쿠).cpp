#include<iostream>
#include<vector>

using namespace std;
//입력값 받는 배열
int sudoku[9][9];

//답 출력했다면 바로 재귀 다 끊을 수 있도록
bool PrintedAnswer = false;

//빈칸의 정보
struct emptySpace {
	//빈칸의 행
	int height;
	//빈칸의 열
	int width;
};

// 0인 칸 정보 미리 저장하는 벡터
vector<emptySpace> v;


void Input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
            //0이면 벡터에 푸시
			if (sudoku[i][j] == 0) 
			    v.push_back({ i,j});
		}
	}
}


/// <summary>
/// num값이 (height,width)좌표에 들어갈 수 있는치 체크
/// </summary>
/// <param name="행(height)"></param>
/// <param name="열(width)"></param>
/// <param name="num"></param>
/// <returns>좌표에 들어간다면 true 못 들어가면 false</returns>
bool CheckIfNumFullfillCondition(int height, int width, int num) {
	for (int i = 0; i < 9; i++) {
		//행에 중복되는 숫자가 있다면 return false
		if (sudoku[height][i] == num) return false;
		//열에 중복되는 숫자가 있다면 return false
		if (sudoku[i][width] == num) return false;
	}
	//해당칸의 3x3구역 중복된거 있는지 체크
	for (int i = (height / 3) *3; i < (height / 3)*3 + 3; i++) {
		for (int j = (width / 3)*3 ; j < (width / 3)*3 + 3; j++) {
			if (sudoku[i][j] == num) return false;
		}
	}
    //중복된게 없다면 return true
	return true;
}

//sudoku프린트하는 함수
void PrintSudoku() {
	cout << '\n';
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j]<<" ";
		}
		cout << '\n';
	}
	PrintedAnswer = true;
}

//백트래킹으로 스도쿠 채우는 함수
void Backtracking(vector<emptySpace>::iterator iter,int zeroFilled) {

	//0갯수가 다 채워졌다면
	if (zeroFilled == v.size()) {
		PrintSudoku();
		return;
	}
	//iterator가 끝이면 return
	if (iter == v.end()) return;

    //반복문을 통해 1부터 9까지 넣고 다음 재귀함수 호출
	for (int i = 1; i <= 9; i++) {
        //이미 출력되었다면 return하기
		if (PrintedAnswer) return;
		//i값이 못 들어가면 continue
		if (!CheckIfNumFullfillCondition(iter->height, iter->width, i)) continue;
		//들어갈 수 있따면 sudoku값 바꾸기
		sudoku[iter->height][iter->width] = i;
		Backtracking(iter+1, zeroFilled + 1);
        //빠져나왔다면 다시 0으로 바꿔주기(백트래킹의 정점 초기화)
		sudoku[iter->height][iter->width] = 0;
	}
}


void Solution() {
	auto iter = v.begin();
	Backtracking(iter, 0);
}

int main() {
	Input();
	Solution();
}
#include<iostream>					

using namespace std;

char** arr;
void solution(const int& N,const int& M);

void input(int&N, int& M) {										//입력값받고 배열 동적할당해주는 함수

	cin >> N >> M;
	arr = new char* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new char[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	solution(N, M);
}

int checkBoard(const int& x,const int& y) {			//입력 좌표값에서 오른쪽 8칸,밑 8칸씩 체크하고 몇개 바꿔야하는지 return하는 함수
													//입력값으로 받아온 (x,y)좌표에서 8x8 사각형 범위에서 좌측 상하단 우측상하단이 검정인지 하양인지 
													//총 8번 비교하는 함수

	int	wrongTile = 64;								//각 네 귀퉁이에서 조사했을때 제일 적게 색바꾸는 수. return값이다.

	if (arr[x][y] == 'B')														//x,y가 검정일 때(좌측 상단)
	{
		int tempWrongTile = 0;													//각 케이스에서 임시로 저장하는 타일수
		for (int i = x; i < x+8; i++) {
			for (int j = y; j < y+8; j++) {
				if ((i-x) % 2 != 0 && (j-y) % 2 != 0 && arr[i][j]!='B') {				//행과 열이 홀수면 
					tempWrongTile++;											//타일은 검은색이여야함.
				}
				else if ((i-x) % 2 != 0 && (j-y) % 2 == 0 && arr[i][j] !='W') {			//행이 홀수고 열이 짝수면
					tempWrongTile++;											//타일은 흰색이여야함.
				}
				else if ((i-x) % 2 == 0 && (j-y) % 2 != 0 && arr[i][j] != 'W') {		//행이 짝수고 열이 홀수면
					tempWrongTile++;											//흰색이여야함.
				}
				else if ((i-x) % 2 == 0 && (j-y) % 2 == 0 && arr[i][j] != 'B') {		//행 짝 열 짝
					tempWrongTile++;											//검정이여야함
				}
			}
		}
		wrongTile = wrongTile > tempWrongTile ? tempWrongTile : wrongTile;		//비교해서 wrongTile값에 넣기
	}
	else if (arr[x][y] == 'W')													//x,y가 흰색일때(좌측 상단)
	{
		int tempWrongTile = 0;	
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i-x) % 2 != 0 && (j-y) % 2 != 0 && arr[i][j] != 'W') {				//행과 열이 홀수면 
					tempWrongTile++;											//타일은 흰색이여야함.
				}
				else if ((i-x) % 2 != 0 && (j-y) % 2 == 0&& arr[i][j] != 'B') {			//행이 홀수고 열이 짝수면
					tempWrongTile++;											//타일은 검정색이여야함.
				}
				else if ((i-x) % 2 == 0 && (j-y) % 2 != 0&& arr[i][j] != 'B') {			//행이 짝수고 열이 홀수면
					tempWrongTile++;											//검정색이여야함.
				}
				else if ((i-x) % 2 == 0 && (j-y) % 2 == 0&& arr[i][j] != 'W') {			//행 짝 열 짝
					tempWrongTile++;											//흰색이여야함
				}
			}
		}
		wrongTile = wrongTile > tempWrongTile ? tempWrongTile : wrongTile;
	}
	if (arr[x + 7][y] == 'B') {													//(x+7,y)값이 검정색일 때(좌측 하단)
		int tempWrongTile = 0;
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i-x) % 2 != 0 && (j-y) % 2 != 0 && arr[i][j] != 'W') {				//행과 열이 홀수면 
					tempWrongTile++;											//타일은 흰색이여야함.
				}
				else if ((i-x) % 2 != 0 && (j-y) % 2 == 0 && arr[i][j] != 'B') {		//행이 홀수고 열이 짝수면
					tempWrongTile++;											//타일은 검정색이여야함.
				}
				else if ((i-x) % 2 == 0 && (j-y) % 2 != 0 && arr[i][j] != 'B') {		//행이 짝수고 열이 홀수면
					tempWrongTile++;											//검정색이여야함.
				}
				else if ((i-x) % 2 == 0 && (j-y) % 2 == 0 && arr[i][j] != 'W') {		//행 짝 열 짝
					tempWrongTile++;											//흰색이여야함
				}
			}
		}
		wrongTile = wrongTile > tempWrongTile ? tempWrongTile : wrongTile;
	}
	else if (arr[x + 7][y] == 'W') {										//(x+7,y)값이 흰색일 때(좌측 하단)
		int tempWrongTile = 0;													//각 케이스에서 임시로 저장하는 타일수
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i - x) % 2 != 0 && (j - y) % 2 != 0 && arr[i][j] != 'B') {				//행과 열이 홀수면 
					tempWrongTile++;											//타일은 검은색이여야함.
				}
				else if ((i - x) % 2 != 0 && (j - y) % 2 == 0 && arr[i][j] != 'W') {			//행이 홀수고 열이 짝수면
					tempWrongTile++;											//타일은 흰색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 != 0 && arr[i][j] != 'W') {		//행이 짝수고 열이 홀수면
					tempWrongTile++;											//흰색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 == 0 && arr[i][j] != 'B') {		//행 짝 열 짝
					tempWrongTile++;											//검정이여야함
				}
			}
		}
		wrongTile = wrongTile > tempWrongTile ? tempWrongTile : wrongTile;		//비교해서 wrongTile값에 넣기
	}
	if (arr[x][y+7] == 'B') {												//(x,y+7)값이 검정색일 때(우측 상단)
		int tempWrongTile = 0;
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i - x) % 2 != 0 && (j - y) % 2 != 0 && arr[i][j] != 'W') {				//행과 열이 홀수면 
					tempWrongTile++;											//타일은 흰색이여야함.
				}
				else if ((i - x) % 2 != 0 && (j - y) % 2 == 0 && arr[i][j] != 'B') {			//행이 홀수고 열이 짝수면
					tempWrongTile++;											//타일은 검정색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 != 0 && arr[i][j] != 'B') {			//행이 짝수고 열이 홀수면
					tempWrongTile++;											//검정색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 == 0 && arr[i][j] != 'W') {			//행 짝 열 짝
					tempWrongTile++;											//흰색이여야함
				}
			}
		}
		wrongTile = wrongTile > tempWrongTile ? tempWrongTile : wrongTile;
	}
	else if (arr[x][y+7] == 'W') {												//(x,y+7)값이 흰색일 때(우측 상단)
		int tempWrongTile = 0;													//각 케이스에서 임시로 저장하는 타일수
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i - x) % 2 != 0 && (j - y) % 2 != 0 && arr[i][j] != 'B') {				//행과 열이 홀수면 
					tempWrongTile++;											//타일은 검은색이여야함.
				}
				else if ((i - x) % 2 != 0 && (j - y) % 2 == 0 && arr[i][j] != 'W') {			//행이 홀수고 열이 짝수면
					tempWrongTile++;											//타일은 흰색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 != 0 && arr[i][j] != 'W') {		//행이 짝수고 열이 홀수면
					tempWrongTile++;											//흰색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 == 0 && arr[i][j] != 'B') {		//행 짝 열 짝
					tempWrongTile++;											//검정이여야함
				}
			}
		}
		wrongTile = wrongTile > tempWrongTile ? tempWrongTile : wrongTile;		//비교해서 wrongTile값에 넣기
	}
	if (arr[x + 7][y+7] == 'B') {											//(x+7,y+7)값이 검정색일 때(우측 하단)
		int tempWrongTile = 0;													//각 케이스에서 임시로 저장하는 타일수
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i - x) % 2 != 0 && (j - y) % 2 != 0 && arr[i][j] != 'B') {				//행과 열이 홀수면 
					tempWrongTile++;											//타일은 검은색이여야함.
				}
				else if ((i - x) % 2 != 0 && (j - y) % 2 == 0 && arr[i][j] != 'W') {			//행이 홀수고 열이 짝수면
					tempWrongTile++;											//타일은 흰색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 != 0 && arr[i][j] != 'W') {		//행이 짝수고 열이 홀수면
					tempWrongTile++;											//흰색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 == 0 && arr[i][j] != 'B') {		//행 짝 열 짝
					tempWrongTile++;											//검정이여야함
				}
			}
		}
		wrongTile = wrongTile > tempWrongTile ? tempWrongTile : wrongTile;		//비교해서 wrongTile값에 넣기
	}
	else if (arr[x + 7][y + 7] == 'W') {									//(x+7,y+7)값이 흰색일 때(우측 하단)
		int tempWrongTile = 0;
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i - x) % 2 != 0 && (j - y) % 2 != 0 && arr[i][j] != 'W') {				//행과 열이 홀수면 
					tempWrongTile++;											//타일은 흰색이여야함.
				}
				else if ((i - x) % 2 != 0 && (j - y) % 2 == 0 && arr[i][j] != 'B') {			//행이 홀수고 열이 짝수면
					tempWrongTile++;											//타일은 검정색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 != 0 && arr[i][j] != 'B') {			//행이 짝수고 열이 홀수면
					tempWrongTile++;											//검정색이여야함.
				}
				else if ((i - x) % 2 == 0 && (j - y) % 2 == 0 && arr[i][j] != 'W') {			//행 짝 열 짝
					tempWrongTile++;											//흰색이여야함
				}
			}
		}
		wrongTile = wrongTile > tempWrongTile ? tempWrongTile : wrongTile;
	}
	return wrongTile;
}

void solution(const int& N,const int& M) {	//답 출력 함수
	int minColor = 2500;					//최소로 색칠해야하는 갯수
	for (int i = 0; i < N - 7; i++) {		//(i,j)칸에서 오른쪽으로 8칸 밑으로 8칸 체크해야하니
		for (int j = 0; j < M - 7; j++) {	//n-7,m-7까지 조사
			int check = checkBoard(i, j);
			minColor=check>minColor? minColor:check;
		}
	}
	cout << minColor;

}

int main() {
	int N = 0, M = 0;
	input(N,M);

	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
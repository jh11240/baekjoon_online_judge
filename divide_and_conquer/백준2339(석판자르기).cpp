#include<iostream>			//3 
							////https://underside.tistory.com/76

using namespace std;

//불순물, 보석 입력받을 배열
int arr[21][21];

//경우의 수 구하는 재귀함수
int solution(int x0, int y0, int x1, int y1, bool slice) {		//slice 참이면 이전에 세로로 자름, slice 거짓이면 이전에 가로로 자름

	//불순물,보석
	int impurities = 0, jewelry = 0;

	//배열에서 불순물, 보석이 몇개있나 체크하는 반복문
	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			if (arr[i][j] == 1) {
				impurities++;
			}
			else if (arr[i][j] == 2) {
				jewelry++;
			}
		}
	}
	//보석 하나, 불순물 0이면 경우의 수 한개 이므로 return 1
	if (impurities == 0 && jewelry == 1)
		return 1;
	//보석이 하나, 불순물 하나면 경우의 수 0(석판엔 무조건 하나의 보석이 있어야 하므로)
	else if (impurities == 1 && jewelry == 1)
		return 0;
	//보석 없거나 불순물없을 때 보석 두개 이상이면 경우의 수 0
	else if (jewelry == 0)
		return 0;
	else if (jewelry > 2 && impurities == 0)
		return 0;

	//답 변수
	int Ans = 0;
	//위의 경우 제외하곤 
	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++)
		{
			//불순물 있을 때
			if (arr[i][j] == 1) {
				//이전에 세로로 잘랐을 때,
				if (slice) {
					//* 가로 방향 조사하므로 기준점체크( 경계선일 땐 못 자른다고 문제에 적혀있으니 체크) *
					if ( i != x0 && i != x1 - 1) {
						bool check = true;
						//해당 불순물 위치에서 수평방향으로 보석 있는 지 체크
						for (int k = y0; k < y1; k++) {
							if (arr[i][k] == 2) {
								check = false;
								break;
							}
						}
						//해당 불순물 위치에서 수평방향에 보석 없다면
						if (check) {
							//답 변수에 넣어주기. * 곱하는 이유는 경우의 수라서 곱해줘야 함! *
							//* 가로로 나눴으므로 위아래로 나눠서 재귀, slice에 반대로 넣어줌 *
							Ans += solution(x0, y0, i, y1, false) * solution(i+1, y0, x1, y1, false);
						}
					}
				}
				//만약 이전에 가로로 잘랐다면, 세로 방향으로 잘라야 함!
				else {
					//세로방향 조사하므로 기준점이 경계선에 걸리는지 체크 
					if (j != y0 && j != y1 - 1) {
						bool check = true;
						//수직 방향으로 보석이 있는 지 검사
						for (int k = x0; k < x1; k++) {
							if (arr[k][j] == 2) {
								check = false;
								break;
							}
						}
						//수직 방향으로 보석 없다면
						if (check) {
							//세로로 나눳으므로 위아래로 나눠서 재귀,slice에 반대로 넣어줌
							Ans += solution(x0, y0, x1, j, true) * solution(x0, j+1, x1, y1, true);
						}
					}
				}
			}
		}
	}
	return Ans;



}

//입력값 받는 함수
void input(int& amount) {			
	int jew=0, imp = 0;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++) {
			cin >> arr[i][j];
			//불순물일 때
			if (arr[i][j] == 1) {	
				imp++;
			}
			//보석일 때
			else if(arr[i][j]==2)
			{
				jew++;
			}
		}
	}

	//보석 하나만 있다면 나눌 필요없으므로
	if (imp == 0 && jew == 1) {
		cout << 1;
	}
	else {
		//가로로 나눳을 때 답
		int resultA = solution(0, 0, amount, amount, false);
		//세로로 나눳을 때 답
		int resultB = solution(0, 0, amount, amount, true);
		//답이 0이면 나눌 수 있는 경우의 수가 없으므로
		if (resultA + resultB == 0) {
			cout << -1;
		}
		else {
			cout << resultA + resultB;
		}
	}
}


int main() {
	int amount=0;
	input(amount);
}
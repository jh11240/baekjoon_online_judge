#include<iostream>
#include<queue>
#include<set>
using namespace std;

string target = "123456780";
//방문 배열은 첨에 생각했던거처럼 1 2 3 숫자에대해 체크가 아니라 문자열에대해 체크 
//해당 문자열을 시도했냐 안했냐로
set<string> visited;
//반복문 일일히 코딩하기 귀찮아서 쓰는 배열
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dz[4] = {-3,3,-1,1};

struct puzzle {
	int zeroLoc;
	string puzzleArr;
};

queue<puzzle> q;

void Input() {
	string init="";
	int tmp = 0;
	int zero = 0;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		//string 값으로 받아서 비교하자
		init += tmp + '0';
		//0위치 기록
		if (tmp == 0) zero = i;
	}
	//큐에 푸시
	q.push({zero,init});
	//방문 set에 넣어준다.
	visited.insert(init);
}
void Solution() {
	if (q.front().puzzleArr == target) {
		cout << 0;
		return;
	}
	int level = 1;
	for (; !q.empty();level++) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			puzzle cur = q.front();
			q.pop();
			//0좌표의 행
			int x = cur.zeroLoc / 3;
			//0좌표의 열
			int y = cur.zeroLoc % 3;

			for (int i = 0; i < 4; i++) {
				//0좌표의 다음 행값
				int nextX = x + dx[i];
				//0좌표의 다음 열값
				int nextY = y + dy[i];
				
				//nextX nextY값이 범위 벗어나면 continue (현재 0위치가 경계면이면 3개의 값만 조사해야되는데 4개의 값 조사하는걸 막는다.)
				if (nextX < 0 || nextY<0 || nextX/3>=1 || nextY/3>=1) continue;
				//다음 zero값과 zero 바꿔준다.
				swap(cur.puzzleArr[cur.zeroLoc+dz[i]], cur.puzzleArr[cur.zeroLoc]);
				//cur값이 답이되면 level 출력
				if (cur.puzzleArr == target) {
					cout << level;
					return;
				}
				//cur 처음보는 배열이면 set과 queue에 추가
				if (visited.find(cur.puzzleArr) == visited.end()) {
					visited.insert(cur.puzzleArr);
					q.push({ cur.zeroLoc+dz[i],cur.puzzleArr });
				}
				//cur을 반복문에서 계속 쓰이므로 되돌려놓기
				swap(cur.puzzleArr[cur.zeroLoc + dz[i]], cur.puzzleArr[cur.zeroLoc]);

			}
		}

	}
	cout << -1;

}

int main() {
	Input();
	Solution();
}
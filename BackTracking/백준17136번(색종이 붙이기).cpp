#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int paper[11][11];

struct oneInfo {
	int height;
	int width;
};

vector<oneInfo> ones;
//만약 답이없을때는 -1 출력해야되는데 minAns를 출력하게하므로 100출력
bool didFinished=false;
int minAns=100;
bool covered[10][10];
int paperAmount[5] = { 5,5,5,5,5 };

void Input() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
			if (paper[i][j] == 1) ones.push_back({ i,j});
		}
	}
}

//그냥 단순히 h,w에서 num만큼 다 false로 해버리면 예를들어 num이 5일때 1,2가 0일때 방금 조사안한값들도 다 false로 바꿔놓음
void returnCoveredToFalse(int num, int height, int width) {
	for (int i = height; i < num+height; i++) {
		for (int j = width; j < num+width; j++) {
			if (covered[i][j])
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
	for (int i = height; i <height+ num; i++) {
		for (int j = width; j <width+ num; j++) {
			//0을 만나면 true리턴
			if (paper[i][j] == 0) {
				return true;
			}
			//paper가 1이라면 continue
			else
				continue;
		}
	}
	//이렇게 한번 더써주는 이유는 covered배열 false로 바꿔주는 함수가 싹다 false로 바꿔버려서
	//이전단계에서 true로 바꿔둔것도 다 바꿔버림
	for (int i = height; i < height + num; i++) {
		for (int j = width; j < width + num; j++) {
			covered[i][j] = true;
		}
	}
	return false;
}

int HowMuchPaperUsed() {
	int ansNum = 0;
	for (int i = 0; i < 5; i++) {
		ansNum += 5 - paperAmount[i];
	}
	return ansNum;
}

void Bactracking(vector<oneInfo>::iterator oneOffset) {
	if (oneOffset == ones.end()) {
		didFinished = true;
		minAns = minAns< HowMuchPaperUsed()? minAns:HowMuchPaperUsed();
		return;
	}
	//만약 다음 1의 자리가 색종이 덮여있다면 다음 1의자리로 패스
	if (covered[oneOffset->height][oneOffset->width]) {
		Bactracking(oneOffset+1);
		//1의 자리가 덮여있다면 밑의 과정 처리 안해도되므로 백트래킹 끝나고 바로 return
		return;
	}
	for (int i = 5; i >0; i--) {
		//0이 색종이로 커버가 된다면 continue , i값 더했을때 범위벗어나면 continue해줘야됨(범위도 더한값이 10까지 허용해줘야 끝값 체크 가능)
		if ((oneOffset->height + i>10 || oneOffset->width+i>10) ||checkIfZeroCovered(i, oneOffset->height, oneOffset->width)) 
			continue;
		//0이 안된다면 이미 해당 구역의 1들은 다 covered가 true 체크되었을 것.
		else {
			//갯수 -1 해줌
			paperAmount[i-1]--;
			//갯수가 음수가 나온다면 이번 재귀에서 바꾼 covered값들 초기화 
			if (paperAmount[i - 1] < 0) {
				returnCoveredToFalse(i, oneOffset->height, oneOffset->width);
				paperAmount[i - 1] ++;
				continue;
			}
			// 종이사용한 양이 최소 사용갯수보다 많다면 continue
			//처음엔 minAns를 큰값으로 잡고 통과하게 해 맨처음 통과되었을때 값으로 갱신하면서 가지치기
			if (HowMuchPaperUsed() >= minAns) {
				returnCoveredToFalse(i, oneOffset->height, oneOffset->width);
				paperAmount[i - 1]++;
				continue;
			}
			if (HowMuchPaperUsed() == 6) {
				cout << "66";
			}
			Bactracking(oneOffset + 1);
			//백트래킹끝나고 초기화
			returnCoveredToFalse(i, oneOffset->height, oneOffset->width);
			paperAmount[i - 1]++;
		}
	}
}

void Solution() {
	Bactracking(ones.begin());
	if (!didFinished) {
		cout << -1;
		return;
	}
	cout << minAns;
}

int main() {
	Input();
	Solution();
}
#include<iostream>
#include<set>

using namespace std;
int width=0, height = 0;
//입력값인 알파벳 받는 배열
char board[21][21];
//방문 배열
bool visited[21][21];
//지금까지 사용한 알파벳들(set 사용시 시간초과 난다. 각 알파벳에서 A를 뺀값으로 배열 사용해야 빠름)
bool used[26];
//최대 길이
int maxLength = 1;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
void Input() {
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> board[i][j];
		}
	}
}

void Backtracking(int h,int w,int length) {
	//예외처리를 바로밑에 주석처리한 부분이 아니라 line 39,40에서 해야 조건 벗어나는 함수를 쓸데없이 호출 안함
	/*이미 방문한 칸이면 return
	if (visited[h][w]) return;
	이미 본 알파벳이면 return
	if (used[board[h][w]-'A']) return;*/

	//각 단계에서 길이값 비교해서 max길이 갱신
	maxLength = length > maxLength ? length : maxLength;
	//알파벳 사용햇다고 체크
	used[board[h][w] - 'A'] = true;
	//방문처리
	visited[h][w] = true;
	//반복문을 이용해 일일이 코딩x
	for (int i = 0; i < 4; i++) {
		int nextH = h + dx[i];
		int nextW = w + dy[i];
		//범위 벗어날시 continue
		if (nextH < 0 || nextW < 0 || nextH >= height || nextW >= width) continue;
		//방문했다면 conitnue
		if (visited[nextH][nextW])continue;
		//이미 사용한 알파벳이면 continue
		if (used[board[nextH][nextW] - 'A']) continue;
		//길이 +1해서 재귀호출
		Backtracking(nextH,nextW,length+1);
	}
	//각 단계에서 전단계로 돌아갈 땐 현재 방문한 곳을 방문 안했다고 처리를 하고 돌아가야함
	visited[h][w] = false;
	used[board[h][w]-'A']=false;
}

void Solution() {
	Backtracking(0, 0, 1);
	cout << maxLength;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solution();
}
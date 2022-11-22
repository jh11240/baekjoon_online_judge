#include<iostream>
#include<queue>

using namespace std;
int totFlo=0, startFlo=0, goalFlo=0;
//4백만 바이트 ㄱㅊ
int visited[1'000'001];
//up 층수, down 층수 저장용 배열
int dx[2];
void input() {
	cin >> totFlo >> startFlo >> goalFlo >> dx[0] >> dx[1];
	//down이므로 -1곱해야함
	dx[1] *= -1;


}

void BFS() {
	//같다면 0출력
	if (startFlo == goalFlo) {
		cout << 0;
		return;
	}
	queue<int> q;
	visited[startFlo] = 1;
	q.push(startFlo);
	int level = 1;
	while (!q.empty()) {
		//큐사이즈는 가변적이라 변수에 할당
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			//큐front 변수에 할당 후 pop
			int cur = q.front();
			q.pop();
			//up과 down에 작동하게 반복문 설정
			for (int i = 0; i < 2; i++) {
				//i가 0일때 up, 1일때 down값
				int nextFlo = cur + dx[i];
				//다음 층수가 목표 층수면 
				if (nextFlo == goalFlo) {
					//해당 레벨 출력
					cout << level<<'\n';
					return;
				}
				//층수가 1보다 크거나 같고, 총 층수 안넘어가면
				if (nextFlo>=1 && nextFlo<totFlo) {
					//방문 안했다면
					if (!visited[nextFlo]) {
						//방문 처리 후
						visited[nextFlo] = true;
						//큐에 넣기
						q.push(nextFlo);
					}
				}
			}
			
		}
		//큐사이즈만큼 반복하고나면 레벨 하나 조사 끝났으므로 레벨 ++
		level++;
	}
	//반복문 빠져나왔다면 해당 값을 못찾은 것이므로 계단써라 출력
	cout << "use the stairs";
	return;
	
}

void solution() {
	BFS();
}

int main() {
	input();
	solution();
}
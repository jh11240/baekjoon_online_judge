#include<iostream>
#include<functional>
#include<queue>

using namespace std;
queue<int> q;
int number=0, maxButtonPress = 0, Goal = 0;
bool visited[100'001];

//function을 사용한 함수 포인터
const function<int(int n)> f[2] = {
	//a버튼
	[](int n) {return n + 1; },
	//b버튼 
	[](int n) {
		//n이 0이라면 b버튼 눌러도 0임(조건) 
		if (n == 0) return 0;
		//2를 곱한값 변수에 할당
		int inputNum = 2 * n;
		//99만 9999넘어가면 -1 return
		if (inputNum > 99'999) return -1;
		//안넘어가면 2*n의 자릿수 구한후 제일 높은자리수 -1해준 후 return
		else {
			int cnt = 1;
			while (inputNum/10 !=  0) {
				cnt *= 10;
				inputNum /= 10;
			}
			return 2 * n - cnt;
		}
	}

};

void input() {
	cin >>number>> maxButtonPress >> Goal;
	q.push(number);
	visited[number] = true;
}


void solution() {
	//만약 목적지와 시작숫자가 같으면 누를이유가 없으므로 0 출력해버리기
	if (Goal == number) {
		cout << 0;
		return;
	}

	int level = 1;
	//bfs에서 큐가 빌때까지 반복, level증가
	for (; !q.empty(); level++) {
		//큐는 가변적이므로 사이즈 미리 할당
		int qSize = q.size();
		//각 레벨 당 버튼한번 누르는 경우이므로 레벨 진행하기전에 하나 감소
		maxButtonPress--;
		// 각 레벨의 노드수만큼 반복문 진행
		for (int i = 0; i < qSize; i++) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < 2; i++) {
				int nextN = f[i](cur);
				if (nextN == Goal) {
					cout << level;
					return;
				}
				//범위 벗어나면 continue
				if (nextN < 0 || nextN>99'999) continue;
				//이미 방문한 수면 continue
				if (visited[nextN]) continue;
				//방문 처리
				visited[nextN] = true;
				//큐에 넣어주기
				q.push(nextN);
			}
		}
		//버튼을 누른 경우의 수가 다끝났을때 0이하면 더이상 못누르므로 ang출력
		if (maxButtonPress <= 0) {
			cout << "ANG";
			return;
		}
	}
	//반복문끝나면 ang출력
	cout << "ANG";
}

int main() {
	input();
	solution();
}
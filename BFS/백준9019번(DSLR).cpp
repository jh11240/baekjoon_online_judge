#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int testCases = 0,startNum=0,goalNum=0;
int visited[10'001];
char DSLR[4] = { 'D','S','L','R' };

//각 bfs에서 사용되는 답배열이랑 숫자배열 저장하는 구조체
struct calculator {
	int Num;
	queue<char> Ans;
};


//함수 포인터
const function<int(int)> f[4] = {
	//D입력받을 시,
	[](int num) {
		if (num * 2 > 9999) { return num = (num * 2) % 1000; }
		else return num *= 2;
	},
	//S입력받을 시,
	[](int num) {
		if (num == 0) { return 9999; }
		else return num -= 1;
	},
	//L입력받을 시,
	[](int num) {
		//제일 높은 자릿수의 숫자
		int tmp = num;
		//자릿수
		int cnt = 1;
		while (tmp/10 != 0) {
			tmp /= 10;
			cnt*=10;
		}
		//제일 윗자리수 빼준 후
		num -= tmp * cnt;
		//숫자 10곱한후 tmp넣어줌.
		num = num * 10 + tmp;
		return num;
	},
	//R입력받을 시,
	[](int num) {
		int tmp = num;
		//자릿수
		int cnt = 1;
		while (tmp / 10 != 0) {
			tmp /= 10;
			cnt *= 10;
		}
		//일의 자리 저장
		int digit1 = num % 10;
		//10으로 나눠줘 일의자리 없애기
		num /= 10;
		//10곱하고 더해주기.
		num = num +cnt*digit1;
		return num;
	},

	
};

void Solution();

void Input() {

	cin >> testCases;
	while (testCases--) {
		cin >> startNum >> goalNum;
	
		Solution();
		if (testCases != 0) cout << '\n';
	}
}

void Solution() {
	queue<calculator> q;
	calculator tmpCal;
	tmpCal.Num = startNum;
	q.push(tmpCal);
	visited[startNum] = true;

	while (!q.empty()) {
		calculator cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			queue<char> nextQ = cur.Ans;
			int nextA = f[i](cur.Num);
			if (nextA == goalNum) {
				while (!cur.Ans.empty()) {
					cout << cur.Ans.front();
					cur.Ans.pop();
				}
				cout << DSLR[i];
				return;
			}
			if (nextA < 0 || nextA >= 10'000) continue;
			if (visited[nextA]) continue;
			visited[nextA] = true;
			nextQ.push(DSLR[i]);
			q.push({ nextA,nextQ });
		}
	}
}

int main() {
	Input();
}
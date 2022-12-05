#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

int testCases = 0, startNum = 0, goalNum = 0;
int visited[10'001];
char DSLR[4] = { 'D','S','L','R' };

//각 bfs에서 사용되는 답배열이랑 숫자배열 저장하는 구조체
struct calculator {
	int Num;
	vector<char> Ans;
};


//함수 포인터
const function<int(int)> f[4] = {
	//D입력받을 시,
	[](int num) {
		if (num * 2 > 9999) { return num = (num * 2) % 10000; }
		else return num *= 2;
	},
	//S입력받을 시,
	[](int num) {
		if (num == 0) { return 9999; }
		else return num -= 1;
	},
		//L입력받을 시,
	[](int num) {
			int tmp = num / 1000;
			num -=tmp * 1000;
			num = num * 10 + tmp;
			return num;
	},
		//R입력받을 시,
		[](int num) {
			int tmp = num;
			//일의 자리 저장
			int digit1 = num % 10;
			//10으로 나눠줘 일의자리 없애기
			num /= 10;
			//10곱하고 더해주기.
			num += 1000 * digit1;
			return num;
		},


};

void Solution();

void Input() {

	cin >> testCases;
	while (testCases--) {
		//visited 배열 초기화
		fill(&visited[0], &visited[10000], false);
		cin >> startNum >> goalNum;

		Solution();
		if (testCases != 0) cout << '\n';
	}
}

void Solution() {
	//bfs에 사용될 큐
	queue<calculator> q;
	calculator tmpCal;
	//초기 calculator에 startNum값 넣어주고,
	tmpCal.Num = startNum;
	//push해줌
	q.push(tmpCal);
	//시작값 방문 처리
	visited[startNum] = true;

	while (!q.empty()) {
		calculator cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			//새로 만들어줄 필요없이 그냥 푸시후 다음에 또 쓰일걸 대비해 팝해주면 된다.
			//vector<char> nextQ = cur.Ans;

			//각 버튼을 눌렀을 때의 숫자
			int nextA = f[i](cur.Num);
			//숫자가 목표와같다면 출력!
			if (nextA == goalNum) {
				for (auto iter = cur.Ans.begin(); iter != cur.Ans.end(); ++iter) {
					cout << *iter;
				}
				cout << DSLR[i];
				return;
			}
			//범위 나가면 continue
			if (nextA < 0 || nextA >= 10'000) continue;
			//방문한 숫자면 continue
			if (visited[nextA]) continue;
			//방문처리
			visited[nextA] = true;
			//각 버튼값 벡터에 넣어줌
			cur.Ans.push_back(DSLR[i]);
			//큐에 다음 노드로 푸시해줌
			q.push({ nextA,cur.Ans });
			//cur.Ans는 반복문 3번할동안 공유하므로 지금넣어준값 pop해야함.
			cur.Ans.pop_back();
		}
	}
}

int main() {
	//시간초과 안나도록,,
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	Input();
}
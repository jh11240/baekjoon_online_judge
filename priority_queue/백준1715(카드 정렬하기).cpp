#include<queue>
#include<vector>
#include<iostream>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

void Solution() {
	int Ans = 0,tmp=0;
	//카드 뭉치 한개라면 비교횟수는 0회
	if (pq.size() == 1) {
		cout << 0 << '\n';
		return;
	}
	//사이즈가 1이 아닐때 
	while (pq.size() != 1) {
		//우선순위큐에서 top값 두개를 빼서 더한다.
		for (int i = 0; i < 2; i++) {
		tmp += pq.top();
		pq.pop();
		}
		//더한 값을 다시 우선순위큐에 넣기
		pq.push(tmp);
		//더한값을 Ans변수에 더해줌 
		Ans += tmp;
		tmp = 0;
	}
	cout << Ans;
	return;
}

void Input() {
	int N=0,tmp=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pq.push(tmp);
	}

}

int main() {
	Input();
	Solution();
}